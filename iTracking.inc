|==================================================================================================|
Sub Tracking

|-------------------------------------------------------
|-Read INI File:

/if (!${Ini[iTracking.ini,${Zone.ID},Enabled]}) {
	/Echo No tracking targets set for Zone ID ${Zone.ID} (${Zone.Name}).
	/Varset intTracking 0
} Else {
	/for intTrackNumber 1 to 19
		/if (${Bool[${Ini[iTracking.ini,${Zone.ID},Mob${intTrackNumber}]}]}) {
			/if (${intTrackReport}) {
				/echo Looking for ${Ini[iTracking.ini,${Zone.ID},Mob${intTrackNumber}]}.
			}
			/if (${SpawnCount[NPC ${Ini[iTracking.ini,${Zone.ID},Mob${intTrackNumber}]}]}) {
				/beep
				/delay 5
				/beep
				/delay 5
				/mapshow ${Ini[iTracking.ini,${Zone.ID},Mob${intTrackNumber}]}
				/g ${Ini[iTracking.ini,${Zone.ID},Mob${intTrackNumber}]} on track.
				/Varset intTracking 0
				/Varset intTrackReport 0
				/delay 1s
			}
		}
	/next intTrackNumber
}

/return
