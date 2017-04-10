Sub DeclareMez
|==================================================================================================|

	/declare intMez				int 	outer 0
	/declare intMaxMezLev 		int 	outer 88
	/declare intMinMezLev 		int 	outer 25

	/declare intMezRadius		int		outer 200
	/declare intMezRadiusZ		int		outer 30
	
	/declare intMezDuration 	int 	outer 0
	/declare intMezTimeLeft 	int 	outer 0
	/declare intNeedsMez 		int 	outer 0

	/declare intMezLoop 		int 	outer 0
	/declare intMezLoopManual 	int 	outer 0
	/declare intMezLoopManual2 	int 	outer 0

	/declare intCurrentTargetID	int		outer 0
	/declare intLastMobMezedID 	int 	outer 0
	/declare arrMezMobID[11] 	int 	outer 0
	/declare arrMezTime[11] 	int 	outer 0
	/declare arrMezNag[11]		int		outer 0
	/declare strMezLevelNag		string	outer 0
	/declare intMezLevelNag		int		outer 0
	/declare intMezBroke		int		outer 0
	
	/declare intLevel 			int 	outer 0
	/declare intMobCount 		int 	outer 0
	/declare intMobsTotal 		int 	outer 0
	
	| What is a Bard's highest level of Mezzable mob?
	/if (${Me.Class.ID} == 8) {
		/varset intMez 1
		/if (${BRDmez.Equal[""Slumber of the Mindshear""]}) /varset intMaxMezLev 88
		/if (${BRDmez.Equal[""Slumber of the Mindshear Rk.II""]}) /varset intMaxMezLev 88
		/if (${BRDmez.Equal[""Slumber of Sionachie Rk. II""]}) /varset intMaxMezLev 93
		/if (${BRDmez.Equal[""Lullaby of the Forlorn""]}) /varset intMaxMezLev 95
		/if (${BRDmez.Equal[""Lullaby of the Forsaken""]}) /varset intMaxMezLev 100
		/if (${BRDmez.Equal[""Slumber of Motlak""]}) /varset intMaxMezLev 103
		/if (${BRDmez.Equal[""Lullaby of Silisia""]}) /varset intMaxMezLev 105
		/if (${BRDmez.Equal[""Slumber of Silisia""]}) /varset intMaxMezLev 108	
	}
	
	| What is an Enchanter's highest level of Mezzable mob?
	/if (${Me.Class.ID} == 14) {
		/varset intMez 0
		/if (${ENCmez.Equal[""Bewilderment""]}) /varset intMaxMezLev 78
		/if (${ENCmez.Equal[""Mystify""]}) /varset intMaxMezLev 83
		/if (${ENCmez.Equal[""Befuddle""]}) /varset intMaxMezLev 88
		/if (${ENCmez.Equal[""Baffle""]}) /varset intMaxMezLev 93
		/if (${ENCmez.Equal[""Mislead""]}) /varset intMaxMezLev 98
		/if (${ENCmez.Equal[""Confounding Flash""]}) /varset intMaxMezLev 103
		/if (${ENCmez.Equal[""Bewildering Flash""]}) /varset intMaxMezLev 108
	}

	/if (${Me.Class.ID} == 8 || ${Me.Class.ID} == 14) /echo Maximum Mez Level set to ${intMaxMezLev}.

/return

|==================================================================================================|
Sub MezCheck
	/declare  intMezVerbose      int 	local 0

	/if (${intMezVerbose}) /echo MEZ CHECK ACTIVE!
	
	:KeepMezzing
	
	|Set main target:	
	/if (${Me.GroupMarkNPC[1].ID}) {
		/varset intCurrentTargetID ${Me.GroupMarkNPC[1].ID}
	} else {
		/if (!${intLead}) {
			/if (${Target.ID} != ${intCurrentTargetID}) {
				/squelch /target clear
				/assist ${strMyTank}
				/for intDelayLoop 1 to 7
					/delay 1
					/doevents
					/doevents flush
					/if (${Target.ID}) /varset intDelayLoop 7
				/next intDelayLoop
			}
		}
		/varset intCurrentTargetID ${Target.ID}
	}
	
	|Catch up to Main assist if too far away:
	/if (${Spawn[${strMyTank}].Distance} > 150) {
		/echo I'm mezzing too far from the leader - Heading back.
		/varset strFollowTarget ${strMyTank}
		/call Follow
	}

	/if (${Me.XTarget} < 1) /return
		
	|-------------------------
	|-Clear out expired Mezzes:
	/varset intMezLoop 0
	:ExpireMezList
	/varcalc intMezLoop ${intMezLoop} + 1 
		/if (${arrMezMobID[${intMezLoop}]}) {
			/if (${intMezVerbose}) /echo Checking ${arrMezMobID[${intMezLoop}]} in slot ${intMezLoop} 
			/varcalc intMezTimeLeft ${arrMezTime[${intMezLoop}]} - ${Macro.RunTime}
			/if (${intMezTimeLeft} < 7) {
				/varset arrMezMobID[${intMezLoop}] 0
				/if (${intMezVerbose}) /echo ${intMezTimeLeft} seconds left - Clearing entry.
			}
		}
	/if (${intMezVerbose} > 1) /echo slot ${intMezLoop} is clear.
	/doevents
	/if (${intMezLoop} < 10) /goto :ExpireMezList
	
	|----------------------
	|-Use XTarget-based mesmerizing for 4 or less mobs, otherwise go to AE type mezzing:
	/if (${Me.XTarget} <=14 ) {

		|----------------------
		|-Mez All Nearby Mobs on the XTARGETS list:
		/if (${intMezVerbose}) /echo Mezzing by XTARGET!
		/for intMezLoop 1 to ${Me.XTarget}
			/if (${intMezVerbose}) /echo I'm starting intMezLoop, iteration ${intMezLoop}.
			/varset intGroupTargetID ${Me.XTarget[${intMezLoop}].ID}
	
			/call MezCheckThisOne
	
		/next intMezLoop
	
	} else {	
		/echo There are a lot of mobs!  Need AE Mezzing!
	}

	/if (${intMezVerbose}) /echo All nearby mobs handled.  What else do I need to do?

	|Check for death:
	/Call ZoneCheck
	
	|Mezzing handled - re-assist main tank:
	/if (${intMezVerbose}) /echo Switching back to the melee target - ${Spawn[${intCurrentTargetID}].CleanName} (${Spawn[${intCurrentTargetID}].ID}).
	/if (${Me.GroupMarkNPC[1].ID}) {
		/target id ${Me.GroupMarkNPC[1].ID}
	} else {
		/if (${intCurrentTargetID}) /target id ${intCurrentTargetID}
	}
	/if (${Target.ID}) /face fast
	/look 0
	
/return
		
		
|==================================================================================================|
Sub MezCheckThisOne
	/declare  intMezVerbose      int 	local 0
		
		/if (${intMezVerbose}) /echo Considering mob ${Spawn[${intGroupTargetID}].Name} (${intGroupTargetID}).
		/varset intNeedsMez 1 

		|-----------------------------------
		|-Don't Mez any mobs in the mez list:
		/varset intMezLoopManual 0
		:CheckMezList
		/varcalc intMezLoopManual ${intMezLoopManual} + 1 
			/if (${arrMezMobID[${intMezLoopManual}]} && ${intMezVerbose} > 1) /echo intMezLoopManual = ${intMezLoopManual}; Mob ID = ${arrMezMobID[${intMezLoopManual}]}.
			/if (${arrMezMobID[${intMezLoopManual}]} == ${intGroupTargetID}) {
				/varcalc intMezTimeLeft ${arrMezTime[${intMezLoopManual}]} - ${Macro.RunTime}
				/if (${Macro.RunTime} > ${arrMezNag[${intMezLoopManual}]}) {
					/echo ${Spawn[${intGroupTargetID}].Name} (${arrMezMobID[${intMezLoopManual}]}) has ${intMezTimeLeft} seconds left.
					/varcalc arrMezNag[${intMezLoopManual}] ${Macro.RunTime} + 5
				}
				/varset intNeedsMez 0
				/return
			}
		/doevents
		/if (${intMezLoopManual} < 10) /goto :CheckMezList
	
		|-----------------------------------
		|-Don't Mez pets:
		/if (${Spawn[${intGroupTargetID}].Master.ID}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo Pets aren't worth mezzing.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
			/return
		}

		|-----------------------------------
		|-Don't Mez marked target:
		/if (${Spawn[${intGroupTargetID}].ID} == ${Me.GroupMarkNPC[1].ID}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo ${intGroupTargetID} is the main group marked target.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
			/call SingleMez
		}

		|-----------------------------------
		|-Don't Mez main tank's target (if there is no group target):
		/if (!${Me.GroupMarkNPC[1].ID}) {
			/if (${Spawn[${intGroupTargetID}].ID} == ${intCurrentTargetID}) {
				/varset intNeedsMez 0
				/if (${intMezVerbose}) /echo ${intGroupTargetID} is the main tank's target.
				/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
				/call SingleMez
			}
		}

		|-----------------------------------
		|-Don't Mez low level mobs:
		/if (${Spawn[${intGroupTargetID}].Level} < ${intMinMezLev}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo ${intGroupTargetID} is level ${Spawn[${intGroupTargetID}].Level}!  Not worth Mezing.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
			/return
		}

		|-----------------------------------
		|-Don't Mez high level mobs:
		/if (${Spawn[${intGroupTargetID}].Level} > ${intMaxMezLev}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo ${intGroupTargetID} is level ${Spawn[${intGroupTargetID}].Level}!  I can't Mez it.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.

			| Clear nag history:
			/if (${Macro.RunTime} > ${intMezLevelNag}) /varset strMezLevelNag 0
			/if (!${strMezLevelNag.Find[${intGroupTargetID}]}) {
				/g ${Spawn[id ${intGroupTargetID}].CleanName} is too high of level for me to Mez!
				/varset strMezLevelNag ${strMezLevelNag}~${intGroupTargetID}
				/varcalc intMezLevelNag ${Macro.RunTime} + (60 * 2)
				/if (${intMezVerbose}) /echo strMezLevelNag= ${strMezLevelNag}, Clearing at ${intMezLevelNag}
			}
			/return
		}

		|-----------------------------------
		|-Don't Mez mobs that are too far away:
		/if (${Spawn[${intGroupTargetID}].Distance} > ${intMezRadius}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo ${intGroupTargetID} is ${Spawn[${intGroupTargetID}].Distance} feet way!  too far to mez.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
			/return
		}
		
		|-----------------------------------
		|-Don't Mez "SAFE" mobs:
		/if (${Spawn[id ${Target.ID} alert 1].ID}) {
			/varset intNeedsMez 0
			/if (${intMezVerbose}) /echo ${intGroupTargetID} is on the safe mobs list.
			/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
			/return
		}

		| Mez any mob that is still valid:
		/if (${intNeedsMez} > 0) {
			|No attacking while Mezzing!
			/if (${Me.Combat}) /attack

			/target id ${intGroupTargetID}
			/varset intLastMobMezedID ${intGroupTargetID}
			/if (!${Target.LineOfSight}) /face fast
			|/g Mezzing %t.
			/if (${intMezVerbose}) /echo ${Target.ID} is ${Target.Name}.
			
			|==========================
			| Bard MEZ Action Section:
			/if (${Me.Class.ID} == 8) {
				/if (${Macro.RunTime} > ${intNextSongTime}) {
					/echo Mezzing ${Spawn[${intGroupTargetID}].Name} (${intGroupTargetID}).
					/g Mezzing ${Spawn[${intGroupTargetID}].CleanName}.
					/stopsong
					/cast ${BRDmez}
					/varset intNextSongTime ${Math.Calc[${Me.Casting.MyCastTime.Float} + ${Macro.RunTime}]}
					/varcalc intMezDuration ${Spell[${BRDmez}].Duration} * 6
					/delay ${Me.Casting.MyCastTime.Float}s
				}
			}
			
			|==========================
			| Enchanter MEZ Action Section (Uses intNextSongTime to time mezzes):
			/if (${Me.Class.ID} == 14) {
				/if (${Macro.RunTime} > ${intNextSongTime}) {
					/echo Mezzing ${Spawn[${intGroupTargetID}].Name} (${intGroupTargetID}).
					/g Mezzing ${Spawn[${intGroupTargetID}].CleanName}.
					/call cast ${ENCmez}
					/varcalc intNextSongTime ${Me.Casting.MyCastTime.Float} + ${Macro.RunTime}
					/varcalc intMezDuration ${Spell[${ENCmez}].Duration} * 6
					/delay ${Me.Casting.MyCastTime.float}s
				} else {
					/if (${intMezVerbose}) /echo I'm not ready to mez yet.
				}
			}
	
			/doevents
		}
		/if (${intMezVerbose}) /echo Mob handled.  Next!
		
		/delay 1
/return


|==================================================================================================|
Sub SingleMez
	/declare  intMezVerbose      int 	local 0

	/if (${Me.XTarget} != 1) /return
	
	/if (${intMezVerbose}) /echo Single XTarget left.  I'll keep it mezzed if Inspect Buffs 2 tells me to!
	
	| If it's mezzed, let's keep it mezzed:
	/if (${Me.LAInspectBuffs} > 1) {
		/if (${Target.Buff[${BRDmez}].ID}) /varset intNeedsMez 1
		/if (${Target.Buff[${ENCmez}].ID}) /varset intNeedsMez 1
		/if (${Target.Buff[${ENCmezAE}].ID}) /varset intNeedsMez 1
		/if (${Target.Buff[${ENCmezfast}].ID}) /varset intNeedsMez 1
	}
	
	/if (${intNeedsMez}) {
		/if (${intMezVerbose}) /echo ${intGroupTargetID} is the main tank's target, but is getting mezzed anyway.
		/if (${intMezVerbose}) /echo intNeedsMez set to ${intNeedsMez}.
	}

/return


|==================================================================================================|
Sub MezList
	/declare  intMezVerbose      int 	local 0

	/if (${intLastMobMezedID}) /g ${Spawn[${intLastMobMezedID}].CleanName} has been MEZZED.
	/mqlog ${Spawn[${intLastMobMezedID}].CleanName} has been MEZZED.

	|-Place mob in the Mez list:
	/if (${intMezVerbose}) /echo ${intLastMobMezedID} (${Spawn[${intLastMobMezedID}].Name}) Mezed.  Adding it to list...
	
	/varset intMezLoopManual2 0
	:BuildMezList
	/varcalc intMezLoopManual2 ${intMezLoopManual2} + 1 
		/if (${intMezVerbose}) /echo Slot number ${intMezLoopManual2} is ${arrMezMobID[${intMezLoopManual2}]}...
		/if (${arrMezMobID[${intMezLoopManual2}]} == 0 || ${arrMezMobID[${intMezLoopManual2}]} == ${intLastMobMezedID}) {
			/if (${intMezVerbose}) /echo Setting slot ${intMezLoopManual2} as ${intLastMobMezedID}
			/varset arrMezMobID[${intMezLoopManual2}] ${intLastMobMezedID}
			/varcalc arrMezTime[${intMezLoopManual2}] ${Macro.RunTime} + ${intMezDuration}
			/varset intMezLoopManual2 11
		}
	/if (${intMezLoopManual2} < 10) /goto :BuildMezList

/return


|==================================================================================================|
Sub MezBroke(MezSpell, MezTarget)
	/declare  intMezVerbose      int 	local 0

	| Was it really a mez?:
	/if (${intMezVerbose}) /echo Validating ${MezSpell} that wore off of ${MezTarget}...
	/varset intMezBroke 0
	/if (${Ini[iBuffs.ini,Bard,BRDmez].Find[${MezSpell}]}) /varset intMezBroke 1
	/if (${Ini[iBuffs.ini,Enchanter,ENCmez].Find[${MezSpell}]}) /varset intMezBroke 1
	/if (${Ini[iBuffs.ini,Enchanter,ENCmezAE].Find[${MezSpell}]}) /varset intMezBroke 1
	/if (${Ini[iBuffs.ini,Enchanter,ENCmezfast].Find[${MezSpell}]}) /varset intMezBroke 1
	
	|/if (${MezSpell.Equal[Slumber of the Mindshear]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Slumber of the Mindshear Rk.II]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Slumber of Sionachie Rk. II]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Bewilderment]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Mystify]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Befuddle]}) /varset intMezBroke 1
	|/if (${MezSpell.Equal[Baffle]}) /varset intMezBroke 1
	/if (!${intMezBroke}) /return
	
	/echo ${MezTarget} BROKE OUT OF THE MEZ!!!
	/mqlog ${MezTarget} BROKE OUT OF THE MEZ!!!
	/varset intMezLoopManual2 0
	:BuildMezList
	/varcalc intMezLoopManual2 ${intMezLoopManual2} + 1 
		/if (${intMezVerbose}) /echo Slot number ${intMezLoopManual2} is ${Spawn[id ${arrMezMobID[${intMezLoopManual2}]}].CleanName} (${arrMezMobID[${intMezLoopManual2}]})...
		/if (${Spawn[id ${arrMezMobID[${intMezLoopManual2}]}].CleanName.Equal[${MezTarget}]}) {
			/if (${intMezVerbose}) /echo Clearing slot ${intMezLoopManual2}: ${intLastMobMezedID}
			/varset arrMezMobID[${intMezLoopManual2}] 0
		}
	/if (${intMezLoopManual2} < 10) /goto :BuildMezList

/return