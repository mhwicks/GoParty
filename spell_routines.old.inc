| spell_routines.inc 
| 
| Written by Rusty~ 
| Last Modified 6/19/2004 
| 
| Features: 
| - Casts spells, clicks items, or uses AA abilities for you 
| - Allows back to back casting without waiting on spell gems to pop all the way up 
| - Will interrupt spell if target dies while casting. If on a mount, it will dismount and duck if the time left 
|   is greater than 3 seconds, else it will strafe to interrupt 
| - Allows you to use items in bags. Equips item, clicks it, then returns it to its previous location 
| - Lets you set how long you want to keep trying to cast the spell (defaults to 0) 
|   If the spell is interrupted before the given time, it will recast, else it will return CAST_INTERRUPTED 
| - Lets you call a custom subroutine while waiting for spell to finish casting 
|   Try to keep custom subroutines very small. A common use would be to interrupt the spell if a certain condition is true 
| - Note: if you don't want this to cast spells while you're invis, in your main macro have this at the top: 
|      /declare noInvis int outer 1 
|   This will wait till invis is off to cast the spell 
| 
| Usage: 
|     /call Cast "spellname|itemname|AAname|AA#" [item|alt|gem#] [give up time][s|m] [custom subroutine name] 
| 
| examples: 
| 
|  To cast Howl of Tashan and mem it in slot 3 if not memmed: 
|    /call Cast "Howl of Tashan" gem3 
| 
|  To cast Arcane Rune and keep trying for 7 seconds, in case of interrupts. 
|    /call Cast "Arcane Rune" gem5 7s 
| 
|  To click Grim Aura earring that's in a bag: 
|    /call Cast "Shrunken Goblin Skull Earring" item 
| 
|  To use AA ability Eldritch Rune: 
|    /call Cast "Eldritch Rune" alt 
|      or 
|    /call Cast "173" alt 
| 
|  To call a subroutine that interrupts CH if target gets healed before it lands: 
|    /call Cast "Complete Healing" gem1 0 CheckHP 
|  Then in your macro have somewhere: 
|    Sub CheckHP 
|       /if ( ${Target.PctHPs}>=80 ) /call Interrupt 
|    /return 
| 
| Returns these values: 
|----------------------+----------------------------------------------------------------------+ 
| CAST_CANCELLED       | Spell was cancelled by ducking (either manually or because mob died) | 
| CAST_CANNOTSEE       | You can't see your target                                            | 
| CAST_IMMUNE          | Target is immune to this spell                                       | 
| CAST_INTERRUPTED     | Casting was interrupted and exceeded the given time limit            | 
| CAST_NOTARGET        | You don't have a target selected for this spell                      | 
| CAST_NOTMEMMED       | Spell is not memmed and you gem to mem was not specified             | 
| CAST_NOTREADY        | AA ability or spell is not ready yet                                 | 
| CAST_OUTOFMANA       | You don't have enough mana for this spell!                           | 
| CAST_OUTOFRANGE      | Target is out of range                                               | 
| CAST_RESISTED        | Your spell was resisted!                                             | 
| CAST_SUCCESS         | Your spell was cast successfully! (yay)                              | 
| CAST_UNKNOWNSPELL    | Spell/Item/Ability was not found                                     | 
|----------------------+----------------------------------------------------------------------+ 

#event BeginCast "You begin casting#*#" 
#event Collapse "Your gate is too unstable, and collapses.#*#" 
#event Fizzle "Your spell fizzles#*#" 
#event Immune "Your target is immune to changes in its attack speed#*#" 
#event Immune "Your target is immune to changes in its run speed#*#" 
#event Immune "Your target cannot be mesmerized#*#" 
#event Interrupt "Your casting has been interrupted#*#" 
#event Interrupt "Your spell is interrupted#*#" 
#event NoLOS "You cannot see your target.#*#" 
#event NoTarget "You must first select a target for this spell!#*#" 
#event NotReady "Spell recast time not yet met.#*#" 
#event OutOfMana "Insufficient Mana to cast this spell!#*#" 
#event OutOfRange "Your target is out of range, get closer!#*#" 
#event Recover "You haven't recovered yet...#*#" 
#event Recover "Spell recovery time not yet met#*#" 
#event Resisted "Your target resisted the #*#" 
#event Standing "You must be standing to cast a spell#*#" 
#event Stunned "You have been stunned.#*#" 
#event Stunned "You cannot cast while stunned#*#" 
#event Stunned "You *CANNOT* cast spells, you have been silenced!#*#" 


Sub Cast(string spellName,string spellType,timer giveUpTimer,string mySub) 
   /if ( ${Me.Invis} && ${noInvis} ) /echo You're invis... waiting to cast 
:wait_for_stop 
   /if ( ${Me.Casting.ID} || ( ${Me.Invis} && ${noInvis} ) ) { 
   	  /stopsong
      /delay 1 
      /goto :wait_for_stop 
   }  
   /if ( ${Me.Speed} ) { 
   :wait_for_stop2 
      /delay 1 
      /if ( ${Me.Moving} ) /goto :wait_for_stop2 
   } 
   /if ( !${Defined[giveUpTimer]} ) /declare giveUpTimer timer local 0 
   /if ( !${Defined[spellRecastTime1]} ) { 
      /declare lastSpell string outer 
      /declare refreshTime timer outer 0 
      /declare itemRefreshTime float outer 0 
      /declare i int local 
      /declare castReturn string outer 
      /delay 5 
      /for i 1 to 12
         /declare spellRecastTime${i} timer outer 
         /if ( ${Me.SpellReady[${i}]} ) { 
            /varset spellRecastTime${i} 0 
         } else { 
            /varcalc spellRecastTime${i} 10*${Me.Gem[${i}].RecastTime} 
         } 
      /next i 
   } 
   /declare currentTarget int local 
   /declare currentTargetType string local 
   /declare swapItemBack bool local false 
   /declare delayTime timer local 
   /declare castEndTime timer local 
   /declare moveBack bool local 
   /if ( !${Defined[spellType]} ) /declare spellType string local spell 
   /if ( ( ${spellType.Equal[spell]} || ${spellType.Left[3].Equal[gem]} ) && !${Int[${Me.Book[${spellName}]}]} ) { 
      /echo Spell: "${spellName}" was not found in your book 
      /return CAST_UNKNOWNSPELL 
   } 
   /if ( ${spellType.Equal[spell]} || ${spellType.Left[3].Equal[gem]} ) { 
      /if ( !${Me.Gem[${spellName}]} ) { 
         /if ( ${spellType.Left[3].Equal[gem]} ) {
         	/if  ( ${spellType.Length} > 4 ) {
         		/memspell ${spellType.Right[2]} "${spellName}" 
         	} else {
            	/memspell ${spellType.Right[1]} "${spellName}" 
            }
         } else { 
            /return CAST_NOTMEMMED 
         } 
         /delay 6s ${Me.Gem[${spellName}]} 
         /if ( !${Me.Gem[${spellName}]} ) { 
            /echo Spell mem interrupted... 
            /return CAST_INTERRUPTED 
         } 
         :wait_for_mem 
         /delay 15s ${Me.SpellReady[${spellName}]} 
         /if ( !${Me.SpellReady[${spellName}]} ) { 
            /if ( ${giveUpTimer} ) /goto :wait_for_mem 
            /return CAST_NOTREADY 
         } 
      } 
      /varset spellType spell 
   } 
   /if ( ${spellName.Find[illusion: ]} && ${Me.AltAbility[project illusion]} ) /call Cast "project illusion" "alt" 
   /declare slotName int local 
   /declare slotID int local 
   /declare oldSlotID int local 
:clear_events 
   /if ( ${Me.SpellReady[${spellName}]} ) /varset spellRecastTime${Me.Gem[${spellName}]} 0 
   /call ClearReturn 
   /doevents Recover 
   /doevents BeginCast 
   /doevents Fizzle 
   /doevents Interrupt 
   /doevents Standing 
   /doevents OutOfRange 
   /doevents OutOfMana 
   /doevents NoLOS 
   /doevents Resisted 
   /doevents Immune 
   /doevents Stunned 
   /doevents Collapse 
   /doevents NoTarget 
   /doevents NotReady 
   /if ( !${castReturn.Equal[CAST_SUCCESS]} ) { 
      /delay 1 
      /goto :clear_events 
   } 
   /varset giveUpTimer ${giveUpTimer.OriginalValue} 
   /declare recoverWaitTime timer local 30 
:cast_loop 
   /if ( ${Me.Ducking} ) /keypress duck 
   /if ( !${Me.Standing} ) /stand 
   /if ( ${spellType.Equal[item]} ) { 
      /if ( !${FindItem[${spellName}].InvSlot} ) { 
         /echo Cannot find item: ${spellName} 
         /return CAST_UNKNOWNSPELL 
      }      
      /if ( ${FindItem[${spellName}].InvSlot}>30 ) { 
         /varset swapItemBack true 
         /if ( ${FindItem[${spellName}].WornSlot[1]} ) { 
            /varset slotName ${FindItem[${spellName}].WornSlot[1]} 
         } else { 
            /varset slotName pack8
         } 
         /varset slotID ${InvSlot[${slotName}].ID} 
         /varset oldSlotID ${FindItem[${spellName}].InvSlot.ID} 
         /autoinventory 
         /if ( ${InvSlot[${oldSlotID}].Pack} ) { 
         :open_pack 
            /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
            /if ( !${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /goto :open_pack 
         } 
      :pick_up_item 
         /if ( ${InvSlot[${oldSlotID}].Pack} && !${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
         /nomodkey /itemnotify ${InvSlot[${oldSlotID}]} leftmouseup 
         /if ( !${Cursor.Name.Equal[${spellName}]} ) /goto :pick_up_item 
      :exchange_items 
         /nomodkey /itemnotify ${slotID} leftmouseup 
         /if ( !${Me.Inventory[${slotID}].Name.Equal[${spellName}]} ) /goto :exchange_items 
         /if ( ${InvSlot[${oldSlotID}].Pack} ) { 
         :close_pack 
            /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
            /if ( ${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /goto :close_pack 
         } 
      } 
      /varset itemRefreshTime ${Math.Calc[${MacroQuest.Running}+500]} 
      /echo Casting: ${FindItem[${spellName}].Spell.Name}${If[!${FindItem[${spellName}].Spell.TargetType.Equal[PB AE]} && !${FindItem[${spellName}].Spell.TargetType.Equal[self]} && ${Target.ID}, on >> ${Target.CleanName} <<,]} 
      /cast item "${spellName}" 
   } else /if ( ${spellType.Equal[spell]} ) { 
      /if ( !${lastSpell.Equal[item]} ) { 
      :wait_on_refresh 
         /if ( ${refreshTime}>0 ) { 
            /delay 1 
            /goto :wait_on_refresh 
         } 
      :wait_for_spell 
         /if ( ${spellRecastTime${Me.Gem[${spellName}]}} ) { 
            /if ( !${giveUpTimer} ) /return CAST_NOTREADY 
            /delay 1 
            /goto :wait_for_spell 
         } 
         /varcalc delayTime 10*(1.5-${Spell[${spellName}].MyCastTime}) 
      :cast_delay_loop 
         /if ( ${delayTime}>0 ) { 
            /delay 1 
            /goto :cast_delay_loop 
         } 
      } 
      /cast "${spellName}" 
   } else { 
      /if ( !${Me.AltAbilityReady[${spellName}]} ) /return CAST_NOTREADY 
      /varset itemRefreshTime ${Math.Calc[${MacroQuest.Running}+500]} 
      /echo Using AA Ability: ${AltAbility[${spellName}].Name} 
      /alt activate ${AltAbility[${spellName}].ID} 
   } 
   /if ( ${Me.Casting.ID} ) { 
      /varcalc castEndTime ${Me.Casting.MyCastTime}*10 
      /if ( ${spellType.Equal[spell]} ) /echo Casting: ${Me.Casting.Name}${If[!${Me.Casting.TargetType.Equal[PB AE]} && !${Me.Casting.TargetType.Equal[self]} && ${Target.ID}, on >> ${Target.CleanName} <<,]} 
   } 
   /varset currentTarget ${Target.ID} 
   /varset currentTargetType ${Target.Type} 
   /varset moveBack false 
:wait_cast_loop 
   /if ( ${Me.Casting.ID} ) { 
     |/echo Still casting - Wait loop...
      /if ( ${Defined[mySub]} ) /call ${mySub} 
      /if ( ${currentTarget} && !${Spawn[${currentTarget}].Type.Equal[${currentTargetType}]} ) { 
      	 |/Echo Target Type does not match (${Spawn[${currentTarget}].Type} VS ${currentTargetType}.
		 /if ( !${Me.Casting.TargetType.Equal[PB AE]} && !${Me.Casting.TargetType.Equal[self]} && !${moveBack} ) { 
            /if ( !${Me.Mount.ID} || ${castEndTime}>30 ) { 
               /call Interrupt 
            } else { 
               /keypress strafe_right hold 
               /delay 1 
               /keypress strafe_right 
               /varset moveBack true 
            } 
         } 
      } 
      /if ( ${Me.State.Equal[DUCK]} ) /varset castReturn CAST_CANCELLED 
      /delay 1 
      /goto :wait_cast_loop 
   } 
   /if ( ${moveBack} ) { 
      /keypress strafe_left hold 
      /delay 1 
      /keypress strafe_left 
      /delay 8 !${Me.Moving} 
   } 
   /if ( ${swapItemBack} ) { 
   :exchange_items2 
      /itemnotify ${slotID} leftmouseup 
      /if ( ${Me.Inventory[${slotID}].Name.Equal[${spellName}]} ) /goto :exchange_items2 
      /if ( ${InvSlot[${oldSlotID}].Pack} ) { 
      :open_pack2 
         /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
         /if ( !${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /goto :open_pack2 
      } 
   :drop_item 
      /if ( ${InvSlot[${oldSlotID}].Pack} && !${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
      /nomodkey /itemnotify ${oldSlotID} leftmouseup 
      /if ( ${Cursor.ID} ) /goto :drop_item 
      /if ( ${InvSlot[${oldSlotID}].Pack} ) { 
      :close_pack2 
         /nomodkey /itemnotify ${InvSlot[${oldSlotID}].Pack} rightmouseup 
         /if ( ${Window[${InvSlot[${oldSlotID}].Pack.Name}].Open} ) /goto :close_pack2 
      } 
   } 
   /if ( ${castReturn.Equal[CAST_CANCELLED]} ) { 
      /echo Spell was cancelled... 
      /return CAST_CANCELLED 
   } 
   /call ClearReturn 
   /doevents Recover 
   /doevents BeginCast 
   /doevents Fizzle 
   /doevents Interrupt 
   /doevents Standing 
   /doevents OutOfRange 
   /doevents OutOfMana 
   /doevents NoLOS 
   /doevents Resisted 
   /doevents Immune 
   /doevents Stunned 
   /doevents Collapse 
   /doevents NoTarget 
   /doevents NotReady 

   /if ( !${castReturn.Equal[CAST_SUCCESS]} ) { 
      /if ( ${castReturn.Equal[CAST_NOTREADY]} ) /return CAST_NOTREADY 
      /if ( ${castReturn.Equal[CAST_FIZZLE]} ) { 
         /echo Spell Fizzled. Recasting... 
         /goto :cast_loop 
      } 
      /if ( ${castReturn.Equal[CAST_RECOVER]} && ${spellType.Equal[spell]} ) { 
         /if ( !${recoverWaitTime} ) { 
            /varcalc spellRecastTime${Me.Gem[${spellName}]} 10*${Spell[${spellName}].RecastTime} 
            /if ( !${giveUpTimer} ) /return CAST_NOTREADY 
         } 
         /goto :cast_loop 
      } 
      /if ( ${castReturn.Equal[CAST_RESTART]} ) /goto :cast_loop 
      /if ( ${castReturn.Equal[CAST_STUNNED]} ) { 
         /delay 3s !${Me.Stunned} 
         /goto :cast_loop 
      } 
      /if ( ${castReturn.Equal[CAST_INTERRUPTED]} ) { 
         /if ( ${giveUpTimer} ) { 
            /echo Spell was interrupted. Recasting... 
            /goto :cast_loop 
         } 
         /echo Spell was interrupted... 
         /return CAST_INTERRUPTED 
      } 
   } 
   /if ( ${spellType.Equal[spell]} ) { 
      /varset lastSpell ${spellName} 
      /if ( !${castReturn.Equal[CAST_CANNOTSEE]} && !${castReturn.Equal[CAST_OUTOFRANGE]} && !${castReturn.Equal[CAST_OUTOFMANA]} && !${castReturn.Equal[CAST_NOTARGET]} ) { 
         /varcalc refreshTime 10*${Spell[${spellName}].RecoveryTime} 
         /varcalc spellRecastTime${Me.Gem[${spellName}]} 10*${Spell[${spellName}].RecastTime} 
      } 
   } else { 
      /varset lastSpell ${spellType} 
   :wait_item_loop 
      /if ( ${itemRefreshTime} > ${MacroQuest.Running} ) { 
         /delay 1 
         /goto :wait_item_loop 
      } 
   } 
   /if ( ${castReturn.Equal[CAST_COLLAPSE]} ) { 
      /varset giveUpTimer 200 
      /goto :cast_loop 
   } 
   /return ${castReturn} 

Sub Interrupt 
   /if ( ${Me.Mount.ID} ) /dismount 
   /if ( !${Me.Ducking} ) { 
      |/echo DUCKING OUT!!! - Return: ${castReturn}
      /keypress duck 
      /keypress duck 
   } 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_CANCELLED 
/return ${Macro.Return} 

Sub ClearReturn 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_SUCCESS 
/return 

Sub Event_Fizzle 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_FIZZLE 
/return 

Sub Event_Resisted 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_RESISTED 
/return 

Sub Event_Interrupt 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_INTERRUPTED 
/return 

Sub Event_Recover 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_RECOVER 
/return 

Sub Event_Immune 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_IMMUNE 
/return 

Sub Event_Stunned 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_STUNNED 
/return 

Sub Event_NoLOS 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_CANNOTSEE 
/return 

Sub Event_Standing 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_RESTART 
   |/echo Ducking...
   /keypress back hold
   /delay 1
   /keypress back
   /delay 1
/return 

Sub Event_Collapse 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_COLLAPSE 
/return 

Sub Event_OutOfMana 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_OUTOFMANA 
/return 

Sub Event_OutOfRange 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_OUTOFRANGE 
/return 

Sub Event_NoTarget 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_NOTARGET 
/return 

Sub Event_NotReady 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_NOTREADY 
/return 

Sub Event_BeginCast 
   /if ( ${Defined[castReturn]} ) /varset castReturn CAST_SUCCESS 
/return