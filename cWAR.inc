|==================================================================================================|
|==================================================================================================|
|
|Warrior Specific inclusions!
|
|==================================================================================================|
|==================================================================================================|
Sub WARSetSpells

/return

|==================================================================================================|
Sub WARBuffCheck
	/call AreaTaunting
/return

|==================================================================================================|
Sub WIZAAPrepare
	
/return

|==================================================================================================|
|Fight Full
|==================================================================================================|
Sub WARFightFull
	/if (${Target.PctHPs} <= 99) /call WARFightAlways
	/if (${Target.PctHPs} >= ${intDDMin} && ${Target.PctHPs} <= ${intDDMax}) /call WARFightMiddle
	/if (${Target.PctHPs} <= 25) /call WARFightEnd
/return

|==================================================================================================|
Sub WARFightAlways
	/call AreaTaunting
/return

|==================================================================================================|
Sub WARFightMiddle

/return

|==================================================================================================|
Sub WARFightEnd

/return

|==================================================================================================|
Sub WARBurn

/return

|==================================================================================================|
Sub AreaTaunting
	|Boop some noses if there are enough of them:
	/if (${Me.XTarget} < 2) /return
	|/echo There are ${Me.XTarget} XTargets.
	
	/if (${SpawnCount[npc zradius 50 radius 50]} < 2) /return
	|/echo There are ${SpawnCount[npc zradius 50 radius 50]} mobs within 50 feet.
	
	/if (${Me.CombatAbilityReady[Stormstrike Blades]}) {
		/echo Wheeling Blades!
		/doability "Stormstrike Blades"
		/delay 3
	} else {
		/if (${SpawnCount[npc zradius 50 radius 30]} > 1) {
			|/echo There are ${SpawnCount[npc zradius 50 radius 30]} mobs within 30 feet.
			/if (${Me.CombatAbilityReady[Rallying Roar]}) {
				/echo Rallying Roar!
				/doability "Rallying Roar"
				/delay 3
			}
		}
	}

/return
