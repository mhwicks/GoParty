|==================================================================================================|
Sub Event_Parvus(EntireMessage, strSpeaker)

	|/echo ${EntireMessage}
	|/echo ${strSpeaker} Hailed Parvus.
	/if (!${Group.Leader.Name.Equal[${strSpeaker}]}) /return

	|Handle Parvus Quests:
	/echo Parvus Event Activated.
	
	|Remove Invis:
	/if (${Me.Buff[Shared Camouflage].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Shared Camouflage].ID}-1]}]} leftmouseup
	/delay 5
	
	|Hail Parvus:
	/target Parvus
	/delay 10

	/hail
	/delay 5
	
	/hail
	/delay 5

	|Get missions:
	/say Serpents
	/delay 5
	/say prepared
	/delay 5
	
	|Clear Windows:
	/KeyPress esc
	/KeyPress esc
	/KeyPress esc
	/KeyPress esc

	
	|Use Fire:
	/call cast "Fellowship Registration Insignia" item
	
	|End Macro:
	|/end
	
/return
