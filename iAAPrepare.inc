
|==================================================================================================|
Sub DeclareAAPrepare
	
	/declare 	intPrepareNag		int 		outer 		0
	
/return

|==================================================================================================|
Sub AAPrepare

	/echo Preparing for something big!
	
	|Stop moving if you are:
	/keypress forward
	
	|Clerics
	/If (${Me.Class.ID} == 2) {
		|/call BuffHandlerAA "Forceful Rejuvenation" |Resets all AA Timers
		|/call BuffHandlerAA "Flurry of Life" |Increases Healing abilities for 60 seconds - Moved to iBurn.
		|/call BuffHandlerAA "Fundament: Second Spire of Divinity" |Increase Healing Ability
		/call BuffHandlerAA "Fundament: Third Spire of Divinity" |Increase Group Survivability
		/call BuffHandlerAA "Ward of Purity" |Creates a healing Ward
		/call BuffHandlerAA "Silent Casting" |Reduces hate on casting by 20% per rank
		/call BuffHandlerAA "Exquisite Benediction" |Creates a Ward that heals all around it
		/call BuffHandlerAA "Glyph of Lost Secrets" |Reduces mana on casting all but percentage or complete heals.
	}

	|Rangers
	/If (${Me.Class.ID} == 4) {
		|
	}
	
	|Mages
	/If (${Me.Class.ID} == 13) {
		|/call BuffHandlerAA "Forceful Rejuvenation" |Resets all AA Timers
		/call BuffHandlerAA "Fortify Companion" |Tough Pet
		/call BuffHandlerAA "Acute Focus of Arcanum" |Spells hit more often
		|/call BuffHandlerAA "Fundament: First Spire of the Elements" |Spell Crits
		/call BuffHandlerAA "Fundament: Second Spire of the Elements" |Pet proc
		|/call BuffHandlerAA "Fundament: Third Spire of the Elements" |Group DS
		/call BuffHandlerAA "Host in the Shell" |Pet Runes!
		/call BuffHandlerAA "Silent Casting" |Reduces hate on casting by 20% per rank
		/call BuffHandlerAA "Glyph of Frantic Infusion" |Increases Pet damage at an increasing rate
	}
	
	|Wizards
	/If (${Me.Class.ID} == 12) {
		|
	}

	|Bards
	/If (${Me.Class.ID} == 8) {
		|
	}

	/doevents flush
	
/return

