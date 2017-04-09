|==================================================================================================|
|==================================================================================================|
|
|Wizard Specific inclusions!
|
|==================================================================================================|
|==================================================================================================|
Sub WIZSetSpells

|WIZshield:
	/declare WIZshield string outer
	/call SetTheSpell WIZshield
	/varset WIZshield ${Macro.Return}
|WIZfamiliar:
	/declare WIZfamiliar string outer
	/call SetTheSpell WIZfamiliar
	/varset WIZfamiliar ${Macro.Return}
|WIZarmor:
	/declare WIZarmor string outer
	/call SetTheSpell WIZarmor
	/varset WIZarmor ${Macro.Return}
|WIZrune:
	/declare WIZrune string outer
	/call SetTheSpell WIZrune
	/varset WIZrune ${Macro.Return}
|WIZnuke:
	/declare WIZnuke string outer
	/call SetTheSpell WIZnuke
	/varset WIZnuke ${Macro.Return}
|WIZblast:
	/declare WIZblast string outer
	/call SetTheSpell WIZblast
	/varset WIZblast ${Macro.Return}
|WIZlightning:
	/declare WIZlightning string outer
	/call SetTheSpell WIZlightning
	/varset WIZlightning ${Macro.Return}
|WIZcold:
	/declare WIZcold string outer
	/call SetTheSpell WIZcold
	/varset WIZcold ${Macro.Return}
|WIZconc:
	/declare WIZconc string outer
	/call SetTheSpell WIZconc
	/varset WIZconc ${Macro.Return}
	/declare intWIZconc int outer 0
|WIZharvest:
	/declare WIZharvest string outer
	/call SetTheSpell WIZharvest
	/varset WIZharvest ${Macro.Return}
|WIZAE:
	/declare WIZAE string outer
	/call SetTheSpell WIZAE
	/varset WIZAE ${Macro.Return}
|WIZhorse:
	/declare WIZhorse string outer "Summon Warhorse"
	/declare WIZhorseitem string outer "White Chain Bridle and Barding"

/return

|==================================================================================================|
Sub WIZBuffCheck

|Check Buffs:

|Shield
|--------------------------
	/call BuffHandler ${WIZshield} 1

|Armor
|--------------------------
	/call BuffHandler ${WIZarmor} 3

|Harvest
|--------------------------
	/if (${Me.PctMana}<=25) {
		/call BuffHandler ${WIZharvest} 9
	}

|Rune
|--------------------------
	/call BuffHandler ${WIZrune} 2

|Familiar
|--------------------------
	|Remove Specialized Familiars:
	/if (${Me.AltAbilityReady[${WIZfamiliar}]}) {
		/if (${Me.Buff[Druzzil's Mystical Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Druzzil's Mystical Familiar].ID}-1]}]} leftmouseup
		/if (${Me.Buff[E'ci's Icy Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[E'ci's Icy Familiar].ID}-1]}]} leftmouseup
		/if (${Me.Buff[Ro's Flaming Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Ro's Flaming Familiar].ID}-1]}]} leftmouseup
	}

	|Pick Spell or AA Familiar:
	/if (${Spell[${WIZfamiliar}].Stacks[2]}) {
		/if (${Me.SpellReady[${WIZfamiliar}]} || ${Me.AltAbilityReady[${WIZfamiliar}]}) {
			/if (${AltAbility[${WIZfamiliar}]} > 0) {
				/call Cast ${WIZfamiliar} alt
			} else {
				/if (${Spell[${WIZfamiliar}].Mana} < ${Me.CurrentMana}) {
					/target myself
					/call Cast ${WIZfamiliar} gem2 0
					/target clear
				}
			}
		}
	}

|Horse
|--------------------------
	/if ((${Spell[${WIZhorse}].Stacks[2]}) && (${intFollow} < 1) && (${boolOutdoors})) {
		/if (${FindItemCount[${WIZhorseitem}]}) {
			/target myself
			/call Cast ${WIZhorseitem} item
			/delay 1s
			/target clear
		}	
	}

/return

|==================================================================================================|
|Fight Full
|==================================================================================================|
Sub WIZFightFull
	/if (${Target.PctHPs} <= 99) /call WIZFightAlways
	/if (${Target.PctHPs} >= ${intDDMin} && ${Target.PctHPs} <= ${intDDMax}) /call WIZFightMiddle
	/if (${Target.PctHPs} <= 25) /call WIZFightEnd
/return

|==================================================================================================|
Sub WIZFightAlways

/return

|==================================================================================================|
Sub WIZFightMiddle

|Avoid double-concussion effect:
/if (${Me.Song["Concussive Flames"].ID} || ${Me.Song["Concussive Flame"].ID} || ${Me.Song["Concussive Magic"].ID} || ${Me.Song["Concussive Chill"].ID})  /varcalc intWIZconc ${intWIZconc} + 1
	
|Don't try to concussion if you don't have it:
/if (!${Me.Book[${WIZconc}]}) /varset intWIZconc 1

/if (${intWIZconc} < 1) {
	|Concussion!
	/call Cast ${WIZconc} gem4 0
	/varcalc intWIZconc ${intWIZconc} + 1
	
	|Pause for delay
	/for intDelayLoop 1 to ${Math.Calc[${intBurnTime}*1.0]}
		/delay 1
		/doevents
	/next intDelayLoop
	
} else {
	|Avoid regular Nuking when AE is engaged:
	|/echo Checking for AE instead of single damage...
	/if (${SpawnCount[npc zradius 50 radius ${Spell[${WIZAE}].AERange}]} < 2 || !${intAE}) {
		|/echo Not AE - Nuking singles engaged...

		|Nuke - While taking into account any Concussive effects:
		/if (${Me.Song["Concussive Flame"].ID} || ${Me.Song["Concussive Flames"].ID}) {
			/call WIZFightPyromancy
		} else {
			/if (${Me.Song["Concussive Magic"].ID}) {
				/call WIZFightArcomancy
			} else {
				/if (${Me.Song["Concussive Chill"].ID}) {
					/call WIZFightCryomancy
				} else {
					|Regular Wizzy Nukes (No concussion effects):
					
					|Pyromancy:
					/if (!${Me.Buff[Pyromancy].ID}) {
						/if (${Me.Buff[Cryomancy].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Cryomancy].ID}-1]}]} leftmouseup
						/if (${Me.Buff[Arcomancy ].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Arcomancy ].ID}-1]}]} leftmouseup
						
						/call Cast "Pyromancy" alt
						/delay 2
					}

					|/echo Regular Wiz Nuke...
					/call Cast ${WIZnuke} gem7 0
					/varset intWIZconc 0
				}
			}
		}
	}
}

/return

|==================================================================================================|
Sub WIZFightPyromancy
	|/g Major safe Wizzy fire incoming!
	
	|=====================================================================================
	|Pyromancy:
	/if (!${Me.Buff[Pyromancy].ID}) {
		/if (${Me.Buff[Cryomancy].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Cryomancy].ID}-1]}]} leftmouseup
		/if (${Me.Buff[Arcomancy ].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Arcomancy ].ID}-1]}]} leftmouseup
		
		/call Cast "Pyromancy" alt
		/delay 2
	}
	|/if (!${Me.Buff[Pyromancy].ID}) /g Pyromantic not good.
	
	|Ro's Familiar:
	/if (!${Me.Buff[Ro's Flaming Familiar].ID}) {
		/if (${Me.AltAbilityReady[Ro's Flaming Familiar]}) {
			/if (${Me.Buff[Druzzil's Mystical Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Druzzil's Mystical Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[E'ci's Icy Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[E'ci's Icy Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[${WIZfamiliar}].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[${WIZfamiliar}].ID}-1]}]} leftmouseup
			
			/call Cast "Ro's Flaming Familiar" alt
		}
	}
	
	|Fury of Ro:
	/if (!${Me.Buff[Fury of Ro].ID}) {
		/if (${Me.AltAbilityReady[Fury of Ro]}) {
			/if (${Me.Buff[Fury of Druzzil].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of Druzzil].ID}-1]}]} leftmouseup
			/if (${Me.Buff[Fury of E'ci].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of E'ci].ID}-1]}]} leftmouseup
	
			/call Cast "Fury of Ro" alt
		}
	}
	
	|Cast Fire Spell:
	/call Cast ${WIZblast} gem6 0
/return
|==================================================================================================|
Sub WIZFightArcomancy
	|/g Major safe Wizzy magic incoming!

	|====================================================================================
	|Arcomancy:
	/if (!${Me.Buff[Arcomancy ].ID}) {
		/if (${Me.Buff[Cryomancy].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Cryomancy].ID}-1]}]} leftmouseup
		/if (${Me.Buff[Pyromancy].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Pyromancy].ID}-1]}]} leftmouseup
		
		/call Cast "Arcomancy" alt
		/delay 2
	}
	|/if (!${Me.Buff[Arcomancy ].ID}) /g Arcomantic not good.

	|Druzzil's Familiar:
	/if (!${Me.Buff[Druzzil's Mystical Familiar].ID}) {
		/if (${Me.AltAbilityReady[Druzzil's Mystical Familiar]}) {
			/if (${Me.Buff[E'ci's Icy Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[E'ci's Icy Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[Ro's Flaming Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Ro's Flaming Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[${WIZfamiliar}].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[${WIZfamiliar}].ID}-1]}]} leftmouseup
			
			/call Cast "Druzzil's Mystical Familiar" alt
		}
	}

	|Fury of Druzzil:
	/if (!${Me.Buff[Fury of Druzzil].ID}) {
		/if (${Me.AltAbilityReady[Fury of Ro]}) {
			/if (${Me.Buff[Fury of Ro].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of Ro].ID}-1]}]} leftmouseup
			/if (${Me.Buff[Fury of E'ci].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of E'ci].ID}-1]}]} leftmouseup

			/call Cast "Fury of Druzzil" alt
		}
	}

	|Cast Magic Spell:
	/call Cast ${WIZlightning} gem8 0
	|/g Lightning bang.
/return
|==================================================================================================|
Sub WIZFightCryomancy
	|/g Major safe Wizzy cold incoming!

	|=============================================================================================
	|Cryomancy:
	/if (!${Me.Buff[Cryomancy].ID}) {
		/if (${Me.Buff[Pyromancy].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Pyromancy].ID}-1]}]} leftmouseup
		/if (${Me.Buff[Arcomancy ].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Arcomancy ].ID}-1]}]} leftmouseup
		
		/call Cast "Cryomancy" alt
		/delay 2
	}
	|/if (!${Me.Buff[Cryomancy].ID}) /g Cryomantic not good.

	|E'ci's Familiar:
	/if (!${Me.Buff[E'ci's Icy Familiar].ID}) {
		/if (${Me.AltAbilityReady[E'ci's Icy Familiar]}) {
			/if (${Me.Buff[Druzzil's Mystical Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Druzzil's Mystical Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[Ro's Flaming Familiar].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Ro's Flaming Familiar].ID}-1]}]} leftmouseup
			/if (${Me.Buff[${WIZfamiliar}].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[${WIZfamiliar}].ID}-1]}]} leftmouseup
			
			/call Cast "E'ci's Icy Familiar" alt
		}
	}

	|Fury of E'ci:
	/if (!${Me.Buff[Fury of E'ci].ID}) {
		/if (${Me.AltAbilityReady[Fury of Ro]}) {
			/if (${Me.Buff[Fury of Ro].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of Ro].ID}-1]}]} leftmouseup
			/if (${Me.Buff[Fury of Druzzil].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Fury of Druzzil].ID}-1]}]} leftmouseup

			/call Cast "Fury of E'ci" alt
		}
	}

	|Cast Cold Spell:
	/call Cast ${WIZcold} gem5 0
/return
|==================================================================================================|
Sub WIZFightEnd

/return
