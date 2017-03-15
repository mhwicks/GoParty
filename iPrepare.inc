|==================================================================================================|
Sub Prepare
|Prepare:

/Echo Preparing to go.

/if ((${Spell[${eleform}].Stacks[2]}) && (!${Me.Buff[Summon Horse].ID})) {
	/if (${Me.AltAbilityReady[Elemental Form: Water]}) {
		/call Cast "62" alt
	   	/squelch /target clear
	}
}

:MedLoop
|/MemSpellSet Prepare
/if (!${Me.Gem[${MAGpet}]}) {
	/memspell 1 ${MAGpet}
	/Delay 5s
}

/if (!${Me.Gem[${MAGarmaments}]}) {
	/memspell 3 ${MAGarmaments}
	/Delay 5s
}

/if  (${Me.CurrentMana} <= ${Spell[${MAGpet}].Mana}) {
	/Echo Mana too low, can't prepare pet yet.
	/if (!${Me.Sitting}) /sit on
	/doevents
	/delay 6s
	/goto :MedLoop
}

/Target myself

/if (${Me.SpellReady[${MAGpet}]}) {
	/call Cast ${MAGpet} gem1 0
} else {
	/delay 5s
	/goto :MedLoop
}

|Did the pet fail?
/delay 1s ${Me.Pet.ID}
/if (!${Me.Pet.ID}) /goto :MedLoop

|Elemental Armaments Section - Weapon up the pet:

:EmptyMyHands
/if (${Cursor.ID}) /AutoInventory
/if (${Cursor.ID}) /goto :EmptyHands


|Clear out acceptable pack8 items first:
/if (${Me.Inventory[pack8].ID} == 17306 || ${Me.Inventory[pack8].ID} == 17310 || ${Me.Inventory[pack8].ID} == 57261) {
	/nomod /itemnotify pack8 leftmouseup
	/destroy
}

|Only do pet toys if pack8 is empty:
/if (!${Me.Inventory[pack8](bool)}) {
	/echo Pack8 is empty, let's get pet toys!
	|/Call Cast "Summon Prime Armaments" gem6 0
	/call Cast ${MAGarmaments} gem3 0
	/echo Casted the armaments spell.
	/Delay 5s ${Cursor.ID}
	/nomod /itemnotify pack8 leftmouseup
	
	/Target ${Me.Pet}
	/Delay 1s ${Target.ID}
	
	|Open the pack (Or cast for new ones):
	/nomod /itemnotify pack8 rightmouseup
	/delay 1s ${Me.Casting.ID}
	/if (${Me.Casting.ID}) {
		|Stash new bag and open it:
		/delay 5s !${Me.Casting.ID}
		/delay 1s ${Cursor.ID}
		/nomod /itemnotify pack8 leftmouseup
		/delay 1s !${Cursor.ID}
		/nomod /itemnotify pack8 rightmouseup
		/delay 1s
	}

	|Get a weapon and hand it - twice for good measure:
	/nomod /itemnotify in pack8 1 leftmouseup
	/Delay 1s ${Cursor.ID}
	/Click Left Target
	/Delay 1s !${Cursor.ID}
	/Click Left Target
	/Delay 1s !${Cursor.ID}
	
	|Get a weapon and hand it - twice for good measure:
	/nomod /itemnotify in pack8 2 leftmouseup
	/Delay 1s ${Cursor.ID}
	/Click Left Target
	/Delay 1s !${Cursor.ID}
	/Notify GiveWnd GVW_Give_Button leftmouseup
	/Delay 1s !${Cursor.ID}
}

|Clear Target:
/delay 1s

/Target Clear
/KeyPress esc
/KeyPress esc
/cleanup

/Return
