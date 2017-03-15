|==================================================================================================|
Sub Clickies

|Look through all of my worn items for Clickies that stack:
/for Looper 0 to 22
	/if (${InvSlot[${Looper}].Item.Spell.ID}) {
		/if (${InvSlot[${Looper}].Item.EffectType.Equal[Click Inventory]}) {
			/if (!${InvSlot[${Looper}].Item.TimerReady}) {
				/if (${InvSlot[${Looper}].Item.Spell.Stacks} && !${Me.Buff[${InvSlot[${Looper}].Item.Spell}].ID}) {
					|/echo ${InvSlot[${Looper}].Name}: ${InvSlot[${Looper}].Item.Spell}

					|Only Allow Clickies from iBuffs.Clickies.Allowable:
					/varset Looper2 0
					:TryNextClickie
					|/delay 1
					/varcalc Looper2 ${Looper2} + 1
					|/echo ${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|]}:
					|/echo -- ${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|].Length}
					|/echo -- ${InvSlot[${Looper}].Item.Spell.Name.Left[${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|].Length}]}
					|/echo -- ${InvSlot[${Looper}].Item.Spell.Name.Left[${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|].Length}].Equal[${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|]}]}
					/if (${InvSlot[${Looper}].Item.Spell.Name.Left[${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|].Length}].Equal[${Ini[iBuffs.ini, Clickies, Allowable].Arg[${Looper2},|]}]}) {
						/echo ${InvSlot[${Looper}].Name}: ${InvSlot[${Looper}].Item.Spell}
						/itemnotify ${Looper} rightmouseup
						/call CastWait
						/varset Looper2 ${Math.Calc[${Ini[iBuffs.ini, Clickies, Allowable].Count[|]} + 1]}
					}
					/if (${Looper2} < ${Math.Calc[${Ini[iBuffs.ini, Clickies, Allowable].Count[|]} + 1]}) /goto :TryNextClickie
					
					:SkipCastClickie
				}
			}
		}
	}
/next Looper

/return


|==================================================================================================|
Sub CastWait

|-------------------------------------------------------

	|Cast Wait:
	/delay 5
	:CastWait
	|/echo Casting!
	/delay 1
	/if (${Me.Casting.ID}) /goto :CastWait
	/delay 1

/return


|==================================================================================================|
Sub ClickiesOld

|-------------------------------------------------------

	|/echo Clickies...

|==================================================================================================
| Mana Buffs

|Aura of Taelosia:
/if (${FindItemCount[=Fingerbone Earring]}) {
	/if (!${Me.Buff[Aura of Taelosia].ID}) {
		/call Cast "Fingerbone Earring" item
		/call CastWait
	}
}

|Maelin's Meditation:
/if (${FindItemCount[=Yerensaal Savannalord Belt]}) {
	/if (!${Me.Buff[Maelin's Meditation].ID}) {
		/call Cast "Yerensaal Savannalord Belt" item
		/call CastWait
	}
}

|Maelin's Methodical Mind:
/if (${FindItemCount[=Golemstone Fragment]}) {
	/if (${Spell[Maelin's Methodical Mind].Stacks} && !${Me.Buff[Maelin's Methodical Mind].ID}) {
		|/echo Using Golemstone Fragment...
		/call Cast "Golemstone Fragment" item
		/call CastWait
	}
}

|Mana Pet:
|/if (${FindItemCount[=Direwolf Totem of Spirit]}) {
|	/if (${Spell[Arcane Wolf Familiar].Stacks}) {
|	|/if (!${Me.Buff[Arcane Wolf Familiar].ID}) {
|		/call Cast "Direwolf Totem of Spirit" item
|		/call CastWait
|	}
|}


|==================================================================================================
| Melee Buffs

|Form of Defense III:
/if (${FindItemCount[=Ring of the Savage Skull]}) {
	/if (!${Me.Buff[Form of Defense III].ID}) {
		/call Cast "Ring of the Savage Skull" item
		/call CastWait
	}
}

|Form of Defense IV:
/if (${FindItemCount[=Astral Ring of Starshine]}) {
	/if (!${Me.Buff[Form of Defense IV].ID}) {
		/call Cast "Astral Ring of Starshine" item
		/call CastWait
	}
}

|Form of Endurance IV:
/if (${FindItemCount[=Arcaapi Ventail]}) {
	/if (!${Me.Buff[Form of Endurance IV].ID}) {
		/call Cast "Arcaapi Ventail" item
		/call CastWait
	}
}

|Savage Guard:
/if (${FindItemCount[=Quickened Platinum Earcowl]}) {
	/if (!${Me.Buff[Savage Guard].ID}) {
		/call Cast "Quickened Platinum Earcowl" item
		/call CastWait
	}
}

|Stoic Wolf Familiar:
/if (${FindItemCount[=Direwolf Totem of Battle]}) {
	/if (${Spell[Stoic Wolf Familiar].Stacks[1]}) {
		/call Cast "Direwolf Totem of Battle" item
		/call CastWait
	}
}

|Taelosian Guard:
/if (${FindItemCount[=Emerald Ring of Blight]}) {
	/if (!${Me.Buff[Taelosian Guard].ID}) {
		/call Cast "Emerald Ring of Blight" item
		/call CastWait
	}
}

|Taelosian Guard:
/if (${FindItemCount[=Thane Ring]}) {
	/if (!${Me.Buff[Taelosian Guard].ID}) {
		/call Cast "Thane Ring" item
		/call CastWait
	}
}

|Toskirakk Signet of the Guard:
/if (${FindItemCount[=Toskirakk Signet of the Guard]}) {
	/if (!${Me.Buff[Form of Defense IV].ID}) {
		/call Cast "Toskirakk Signet of the Guard" item
		/call CastWait
	}
}

|Vengeful Guard:
|/if (${FindItemCount[=Warsmasher Cloak]}) {
|	/if (${Spell[Vengeful Guard].Stacks}) {
|		/call Cast "Warsmasher Cloak" item
|		/call CastWait
|	}
|}

|==================================================================================================
| Illusions Buffs

|Grand Illusion:
/if (${FindItemCount[=Bone Mask of the Ancient Iksar]}) {
	/if (!${Me.Buff[Illusion: Ancient Iksar].ID}) {
		/if (${Zone.ID} == 452 || ${Zone.ID} == 454 || ${Zone.ID} == 455) {
			/call Cast "Bone Mask of the Ancient Iksar" item
			/call CastWait
		}
	}
}

|Spectre:
/if (${FindItemCount[=Efreeti Death Visage]}) {
	/if (!${Me.Buff[Illusion: Spectre].ID}) {
	|/if (${Spell[Illusion: Spectre].Stacks}) {
		/call Cast "Efreeti Death Visage" item
		/call CastWait
	}
}

|==================================================================================================
| Alcohol Tolerance!

|Mead:
/if (${FindItemCount[=Mead]}) {
	/if (${Me.Drunk} <= 5) {
		
		/if (${Me.Skill[alcohol tolerance]} < ${Skill[alcohol tolerance].SkillCap}) {
	
			/echo I'm this drunk: ${Me.Drunk}, and I tolerate ${Me.Skill[alcohol tolerance]} / ${Skill[alcohol tolerance].SkillCap}.
			
			|empty your hands		
			/autoinventory 
			|Old Slot ID: ${FindItem[=Mead].InvSlot.ID}
	
			/if ( ${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack} ) { 
				:open_pack
				|/echo Opening the pack...
				/nomodkey /itemnotify ${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack} rightmouseup 
				/if ( !${Window[${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack.Name}].Open} ) /goto :open_pack 
			} 
			:pick_up_item 
			|/echo Picking up the mead...
			/if ( ${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack} && !!${Window[${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack.Name}].Open} ) {
				/nomodkey /itemnotify ${InvSlot[${FindItem[=Mead].InvSlot.ID}].Pack} rightmouseup 
			}
			/ctrlkey /itemnotify ${InvSlot[${FindItem[=Mead].InvSlot.ID}]} leftmouseup 
			/if ( !${Cursor.Name.Equal[Mead]} ) /goto :pick_up_item 
			:exchange_items 
			/nomodkey /itemnotify 30 leftmouseup 
			/if ( !${Me.Inventory[30].Name.Equal[Mead]} ) /goto :exchange_items 
			
			|Click the mead:
			/nomodkey /itemnotify 30 rightmouseup
			/delay 5
			/nomodkey /itemnotify 30 leftmouseup 
			/delay 5
			/autoinv
			/cleanup
	
			/call CastWait
		}
	}
}

/return

