
|==================================================================================================|
Sub DeclareGoLow

	|----------------------------------------------------------**| 
	|Variable Declarations:
	/declare intLowestHP 		int 		outer 		100
	/declare intRadius 			int 		outer 		40 			| This should be a low number - lower than ${LocRange[${MoveIndex}]} which defaults to 70
	/declare intAttackPercent 	int 		outer 		100
	/declare intHitLoops		int			outer		0
	
	/declare intMayBestID		int 		outer 		0
	/declare intBestID 			int 		outer 		0
	/declare intGoLow 			int 		outer
	/declare arrHitList[99]		int			outer		0
	/declare intHitList			int			outer		0
	/declare intHitDuration		int			outer		0

/return

|==================================================================================================|
Sub GoLow
	/declare	intLocalDebug		int		local	0
	
	| Leave if there's nothing going on:
	/if (!${SpawnCount[npc radius ${intRadius} noalert 1]}) {
		/for intHitLoops 1 to ${intHitList}
			/varset arrHitList[${intHitLoops}] 0
		/next intHitLoops
		/varset intHitList 0
		/return
	}

	| One quick chance to update the list:
	/doevents flush
	
	| Give a little time on the current mob if not already on the hit list:	
	/if (${Macro.RunTime} < ${intHitDuration}) /return
	/if (${intLocalDebug}) /echo We've been on this one long enough, let's look for a better target...
	/if (${Target.ID}) {
		/for intHitLoops 1 to ${intHitList}
			/if (${arrHitList[${intHitLoops}]} == ${Target.ID}) /varset intHitDuration 0
		/next intHitLoops
	}
		
	| Show Hit List if in debug mode:
	/if (${intLocalDebug}) {
		/for intHitLoops 1 to ${intHitList}
			/if (${intLocalDebug}) /echo Hit List ${intHitLoops}: ${Spawn[id ${arrHitList[${intHitLoops}]}].CleanName} (${Spawn[id ${arrHitList[${intHitLoops}]}].PctHPs}) - ID: ${arrHitList[${intHitLoops}]}
		/next intHitLoops
	}
	
	| Target which of the closest mobs has the least HP:
	/if (${intLocalDebug}) /echo Monitoring ${SpawnCount[npc radius ${intRadius} noalert 1]} mobs within ${intRadius} feet.
	/varset intBestID 0
	/for Iterations 1 to ${SpawnCount[npc radius ${intRadius} noalert 1]}
		/target ${NearestSpawn[${Iterations}, npc zradius 20 radius ${intRadius} noalert 1]}

		/if (${intLocalDebug}) /echo Mob ${Iterations}: ${Target.CleanName} (${Target.PctHPs})
		/if (${Target.PctHPs} > 5 && ${Target.PctHPs} <= ${intAttackPercent}) {
		
			| Don't set it as best target if it's on the hit list:
			/varset intMayBestID ${Target.ID}
			/for intHitLoops 1 to ${intHitList}
				/if (${arrHitList[${intHitLoops}]} == ${Target.ID}) {
					/if (${intLocalDebug}) /echo This mob: ${Target.CleanName} (${Target.ID}) is on the hit list already.
					/varset intMayBestID 0
				}
			/next intHitLoops
			
			| Find the lowest of the non-hitlisters:
			/if (${intMayBestID}) {
				/if (!${intBestID}) /varset intBestID  ${Target.ID}
				/if (${Target.PctHPs} <= ${Spawn[id ${intBestID}].PctHPs}) {
					/varset intBestID ${Target.ID}
					/if (${intLocalDebug}) /echo So far ${Target.CleanName} (${Target.ID}) Looks like the best target.
				}
			}
		}
		/delay 1
	/next Iterations
	
	|Target the Lowest HP mob:
	/if (${intBestID}) {
		/target id ${intBestID}
	} else {
		/echo I THINK I GOT THEM ALL!  Let's Start over to be sure!
		/for intHitLoops 1 to ${intHitList}
			/varset arrHitList[${intHitLoops}] 0
		/next intHitLoops
		/varset intHitList 0

		/target ${NearestSpawn[1, npc zradius 20 radius ${intRadius} noalert 1]}
	}
	/echo Attacking ${Target.CleanName} (${Target.PctHPs})!
	
	| Let's commit to this mob for a few second:
	/varcalc intHitDuration ${Macro.RunTime} + 7
	/if (${intLocalDebug}) /echo Current: ${Macro.RunTime}; intHitDuration: ${intHitDuration}.
	
/return

|==================================================================================================|
Sub GoLowLister

	/for intHitLoops 1 to ${intHitList}
		/if (${arrHitList[${intHitLoops}]} == ${Target.ID}) /return
	/next intHitLoops
	
	/varcalc intHitList ${intHitList} + 1
	/varset arrHitList[${intHitList}] ${Target.ID}
	/echo ADD ${intHitList}: ${Target.CleanName} (${Target.PctHPs}) to the hit list.
	|/squelch /target clear
	/varset intHitDuration 0
	/doevents flush
	
/return
