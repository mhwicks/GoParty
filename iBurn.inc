
|==================================================================================================|
Sub DeclareBurn

	/declare intBurn int outer 0
	/declare intDefaultSpellDelay 4
	/declare intBurnTime outer 4
	/declare intBurnNotice outer 0

/return

|==================================================================================================|
Sub BurnDown

	/if (!${intBurnNotice}) {
		/echo Burn them down!
		/varset intBurnNotice 1
	}	
	/varset Combating 1
	
	/if (${Target.Type.Equal[Corpse]}) {
		/target clear
		/varset intBurn 0
		/return
	}

	|Bards
	/If (${Me.Class.ID} == 8) {
		/if (${Me.Book[Song of Stone]}) {
			/call Cast "Song of Stone" alt
		}
	}

	|Clerics
	/If (${Me.Class.ID} == 2) {
		|Try them one at a time to prevent missing a heal!
		/if (${Me.AltAbilityReady[Flurry of Life]}) {
			|25% better heals for 60 seconds
			/call Cast "Flurry of Life" alt
			/return
		}
		/if (${Me.AltAbilityReady[Healing Frenzy]}) {
			|All heals are crits for a short time
			/call Cast "Healing Frenzy" alt
			/return
		}
		/if (${Me.AltAbilityReady[Celestial Rapidity]}) {
			|Reduces Healing Cast Time by 50% for 24 seconds.
			/call BuffHandlerAA "Celestial Rapidity"
			/return
		}
			
			
	}

	|Druids
	/If (${Me.Class.ID} == 6) {
		/if (${Me.Book[Spirits Nature]}) {
			/call Cast "Spirits Nature" alt
		}
	}

	|Enchanters
	/if (${Me.Class.ID} == 14) {
		/call Cast "Illusions of Grandeur" alt
	}
	
	|Mages
	/If (${Me.Class.ID} == 13) {
		/call Cast "Glyph of Frantic Infusion" alt

		||Frenzied Burnout (60)
		|/Alt Activate 60
		/call Cast "Frenzied Burnout" alt
		
		||Host of Elements (207)
		|/if ($Spell[Host of Elements].MyCastTime}
		|/Alt Activate 207
		/call Cast "Host of the Elements" alt
	
		||Servant of Ro (174)
		|/Alt Activate 174
		/call Cast "Servant of Ro" alt
		
		||Fire Core (621)
		|/Alt Activate 621
		/call Cast "Fire Core" alt
		
		/pet attack
	}
	
	|Rangers
	/If (${Me.Class.ID} == 4) {
		||Auspice of the Hunter (462)
		|/Alt Activate 462
		/call Cast "Auspice of the Hunter" alt
		
		/call Cast "Group Guardian of the Forest" alt

		||Guardian of the Forest (184)
		|/Alt Activate 184
		/call Cast "Guardian of the Forest" alt
		
		
		|Outrider's Accuracy (3804)
		/call Cast "Outrider's Accuracy" alt
		
		/call Cast "Pack Hunt" alt
		
		/call Cast "Protection of the Spirit Wolf" alt
	}
	
	|Shamen
	/If (${Me.Class.ID} == 10) {
		/if (${Me.Book[Spirit Call]}) {
			/call Cast "Spirit Call" alt
		}
	}

	|Wizards
	/if (${Me.Class.ID} == 12) /Call WizBurn

	/doevents flush
	
/return
