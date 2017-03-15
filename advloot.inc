| 
| Advanced Loot Code: AdvLoot.inc 
|    
| This include Does the following: 
|       - Allows you to specify what to keep / destroy via set INI file it will create / append 
|       - Will not loot no drops however it can be configured to do so 
|       - Will not revisit corpses with no drop items unless threshold met 
|       - Will wait for a "clear camp" before it try's to loot 
|       - Will loot from "home" to corpse to corpse, not home to corpse to home to corpse 
|       - Will not loot if inventory is full (see known issues) 
|       - If attempt to loot fails, it treats the mob as if it had no drop loot 
|       - Will not loot PC corpses 
| 
| Known Issues (most likely won't be fixing these) 
|       - If you have a bag that won't hold an item you loot, and no other slot is available, 
|         it drops the loot and will continue to do so until 100% of all slots are full. 
| 
| Possible Bugs 
| fixt    - If mobs are too close (even if mob already on alert list) it will not loot 
|         (eg. a hollow tree is excluded, but won't loot the corpse next to it) 
|        
| 
| Requirements: 
|       - Subs: SetupAdvLootVars and LoadALINIVals must be executed PRIOR to LootMobs 
|         (generally call them from your host macro, prior to your primary loop routine) 
|       - ${IniFile} must be declaired / defined in your host macro 
|       - ${AlertList} must be declaired / defined in your host macro 
| 
| Method of use: 
| 
| /if (${useAutoLoot} && ${LootMobs}==1 && !${Me.Moving} && ${ACState}<1 ) /call LootMobs 
| 
| Date:10/21/2005  
| 
| Version 1.42 - Fixed issue introduced in the v1.41 
|                      (looter wouldn't stop "looking for home point") 
|              
|  
| Notes - If you wish to use MOVE.INC just delete the same named subs 
|            in this file and the include should work as it did before 
| 

Sub SetupAdvLootVars 

| To loot (1) or not to loot (0) 
/declare LootMobs int outer 1 

| How many corpses at camp right now 
/declare CorpseList string outer 

| How far to look for a corpse 
/declare CorpseRadius int outer 0

| Are mobs too close 
/declare MobsTooClose int outer 100 

| Did I try to loot this mob already 
/declare CorpseAlertList int outer 25 

| How often do you want me to clear the CorpseAlearList 
/declare CorpseRotTime string outer 440s 

| Timer for CorpseRotTime 
/declare CorpseRotTimer timer outer 

| Am I waiting to try and loot no drops again 
/declare CorpseRotSetTimer string outer 
  /varset CorpseRotSetTimer FALSE 

| What ini file am I writing loot to 
/declare LootINIFile string outer 
  /varset LootINIFile "loot.ini" 

| Is my inventory overflowing 
/declare useAutoLoot string outer 
  /varset useAutoLoot TRUE 

/return 

Sub MoveToLoc(MoveToY, MoveToX) 
    /declare running int local 
    /declare distanceNow float local 
    /declare distanceBefore float local 
    /declare distanceModifier int local 
    /varset running 0 
    /declare distanceTimer timer 0 
    /varset distanceModifier 1 
    
    :moveToLocation 

    /face fast nolook loc ${MoveToY},${MoveToX} 

    /if (${Math.Distance[${Me.Y},${Me.X}:${MoveToY},${MoveToX}]}<1) { 
        /keypress forward 
        /return 
    } 
    
    /if (${distanceTimer}==0) { 
        /if (${Me.Sneaking}) { 
            /varset distanceModifier 2 
        } else { 
            /varset distanceModifier 1 
        } 

        /varset distanceNow ${Math.Distance[${Me.Y},${Me.X}:${MoveToY},${MoveToX}]} 
        /if (${Math.Calc[${distanceBefore}-${distanceNow}]}<${Math.Calc[2/${distanceModifier}]} && ${distanceBefore} ) { 
           /call strafePastObstacle 
        } 
        /varset distanceBefore ${Math.Distance[${Me.Y},${Me.X}:${MoveToY},${MoveToX}]} 
        /varset distanceTimer 15 
    } 

    /if (${running}==0) { 
        /keypress forward 
        /if (${Math.Distance[${Me.Y},${Me.X}:${MoveToY},${MoveToX}]}>1) { 
            /varset running 1 
            /keypress forward hold 
        } 
    } else { 
        /if (${Math.Distance[${Me.Y},${Me.X}:${MoveToY},${MoveToX}]}<1) { 
            /varset running 0 
            /keypress forward 
        } 
    } 
    /goto :moveToLocation 
/return 


| Sub MoveToSpawn                                   | 
|---------------------------------------------------| 
|This moves the player to within a provided distance| 
|of the provided spawn, while avoiding obstacles    | 
|                                                   | 
|The second parameter, Distance, allows for the     | 
|player to stop short of the target by a certain    | 
|amount, to provide for different aggro radii, etc. | 
|                                                   | 
|SYNTAX: /call MoveToSpawn ID Distance              | 

Sub MoveToSpawn(MoveToID, StopDistance) 

    /if (!(${Defined[MoveToID]})||(${Spawn[MoveToID].ID})) { 
        /echo Spawn ID not found or no ID provided. Aborting... 
        /return 
    } 
    /if (!(${Defined[StopDistance]})) { 
        /echo Stopping point not defined, using default distance of 70 
        /declare StopDistance int local 
        /varset StopDistance 70    
    } 

    /echo Moving to Spawn: ${MoveToID} (${Spawn[${MoveToID}].CleanName}). 
    /declare running int local 
    /declare distanceNow float local 
    /declare distanceBefore float local 
    /declare distanceModifier int local 
    /varset running 0 
    /declare distanceTimer timer 15 
    /varset distanceBefore ${Spawn[${MoveToID}].Distance} 
    /varset distanceModifier 1 
    
    :moveToSpawn 

    /squelch /face fast nolook id ${MoveToID} 

    /if (${Spawn[${MoveToID}].Distance}<${StopDistance}) { 
        /keypress forward 
        /return 
    } 
    
    /if (${distanceTimer}==0) { 
        /if (${Me.Sneaking}) { 
            /varset distanceModifier 2 
        } else { 
            /varset distanceModifier 1 
        } 

        /varset distanceNow ${Spawn[${MoveToID}].Distance} 
        /if (${Math.Calc[${distanceBefore}-${distanceNow}]}<${distanceModifier}) { 
      /call strafePastObstacle 
        } 
        /varset distanceBefore ${Spawn[${MoveToID}].Distance} 
        /varset distanceTimer 15 
    } 

    /if (${running}==0) { 
        /keypress forward 
        /if (${Spawn[${MoveToID}].Distance}>=${StopDistance}) { 
            /varset running 1 
            /keypress forward hold 
        } 
    } else { 
        /if (${Spawn[${MoveToID}].Distance}<${StopDistance}) { 
            /varset running 0 
            /keypress forward 
        } 
    } 
    /goto :moveToSpawn 
/return 

| Only to be used by the previous functions - It's obvious what it does. | 

sub strafePastObstacle 
    /keypress forward 
    /keypress back hold 
    /delay 5 
    /keypress back 
    /if (${Math.Rand[99]}>50) { 
        /keypress strafe_right hold 
    } else { 
        /keypress strafe_left hold 
    } 
    /delay 1s 
    /keypress strafe_right 
    /keypress strafe_left 
    /keypress forward hold 
/return 

Sub LoadALINIVals 
   /declare TempStr string local 
   /varset TempStr ${Ini[${IniFile},Settings,LootMobs,NOTFOUND]} 
   /varset LootMobs ${TempStr} 
   /if (${TempStr.Equal["NOTFOUND"]}) { 
      /ini "${IniFile}" Settings LootMobs 1 
      /varset LootMobs 1 
   } 
   /varset TempStr ${Ini[${IniFile},Settings,CorpseRadius,NOTFOUND]} 
   /varset CorpseRadius ${TempStr} 
   /if (${TempStr.Equal["NOTFOUND"]}) { 
      /ini "${IniFile}" Settings CorpseRadius 100 
      /varset CorpseRadius 100 
   } 
   /varset TempStr ${Ini[${IniFile},Settings,MobsTooClose,NOTFOUND]} 
   /varset MobsTooClose ${TempStr} 
   /if (${TempStr.Equal["NOTFOUND"]}) { 
      /ini "${IniFile}" Settings MobsTooClose 100 
      /varset MobsTooClose 100 
   } 
   /varset TempStr ${Ini[${IniFile},Settings,CorpseRotTime,NOTFOUND]} 
   /varset CorpseRotTime ${TempStr} 
   /if (${TempStr.Equal["NOTFOUND"]}) { 
      /ini "${IniFile}" Settings CorpseRotTime 420s 
      /varset CorpseRotTime 420s 
   } 
/return 

Sub ListAppendElement(string sList,string sElement,string sDiv) 
   /if (!${Defined[sDiv]}) /declare sDiv string local | 
   /if (${${sList}.Length}) { 
      /varset ${sList} ${${sList}}${sDiv}${sElement} 
   } else { 
      /varset ${sList} ${sElement} 
   } 
   /if (${DebugList.Find[core]}) /echo List ${${sList}}  Added: ${sElement} 
/return 

Sub Target(string sTargetName) 

   | Check if intended target already targetted. 
   /if (${Target.ID} && ${Spawn[${sTargetName}].ID}==${Target.ID} && (!${Spawn[pc ${sTargetName}].ID} || ${Target.Type.Equal[pc]})) /return 
   /squelch /target clear 
   /if (${Spawn[pc ${sTargetName} radius ${CorpseRadius}].ID}) { 
      /squelch /target pc ${sTargetName} radius ${CorpseRadius} 
   } else { 
      /target ${sTargetName} radius ${CorpseRadius} 
   } 
   /delay 2s ${Target.ID} 
   /if (!${Target.ID}) /echo Unable to locate target ${sTargetName}. 
/return 



Sub LootCorpse(int leaveLast,string noDrop) 
   /declare i int local 
   /declare lootslot int local 
   /declare loottotal int local -1 

 :auto_inv 
   /if ( ${Cursor.ID} ) { 
      /autoinventory 
      /delay 5 ${Cursor.ID} 
      /goto :auto_inv 
   } 
   /if ( !${Defined[leaveLast]} ) { 
      /declare leaveLast int local 
      /varset leaveLast 0 
   } 
   /if ( !${Defined[noDrop]} ) { 
      /declare noDrop string local 
      /varset noDrop no 
   } 
   /declare lootNoDrop bool local 
   /if ( ${Target.Name.Find[${Me.Name}]} || ${noDrop.Equal[nodrop]} ) { 
      /varset lootNoDrop true 
   } else { 
      /varset lootNoDrop false 
   } 
   /if ( ${leaveLast}!=0 ) /varset leaveLast 1 
   /loot 
   /delay 10s ${Corpse.Open} 
   /delay 1s 
   /varset loottotal ${Corpse.Items} 
   /if (${loottotal} !>=1) { 
      /echo NO LOOT! Cheap Bastard! 
      /goto :wait_for_done 
    } 

 :autoxplootlag 
   /if (${loottotal}!=${Corpse.Items}) { 
      /varset loottotal ${Corpse.Items} 
      /goto :autoxplootlag 
   } 
  
   /for lootslot 1 to ${loottotal} 
      :retryloot 
        /if ( !${Corpse.Item[${Math.Calc[${lootslot}+${leaveLast}]}].ID} ) /goto :nextloot 
        /shiftkey /itemnotify loot${lootslot} leftmouseup 
        /delay 2 
        /if ( ${Window[ConfirmationDialogBox].Open} ) { 
           /if ( ${lootNoDrop} ) { 
              /notify ConfirmationDialogBox Yes_Button leftmouseup 
           } else { 
              /notify ConfirmationDialogBox No_Button leftmouseup    
              /goto :nextloot      
           } 
        } 
        /if (!${Cursor.ID}) { 
           /goto :retryloot 
        } 
        /if (${Ini[${LootINIFile},"${Zone}","${Cursor}"].Equal[Keep]}) { 
                /echo Keeping a ${Cursor.Name}... WOOT! 
      :autoxpLootItem 
                /autoinventory 
           /if (${Cursor.ID}) /goto :autoxpLootItem 
        } 
        /if (${Ini[${LootINIFile},"${Zone}","${Cursor}"].Equal[Destroy]}) { 
           /echo Destroying a ${Cursor.Name}... See Yah! 
      :autoxpLootItem1  
           /destroy 
           /if (${Cursor.ID}) /goto :autoxpLootItem1 
        } 
        /if (!${Cursor.ID}) /goto :nextloot 
        /echo "Adding [${Zone}] ${Cursor} to ${LootINIFile} defaulting as Keep" 
        /ini "${LootINIFile}" "${Zone}" "${Cursor}" Keep 
      :autoxpLootItem2 
        /autoinventory 
        /delay 2s 
        /if (${Cursor.ID}) /goto :autoxpLootItem2 
     :nextloot 
   /next lootslot 
   /delay 1s 
 :wait_for_done 
   /delay 1s 
   /if ( ${Corpse.Items}>0 ) { 
      /echo Nodrop or was Asked to Leave Items on Corpse or just can't loot 
      /alert add ${CorpseAlertList} CORPSE "${Target.Name}" 
      /if (!${CorpseRotSetTimer}) { 
        /varset CorpseRotSetTimer TRUE 
        /varset CorpseRotTimer ${CorpseRotTime} 
      } 
   } 
   /keypress esc 
   /if ( ${Corpse.Open} ) /goto :wait_for_done 
/return 


Sub LootMobs 
   /if (!${useAutoLoot}) /return 
   /declare DeadCount int local 
   /declare LiveCount int local 
   /varset LiveCount ${SpawnCount[npc radius ${MobsTooClose} noalert ${AlertList}]} 
   /if (${LiveCount}>=1) /return 
   /if (${CorpseRotTimer}<=0 && ${CorpseRotSetTimer}) { 
      /squelch /alert clear ${CorpseAlertList} 
      /varset CorpseRotSetTimer FALSE 
   } 

   /varset DeadCount ${SpawnCount[corpse radius ${CorpseRadius} noalert ${CorpseAlertList}]} 
   /if (!${DeadCount} || ${DeadCount}<=0) /return 
   /if (${Me.Combat}) /return 

   /if (!${Me.FreeInventory}) { 
      /beep 
      /echo ** INVENTORY FULL ! 
      /varset useAutoLoot FALSE 
      /echo ** AutoLooting is now OFF! 
      /goto :doneloot 
   }  

   /declare si int local 
   /varset CorpseList 
   /declare tempX ${Me.X} 
   /declare tempY ${Me.Y} 
   /declare tempHeading ${Me.Heading.DegreesCCW} 
    
   /for si 1 to ${DeadCount} 
      /call ListAppendElement CorpseList ${NearestSpawn[${si},corpse radius ${CorpseRadius} noalert ${CorpseAlertList}].ID} " " 
   /next si 
   /echo CorpseList ${CorpseList} 
   /if ( ${Me.Mount.ID} ) /dismount 
   /for si 1 to ${DeadCount} 
      /call Target "id ${CorpseList.Arg[${si}]}" 
      /if (${Target.Type.Equal[corpse]}) { 
          /if (${Target.Deity.ID}<>0) { 
             /squelch /aleart add ${CorpseAlertList} CORPSE "${Target.Name}" 
           } else { 
             /call MoveToSpawn ${Target.ID} 10 
             /call LootCorpse 
          } 
      } 
   /next si 
   /if (!${Target.ID}) { 
      /call MoveToLoc ${tempY} ${tempX} 
      /face fast heading ${tempHeading} 
      /delay 15 !${Me.Moving} 
   } 
 :doneloot 
/return