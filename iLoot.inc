
|==================================================================================================|
Sub DeclareLoot

/declare intLootItems 				int 	outer 	0
/declare LootItemLoop 				int 	outer 	0
/declare Loops 						int 	outer 	0
/declare intDifficultCorpse 		int 	outer 	0
/declare intDifficultCorpseNag		int		outer	0
/declare intSpecialLoot 			int 	outer 	0
/declare strSpecialLoot 			str 	outer
/declare intSpecialItemCount		int		outer	0
/declare intSafeLootRadius			int		outer	50

/declare strLoot 					string 	outer
/declare intKeep 					int 	outer 	1
/declare intJustLooted 				int 	outer 	0
/declare intReturnToWaypoint 		int 	outer 	0

/declare intRange 					int 	outer 	150

/declare arrDiffCorpse[11] 			int 	outer 0


|Add corpses to ignore:
/squelch /alert add 2 "Arei's corpse"
/squelch /alert add 2 "Baiylee's corpse"
/squelch /alert add 2 "Biha's corpse"
/squelch /alert add 2 "Bihajr's corpse"
/squelch /alert add 2 "Biho's corpse"
/squelch /alert add 2 "Bloodraven's corpse"
/squelch /alert add 2 "Bodybags's corpse"
/squelch /alert add 2 "Cnote's corpse"
/squelch /alert add 2 "Derailer's corpse"
/squelch /alert add 2 "Exxit's corpse"
/squelch /alert add 2 "Frakkin's corpse"
/squelch /alert add 2 "Goodbeats's corpse"
/squelch /alert add 2 "Heffex's corpse"
/squelch /alert add 2 "Kamdara's corpse"
/squelch /alert add 2 "Kristella's corpse"
/squelch /alert add 2 "Lilit's corpse"
/squelch /alert add 2 "Logs's corpse"
/squelch /alert add 2 "Pleasant's corpse"
/squelch /alert add 2 "Qween's corpse"
/squelch /alert add 2 "Sabbatarian's corpse"
/squelch /alert add 2 "Shawdow's corpse"
/squelch /alert add 2 "Size's corpse"
/squelch /alert add 2 "Tinksa's corpse"
/squelch /alert add 2 "Tinkso's corpse"
/squelch /alert add 2 "Tyrannasaurus's corpse"

/return

|==================================================================================================|
Sub LootCheck
|---------------------------------------------------
/declare  intVerbose      int 	local 0

|Cancel if I have a target:
/if (${Target.ID}) /return

|Cancel if I have an Extended Target:
/if (${Me.XTarget}) /return

|Look for ground spawns first:
/if (${intVerbose}) /echo Looking for ground spawns...
/squelch /itemtarget
/if (${ItemTarget.Name.NotEqual[NULL]} && ${ItemTarget.Name.Length} > 3) {
	/if (${ItemTarget.Distance} < 15 && ${ItemTarget.DistanceZ} < 15) {
		/echo Ground Spawn found, looting ${ItemTarget.Name}.
		/if (${Cursor.ID}) /autoinv
		/delay 5
		/face item
		|/click left center
		/keypress u
		/if (!${Cursor.ID} || ${Target.ID}) {
			/look -128
			:itemloop
			|/click left center
			/keypress u
			/if (${Target.ID}) /squelch target clear
			/if (!${Cursor.ID} && ${Me.Look} < 0) {
				/if (${intVerbose}) /echo Missed it, trying again...
				/delay 2
				|/echo Looking to ${Math.Calc[${Me.Look} +2]}
				/look ${Math.Calc[${Me.Look} +2]}
				/goto :itemloop
			}
		}
		/delay 5
		/if (${Cursor.ID}) {
			/call CursorHandler
		}
		/look 0
		/keypress esc
		/keypress esc
		/keypress esc
	}	
}

|Look for Lootable Mobs within Range:
|---------------------------------------------------
/if (${intVerbose}) /echo Looking for lootable corpses...
/squelch /target Clear

/call FindEasyTarget

|Clear out corpses that I have no Line Of Sight to:
/if (!${LineOfSight[${Me.Y},${Me.X},${Me.Z}:${Target.Y},${Target.X},${Target.Z}]}) {
	/if (!${intDifficultCorpse} && ${Target.ID}) {
		/varset intDifficultCorpse ${Target.ID}
		/squelch /target clear
		/echo Cleared Corpse: ${intDifficultCorpse} because I don't have line of sight.
	}
}

|Clear out corpses that are out of range:
/if (${intVerbose}) /echo Targeting Corpse: ${Target.Name} at ${Target.Distance}.
/if (${Target.Distance} > ${intRange}) {
	/if (${Target.Distance} < 1000) {
		/if (${intDifficultCorpseNag} != ${intDifficultCorpse}) {
			/echo Clearing Distant Corpse: ${Target.Name} (${Target.ID}) at ${Target.Distance}.
	   		/varset intDifficultCorpse ${Target.ID}
			/varset intDifficultCorpseNag ${intDifficultCorpse}
		}
	}
   	/squelch /target Clear
}

|Looks like there is a valid corpse to loot:
/if (${Target.ID}!=0) {

	/if (${intVerbose}) /echo Found a lootable corpse.

	|Move to Loot Spot:
	|---------------------------------------------------
	/if (${intVerbose}) /echo Moving to Loot Location.
	/varset intJustLooted 1

	|Set Loot name:
	/if (!${intMelee}) {
		/varset intDifficultCorpse ${Target.ID}
		/if (${intVerbose}) /echo Set Difficult Corpse to ${Target.ID}.
	}
	
	|Set Loot coordinates:
	/Stand
	/Varset MobX ${Target.X}
	/Varset MobY ${Target.Y}
   	/varset Iterations 1

	:LootLoop
	/if (!${Target.ID}) {
		/keypress back
		/return
	}
	/face fast
	|/keypress forward 

	/varcalc LocDistance ${Math.Distance[${Me.X},${Me.Y},0:${MobX},${MobY},0]}
	
	|If we run into a mob that's VERY close, mark difficult and return:
	/if (${SpawnCount[npc zradius 20 radius ${intSafeLootRadius} noalert 1]} > 0) {
		/echo Mob (${NearestSpawn[npc zradius 20 radius ${intSafeLootRadius} noalert 1].CleanName}) close to corpse, better wait on this one.
		/varset intDifficultCorpse ${Target.ID}
		
		|Abort loot and return!:
		/keypress back hold
		/delay 1
		/keypress back
		/return
		
		|Only if not "GoWipe"
		/if (${intRange} < 175) {
			/varset Iterations 1000
			/squelch /target clear
		}
	}
		
	|If we've been walking too long, give up.
	/Varcalc Iterations ${Iterations} + 1
	/if  (${Iterations} > ${Math.Calc[${intRange} * 21]}) {
		|Used to be range 400, made longer for GoWipe looting.
		/echo I walked too long, stopping.
		/Varset LocDistance 0
	} 
	|/echo ${LocDistance}
	
	|=============================================================================
	|Slow Down Distance: Was 30.
	/if (${LocDistance} > 20) {
		/keypress forward hold 
		/Goto :LootLoop
	} else {
		|=============================================================================
		|Loot Distance: Was 12, 15 (22.94 > LootRange > 21.59).
		/if (${LocDistance} > 15) {
			/if (${intVerbose}) /echo Very close: ${LocDistance}
			/keypress forward hold
			/delay 1
			/keypress back
			/delay 1

			|Rapid increase if not getting closer:
			/if (${LocDistance} <= ${Math.Distance[${Me.X},${Me.Y},0:${MobX},${MobY},0]}) {
				/Varcalc Iterations ${Iterations} + 40
				/echo Moving too slow!
			}

			/Goto :LootLoop
		}
	}
	
	/keypress forward
	/if (${intVerbose}) /echo It took ${Iterations} loops to get to corpse.
	/Varset Iterations 0

	|Actual Looting:
	|---------------------------------------------------
	/if (${intVerbose}) /echo Looting corpse.
	/loot
	
	|Prepare to open the loot window:
	/if (${intVerbose}) /echo Waiting for Corpse Items to populate.
	|Wait 1.5 seconds, or until the loot window is open:
	/delay 15 ${Corpse.Items}
	/if (${intVerbose}) /echo Corpse Items populated.
	
	/if (${intVerbose}) /echo Doing events...
	/doevents
	/if (${intVerbose}) /echo Events Done...

	|${Window[LootWnd].Open}
	/if (!${Corpse.Items}) {
		/echo Empty Corpse... 
 		/notify LootWnd DoneButton leftmouseup
	} else {
		|Mark this corpse to prevent loot loop:
		/varset intDifficultCorpse ${Target.ID}

		/varset intLootItems ${Math.Calc[${Corpse.Items}]}
		/if (${intVerbose}) /echo Looting ${intLootItems} item(s)...
		
		|Loot Corpse (Skipping Special Items):
		/varset LootItemLoop 1
		/varset intSpecialItemCount 0
		:LootCorpseLoop

		|/delay 1
		/if (${intVerbose}) /echo Evaluating: ${Corpse.Item[${LootItemLoop}]}

		| Handle Special Loot:
		/if (${intVerbose}) /echo Checking for special loot...
		/varset intSpecialLoot 0			
		/varset intSpecialLoot ${Ini[iLoot.ini,SpecialLoot,${Corpse.Item[${LootItemLoop}]}]} 
		/if (${intSpecialLoot}) {
			|Special Item found!
			/g ${Corpse.Item[${LootItemLoop}]} rotting here in ${Zone.Name} on ${Target.CleanName}!
			/varcalc intSpecialItemCount ${intSpecialItemCount} + 1
			|/varset LootItemLoop ${intLootItems}
			/goto :LootPrepareForNextItem
		}
		
		| Handle NoTrade item (if not Lootall):
		/if (${intVerbose}) /echo Checking for NoTrade items...
		/if (!${intLootAll}) {
			| Is the item really No Drop?
			/if (${intVerbose}) /echo NoDrop: ${Corpse.Item[${LootItemLoop}].NoDrop}
			/if (${Corpse.Item[${LootItemLoop}].NoDrop}) {
				| If the item is already in the delete list, I'll follow regular rules:
				/if (${intVerbose}) /echo It's no drop - is it auto delete?
				/if (${Ini[iLoot.ini,Keepers,${Corpse.Item[${LootItemLoop}]},1]}) {
					/g ${Corpse.Item[${LootItemLoop}]} on ${Target.CleanName} is No Drop! I refuse to loot it!
					/varcalc intSpecialItemCount ${intSpecialItemCount} + 1
					| Link cool loot items:
					/keypress enter
					/keypress / chat
					/keypress g chat
					|/keypress u chat
					/keypress space chat
					/notify LootWnd BroadcastButton leftmouseup
					/keypress enter chat

					/goto :LootPrepareForNextItem
				}
			}
		}
		
		|Follow Regular loot rules:
		/if (${intVerbose}) /echo Looting regular item...

		| Changed for HoT Updates:
		|/shift /itemnotify loot${LootItemLoop} leftmouseup 
		/shift /itemnotify ${Corpse.Item[${LootItemLoop}].InvSlot.ID} leftmouseup
		
		|Wait until I have the item, the confirmation box, or a full second:
		/delay 1s (${Cursor.ID} || ${Window[ConfirmationDialogBox].Open})

		|Handle Confirmation box for stacks:
		/if (${Window[ConfirmationDialogBox].Open}) {
			/notify ConfirmationDialogBox Yes_Button leftmouseup
			/delay 5 !${Window[ConfirmationDialogBox].Open}
		}

		|Wait until I have the item (give stacks more time):
		/delay 1s ${Cursor.ID}
		
		/if (${intVerbose}) /echo Cursor Handler...
		/call CursorHandler
  		
  		:LootPrepareForNextItem

  		/varcalc LootItemLoop ${LootItemLoop} + 1
  		
  		|Force exit when done (Accounting for Special Items):
	  	/if (${Corpse.Items} - ${intSpecialItemCount} < 1) /varset LootItemLoop 16
	  	
	  	|Force Exit if in an error state (Like it has a Lore item you already have):
	  	/if (!${Corpse.Item[${LootItemLoop}].ID}) /varset LootItemLoop 15
	  	
	  	/if (${intVerbose}) /echo ${Corpse.Items}, ${intSpecialItemCount}, ${LootItemLoop}
	  	/if (${LootItemLoop} < 15) /goto :LootCorpseLoop

  		/notify LootWnd DoneButton leftmouseup
 		/if (${intVerbose}) /echo Done with this corpse.
  	}
  	
  	/call FillDiffArray
  	
	/squelch /target clear
	/if (${intVerbose}) /echo Target cleared.
	/delay 5
	/look 0
	/if (${intVerbose}) /echo Returning to calling sub.
}
/return

|==================================================================================================|
sub CursorHandler
|---------------------------------------------------
	|Echo - Let's play "What's in my hand?"!

	/declare intLootLoops	int		local	0
	
	/if (!${Cursor.ID}) /return
		
	:NextItem
	/varcalc intLootLoops ${intLootLoops} + 1
	/varset strLoot ${Cursor.Name}
	
	|Look up this item in the .ini:
	/varset intKeep ${Ini[iLoot.ini,Keepers,${Cursor.Name},-1]} 

	/delay 1 

	|If the item isn't in the .ini file then add it. 
	/if (${intKeep}==-1) { 
	    /varset intKeep 1
		/ini "iLoot.ini" "Keepers" "${Cursor.Name}" "1" 
		/echo Added ${Cursor.Name} to the loot list as a keeper.
	} 

	|Handle Stack Fillers here:
	/if (${intKeep}==2) {
		/if (${FindItemCount[${Cursor.Name}]} != 0 && ${FindItem[${Cursor.Name}].FreeStack} == 0) {
			/varset intKeep 0
		} else {
			/varset intKeep 1
		}
	}

	|Actually handle the item:
	/if (${intKeep}!=1) {
		/destroy
		/echo DESTROYED ${strLoot}.
		/varset intKeep 1
	} else {
		/autoinventory
		/echo Kept ${strLoot}.
	}

	/delay 5
	
	|Check for loot handling problems:
	/if (${intLootLoops} > 5) {
		/echo Inventory Full?  DESTROYED ${strLoot}.
		/destroy
	}
	
    /if (${Cursor.ID}) /goto :NextItem 

/return  


|==================================================================================================|
sub FindTarget 
|---------------------------------------------------
	|This can be deleted once FindEasyTarget is tested.
	
	/squelch /target Corpse noalert 2
	|/squelch /target Corpse zradius 25
					 	
	|Clear out Difficult Corpses:
	/if (${Target.ID} == ${intDifficultCorpse}) {
		/if (${intDifficultCorpse}) {
			/if (${intDifficultCorpseNag} != ${intDifficultCorpse}) {
				/echo Cleared Difficult Corpse: ${intDifficultCorpse}.
				/varset intDifficultCorpseNag ${intDifficultCorpse}
			}
		/squelch /target clear
		/return
		}
	}
/return


|==================================================================================================|
sub FindEasyTarget
|---------------------------------------------------
	/declare	intVerbose 	     		int 	local 0
	/declare	intEasyCorpseLoop 		int 	local 0
	/declare	intEasyNotLoop 			int 	local 0
	/declare	intHopefulCorpse		int		local 0

	/if (${intVerbose}) /echo *** FindEasyTarget ***
	
	|Loop through up to 10 nearest mobs:
	/varset intEasyCorpseLoop 0
	:EasyCorpseList
	/varcalc intEasyCorpseLoop ${intEasyCorpseLoop} + 1
	/if (${intVerbose}) /echo intEasyCorpseLoop corpse: ${intEasyCorpseLoop}
	
	/if (${intVerbose}) /echo Evaluating corpse: ${NearestSpawn[${intEasyCorpseLoop}, corpse noalert 2]}
	|Ran out of easy corpses:
	/if (!${NearestSpawn[${intEasyCorpseLoop}, corpse noalert 2].ID}) {
		/if (${intVerbose}) /echo Out of easy corpses, returning.
		/return
	}
	/varset intHopefulCorpse ${NearestSpawn[${intEasyCorpseLoop}, corpse noalert 2].ID}
	/if (${intVerbose}) /echo Setting intHopefulCorpse to ${intHopefulCorpse}.

	|Compare to up to 10 arrDiffCorpse
	/varset intEasyNotLoop 0
	:EasyNotList
	/varcalc intEasyNotLoop ${intEasyNotLoop} + 1
	/if (${intVerbose}) /echo intEasyNotLoop corpse: ${intEasyNotLoop} (${arrDiffCorpse[${intEasyNotLoop}]})
		
	|Skip difficult corpses:
	/if (${intHopefulCorpse} == ${arrDiffCorpse[${intEasyNotLoop}]}) {
		/if (${intVerbose}) /echo ${NearestSpawn[${intEasyCorpseLoop}, corpse noalert 2].CleanName} is on the difficult list.
		/varset intHopefulCorpse 0
		/varset intEasyNotLoop 11
	}
	
	|Drop if we've seen all the difficult corpses:
	/if (!${arrDiffCorpse[${intEasyCorpseLoop}]}) {
		/if (${intVerbose}) /echo There is not a mob in this position on the difficult list.
		/varset intEasyNotLoop 11
	}

	/if (${intVerbose}) /delay 1
	/doevents
	/if (${intEasyNotLoop} < 10) /goto :EasyNotList
	
	/if (${intHopefulCorpse}) {
		/varset intEasyCorpseLoop 11
	}
	/if (${intEasyCorpseLoop} < 10) /goto :EasyCorpseList
	
	/squelch /target id ${intHopefulCorpse}
	/if (${intVerbose}) /echo ${Target.CleanName} is the right corpse to loot.
	
/return


|==================================================================================================|
sub FillDiffArray
|---------------------------------------------------
	/declare	intVerbose 	     		int 	local 0
	/declare	intNewDiff				int		local 0
	/declare	intEasyNotLoop			int		local 0
	
	/if (${intVerbose}) /echo *** FillDiffArray ***
	/varset intNewDiff ${Target.ID}
	/if (${intVerbose}) /echo Evaluating ${Target.CleanName} (${intNewDiff}) for difficult corpse array.
	/delay 10
	/if (!${NearestSpawn[id ${intNewDiff}].ID}) {
		/if (${intVerbose}) /echo Not difficult, returning.
		|/varset intDifficultCorpse 0
		/return
	}

	/if (${intVerbose}) /echo Adding ${intNewDiff} to the list.

	|Clear entire table if full:
	/if (${arrDiffCorpse[10]} > 0) {
		/if (${intVerbose}) /echo Difficult Corpse table is full, restarting it!
		/varset intEasyNotLoop 0
		:EasyNotListClear
		/varcalc intEasyNotLoop ${intEasyNotLoop} + 1
		/varset arrDiffCorpse[${intEasyNotLoop}]) 0
		/if (${intVerbose}) /echo intEasyNotLoop corpse: ${intEasyNotLoop} (${arrDiffCorpse[${intEasyNotLoop}]})
		/if (${intEasyNotLoop} < 10) /goto :EasyNotListClear
	}
	
	|Compare to up to 10 arrDiffCorpse
	/varset intEasyNotLoop 0
	:EasyNotList
	/varcalc intEasyNotLoop ${intEasyNotLoop} + 1
	/if (${intVerbose}) /echo intEasyNotLoop corpse: ${intEasyNotLoop} (${arrDiffCorpse[${intEasyNotLoop}]})
		
	|Drop if this one is on the list:
	/if (${intNewDiff} == ${arrDiffCorpse[${intEasyNotLoop}]}) {
		if (${intVerbose}) /echo ${intNewDiff} is on the difficult list.
		/varset intEasyNotLoop 11
	}
	
	|Add if we've seen all the difficult corpses:
	/if (!${arrDiffCorpse[${intEasyNotLoop}]}) {
		/if (${intVerbose}) /echo Evaluated every taken position on the difficult list, adding ${intEasyNotLoop} (${intNewDiff}).
		/varset arrDiffCorpse[${intEasyNotLoop}] ${intNewDiff}
		/varset intEasyNotLoop 11
	}

	/if (${intVerbose}) /delay 1
	/doevents
	/if (${intEasyNotLoop} < 10) /goto :EasyNotList

/return
