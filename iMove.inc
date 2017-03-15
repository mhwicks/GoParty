Sub DeclareMove

	/declare LocationID int outer 208
	/declare TotalLocs int outer 0
	/declare MoveIndex int outer 1
	/declare LocDistance float outer
	/declare intFreeToMoveTime int outer 0
	/declare intBackStep int outer 0
	/declare intStartingDistance int outer 0
	/declare intSafeMob int outer 0
	
	/declare MobX int outer 0
	/declare MobY int outer 0
	/declare LocX[150] float outer
	/declare LocY[150] float outer
	/declare LocFace[150] float outer
	/declare LocDur[150] float outer
	/declare LocRange[150] float outer
	/declare LocDesc[150] string outer
	/declare LocPullRange[150] int outer

/Return

|==================================================================================================|
Sub MoveCheck

|Mana check for long pit stops:
|---------------------------------------------------
/if (${Iterations} > ${LocDur[${MoveIndex}]}) {

	|Check for backStep Requirement:
	/if (!${intBackStep}) {
		|Hang tight if anyone in the group is casting or low mana:
		/if (${intFreeToMoveTime} > ${Macro.RunTime}) {
			/echo Waiting for a group member to finish casting or medding.
			/varcalc Iterations ${Iterations} - 10
			/if (${Iterations} < 0) /varset Iterations 0
		}
	
		/If (${LocDur[${MoveIndex}]} > 4) {
			/If  (${Me.PctMana} <= 80 && ${Me.PctMana} > 0) {
				/Echo Mana too low, resetting Iterations.
				/Varset Iterations 0
			}
			/If  (${Me.PctHPs} <= 80) {
				/Echo Health too low, resetting Iterations.
				/Varset Iterations 0
			}
		}
	}
}

/if  (${Math.Distance[${Me.X},${Me.Y},0:${LocX[${MoveIndex}]},${LocY[${MoveIndex}]},0]} > 5 || ${TotalLocs} > 2) {
	|/echo I am ${Math.Distance[${Me.X},${Me.Y},0:${LocX[${MoveIndex}]},${LocY[${MoveIndex}]},0]} feet from base.
	/call MoveOut
} else {
	|/echo I'm only ${Math.Distance[${Me.X},${Me.Y},0:${LocX[${MoveIndex}]},${LocY[${MoveIndex}]},0]} feet from base, I'm good.
}

/return

|==================================================================================================|
Sub MoveOut

|Move code:
|---------------------------------------------------
/If (${Iterations} > ${LocDur[${MoveIndex}]}) {
	/varset StuckCounter 0
	/varset BigStuckCounter 0
	/Varset Iterations 0
	/if (!${intBackStep}) {
		/Varcalc MoveIndex ${MoveIndex} + 1
		/varset intDifficultCorpse 0
	} else {
		/Varset intBackStep 0
	}

	|Checks TOP end of Move Line/Loop
	/if (${MoveIndex} > ${TotalLocs}) {
		/Varset MoveIndex 1
	}

	/echo Moving to ${LocDesc[${MoveIndex}]}.
	/mqlog Moving to ${LocDesc[${MoveIndex}]}.

	|/echo Waypoint=${MoveIndex}, X=${LocX[${MoveIndex}]}, Y=${LocY[${MoveIndex}]}.
	|/echo Facing=${LocFace[${MoveIndex}]}, Dur=${LocDur[${MoveIndex}]}, Range=${LocRange[${MoveIndex}]}.
	|/echo I'm at X=${Me.X}, Y=${Me.Y}.
	/Stand
	
	:MoveLoop
	/face fast nolook loc ${LocY[${MoveIndex}]},${LocX[${MoveIndex}]} 
	/keypress forward hold 
	/varcalc LocDistance ${Math.Distance[${Me.X},${Me.Y},0:${LocX[${MoveIndex}]},${LocY[${MoveIndex}]},0]}

	|Stop walking if a mob is too close:
	/varset intSafeMob 0
	/if  ((${NearestSpawn[NPC zradius 25].Distance} <= 30) && (${NearestSpawn[NPC zradius 25].Distance} >= 1)) {
		/for Looper	1 to ${Math.Calc[${Ini[iSafeMobs.ini, SafeMobs, ${Zone.Name}].Count[|]} + 1]}
			|/echo Checking ${Ini[iSafeMobs.ini, SafeMobs, ${Zone.Name}].Arg[${Looper},|]}.
			/if (${NearestSpawn[NPC zradius 30].CleanName.Equal[${Ini[iSafeMobs.ini, SafeMobs, ${Zone.Name}].Arg[${Looper},|]}]}) /varset intSafeMob 1
		/next Looper
		/if (${NearestSpawn[NPC zradius 25].Name.Length} > 3) /varset intSafeMob 1
	
		/if (!${intSafeMob}) {
			/echo ${NearestSpawn[NPC zradius 25].Name} encountered En Route (${NearestSpawn[NPC zradius 25].Distance})!
			/varset intBackStep 1
			/Varset LocDistance 0
		}
	} 
	
	|If we've been walking too long, give up.
	/Varcalc Iterations ${Iterations} + 1
	/if  (${Iterations} > 300) {
		/Varset LocDistance 0
	} 
	
	|--------------------------------------------------------------------------
	|Handle slowdowns, and sticks.
	/vardata LocDiff Math.Calc[${LocDistance} + 0.5]
	/if  (${LastDistance} < ${LocDiff}) {
	
		|If there is a door - open it:
		/squelch /doortarget
		/if (${DoorTarget.Distance} < 10) {
			/face door nolook
			/delay 5
			/keypress use
			/delay 2
		
		|Otherwise jiggle:	
		} else {
			|/echo Jiggle (${Target.Name} at range ${Target.Distance})...
			/varcalc StuckCounter ${StuckCounter} + 1
			/echo Stuck? ${StuckCounter}, ${LastDistance}, ${LocDiff}
			/delay 1
			/if (${StuckCounter} > 8) {
				/echo Jiggle (${Target.Name} at range ${Target.Distance})...
				/varcalc BigStuckCounter ${BigStuckCounter} + 1
				/keypress forward
				/delay 1
				/if (${BigStuckCounter} > 2) {
					/keypress STRAFE_LEFT hold
				} else {
					/keypress STRAFE_RIGHT hold
				}
				/keypress back hold
			
				/echo Big loops: ${BigStuckCounter}, Trying for: ${LocDesc[${MoveIndex}]}.
				/for Looper 1 to ${BigStuckCounter}
					/face nolook loc ${LocY[${MoveIndex}]},${LocX[${MoveIndex}]} 
					/if (${Looper} > 1) /keypress back
					/delay 1s
				/next Looper
				
				|Pop out if you are really stuck.
				/if (${BigStuckCounter} > 4) {
					|/varset StillGotOne 0
					/varset LocDistance 0
					
					|Backstep one location to get out.
					/Varcalc MoveIndex ${MoveIndex} - 1
					/if (${MoveIndex} < 1) {
						/varset MoveIndex ${TotalLocs}
					}
					/Varset intBackStep 1
				}
	
				/keypress right
				/keypress back
				/varset Iterations 1
				/varset StuckCounter 0
			}
		}
	}
	/varset LastDistance ${LocDistance}
	/delay 1
	
	|/echo ${LocDistance}
	/if  (${LocDistance} > 10) {
		/Goto :MoveLoop
	} 
	/keypress forward
	/Face Heading ${LocFace[${MoveIndex}]}
	/Varset Iterations 0
	/varset LastDistance 1000

	|Wait for pets:
	/delay 1s
}
/return
