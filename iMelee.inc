
|==================================================================================================|
Sub DeclareMelee
	
	/declare intClosingCombat 	int 	outer 0
	/declare intMeleeMarkY 		int 	outer 0
	/declare intMeleeMarkX 		int 	outer 0
	/declare strStrafeDirection	string	outer
	/declare intMeleeVerbose	int		outer 0
	
/return

|==================================================================================================|
Sub Melee

	|/echo Melee!
	
	|Get Lowest Health Target if intGoLow:
	/if (${intGoLow}) {
		/call GoLow
	}

	|Get within melee range of mob:
	:MeleeLoop

	|Break out if mob is dead:
	/if (!${Target.ID}) {
		/keypress forward
		/if (${Me.Combat}) /attack off
		/echo No target - melee stopped.
	 	/return
	}

	|Break out if self targeted:
	/if (${Target.ID} == ${Me.ID}) {
		/keypress forward
		/if (${Me.Combat}) /attack off
	 	/return
	}
	
	|Break out if DS is scary (set in goparty.mac):
	/if (${intMobHasDS} && ${Me.Combat}) {
		/echo ${Me.Combat}
		/echo No melee because of DS.
		/keypress forward
		/attack off
		/delay 5
		/return
	}

	/stand
	/face fast nolook
	/if (${Target.Distance} > 12) {
		|Get closer
		|/echo I'm at ${Target.Distance}, but need to be within ${Target.MaxRangeTo}.
		/keypress forward hold
		/delay 1
		
		/varset intClosingCombat 1
		
		|Bards check for Mez action:
		/if (${intMez}) {
			/if (${SpawnCount[npc zradius ${intMezRadiusZ} radius ${intMezRadius}]} > 1) {
				/keypress forward
				/varset intClosingCombat 0
				/return
			}
		}

	} else {
		/if (${Target.Distance} < 2) {
			|It's just a bit tight
			|/echo I'm at ${Target.Distance}, but ONLY need to be within ${Target.MaxRangeTo}.
			/keypress back hold
			/varset intClosingCombat 1
		} else {
			|/echo Distance of ${Target.Distance} is reasonable.
			/keypress back
			/varset intClosingCombat 0
		}
	}
	
	|Stay in this loop until distance is correct:
	/if (${intClosingCombat}) /goto :MeleeLoop
	
	|Take the mob's Back:
	/if (!${intTank}) /call MeleeBack
	
	|Verify Auto Attack is ON:
	/if (${Target.ID}) {
		/if (${Target.PctHPs} <= 99 || ${intLead}) {
			/if (!${Me.Combat}) {
				|/echo All Melee Classes - Attack the mob!:
				/attack
			}

			|Berzerkers: Press 1 and 2 for Stone/Kick:
			/if (${Me.Class.ID} == 16) {
				|/if (${Me.CombatAbilityReady[Divertive Strike]}) /keypress 3
				/if (${Me.CombatAbilityReady[Throw Stone]}) /keypress 1
				/if (${Me.AbilityReady[Kick]}) /doability Kick
			}

			|Monks - Get on the offense!
			/if (${Me.Class.ID} == 7) {
				|/echo Monk Melee!
				/if (${Me.AbilityReady[Flying Kick]}) /doability "Flying Kick"
				/if (${Me.AbilityReady[disarm]}) /doability "disarm"
				/if (${Me.CombatAbilityReady[Cloud of Fists Rk. II]}) /doability "Cloud of Fists Rk. II"
				/if (${Me.CombatAbilityReady[Veilwalker's Synergy]}) /doability "Veilwalker's Synergy"
				/if (${Me.AbilityReady[Eagle Strike]})   /doability "Eagle Strike"
				/if (${Me.AltAbilityReady[Eye Gouge]}) /alt activate 470
			}

		}
	}

/return

|==================================================================================================|
Sub MeleeBack

	|If we have TargetOfTarget, use it:
	/if (${Me.LAHoTT}) {
		/if (${Me.TargetOfTarget.ID} == ${Me.ID}) /return
	}
	
	|/if (${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} == 0) {
	/if (${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} >= -1 && ${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} <= 1) {
		/if (${intMeleeVerbose}) /echo I have the mob's back.
		/return
	}
	
	/if (${Target.PctHPs} > 80) /return
	
	/if (${intMeleeVerbose}) /echo I gotta get to the back...
	/if (${intMeleeVerbose}) /echo Me: ${Me.Heading.Clock} Mob: ${Target.Heading.Clock} Difference: ${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]}
	
	/varset strStrafeDirection "STRAFE_RIGHT"
	/if (${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} < 0) /varset strStrafeDirection "STRAFE_LEFT"
	
	/keypress ${strStrafeDirection} hold
	/for Looper 1 to 3
		/if (${intMeleeVerbose}) /echo strafing...
		/if (!${Target.ID}) {
			/keypress right
			/return
		}
		/if (${Target.ID}) /face fast nolook
		/keypress forward
		/delay 1 (${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} == 0)
		/if (${Target.ID}) /face fast nolook
		/if (${Math.Calc[${Me.Heading.Clock} - ${Target.Heading.Clock}]} == 0) /varset Looper 10
	/next Looper
	/keypress right
	
/return

|==================================================================================================|
Sub MeleeMark

	|Only melee mark if not still in combat - no mobs within 50 feet:	
	|/if (${SpawnCount[npc zradius 40 radius 50]} < 1) {
		/varset intMeleeMarkY ${Me.Y}
		/varset intMeleeMarkX ${Me.X}
		|/echo MeleeMarking Y:${intMeleeMarkY}, X:${intMeleeMarkX}
	|}
/return

|==================================================================================================|
Sub MeleeReturnToMark

	|/echo MeleeReturning
	
	|End subroutine if MeleeMarks are not set:
	/if (!${intMeleeMarkY} && !${intMeleeMarkY}) /return

	/Varset LocDesc[${TotalLocs}] "Returning"
	/Varset LocY[${TotalLocs}] ${intMeleeMarkY}
	/Varset LocX[${TotalLocs}] ${intMeleeMarkX}
	/Varset LocFace[${TotalLocs}] ${Spawn[${strMyTank}].Heading.DegreesCCW}
	/Varset Iterations 999
	
	/if (${Me.Combat}) /attack off
	/look 0
	/if  (${Math.Distance[${Me.X},${Me.Y},0:${intMeleeMarkX},${intMeleeMarkY},0]} > 15) {
		|/echo Base is ${Math.Distance[${Me.X},${Me.Y},0:${intMeleeMarkX},${intMeleeMarkY},0]} feet away.
		|/echo Moving Out!
		/call MoveOut
		/look 0
	} else {
		|/echo Already close enough to Melee Mark.
	}
	
/return
