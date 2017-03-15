
|==================================================================================================|
Sub DeclareFollow

	/declare strFollowTarget string outer
	/declare LastDistance float outer 1000
	/declare LocDiff float outer 0
	/declare StuckCounter int outer 0
	/declare BigStuckCounter int outer 0
	/declare Looper int outer 0
	/declare Looper2 int outer 0

/return

|==================================================================================================|
Sub Follow

|Follow:
	/if (${NearestSpawn[PC ${strFollowTarget}].Distance} > 20) {
		|/echo Follow mode activated.
		/varset StuckCounter 0
		/varset BigStuckCounter 0
		/varset Iterations 0
		
		:FollowLoop

		/if (${Me.Class.ID} == 8) /Call BardSongs

		/Target PC ${strFollowTarget}
	
		/if (${Me.AutoFire}) /AutoFire
	
		/face fast
		/varcalc LocDistance ${Math.Distance[${Me.X},${Me.Y},0:${Target.X},${Target.Y},0]}
		/vardata LocDiff Math.Calc[${LocDistance} + 0.20]

		|STOP if too close:
		/if  (${LocDistance} < 10) {
			/keypress forward
			/squelch /target clear
			/delay 1
		} 
		
		|Follow if we can:
		/if  (${LocDistance} > 20) {
			/keypress forward hold
		} 
		
		/call Jiggle
		
		/varset LastDistance ${LocDistance}

		/delay 1
		
		|Reloop:
		/if (${Target.ID}) /goto :FollowLoop
		
		|/echo Follow mode complete.
		/keypress back
		/look 0
		/varset LastDistance 1000
		/face heading ${NearestSpawn[PC ${strFollowTarget}].Heading.DegreesCCW}
		/doevents
		/doevents flush

	}

/return


|==================================================================================================|
Sub Jiggle

	|--------------------------------------------------------------------------
	|Jiggle occsionally to prevent getting stuck.
		/Varcalc Iterations ${Iterations} + 1
		|Account for target moving:
		/if (${Target.Speed} > 50) {
			/vardata LocDiff Math.Calc[${LocDistance} - 5]
		}
		/if  ((${LastDistance} < ${LocDiff})&&(${LocDistance} > 25)) {
			|/echo Jiggle (${Target.Name} at range ${Target.Distance})...
			/varcalc StuckCounter ${StuckCounter} + 1
			|/echo Stuck? ${StuckCounter}, ${LastDistance}, ${LocDiff}
			/delay 5
			/if (${StuckCounter} > 9) {
				/echo Jiggle - (${Target.Name} at range ${Target.Distance})...
				/varcalc BigStuckCounter ${BigStuckCounter} + 1
				/keypress forward
				/delay 1
				/if (${BigStuckCounter} % 2 == 0) {
					/keypress STRAFE_RIGHT hold
				} else {
					/keypress STRAFE_LEFT hold
				}
				/keypress back hold
				/face
			
				/echo Big loops: ${BigStuckCounter}
				/for Looper 1 to ${BigStuckCounter}
					/if (${Looper} > 1) /keypress back
					/delay 1s
				/next Looper
				
				|Pop out if you are really stuck.
				/if (${BigStuckCounter} > 5) {
					/return
				}

				/keypress right
				/keypress back
				/varset Iterations 1
				/varset StuckCounter 0
			}
		}

/return
