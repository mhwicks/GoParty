Sub DeclareSlow
|==================================================================================================|

	/declare intSlowDuration int outer 240		|- Duration of slow spell in Seconds
	/declare intSlowTimeLeft int outer 0
	/declare intNeedsSlow int outer 0
	/declare intSlowRange int outer 80

	/declare intSlowLoop int outer 0
	/declare intSlowLoopManual int outer 0
	/declare intSlowLoopManual2 int outer 0

	/declare intPrimaryTarget int outer 0
	/declare intGroupTargetID int outer 0
	/declare intLastMobSlowedID int outer 0
	/declare arrSlowMobID[11] int outer 0
	/declare arrSlowTime[11] int outer 0
	
/return

|==================================================================================================|
Sub SlowCheck
	/declare	intLocalDebug		int		local	0

	/if (${intLocalDebug}) /echo SLOW CHECK ACTIVE!
	
	/varset intPrimaryTarget ${Target.ID}
	
	|Check XTargets:
	/if (${Me.XTarget} <= 1) /return

	|-If no mobs in range, don't bother:
	/if (${SpawnCount[npc zradius 25 radius ${intSlowRange}]} > 1) {
		/echo Mobs within ${intSlowRange} feet: ${SpawnCount[npc zradius 25 radius ${intSlowRange}]}
	}
	/if (${SpawnCount[npc zradius 25 radius ${intSlowRange}]}) {
	
		|-------------------------
		|-Clear out expired slows:
		/varset intSlowLoop 0
		:ExpireSlowList
		/varcalc intSlowLoop ${intSlowLoop} + 1 
			/if (${arrSlowMobID[${intSlowLoop}]}) {
				|/echo Checking ${arrSlowMobID[${intSlowLoop}]} in slot ${intSlowLoop} 
				/varcalc intSlowTimeLeft ${arrSlowTime[${intSlowLoop}]} - ${Macro.RunTime}
				/if (${intSlowTimeLeft} < 30) {
					/varset arrSlowMobID[${intSlowLoop}] 0
					|/echo ${intSlowTimeLeft} seconds left - Clearing entry.
				}
			}
		|/echo slot ${intSlowLoop} is clear.
		/doevents
		/if (${intSlowLoop} < 10) /goto :ExpireSlowList
		
		|----------------------
		|-Slow All Nearby Mobs:
		/varset intSlowLoop 0
		:CheckNearbyMobs
		/varcalc intSlowLoop ${intSlowLoop} + 1 
		|/echo I'm starting intSlowLoop.
	
		|-------------------------------------------
		|- Look for a record of slowing each target:
		/varset intNeedsSlow 1 
		|/varset intGroupTargetID ${NearestSpawn[${intSlowLoop},npc zradius 25 radius ${intSlowRange}].ID}
		/varset intGroupTargetID ${Me.XTarget[${intSlowLoop}].ID}
		
		|Set Primary Target if no target found:
		/if (!${intGroupTargetID}) /varset intGroupTargetID ${intPrimaryTarget}
					|/echo Considering mob ${Spawn[${intGroupTargetID}].Name}(${intGroupTargetID}).
		/varset intSlowLoopManual 0
		:CheckSlowList
		/varcalc intSlowLoopManual ${intSlowLoopManual} + 1 
			|/echo intSlowLoopManual = ${intSlowLoopManual}; Mob ID = ${arrSlowMobID[${intSlowLoopManual}]}.
			/if (${arrSlowMobID[${intSlowLoopManual}]} == ${intGroupTargetID}) {
				/varcalc intSlowTimeLeft ${arrSlowTime[${intSlowLoopManual}]} - ${Macro.RunTime}
				/if (${intLocalDebug}) /echo ${Spawn[${intGroupTargetID}].Name} (${arrSlowMobID[${intSlowLoopManual}]}) has ${intSlowTimeLeft} seconds left.
				/varset intNeedsSlow 0
			}
		/doevents
		/if (${intSlowLoopManual} < 10) /goto :CheckSlowList
		
		|-----------------------------------
		|-Check mob health for safe slowing:
		/Target id ${intGroupTargetID}
		/delay 4
		/if (${Spawn[${intGroupTargetID}].CurrentHPs} > 99) {
			/varset intNeedsSlow 0
			/if (${intLocalDebug}) /echo ${intGroupTargetID} is at ${Spawn[${intGroupTargetID}].CurrentHPs}%!  No Slow yet.
			|/echo intNeedsSlow set to ${intNeedsSlow}.
			|/squelch /target clear
		}

		|-----------------------------------
		|-Don't Slow Corpses or mob not worth it:
		/if (${Spawn[${intGroupTargetID}].CurrentHPs} < 20) {
			/varset intNeedsSlow 0
			|/echo ${intGroupTargetID} is at ${Spawn[${intGroupTargetID}].CurrentHPs}%!  Not worth slowing.
			|/echo intNeedsSlow set to ${intNeedsSlow}.
			|/squelch /target clear
		}

		|-----------------------------------
		|Clear safe mob list:
		/if (${Spawn[id ${Target.ID} alert 1].ID}) /squelch /target clear


		|- Slow any mob not in list:
		/if (${intNeedsSlow} > 0) {
			/echo Slowing ${Spawn[${intGroupTargetID}].Name} (${intGroupTargetID}).
			|/Target id ${intGroupTargetID}
			/varset intLastMobSlowedID ${intGroupTargetID}
			/delay 10
			/face nolook
			|/g Slowing %t.
			|/echo ${Target.ID} is ${Target.Name}.
			
			|Chanter Slow:
			/if (${Me.Class.ID} == 14) /call Cast ${ENCslow} gem5 0
			
			|Shammy Slow:
			/if (${Me.Class.ID} == 10) /call Cast ${SHMslow} alt

			/delay 1
			/pet attack
			|/target clear
			/doevents
		}
		|/echo Mob handled.  Next!
		|/if (${intSlowLoop} <= ${SpawnCount[npc zradius 25 radius ${intSlowRange}]}) /goto :CheckNearbyMobs
		/if (${intSlowLoop} <= ${Me.XTarget}) /goto :CheckNearbyMobs
		|/echo All nearby mobs handled.  What else do I need to do?
	}
/return

|==================================================================================================|
Sub SlowList
	
	|-Place mob in the slow list:
	/echo ${Spawn[${intLastMobSlowedID}].Name} (${intLastMobSlowedID}) slowed.  Adding it to list...
	
	/varset intSlowLoopManual2 0
	:BuildSlowList
	/varcalc intSlowLoopManual2 ${intSlowLoopManual2} + 1 
		|/echo Slot number ${intSlowLoopManual2} is ${arrSlowMobID[${intSlowLoopManual2}]}...
		/if (${arrSlowMobID[${intSlowLoopManual2}]} == 0) {
			/if (${intLocalDebug}) /echo Setting slot ${intSlowLoopManual2} as ${intLastMobSlowedID}
			/varset arrSlowMobID[${intSlowLoopManual2}] ${intLastMobSlowedID}
			/varcalc arrSlowTime[${intSlowLoopManual2}] ${Macro.RunTime} + ${intSlowDuration}
			/varset intSlowLoopManual2 11
		}
	/if (${intSlowLoopManual2} < 10) /goto :BuildSlowList

/return