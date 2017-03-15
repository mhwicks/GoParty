Sub DeclareBardSongs
|==================================================================================================|

/declare intSongLoop 		int 	outer 	0
/declare intNextSongTime 	int		outer	0

/declare intLastSongRest	int		outer	0
/declare intLastSongCombat	int		outer	0

/declare strCurrentSong		string	outer
/declare strLastSongRest	string	outer
/declare strLastSongCombat	string	outer

/return

|==================================================================================================|
Sub BardSongs
	/declare	intLocalDebug		int		local	0
	/if (${intLocalDebug} > 1) /echo Bard songs...
	
	|Drop out if you haven't fully begun the most recent song:
	/if (${Macro.RunTime} <= ${intNextSongTime}) /return
	
	/varset strLastSongCombat ""
	/stopsong

	|Determine next song in the set:
	/if (${strLastSongRest.Equal["${BRDregen}"]}) /varset strCurrentSong ${BRDinvis}
	/if (${strLastSongRest.Equal["${BRDinvis}"]}) /varset strCurrentSong ${BRDfood}
	/if (${strLastSongRest.Equal["${BRDfood}"]}) /varset strCurrentSong ${BRDregen}
	/if (${strLastSongRest.Length} < 5) /varset strCurrentSong ${BRDregen}

	/if (${intLocalDebug}) /echo I'm planning to sing ${strCurrentSong}
	
	/cast ${strCurrentSong}
	/delay 1 ${Me.Casting.ID}
	/varset strLastSongRest ${strCurrentSong}
	/varset intNextSongTime ${Math.Calc[${Me.Casting.MyCastTime.Float} + ${Macro.RunTime}]}
	
/return


|==================================================================================================|
Sub BardSongsCombat
	/declare	intLocalDebug		int		local	0
	/if (${intLocalDebug} > 1) /echo Bard COMBAT songs...
	
	|Drop out if you haven't fully begun the most recent song:
	/if (${Macro.RunTime} <= ${intNextSongTime}) /return
	
	/varset strLastSongRest ""
	/stopsong

	|Determine next song in the set:
	/if (${strLastSongCombat.Equal["${BRDregen}"]}) /varset strCurrentSong ${BRDresist}
	/if (${strLastSongCombat.Equal["${BRDresist}"]}) /varset strCurrentSong ${BRDburnout}
	/if (${strLastSongCombat.Equal["${BRDburnout}"]}) /varset strCurrentSong ${BRDfocus}
	/if (${strLastSongCombat.Equal["${BRDfocus}"]}) /varset strCurrentSong ${BRDnuke}
	/if (${strLastSongCombat.Equal["${BRDnuke}"]}) /varset strCurrentSong ${BRDabsorb}
	/if (${strLastSongCombat.Equal["${BRDabsorb}"]}) /varset strCurrentSong ${BRDsnare}
	/if (${strLastSongCombat.Equal["${BRDsnare}"]}) /varset strCurrentSong ${BRDregen}
	/if (${strLastSongCombat.Length} < 5) /varset strCurrentSong ${BRDresist}

	/if (${intLocalDebug}) /echo I'm planning to sing ${strCurrentSong}
	
	/cast ${strCurrentSong}
	/delay 1 ${Me.Casting.ID}
	/varset strLastSongCombat ${strCurrentSong}
	/varset intNextSongTime ${Math.Calc[${Me.Casting.MyCastTime.Float} + ${Macro.RunTime}]}
	

/return
