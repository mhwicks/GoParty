
|==================================================================================================|
Sub DeclareHeal
	
	/declare intJustHealed 			int 	outer 	0
	/declare intCastHeal 			int 	outer 	0
	/declare intHealLoop 			int 	outer 	0
	/declare intRealMobID 			int 	outer 	0
	/declare intHealTargetID 		int 	outer 	0
	/declare intNeedCure 			int 	outer 	0
	/declare intKeyinGroup 			int 	outer 	0
	
	/declare QuickHeal 				string 	outer
	/declare intEmergencyHeal		int 	outer 	69
	
	/declare intHealthHeal 			int 	outer 	75
	/declare intHealthHealPet 		int 	outer 	90
	/declare intLightHeal			int		outer	85
	
	/declare intHealPullerNag		int		outer	0
	
	|For healing low levels:
	/declare intFriendlyHeals 		int 	outer 	1
	/declare intFriendlyHealLevel 	int 	outer 	70
	/declare intFriendlyHealID 		int 	outer 	0

	|For Heals over time (HOT):
	/declare intHot					int		outer	0
	/declare HOTHeal				string	outer
	/declare HOTTimer				int		outer	0
	
	|Transfer other class heals to QuickHeal:
	/if (${Me.Class.ID} == 2) /varset QuickHeal ${CLRquick}
	/if (${Me.Class.ID} == 4) /varset QuickHeal ${RNGheal}
	/if (${Me.Class.ID} == 6) /varset QuickHeal ${DRUheal}
	/if (${Me.Class.ID} == 10) /varset QuickHeal ${SHMheal}
	/if (${Spell[${QuickHeal}].ID}) /echo QuickHeal set to ${QuickHeal}.
	
	|Transfer heal spells to HOTheal:
	/if (${Me.Class.ID} == 2) /varset HOTHeal ${CLRhot}
	/if (${Spell[${HOTHeal}].ID}) /echo HOTHeal set to ${HOTHeal}.

/return

|==================================================================================================|
Sub QuickHealSub

	|/echo QuickHealSub Activated.
	
	/declare	intLocalDebug		int		local	0
	
	|/if (${intLocalDebug}) /echo Quick Heal Subroutine!
	
	|Clerics:
	/if (${Me.Class.ID} == 2) {
		/varset intHealthHeal 85
		/varset intHealthHealPet 85
		/if (${intMelee}) /varset intHealthHealPet 60
	}
	|Ranger
	/if (${Me.Class.ID} == 4) {
		/varset intHealthHeal 40
		/varset intHealthHealPet 40
	}
	|Shaman
	/if (${Me.Class.ID} == 10) {
		/varset intHealthHeal 80
		/varset intHealthHealPet 80
	}
	|Druid
	/if (${Me.Class.ID} == 6) {
		/varset intHealthHeal 70
		/varset intHealthHealPet 70
	}
	
	|Check for Quick Heals:
	|--------------------------
	/varset intRealMobID ${Target.ID}
	/if (${Target.Type.Equal[PC]}) /varset intRealMobID 0
	|/echo Setting REAL MOB ID to ${intRealMobID}!

	/varset intJustHealed 0
	
	|Check area for friendly heal targets:
	/if (${intFriendlyHeals} && !${Target.ID}) {
		|Loop through all players level 1 through ${intFriendlyHealLevel} within 200 feet:
		
		/if (${SpawnCount[pc range 1 ${intFriendlyHealLevel} radius 200]} > 0) {
			/if (${intLocalDebug}) /echo Checking heals for ${SpawnCount[pc range 1 ${intFriendlyHealLevel} radius 200]} nearby players.
			/for intHealLoop 1 to ${SpawnCount[pc range 1 ${intFriendlyHealLevel} radius 200]}
				/varset intFriendlyHealID ${NearestSpawn[${intHealLoop}, pc range 1 ${intFriendlyHealLevel} radius 200].ID}
				
				|Only go through this brain damage if they are not in your group:
				/if (${intLocalDebug}) /echo Checking on ${Spawn[${intFriendlyHealID}].CleanName}...
				/if (!${Me.GroupList.Find[${Spawn[${intFriendlyHealID}].CleanName}]}) {
					/if (${intLocalDebug}) /echo ${Spawn[${intFriendlyHealID}].CleanName} is not in my group!
				
					|Pets:
					/if (${Spawn[${intFriendlyHealID}].Pet.ID}) {
						/target id ${Spawn[${intFriendlyHealID}].Pet.ID}
						|/echo Checking ${Target.CleanName} who is at ${Target.PctHPs}
						/delay 1
						/if (${Target.PctHPs} < ${intHealthHealPet} && ${Target.PctHPs} > 1) {
							/echo HEALING ${Target.CleanName} who is at ${Target.PctHPs}
							/varset intHealTargetID ${Target.ID}
							/varset intCastHeal 1
						}
					}
					|Players:
					/if (${Spawn[${intFriendlyHealID}].ID}) {
						/target id ${Spawn[${intFriendlyHealID}].ID}
						|/echo Checking ${Target.CleanName} who is at ${Target.PctHPs}
						/delay 1
						/if (${Target.PctHPs} < ${intHealthHeal} && ${Target.PctHPs} > 1) {
							/echo HEALING ${Target.CleanName} who is at ${Target.PctHPs}
							/varset intHealTargetID ${Target.ID}
							/varset intCastHeal 1
						}
					}
				}
			/next intHealLoop
			/squelch /target clear
		}
	}
	
	|Loop through the group:
	/for intHealLoop 0 to ${Group.Members} 

		|Pets:
    	/if (${Group.Member[${intHealLoop}].ID} && ${Group.Member[${intHealLoop}].Pet.ID}) {
    		|/echo Checking health of ${Group.Member[${intHealLoop}].Pet.Name}
      		/if (${Group.Member[${intHealLoop}].Pet.PctHPs} < ${intHealthHealPet} && ${Group.Member[${intHealLoop}].Pet.PctHPs} > 1) {
      			/if (${Group.Member[${intHealLoop}].Pet.Distance} <= ${Spell[${QuickHeal}].MyRange}) {
					/varset intHealTargetID ${Group.Member[${intHealLoop}].Pet.ID}
					/varset intCastHeal 1
				}
      		}
      	}
      	
      	|Players:
      	/if (${Group.Member[${intHealLoop}].ID}) {
      		|/echo ${Group.Member[${intHealLoop}].CleanName} is at ${Group.Member[${intHealLoop}].PctHPs}.
      		/if (${Group.Member[${intHealLoop}].ID} == ${Spawn[pc ${strMyTank}].ID}) /varset intKeyinGroup 1
      		/if ((!${Group.Member[${intHealLoop}].Type.Equal[Corpse]}) && (${Group.Member[${intHealLoop}].PctHPs} < ${intHealthHeal})) {
      			/if (${Group.Member[${intHealLoop}].Distance} <= ${Spell[${QuickHeal}].MyRange}) {
					/varset intHealTargetID ${Group.Member[${intHealLoop}].ID}
      				/varset intCastHeal 1
					/if (${Group.Member[${intHealLoop}].PctHPs} < ${intEmergencyHeal}) {
						/varset intCastHeal 2
						|If the player needing a type 2 heal is a Warrior (1), Cleric(2) or Monk (7) drop out and heal them! This overrides strMyTank!
						/if (${Spawn[id ${intHealTargetID}].Class.ID} == 1) /varset intHealLoop 9
						/if (${Spawn[id ${intHealTargetID}].Class.ID} == 2) /varset intHealLoop 9
						/if (${Spawn[id ${intHealTargetID}].Class.ID} == 7) /varset intHealLoop 9
					}
      			}
      		}
      	}
      	
	    /if (${intCastHeal} && ${intHealTargetID} == ${Spawn[pc ${strMyTank}].ID}) {
	    	|The player marked as 'key' needs a heal.  Let's take care of that before checking anyone else:
	    	|/echo MY Leader needs a heal!
	    	/varset intHealLoop 9
	    }
	    
	/next intHealLoop

	|Is the healer also the tank?
	/if (${strMyTank.Equal[${Me.CleanName}]}) {
		|/echo Checking myself for heals...
		/varset intKeyinGroup 1
  		/if (${Me.PctHPs} < ${intHealthHeal}) {
  			|/echo I need to heal myself!
			/varset intHealTargetID ${Me.ID}
				/varset intCastHeal 1
			|/echo ${intHealTargetID} Needs a heal...
			/if (${Me.PctHPs} < ${intEmergencyHeal}) {
				|/echo I need to emergency heal myself!
				/varset intCastHeal 2
			}
		}			
	}
	
	|If nobody needs a heal, the nag can reset:
	/if (!${intCastHeal} && ${intHealPullerNag}) {
		/varset intHealPullerNag 0
	}

	|Cancel heals for pullers out of range:
	/if (${intCastHeal}) {
		/if (${Spawn[id ${intHealTargetID}].Name.Equal[${Group.Puller}]}) {
			|/echo Puller needs a heal...
			/if (${Spawn[id ${intHealTargetID}].Distance} > 75) {
				|Puller is out of range:
				/varset intCastHeal 0
				/if (!${intHealPullerNag}) {
					/echo Puller is too far for a safe heal!
					/g ${Spawn[id ${intHealTargetID}].Name} - the puller - is too far for a safe heal!
					/mqlog Warned ${Group.Member[${intHealLoop}].CleanName} that they are too far from me.
					/varset intHealPullerNag 1
				}
			} else {
				|Puller is in range:
				/if (${intHealPullerNag}) {
					/echo Puller is back in heal range.
					/g ${Spawn[id ${intHealTargetID}].Name} is back in heal range.
				}
				/varset intHealPullerNag 0
			}
		}
	}

	|--------------------------------------------
	|Now we know who needs a heal, and what type!
	
    |Show the healing details:
	|--------------------------
	/if (${intCastHeal}) {
		|Only yap if spell casting is ready (Based on fast heal):
		/if (${Me.SpellReady[11]}) {
			/echo ${Spawn[id ${intHealTargetID}].Name} needs a type ${intCastHeal} heal (${Spawn[id ${intHealTargetID}].PctHPs}%).
		}
	}
			
	|Clerics only:
	/if (${Me.Class.ID} == 2) {
	
		|Check Designated Key:
	  	/if (!${intKeyinGroup}) {
	  		|/echo Checking the key...
	  		/if (!${Target.Type.Equal[PC]}) {
	
	  			/if (${SpawnCount[pc ${strMyTank}]}) {
					/target id ${Spawn[pc ${strMyTank}].ID}
					|/echo Targeting tank.
					/for Looper 1 to 10
						/doevents
						/if (${Target.ID}) /varset Looper 10
						/delay 1
					/next Looper
					|/echo ${Target.CleanName} has ${Target.PctHPs}% health.
	
					/if (${Target.PctHPs} < ${intHealthHeal} && ${Target.PctHPs} > 1) {
		      			/if (${Group.Member[${intHealLoop}].Distance} <= ${Spell[${QuickHeal}].MyRange}) {
							|/echo ${Target.CleanName} heal activated!
							/varset intHealTargetID ${Target.ID}
		      				/varset intCastHeal 1
		      				/if (${Target.PctHPs} < ${intEmergencyHeal}) {
		      					/varset intCastHeal 2
		      				}
		      			}
		      		} else {
	      				/squelch /target clear
	      			}
	      		}
	      	}
	    }
	    
		|Check for Cleric's Promise:
		|--------------------------
		/if (${intCastHeal} == 1) {
			/if (${Target.Level} > 60) {
				/if (${Me.Class.ID} == 2) {
					/if (${Me.SpellReady[${CLRpromise}]}) {
						/call Promise
					}
					|Check for Promised Heal on target:
					/for Looper 1 to 2
						/if (${Spawn[${intHealTargetID}].CleanName.Equal[${strPRTarget[${Looper}]}]}) {
							/echo ${strPRTarget[${Looper}]} - has PR and may need another heal.
							/if (${Spawn[${intHealTargetID}].PctHPs} > ${intHealthHeal}) /varset intCastHeal 0
						}
					/next Looper
				}
			}
		}
	}
		
	|Cancel heal if not enough mana:
	/if (${intCastHeal}) {
		/if (${Spell[${QuickHeal}].Mana} > ${Me.CurrentMana}) {
			/echo ${QuickHeal} requires ${Spell[${QuickHeal}].Mana} mana, but I'm at ${Me.CurrentMana}.
			/varset intCastHeal 0
		}
	}
	
	/if (${intCastHeal}) {
		|/echo Heal required, targeting #${intHealTargetID}.
		/target id ${intHealTargetID}
		|/echo Got ${Target.Name}, healing.
		/if (${intCastHeal} > 1) {
		
			|---------------------------------------------------------------------------------------------
			|Cleric Emergency Heal Section:
			/if (${Me.Class.ID} == 2) {
				/if (${intLocalDebug}) /echo EMERGENCY HEAL SECTION!
				|Twelfth Night type spells:
				/if (${Target.PctHPs} < 45) {
					/if (${Me.SpellReady[${CLRLastHope}]}) {
						/g EMERGENCY: ${CLRLastHope} for ${Target.CleanName}!!!
						/call Cast ${CLRLastHope} gem3
						/varset intCastHeal 0
					}
				}

				/if (${intCastHeal}) {
					/if (${Me.AltAbilityReady[Burst of Life]}) {
						/call EmergencyHeals "Burst of Life" |Instant Heal
						/varset intCastHeal 0
					}
					/if (${intCastHeal} > 1) {
						/if (${Me.AltAbilityReady[Focused Celestial Regeneration]}) {
							/call EmergencyHeals "Focused Celestial Regeneration" |Big HOT
							/varset intCastHeal 0
						}
					}
				}

				/if (${Target.PctHPs} < 30) {
					/if (${intLocalDebug}) /echo !!!${Target.CleanName} at ${Target.PctHPs}!!!
					/if (${intCastHeal} > 1) {
						|Group level out HP
						/if (${intLocalDebug}) /echo DIVINE ARBITRATION
						/call EmergencyHeals "Divine Arbitration"
						/if (${intCastHeal} == 1) /call Cast "Celestial Regeneration" alt
					}
				}
				
				|Keep the Mages alive!
				/if (${Target.Class.ID} == 13) {
					/if (${Target.PctHPs} < 30) {
						/if (${intCastHeal} > 1) /call EmergencyHeals "Cascading Divine Aura" |DA with a heal
						/if (${intCastHeal} > 1) /call EmergencyHeals "Bestow Divine Aura Beza" |Your target becomes invulnerable
					}
					/if (${intCastHeal} > 1) /call EmergencyHeals "Blessing of Sanctuary" |Mobs will choose other targets over this one
					|/if (${intCastHeal} > 1) /call EmergencyHeals "Improved Sanctuary" |Faster Sanctuary Spell
					/if (${intCastHeal} > 1) /call EmergencyHeals "Sanctuary" |The original
				}
			}
		}
		
		|Clerics may be able to use a "Light" style heal:
		/if (${Me.Class.ID} == 2) {
			/if (${intCastHeal}) {
				/if (${intLocalDebug}) /echo This Cleric is using "Light" heals.
				/if ((${Target.PctHPs} > ${intEmergencyHeal}) && (${Target.PctHPs} < ${intLightHeal})) {
					/if (${intLocalDebug}) /echo Light opportunity detected, Light heal!
					/if (${Me.SpellReady[${CLRlight}]}) {
		   				/call Cast ${CLRlight} gem12
		  				/mqlog LIGHT HEALING ${Target.Name} WITH ${CLRlight}.
				   		/varset intCastHeal 0
					}
				}
			}
		}
		
		/if (${intCastHeal}) {
			|Regular Quick Heals here:
			/if (${Me.SpellReady[${QuickHeal}]}) {
   				/call Cast ${QuickHeal} gem5
  				/mqlog HEALING ${Target.Name} WITH ${QuickHeal}.
  				/varset intCastHeal 0
  			}
   		}
	
		|Move on with our lives:
		/varset intJustHealed 1
		/varset intCastHeal 0
		/squelch /target clear
		
	}

	/if (!${Target.ID} && ${intRealMobID} > 0) {
		/target id ${intRealMobID}
		/for Looper 1 to 10
			/doevents
			/if (${Target.ID}) /varset Looper 10
			/delay 1
		/next Looper
	}
	
	|--------------------------
	|Cleric CURE
	/if (${Me.Class.ID} == 2) {						
		/varset intNeedCure 0
		/if (${Me.Buff[Wind of Tashanian].ID}) /varset intNeedCure 1
		/if (${Me.Buff[Silvered Tongue].ID}) /varset intNeedCure 1
		/if (${Me.Buff[Packmaster's Curse].ID}) /varset intNeedCure 1
		/if (${Me.Buff[Torment of Body].ID}) /varset intNeedCure 1
		/if (${Me.Buff[Touch of Anguish].ID}) /varset intNeedCure 1
		/if (${Me.Buff[Malis].ID}) /varset intNeedCure 1
		
		|No cures while attacking:
		/if (${Me.Combat}) /varset intNeedCure 0
		
		/if (${intNeedCure}) {
			/varset intRealMobID ${Target.ID}

			/target myself
			/if (${Me.AltAbilityReady[${CLRradiant}]}) {
				|/g Incoming Radiant Cure.
				/call Cast ${CLRradiant} alt
				/delay 1
				/for intDelayLoop 1 to ${Math.Calc[${Spell[${CLRradiant}].MyCastTime.Float} * 10]}
					/delay 1
					/doevents
				/next intDelayLoop
				/delay 1
			} else {
				|/g A RADIANT CURE IS NEEDED BUT NOT AVAILABLE!!!  Trying alternate cure spell.
				/if (${Spell[${CLRcure}].Mana} < ${Me.CurrentMana}) {
			    	/call Cast ${CLRcure} gem10
			    }
			}
			/squelch /target clear
			/if (${intRealMobID} > 0) {
				/target id ${intRealMobID}
				/for Looper 1 to 10
					/doevents
					/if (${Target.ID}) /varset Looper 10
					/delay 1
				/next Looper
			}
		}
	}	

/return

|==================================================================================================|
Sub HOTSub

	/if (${intHOT}) {
		/echo HOTSub Activated.
		/if (${Target.PctHPs} > 90) {
			/echo Target is close to full health.
			/if (${Target.Type.Equal[Named]} || ${Target.Level} >= ${Me.Level}) {
				/echo Target is named or is higher level than me.
				/if (${HOTTimer} < ${Macro.RunTime}) {
					/echo Target probably does not have a HOT on them.
					/target id ${Spawn[pc ${strMyTank}].ID}
					/g ${Target.CleanName} needs a HOT for this one.
					/call Cast ${HOTHeal} gem8
					/varcalc HOTTimer ${Macro.RunTime} + ${Math.Calc[${Spell[${HOTHeal}].Duration} * 6]}
				}
			}
		}
	}
	
/return


|==================================================================================================|
Sub EmergencyHeals

	/varset strCurrentSpell "${Param0}"
	/if (${Me.AltAbility[${strCurrentSpell}]}) {
		/if (${Me.AltAbilityReady[${strCurrentSpell}]}) {
   			/if (${Group.Member[${intHealLoop}].Distance} <= ${Spell[${strCurrentSpell}].MyRange}) {
				/g EMERGENCY: ${strCurrentSpell} for ${Target.CleanName}!!!
				/call Cast ${strCurrentSpell} alt
				/varset intCastHeal 1
	
				|Log Heals:	   		
	   			/mqlog EMERGENCY AA SAVE for ${Target.Name} WITH ${strCurrentSpell}.
			} else {
				/g Hey ${Target.CleanName}!  You are out of range for ${strCurrentSpell} (${Spell[${strCurrentSpell}].MyRange})!
			}	
		} else {
			/echo ${strCurrentSpell} is not quite ready.
		}
	} else {
		/echo I don't have ${strCurrentSpell} yet.
	}
	
/return

