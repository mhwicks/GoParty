Sub DeclareBuffs
|==================================================================================================|

	/declare intBuffLoop 			int 	outer 	0
	/declare intDelayLoop 			int		outer	0
	/declare strCurrentSpell 		string	outer
	/declare CurrentVersion			string	outer
	/declare VersionSize			int		outer	0
	/declare BaseSpellSize			int		outer	0 
	/declare BaseSpell		   		string	outer 
	/declare strGroupSpell			string	outer	
	/declare intMemRetries			int		outer	0
	/declare intNextSinglesBuffTime int		outer	0
	/declare intSingleBuffTarget	int		outer 	0
	/declare intStackableSpell		int		outer	1
	/declare intBuffNag				int		outer	0
	/declare intAbilityCountdown	int		outer	0
	/declare strNewAA				string	outer	
	/declare strDOTList				string	outer
		
|==================================================================================================|
| BARD Declaration Section:

	/if (${Me.Class.ID} == 8) {
	|BRDregen:
		/declare BRDregen string outer
		/call SetTheSpell BRDregen
		/varset BRDregen ${Macro.Return}
	|BRDinvis:
		/declare BRDinvis string outer
		/call SetTheSpell BRDinvis
		/varset BRDinvis ${Macro.Return}
	|BRDfood:
		/declare BRDfood string outer
		/call SetTheSpell BRDfood
		/varset BRDfood ${Macro.Return}
	|BRDresist:
		/declare BRDresist string outer
		/call SetTheSpell BRDresist
		/varset BRDresist ${Macro.Return}
	|BRDburnout:
		/declare BRDburnout string outer
		/call SetTheSpell BRDburnout
		/varset BRDburnout ${Macro.Return}
	|BRDfocus:
		/declare BRDfocus string outer
		/call SetTheSpell BRDfocus
		/varset BRDfocus ${Macro.Return}
	|BRDnuke:
		/declare BRDnuke string outer
		/call SetTheSpell BRDnuke
		/varset BRDnuke ${Macro.Return}
	|BRDmez:
		/declare BRDmez string outer
		/call SetTheSpell BRDmez
		/varset BRDmez ${Macro.Return}
	|BRDsnare:
		/declare BRDsnare string outer
		/call SetTheSpell BRDsnare
		/varset BRDsnare ${Macro.Return}
	|BRDabsorb:
		/declare BRDabsorb string outer
		/call SetTheSpell BRDabsorb
		/varset BRDabsorb ${Macro.Return}
	|BRDcure:
		/declare BRDcure string outer
		/call SetTheSpell BRDcure
		/varset BRDcure ${Macro.Return}
		
	|Mem Important Spells:
		/call MemTheSpell 1 ${BRDregen}
		/call MemTheSpell 2 ${BRDinvis}
		/call MemTheSpell 3 ${BRDfood}
		/call MemTheSpell 4 ${BRDresist}
		/call MemTheSpell 5 ${BRDburnout}
		/call MemTheSpell 6 ${BRDfocus}
		/call MemTheSpell 7 ${BRDnuke}
		/call MemTheSpell 8 ${BRDmez}
		/call MemTheSpell 9 ${BRDsnare}
		/call MemTheSpell 10 ${BRDabsorb}
		/call MemTheSpell 11 ${BRDcure}

	}
		
	/if (${Me.Class.ID} == 2) {
	|CLRarm:
		/declare CLRarm string outer
		/call SetTheSpell CLRarm
		/varset CLRarm ${Macro.Return}
	|CLRhand:
		/declare CLRhand string outer
		/call SetTheSpell CLRhand
		/varset CLRhand ${Macro.Return}
	|CLRsymbol:
		/declare CLRsymbol string outer
		/call SetTheSpell CLRsymbol
		/varset CLRsymbol ${Macro.Return}
	|CLRhaste:
		/declare CLRhaste string outer
		/call SetTheSpell CLRhaste
		/varset CLRhaste ${Macro.Return}
	|CLRnuke:
		/declare CLRnuke string outer
		/call SetTheSpell CLRnuke
		/varset CLRnuke ${Macro.Return}
	|CLRquick:
		/declare CLRquick string outer
		/call SetTheSpell CLRquick
		/varset CLRquick ${Macro.Return}
	|CLRgroup:
		/declare CLRgroup string outer
		/call SetTheSpell CLRgroup
		/varset CLRgroup ${Macro.Return}
	|CLRcure:
		/declare CLRcure string outer
		/call SetTheSpell CLRcure
		/varset CLRcure ${Macro.Return}
	|CLRaura:
		/declare CLRaura string outer
		/call SetTheSpell CLRaura
		/varset CLRaura ${Macro.Return}
	|CLRauraeffect:
		/declare CLRauraeffect string outer
		/if (${CLRaura.Equal[""Aura of the Zealot""]}) /varset CLRauraeffect "Aura of the Zealot Effect"
		/if (${CLRaura.Equal[""Circle of Divinity Rk. II""]}) /varset CLRauraeffect "Divinity Effect"
		/if (${CLRaura.Equal[""Aura of Divinity""]}) /varset CLRauraeffect "Aura of Divinity Effect"
		/echo Cleric Aura: ${CLRaura}:${CLRauraeffect}
	|CLRaura2:
		/declare CLRaura2 string outer
		/call SetTheSpell CLRaura2
		/varset CLRaura2 ${Macro.Return}
	|CLRauraeffect2:
		/declare CLRauraeffect2 string outer
		/if (${CLRaura2.Equal[""Aura of the Zealot""]}) /varset CLRauraeffect2 "Aura of the Zealot Effect"
		/if (${CLRaura2.Equal[""Circle of Divinity Rk. II""]}) /varset CLRauraeffect2 "Divinity Effect"
		/if (${CLRaura2.Equal[""Aura of the Reverent""]}) /varset CLRauraeffect2 "Aura of the Reverent"
		/echo Cleric Aura2: ${CLRaura}:${CLRauraeffect}
	|CLRradiant:
		/declare CLRradiant string outer
		/call SetTheSpell CLRradiant
		/varset CLRradiant ${Macro.Return}
	|CLRvow:
		/declare CLRvow string outer
		/call SetTheSpell CLRvow
		/varset CLRvow ${Macro.Return}
	|CLRpromise:
		/declare CLRpromise string outer
		/call SetTheSpell CLRpromise
		/varset CLRpromise ${Macro.Return}
	|CLRvie:
		/declare CLRvie string outer
		/call SetTheSpell CLRvie
		/varset CLRvie ${Macro.Return}
	|CLRvieG:
		/declare CLRvieG string outer
		/call SetTheSpell CLRvieG
		/varset CLRvieG ${Macro.Return}
	|CLRmark:
		/declare CLRmark string outer
		/call SetTheSpell CLRmark
		/varset CLRmark ${Macro.Return}
	|CLRLastHope:
		/declare CLRLastHope string outer
		/call SetTheSpell CLRLastHope
		/varset CLRLastHope ${Macro.Return}
	|CLRpet:
		/declare CLRpet string outer
		/call SetTheSpell CLRpet
		/varset CLRpet ${Macro.Return}
	|CLRhot:
		/declare CLRhot string outer
		/call SetTheSpell CLRhot
		/varset CLRhot ${Macro.Return}
	|CLRlight:
		/declare CLRlight string outer
		/call SetTheSpell CLRlight
		/varset CLRlight ${Macro.Return}
	|CLRunity:
		/declare CLRunity string outer
		/call SetTheSpell CLRunity
		/varset CLRunity ${Macro.Return}
	|CLRunityeffect:
		/declare CLRunityeffect string outer
		/if (${CLRunity.Equal[""Unified Hand of Credence""]}) /varset CLRunityeffect "Blessing of Assurance"
		/if (${CLRunity.Equal[""Unified Hand of Certitude""]}) /varset CLRunityeffect "Blessing of Fervor"
		/if (${CLRunity.Equal[""Unified Hand of Surety""]}) /varset CLRunityeffect "Benediction of Piety"
		/echo Cleric Unity: ${CLRunity}:${CLRunityeffect}
		
	|Mem Important Spells:
		/call MemTheSpell 2 ${CLRpromise}
		/call MemTheSpell 3 ${CLRLastHope}
		/call MemTheSpell 5 ${CLRquick}
		/call MemTheSpell 11 ${CLRlight}
		/call MemTheSpell 12 ${CLRhot}

	}
	
|==================================================================================================|
| DRUID Declaration Section:

	/if (${Me.Class.ID} == 6) {
	|DRUheal:
		/declare DRUheal string outer
		/call SetTheSpell DRUheal
		/varset DRUheal ${Macro.Return}
	|DRUnukeFire:
		/declare DRUnukeFire string outer
		/call SetTheSpell DRUnukeFire
		/varset DRUnukeFire ${Macro.Return}
	|DRUnukeCold:
		/declare DRUnukeCold string outer
		/call SetTheSpell DRUnukeCold
		/varset DRUnukeCold ${Macro.Return}
	|DRUaura:
		/declare DRUaura string outer
		/call SetTheSpell DRUaura
		/varset DRUaura ${Macro.Return}
	|DRUauraEffect:
		/declare DRUauraEffect string outer
		/if (${DRUaura.Equal[""Aura of the Grove""]}) /varset DRUauraEffect "Aura of the Grove Effect"
		/echo Druid Aura: ${DRUaura}:${DRUauraEffect}
	|DRUdotWrath:
		/declare DRUdotWrath string outer
		/call SetTheSpell DRUdotWrath
		/varset DRUdotWrath ${Macro.Return}
	|DRUdotHorde:
		/declare DRUdotHorde string outer
		/call SetTheSpell DRUdotHorde
		/varset DRUdotHorde ${Macro.Return}
	|DRUdotCurse:
		/declare DRUdotCurse string outer
		/call SetTheSpell DRUdotCurse
		/varset DRUdotCurse ${Macro.Return}
	|DRUdebuff:
		/declare DRUdebuff string outer
		/call SetTheSpell DRUdebuff
		/varset DRUdebuff ${Macro.Return}
	|DRUsnare:
		/declare DRUsnare string outer
		/call SetTheSpell DRUsnare
		/varset DRUsnare ${Macro.Return}
	|DRUbramble:
		/declare DRUbramble string outer
		/call SetTheSpell DRUbramble
		/varset DRUbramble ${Macro.Return}
	|DRUskin:
		/declare DRUskin string outer
		/call SetTheSpell DRUskin
		/varset DRUskin ${Macro.Return}
	|DRUmana:
		/declare DRUmana string outer
		/call SetTheSpell DRUmana
		/varset DRUmana ${Macro.Return}
	|DRUregen:
		/declare DRUregen string outer
		/call SetTheSpell DRUregen
		/varset DRUregen ${Macro.Return}
	|DRUsuccor:
		/declare DRUsuccor string outer
		/call SetTheSpell DRUsuccor
		/varset DRUsuccor ${Macro.Return}

	|Mem Important Spells:
		/call MemTheSpell 1 ${DRUsnare}
		/call MemTheSpell 2 ${DRUheal}
		/call MemTheSpell 3 ${DRUnukeCold}
		/call MemTheSpell 4 ${DRUnukeFire}
		/call MemTheSpell 5 ${DRUdotHorde}
		/call MemTheSpell 6 ${DRUdotWrath}
		/call MemTheSpell 7 ${DRUdebuff}
		/call MemTheSpell 9 ${DRUdotCurse}
		/call MemTheSpell 10 ${DRUsuccor}
		
	}
	
|==================================================================================================|
| ENCHANTER Declaration Section:

	/if (${Me.Class.ID} == 14) {
	|ENCrune:
		/declare ENCrune string outer
		/call SetTheSpell ENCrune
		/varset ENCrune ${Macro.Return}
	|ENCruneeffect:
		/declare ENCruneeffect string outer
		/varset ENCruneeffect ${ENCrune}
		/if (${ENCrune.Equal[""Arcane Unity""]}) /varset ENCruneeffect "Polyarcanic Rune"
		/if (${ENCrune.Equal[""Phantasmal Unity""]}) /varset ENCruneeffect "Polyiridescent Rune"
		/if (${ENCrune.Equal[""Enticer's Unity""]}) /varset ENCruneeffect "Polyrefractive Rune"
		/echo Enchanter Rune: ${ENCrune}:${ENCruneeffect}

    |ENCgrouprune:
		/declare ENCgrouprune string outer
		/call SetTheSpell ENCgrouprune
		/varset ENCgrouprune ${Macro.Return}
    |ENCpet:
		/declare ENCpet string outer
		/call SetTheSpell ENCpet
		/varset ENCpet ${Macro.Return}
	|ENCspeed:
		/declare ENCspeed string outer
		/call SetTheSpell ENCspeed
		/varset ENCspeed ${Macro.Return}
	|ENCmana:
		/declare ENCmana string outer
		/call SetTheSpell ENCmana
		/varset ENCmana ${Macro.Return}
	|ENCshield:
		/declare ENCshield string outer
		/call SetTheSpell ENCshield
		/varset ENCshield ${Macro.Return}
	|ENCslow:
		/declare ENCslow string outer
		/call SetTheSpell ENCslow
		/varset ENCslow ${Macro.Return}
	|ENCresist:
		/declare ENCresist string outer
		/call SetTheSpell ENCresist
		/varset ENCresist ${Macro.Return}
	|ENCscarecrow:
		/declare ENCscarecrow string outer
		/call SetTheSpell ENCscarecrow
		/varset ENCscarecrow ${Macro.Return}
	|ENCnuke:
		/declare ENCnuke string outer
		/call SetTheSpell ENCnuke
		/varset ENCnuke ${Macro.Return}
	|ENCdebuff:
		/declare ENCdebuff string outer
		/call SetTheSpell ENCdebuff
		/varset ENCdebuff ${Macro.Return}
	|ENCillusion:
		/declare ENCillusion string outer
		/call SetTheSpell ENCillusion
		/varset ENCillusion ${Macro.Return}
	|ENCmez:
		/declare ENCmez string outer
		/call SetTheSpell ENCmez
		/varset ENCmez ${Macro.Return}
	|ENCaura:
		/declare ENCaura string outer
		/call SetTheSpell ENCaura
		/varset ENCaura ${Macro.Return}
	|ENCauraeffect:
		/declare ENCauraeffect string outer
		/if (${ENCaura.Equal[""Arctender's Aura""]}) /varset ENCauraeffect "Arctender's Aura Effect"
		/if (${ENCaura.Equal[""Mana Reiterate Aura""]}) /varset ENCauraeffect "Mana Reiterate"
		/if (${ENCaura.Equal[""Mana Reiteration Aura""]}) /varset ENCauraeffect "Mana Reiteration"
		/if (${ENCaura.Equal[""Mana Repercussion Aura""]}) /varset ENCauraeffect "Mana Repercussion"
		/if (${ENCaura.Equal[""Mana Reverberation Aura""]}) /varset ENCauraeffect "Mana Reverberation"
		/if (${ENCaura.Equal[""Mana Reciprocation Aura""]}) /varset ENCauraeffect "Mana Reciprocation"
		/echo Enchanter Aura: ${ENCaura}:${ENCauraeffect}
	|ENCaura2:
		/declare ENCaura2 string outer
		/call SetTheSpell ENCaura2
		/varset ENCaura2 ${Macro.Return}
	|ENCaura2effect:
		/declare ENCauraeffect2 string outer
		/if (${ENCaura2.Equal[""Twincast Aura""]}) /varset ENCauraeffect2 "Twincast Effect"
		/echo Enchanter Aura: ${ENCaura2}:${ENCauraeffect2}


	|Mem Important Spells:
		/call MemTheSpell 1 ${ENCspeed}
		/call MemTheSpell 2 ${ENCmana}
		/call MemTheSpell 3 ${ENCscarecrow}
		|/call MemTheSpell 4 ${ENCshield} Slot 4 used for general buffs.
		/call MemTheSpell 5 ${ENCslow}
		/call MemTheSpell 6 ${ENCrune}
		/call MemTheSpell 7 ${ENCnuke}
		/call MemTheSpell 8 ${ENCdebuff}
		/call MemTheSpell 9 ${ENCmez}
		/call MemTheSpell 10 ${ENCaura}
		/call MemTheSpell 11 ${ENCaura2}
		/call MemTheSpell 12 ${ENCgrouprune}

	}

|==================================================================================================|
|Mage Spells:

	/if (${Me.Class.ID} == 13) {

	|Damage Shield:
		/declare damageshield string outer
		/call SetTheSpell damageshield
		/varset damageshield ${Macro.Return}
	|Burnout:
		/declare burnout string outer
		/call SetTheSpell burnout
		/varset burnout ${Macro.Return}
	|Protect:
		/declare protect string outer
		/call SetTheSpell protect
		/varset protect ${Macro.Return}
	|Shield:
		/declare shield string outer
		/call SetTheSpell shield
		/varset shield ${Macro.Return}
	|Heal:
		/declare heal string outer
		/call SetTheSpell heal
		/varset heal ${Macro.Return}
	|Aura:
		/declare aura string outer
		/call SetTheSpell aura
		/varset aura ${Macro.Return}
	|Aura Effect:
		/declare auraeffect string outer
		|/call SetTheSpell auraeffect
		/varset auraeffect "${aura.Arg[1,"""]} Effect"
	|Bolt:
		/declare bolt string outer
		/call SetTheSpell bolt
		/varset bolt ${Macro.Return}
	|Nuke:
		/declare nuke string outer
		/call SetTheSpell nuke
		/varset nuke ${Macro.Return}
	|Elemental Form:
		/declare eleform string outer
		/call SetTheSpell eleform
		/varset eleform ${Macro.Return}
	|Block:
		/declare MAGblock string outer
		/call SetTheSpell MAGblock
		/varset MAGblock ${Macro.Return}
	|Bad-ass servant:
		/declare MAGservant string outer
		/call SetTheSpell MAGservant
		/varset MAGservant ${Macro.Return}
	|Mana Regen:
		/declare MAGsymbiosis string outer
		/call SetTheSpell MAGsymbiosis
		/varset MAGsymbiosis ${Macro.Return}
	|Mana Regen Recourse:
		/declare MAGsymbiosisRecourse string outer
		/varset MAGsymbiosisRecourse "${MAGsymbiosis.Arg[1,"""]} Recourse"
		/if (${MAGsymbiosis.Right[7].Equal[Rk. II"]}) {
			/varset MAGsymbiosisRecourse "${MAGsymbiosis.Left[${Math.Calc[${MAGsymbiosis.Length} - 7]}]}"
			/varset MAGsymbiosisRecourse "${MAGsymbiosisRecourse.Arg[1,"""]}Recourse Rk. II"
		}
		/if (${MAGsymbiosis.Equal[""Spectral Symbiosis Rk. II""]}) {
			/varset MAGsymbiosisRecourse "Spectral Symbiosis Recourse II"
		}
		/echo Setting MAGsymbiosisRecourse to ${MAGsymbiosisRecourse}
	|Area Effect Spell:
		/declare MAGAE string outer
		/call SetTheSpell MAGAE
		/varset MAGAE ${Macro.Return}
	|Pet:
		/declare MAGpet string outer
		/call SetTheSpell MAGpet
		/varset MAGpet ${Macro.Return}
	|Arms:
		/declare MAGarmaments string outer
		/call SetTheSpell MAGarmaments
		/varset MAGarmaments ${Macro.Return}
	|MAGbodyguard:
		/declare MAGbodyguard string outer
		/call SetTheSpell MAGbodyguard
		/varset MAGbodyguard ${Macro.Return}
	|MAGmany:
		/declare MAGmany string outer
		/call SetTheSpell MAGmany
		/varset MAGmany ${Macro.Return}

	|MAGsurge:
		/declare MAGsurge string outer
		/call SetTheSpell MAGsurge
		/varset MAGsurge ${Macro.Return}

	|Mem Important Spells:
		/call MemTheSpell 1 ${MAGpet}
		/call MemTheSpell 4 ${bolt}
		/call MemTheSpell 6 ${MAGblock}
		/call MemTheSpell 7 ${nuke}
		/call MemTheSpell 8 ${heal}
		/call MemTheSpell 9 ${MAGservant}
		/call MemTheSpell 10 ${MAGsurge}
		/call MemTheSpell 11 ${MAGmany}
		
	}	

|==================================================================================================|
| NECRO Declaration Section:
	/if (${Me.Class.ID} == 11) {

	|NECnuke:
		/declare NECnuke string outer
		/call SetTheSpell NECnuke
		/varset NECnuke ${Macro.Return}

	|NECdot1:
		/declare NECdot1 string outer
		/call SetTheSpell NECdot1
		/varset NECdot1 ${Macro.Return}
		
	}

|==================================================================================================|
|Ranger Spells:
	/if (${Me.Class.ID} == 4) {

	|RNGSpike:
		/declare RNGSpike string outer
		/call SetTheSpell RNGSpike
		/varset RNGSpike ${Macro.Return}
	|RNGConsume:
		/declare RNGConsume string outer
		/call SetTheSpell RNGConsume
		/varset RNGConsume ${Macro.Return}
	|RNGMana:
		/declare RNGMana string outer
		/call SetTheSpell RNGMana
		/varset RNGMana ${Macro.Return}
	|RNGSkin:
		/declare RNGSkin string outer
		/call SetTheSpell RNGSkin
		/varset RNGSkin ${Macro.Return}
	|RNGHail:
		/declare RNGHail string outer
		/call SetTheSpell RNGHail
		/varset RNGHail ${Macro.Return}
	|RNGSnare:
		/declare RNGSnare string outer
		/call SetTheSpell RNGSnare
		/varset RNGSnare ${Macro.Return}
	|RNGSnarl:
		/declare RNGSnarl string outer
		/call SetTheSpell RNGSnarl
		/varset RNGSnarl ${Macro.Return}
	|RNGStrength:
		/declare RNGStrength string outer
		/call SetTheSpell RNGStrength
		/varset RNGStrength ${Macro.Return}
	|RNGNuke:
		/declare RNGNuke string outer
		/call SetTheSpell RNGNuke
		/varset RNGNuke ${Macro.Return}
	|RNGheal:
		/declare RNGheal string outer
		/call SetTheSpell RNGheal
		/varset RNGheal ${Macro.Return}
	|RNGJolt:
		/declare RNGJolt string outer
		/call SetTheSpell RNGJolt
		/varset RNGJolt ${Macro.Return}
	|RNGJoltMelee:
		/declare RNGJoltMelee string outer
		/call SetTheSpell RNGJoltMelee
		/varset RNGJoltMelee ${Macro.Return}
	|RNGBlades:
		/declare RNGBlades string outer
		/call SetTheSpell RNGBlades
		/varset RNGBlades ${Macro.Return}
	|RNGJoltBuff:
		/declare RNGJoltBuff string outer
		/call SetTheSpell RNGJoltBuff
		/varset RNGJoltBuff ${Macro.Return}
	|RNGGuard:
		/declare RNGGuard string outer
		/call SetTheSpell RNGGuard
		/varset RNGGuard ${Macro.Return}
	|RNGCalled:
		/declare RNGCalled string outer
		/call SetTheSpell RNGCalled
		/varset RNGCalled ${Macro.Return}
	|RNGHailFocus:
		/declare RNGHailFocus string outer
		/call SetTheSpell RNGHailFocus
		/varset RNGHailFocus ${Macro.Return}

	|Mem Important Spells:
		/call MemTheSpell 1 ${RNGNuke}
		/call MemTheSpell 2 ${RNGGuard}
		/call MemTheSpell 3 ${RNGHail}
		/call MemTheSpell 7 ${RNGHailFocus}
		/call MemTheSpell 8 ${RNGheal}
		/call MemTheSpell 9 ${RNGCalled}
		/call MemTheSpell 10 ${RNGJolt}
		
	}

|==================================================================================================|
|Shaman Spells:

	/if (${Me.Class.ID} == 10) {

	|Heal:
		/declare SHMheal string outer
		/call SetTheSpell SHMheal
		/varset SHMheal ${Macro.Return}
	|Nuke:
		/declare SHMnuke string outer
		/call SetTheSpell SHMnuke
		/varset SHMnuke ${Macro.Return}
	|Hit Points:
		/declare SHMhits string outer
		/call SetTheSpell SHMhits
		/varset SHMhits ${Macro.Return}
	|Agility:
		/declare SHMagility string outer
		/call SetTheSpell SHMagility
		/varset SHMagility ${Macro.Return}
	|Regen:
		/declare SHMregen string outer
		/call SetTheSpell SHMregen
		/varset SHMregen ${Macro.Return}
	|Stamina:
		/declare SHMstamina string outer
		/call SetTheSpell SHMstamina
		/varset SHMstamina ${Macro.Return}
	|Pet:
		/declare SHMpet string outer
		/call SetTheSpell SHMpet
		/varset SHMpet ${Macro.Return}
	|SHMdotBlood:
		/declare SHMdotBlood string outer
		/call SetTheSpell SHMdotBlood
		/varset SHMdotBlood ${Macro.Return}
	|SHMdotNectar:
		/declare SHMdotNectar string outer
		/call SetTheSpell SHMdotNectar
		/varset SHMdotNectar ${Macro.Return}
	|SHMdotVenom:
		/declare SHMdotVenom string outer
		/call SetTheSpell SHMdotVenom
		/varset SHMdotVenom ${Macro.Return}
	|SHMdotCurse:
		/declare SHMdotCurse string outer
		/call SetTheSpell SHMdotCurse
		/varset SHMdotCurse ${Macro.Return}
	|SLOW:
		/declare SHMslow string outer
		/call SetTheSpell SHMslow
		/varset SHMslow ${Macro.Return}
	|Speed:
		/declare SHMspeed string outer
		/call SetTheSpell SHMspeed
		/varset SHMspeed ${Macro.Return}
	|Procs:
		/declare SHMproc string outer
		/call SetTheSpell SHMproc
		/varset SHMproc ${Macro.Return}
	|United Buffs:
		/declare SHMunity string outer
		/call SetTheSpell SHMunity
		/varset SHMunity ${Macro.Return}
		/declare SHMunityeffect string outer
		/call SetTheSpell SHMunityeffect
		/varset SHMunityeffect ${Macro.Return}

		|Mem Important Spells:
		/call MemTheSpell 1 ${SHMdotBlood}
		/call MemTheSpell 2 ${SHMdotNectar}
		/call MemTheSpell 3 ${SHMdotVenom}
		/call MemTheSpell 4 ${SHMdotCurse}
		/call MemTheSpell 5 ${SHMproc}
		/call MemTheSpell 6 ${SHMheal}
		/call MemTheSpell 7 ${SHMnuke}

		/call MemTheSpell 9 ${SHMunity}
		
	}

|==================================================================================================|
| WIZARD Declaration Section:

	/if (${Me.Class.ID} == 12) /call WIZSetSpells
	
/return


|==================================================================================================|
|Buff Checking Sections:
|==================================================================================================|

|==================================================================================================|
Sub CLRBuffCheck

	|Check Buffs:
	
|Unity Buff:
|--------------------------
	/if (${Spell[${CLRunityeffect}].Stacks[2]} && (${Me.Book[${CLRunity}]})) {
		/if (${Spell[${CLRunity}].Mana} < ${Me.CurrentMana}) {
	   		/Target myself
	   		/call Cast ${CLRunity} gem8
	   		/target clear
	   	}
	}

|Armor of the Sacred
	/call BuffHandler ${CLRarm} 4

|Hand of Tenacity
|--------------------------
	/call BuffHandler ${CLRhand} 8
	
|Symbol
|--------------------------
	/call BuffHandler ${CLRsymbol} 8

|Aura of Purpose
|--------------------------
	/call BuffHandler ${CLRhaste} 8

|Cure
|--------------------------
	/if (${Me.Buff[Wind of Tashanian for the dippy dog].ID}) {
	    /target myself
		/if (${Me.AltAbilityReady[${CLRradiant}]}) {
	    	/call Cast ${CLRradiant} alt
			/for intDelayLoop 1 to 30
				/delay 1
				/doevents
			/next intDelayLoop
		} else {
			/if (${Spell[${CLRcure}].Mana} < ${Me.CurrentMana}) {
		    	/call Cast ${CLRcure} gem10
		    }
	    }
	   /target clear
	}
	
|Cleric Aura
|--------------------------
	/if (!${Me.Song[${CLRauraeffect}].ID} && (${Me.Book[${CLRaura}]})) {
		/if (${Me.Book[${CLRaura}]}) {
			/if (${Spell[${CLRaura}].Mana} < ${Me.CurrentMana}) {
		   		/Target myself
		   		/call Cast ${CLRaura} gem4
		   		/target clear
		   	}
	   	}
	}

|Cleric Aura2
|--------------------------
	/if (${Me.AltAbility["Spirit Mastery"]}) {
		/if (!${Me.Song[${CLRauraeffect2}].ID} && (${Me.Book[${CLRaura2}]})) {
			/if (${Me.Book[${CLRaura2}]}) {
				/if (${Spell[${CLRaura2}].Mana} < ${Me.CurrentMana}) {
			   		/Target myself
			   		/call Cast ${CLRaura2} gem4
			   		/target clear
			   	}
		   	}
		}
	}

|Vie - Damage Absorber!
|--------------------------
	/call BuffHandler ${CLRvieG} 10
	
|Vie for singles
|--------------------------
	/call SinglesBuffs ${CLRvie} 10 ${CLRvieG}
	
|Buy AAs
|--------------------------
	|/call BuyAA "Glyph of Lost Secrets"

/return


|==================================================================================================|
Sub DRUBuffCheck

	|Check Buffs:

|Druid Aura
|--------------------------
	/if (!${Me.Song[${DRUauraEffect}].ID}) {
		/if (${Me.Book[${DRUaura}]}) {
			/if (${Spell[${DRUaura}].Mana} < ${Me.CurrentMana}) {
		   		/Target myself
		   		/call Cast ${DRUaura} gem8
		   		/target clear
		   	}
	   	}
	}
	
|DRUbramble
|--------------------------
	/call BuffHandler ${DRUbramble} 8

|DRUskin
|--------------------------
	/call BuffHandler ${DRUskin} 8

|DRUmana
|--------------------------
	/call BuffHandler ${DRUmana} 8

|DRUregen
|--------------------------
	/call BuffHandler ${DRUregen} 8

	
/return

	
|==================================================================================================|
Sub ENCBuffCheck

|Pet
	/if (!${Me.Pet.ID}) {
		/call BuffHandler ${ENCpet} 4
	}

|Mana
	/call BuffHandler ${ENCmana} 2
	/if (${Spell[${ENCmana}].Stacks[2]}) /return

|Speed
	/call BuffHandler ${ENCspeed} 1

|Shield
	|/call BuffHandler ${ENCshield} 4
	/if (!${Me.Buff[Shield of Dreams].ID}) /call BuffHandler ${ENCshield} 4

|Resists
	/call BuffHandler ${ENCresist} 4
	
|ENCillusion
	|remove boring Enchanter Illusion:
	|/call BuffHandler ${ENCillusion} 4

|Scarecrow
|--------------------------
	/if (${Me.SpellReady[${ENCscarecrow}]} && !${Target.ID}) {
		|/target clear
		/for intBuffLoop 0 to ${Group.Members} 
	    	/if (${Group.Member[${intBuffLoop}].ID} && ${Group.Member[${intBuffLoop}].Pet.ID}) {
	      		/if (!${Group.Member[${intBuffLoop}].Pet.Race.Name.Equal[Scarecrow]} && !${Group.Member[${intBuffLoop}].Pet.Race.Name.Equal[Werewolf]} && !${Group.Member[${intBuffLoop}].Pet.Race.Name.Equal[Samhain]} && !${Group.Member[${intBuffLoop}].Pet.Race.Name.Equal[Bixie]}) {
	      			/if (${Group.Member[${intBuffLoop}].Pet.Distance} <= 80) {
						/if (!${Group.Member[${intBuffLoop}].Pet.Name.Left[1].Equal[#]}) {
							/target id ${Group.Member[${intBuffLoop}].Pet.ID}
		      				/delay 9
		      			}
					}
	      		}
	      	}
		/next intBuffLoop  
		/if (${Target.ID}) {
			|-/g %t is about to be a Scarecrow...
	   		/call Cast ${ENCscarecrow} gem3 0
			/target clear
		}	   
	} else {
		/if (!${Me.Gem[${ENCscarecrow}]} && ${Me.Book[${ENCscarecrow}]}) {
			/echo Memming ${ENCscarecrow}.
			/memspell 3 ${ENCscarecrow}
		}
	}

|Enchanter Aura
|--------------------------
	/if (!${Me.Song[${ENCauraeffect}].ID} && (${Me.Book[${ENCaura}]})) {
		/if (${Me.Book[${ENCaura}]}) {
			/if (${Spell[${ENCaura}].Mana} < ${Me.CurrentMana}) {
		   		/Target myself
		   		/call Cast ${ENCaura} gem10
		   		/target clear
		   		
		   		|Ugly hack to prevent casting again (and again) while it primes:
		   		/echo Waiting 9 seconds for this Aura to prime.
		   		/delay 9s
		   	}
	   	}
	}

|Enchanter Aura 2 (Auroria Mastery AA Required)
|--------------------------
	/if (${Me.AltAbility["Auroria Mastery"]} > 0) {
		/if (!${Me.Song[${ENCauraeffect2}].ID} && (${Me.Book[${ENCaura2}]})) {
			/if (${Me.Book[${ENCaura2}]}) {
				/if (${Spell[${ENCaura2}].Mana} < ${Me.CurrentMana}) {
			   		/Target myself
			   		/call Cast ${ENCaura2} gem11
			   		/target clear
			   	}
		   	}
		}
	}

/return

|==================================================================================================|
Sub ENCRuneCheck

|RUNE!
|--------------------------
	|/call BuffHandler ${ENCrune} 6
	|/if (!${Me.Buff[Spectral Rune].ID}) /call BuffHandler ${ENCrune} 6
	
	|Unity Rune Buff:
|--------------------------
	/if (${Spell[${ENCruneeffect}].Stacks[2]} && (${Me.Book[${ENCrune}]})) {
		/if (${Spell[${ENCrune}].Mana} < ${Me.CurrentMana}) {
	   		/Target myself
	   		/call Cast ${ENCrune} gem6
	   		/target clear
	   	}
	}

/return

|==================================================================================================|
Sub MAGBuffCheck

	|Check Buffs:
	
	|/rem ${Spell[${SpellName}].Stacks[2]} - 2 ticks are left on a buff that stacks with it.  :)
	|/if (!${Me.Buff[${WIZmana}].ID}) {

|Elemental Form: Fire/Water
|--------------------------
	|Change to Fire at high mana (80+):
	/if (${Me.PctMana} > 80) {
		/if (!${Me.Buff[Elemental Form: Fire].ID} || ${Me.Buff[Al'Kabor's Permanent Aura].ID}) {
			/if (${Me.AltAbilityReady[Elemental Form: Fire]}) {
				|/if (${Me.Buff[Elemental Form: Water].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Elemental Form: Water].ID}-1]}]} leftmouseup
				/if (${Me.Buff[Elemental Form: Water].ID}) / ${Me.Buff[Elemental Form: Water].Remove}
				|/if (${Me.Buff[Cloak of Quills Rk. II].ID}) /notify BuffWindow Buff${Int[${Math.Calc[${Me.Buff[Cloak of Quills Rk. II].ID}-1]}]} leftmouseup
				/if (${Me.Buff[Cloak of Quills Rk. II].ID}) / ${Me.Buff[Cloak of Quills Rk. II].Remove}
				/call BuffHandlerAA "Elemental Form: Fire"
			}
		}
	}
	
	|Change to Water at low mana:
	/if (${Me.PctMana} < 50) {
		/if (!${Me.Buff[Elemental Form: Water].ID}) {
			/if (${Me.AltAbilityReady[Elemental Form: Water]}) {
				/if (${Me.Buff[Elemental Form: Fire].ID}) {
					/ ${Me.Buff[Elemental Form: Fire].Remove}
					/call BuffHandlerAA "Elemental Form: Water"
				}
			}
		}
	}
	
|Protection Buff
|--------------------------
	/call BuffHandler ${protect} 5

|Damage Shield
|--------------------------
	/if (${Spell[${damageshield}].Stacks[2]}) {
		/if (${Spell[${damageshield}].Mana} < ${Me.CurrentMana}) {
			|Randomize casting based on mana to prevent doublecasting if there are other mages near:
			/if ((${Me.PctMana} > ${Math.Rand[100]}) || (${SpawnCount[radius 100 pc class magician]} < 2)) {
				/if (${Me.Level} > 74) /g Group DS incoming!
				/call BuffHandler ${damageshield} 3
			 	/target clear
			} else {
				/echo No damage shield right now.
				/for Looper 1 to 10
					/doevents
					/if (${Target.ID}) /varset Looper 10
					/delay 1
				/next Looper
			}
		}
	}

|PET Damage Shield
|--------------------------
	|PET:
	|Only worry about this if you do not have pet affinity:
	/if (!${Me.AltAbility[Pet Affinity]}) {
		/if ((!${Me.PetBuff[${damageshield}]}) && (!${Me.PetBuff[Circle of Lavaskin]})&& (!${Me.PetBuff[Circle of Magmaskin]}) && (!${Me.PetBuff[Circle of Brimstoneskin]})) {
		   /Target ${Me.Pet.CleanName}
		   /call Cast ${damageshield} gem3 0
		   /target clear
		}
	}

|Burnout
|--------------------------
	/call PetBuffHandler ${burnout} 2

|PET Aura
|--------------------------
	|PET:
	/if (!${Me.PetBuff[${auraeffect}]}) {
		/call PetBuffHandler ${aura} 3
	}

|Mana Conversion (Symbiosis)
|--------------------------
	/if (${Spell[${MAGsymbiosisRecourse}].Stacks[2]}) {
		/call BuffHandler ${MAGsymbiosis} 3
	}
	
|PET Block
|--------------------------
	/call PetBuffHandler ${MAGblock} 6

|Arcane Shield
|--------------------------
	/if (!${Me.Buff[Shield of Dreams].ID}) /call BuffHandler ${shield} 3

|MAGbodyguard
|--------------------------
	/call BuffHandler ${MAGbodyguard} 3
	
|MAGsurge - Massive DS
|--------------------------
	/call PetBuffHandler ${MAGsurge} 10
	

|Buy Frantic Infusion	
|--------------------------
	/if (${Me.AAPointsSpent} > 9500) {
		/if (${Me.AAPoints} > 98) {
			/if (!${Me.AltAbilityReady[Glyph of Frantic Infusion]}) {
				/call cast "Glyph of Frantic Infusion" alt

				/mqlog "Buying Glyph of Frantic Infusion."
				|Buy Frantic Infustion:
				|Open Window:
				/windowstate AAWindow open
				/delay 5
				|Select Tab "Special":
				/notify AAWindow AAW_Subwindows tabselect 4
				/delay 5
				|Select "Frantic Infusion":
				|/notify AAWindow AAW_SpecialList listselect 9
				/nomodkey /notify AAWindow AAW_SpecialList listselect ${Window[AAWindow].Child[AAW_SpecialList].List[=Glyph of Frantic Infusion]} 
				/nomodkey /notify AAWindow AAW_SpecialList leftmouse ${Window[AAWindow].Child[AAW_SpecialList].List[=Glyph of Frantic Infusion]} 
				/delay 2s
				|Press the "Train" button:
				/notify AAWindow AAW_TrainButton leftmouseup
				/delay 5
				|Say "Yes" you are sure:
				/notify ConfirmationDialogBox Yes_Button leftmouseup
				/delay 5
				|Close Window:
				/windowstate AAWindow close
			}
		}
	}

/Return

|==================================================================================================|
Sub RNGBuffCheck


	|Check Buffs:

|Mana
|--------------------------
	/call BuffHandler ${RNGMana} 4

|Spikes
|--------------------------
	/call BuffHandler ${RNGSpike} 5

|Snarl
|--------------------------
	/call BuffHandler ${RNGSnarl} 5

|Strength
|--------------------------
	/call BuffHandler ${RNGStrength} 5

|Hunt
|--------------------------
	/call BuffHandler ${RNGConsume} 5
|	/if (${Spell[${RNGConsume}].Stacks[2]}) {
|		/if (${Zone.ID} != 72) {
|			|Spell Does not work in FEAR.
|		   /Target myself
|		   /call Cast ${RNGConsume} gem5 0
|		   |/delay 1
|		   /target clear
|		}
|	}

|Skin
|--------------------------
	/call BuffHandler ${RNGSkin} 5

|Blades
|--------------------------
	/if (${intMelee}) {
		/if (${intTank}) {
			|Keep Aggro:
			/call BuffHandler ${RNGBlades} 4
		} else {
			|Reduce Aggro:
			/call BuffHandler ${RNGJoltBuff} 4
		}
	}
|Guard for singles
|--------------------------
	/call SinglesBuffs ${RNGGuard} 2 ${RNGGuard}
	
|Check Harmonious Arrow Timer:
	/if (${Me.AltAbilityTimer[Harmonious Arrow]}) {
		/if  (${Me.AltAbilityTimer[Harmonious Arrow]} != ${intAbilityCountdown}) {
			/echo Harmonious in ${Me.AltAbilityTimer[Harmonious Arrow]} ticks.
			/varset intAbilityCountdown ${Me.AltAbilityTimer[Harmonious Arrow]}
		}
	}


/return


|==================================================================================================|
Sub SHMBuffCheck

|Check Buffs:

|Pet Creation:
|--------------------------
	/if (!${Me.Pet.ID}) {
		/if (${Spell[${SHMpet}].Mana} < ${Me.CurrentMana}) {
		   	/Target myself
		   	/call Cast ${SHMpet} gem8 0
		   	/target clear
		}
	}

|Unity Buff:
|--------------------------
	/if (${Spell[${SHMunityeffect}].Stacks[2]} && (${Me.Book[${SHMunity}]})) {
		/if (${Me.Book[${SHMunity}]}) {
			/if (${Spell[${SHMunity}].Mana} < ${Me.CurrentMana}) {
		   		/Target myself
		   		/call Cast ${SHMunity} gem9
		   		/target clear
		   	}
	   	}
	}

|Hit Points Buff:
|--------------------------
	/if (!${Me.Book[${SHMunity}]}) {
		/call BuffHandler ${SHMhits} 8
	}

|Agility Buff:
|--------------------------
	/call BuffHandler ${SHMagility} 8

|Regen Buff:
|--------------------------
	/call BuffHandler ${SHMregen} 8

|Stamina Buff:
|--------------------------
	/call BuffHandler ${SHMstamina} 8

|Haste:
|--------------------------
	/call BuffHandler ${SHMspeed} 8

/return


|==================================================================================================|
| Reads the Spell from the appropriate INI file
|==================================================================================================|
Sub SetTheSpell

	|/echo Running SetTheSpell on ${Param0}
	/varset Looper 0
	:TryNextSpell
	/varcalc Looper ${Looper} + 1
	/varset strCurrentSpell "${Ini[iBuffs.ini,${Me.Class},${Param0}].Arg[${Looper},|]}"
	|/echo Try number ${Looper} of ${Math.Calc[${Ini[iBuffs.ini, ${Me.Class}, ${Param0}].Count[|]} + 1]} is ${strCurrentSpell}.
	|/if (!${Me.Book[${strCurrentSpell}]} && ${Looper} < ${Math.Calc[${Ini[iBuffs.ini,${Me.Class},${Param0}].Count[|]} + 1]}) /goto :TryNextSpell
	/if (${Me.Book[${strCurrentSpell}]}) {
		/echo Setting ${Param0} to ${strCurrentSpell} (option # ${Looper}).
		/varset Looper ${Math.Calc[${Ini[iBuffs.ini,${Me.Class},${Param0}].Count[|]} + 1]}
	}

	|AA Override section:
	/if (${Me.AltAbility["${Ini[iBuffs.ini,${Me.Class},${Param0}].Arg[${Looper},|]}"]} > 0) {
		/varset strCurrentSpell "${Ini[iBuffs.ini,${Me.Class},${Param0}].Arg[${Looper},|]}"
		/varset ${Param0} "${strCurrentSpell}"
		/echo AA Override: setting ${Param0} to AA ${strCurrentSpell}.
		/varset Looper ${Math.Calc[${Ini[iBuffs.ini,${Me.Class},${Param0}].Count[|]} + 1]}
	}
	/if (${Looper} < ${Math.Calc[${Ini[iBuffs.ini,${Me.Class},${Param0}].Count[|]} + 1]}) /goto :TryNextSpell
	|/delay 1

/return ${strCurrentSpell}

|==================================================================================================|
| Mems important Spells into the Correct Gem
|==================================================================================================|
Sub MemTheSpell

	/echo MemTheSpell - Gem: ${Param0}; Spell: ${Param1}
	
	/if (${Param1.Equal[Null]}) /return
	
	/if (!${Me.Book[${Param1}]}) /return
	
	/if (!${Me.Gem[${Param1}]}) {
		/delay 1
		/memspell ${Param0} "${Param1}"
		/delay 5s
	}

/return ${strCurrentSpell}

|==================================================================================================|
| Super Buff Handler!
|==================================================================================================|
Sub BuffHandler
	/declare	intLocalDebug		int		local	0

	|/echo Running BuffHandler on ${Param0} for gem ${Param1}
	/varset strCurrentSpell "${Param0}"
	/if (${intLocalDebug}) /echo Checking Buff: ${strCurrentSpell}.
	/if (${strCurrentSpell.Equal["NULL"]}) /return
	
	|Look for base spell
	/call GetBaseSpell
	/if (${intLocalDebug}) /echo Found base buff: ${BaseSpell}.

	/if (!${Spell[${strCurrentSpell}].Stacks[2]}) /return
	/if (!${Spell[${BaseSpell}].Stacks[2]}) /return
	/if (${intLocalDebug}) /echo Base buff stacks: ${BaseSpell}.
		
	|Check for AA version first:
	/if (${Me.AltAbility[${strCurrentSpell}]}) {
		/if (${intLocalDebug}) /echo I have an AA version of ${strCurrentSpell}.
		/if (${Me.AltAbilityReady[${strCurrentSpell}]}) {
			/target myself
			/call Cast ${strCurrentSpell} alt
			/squelch /target clear
		} else {
			/if (!${intBurn}) /echo ${strCurrentSpell} is not quite ready.
		}
	} else {

		|Revert to regular Spell:
		:BuffHandlerRetry
		/if (${Me.SpellReady[${strCurrentSpell}]}) {
			/if (${intLocalDebug}) /echo ${strCurrentSpell} is ready to cast...
			/if (${Spell[${strCurrentSpell}].Mana} < ${Me.CurrentMana}) {
				/if (${intLocalDebug}) /echo I have enough mana to cast ${strCurrentSpell}, casting...
				/target myself
				/call Cast ${strCurrentSpell} gem${Param1} 0
				/target clear
			}
		} else {
			|The spell is not memmed:
			/if (!${Me.Gem[${strCurrentSpell}]}) {
				/if (${intLocalDebug}) /echo ${strCurrentSpell} needs to be memmed into slot ${Param1}...
				/if (${Me.Book[${strCurrentSpell}]}) {
					|/echo ${strCurrentSpell} is in your book, memming now...
					/if (${Spell[${strCurrentSpell}].Mana} < ${Me.CurrentMana}) {
						/memspell ${Param1} ${strCurrentSpell}
						/varset intMemRetries 0
						:BuffHandlerMemTime
						/delay 1d
						/doevents
						/varcalc intMemRetries ${intMemRetries} +1
						/if (${intMemRetries} > 200) /return
						/if (!${Me.SpellReady[${strCurrentSpell}]}) {
							/goto :BuffHandlerMemTime
						}
						/goto :BuffHandlerRetry
					}
				}
			}
		}
		}
/return

|==================================================================================================|
| Super Buff Handler for AAs!
|==================================================================================================|
Sub BuffHandlerAA

	|/echo Running BuffHandlerAA on ${Param0}.
	/varset strCurrentSpell "${Param0}"
	
	/if (${Me.AltAbility[${strCurrentSpell}]}) {
		/if (${Me.AltAbilityReady[${strCurrentSpell}]}) {
			/target myself
			/call Cast ${strCurrentSpell} alt
			/squelch /target clear
		} else {
			/if (!${intBurn}) /echo ${strCurrentSpell} is not quite ready.
		}
	} else {
		/echo I don't have ${strCurrentSpell} yet.
	}
/return

|==================================================================================================|
| Super Buff Handler for Pets!
|==================================================================================================|
Sub PetBuffHandler

	/declare	intLocalDebug		int		local	0
	
	/if (${intLocalDebug}) /echo Running BuffHandler on ${Param0} for gem ${Param1}
	/varset strCurrentSpell "${Param0}"

	|Look for base spell
	/call GetBaseSpell

	/if (${Me.PetBuff[${strCurrentSpell}]}) /return
	/if (${Me.PetBuff[${BaseSpell}]}) /return

	/if (${intLocalDebug}) /echo ${strCurrentSpell} stacks...
	
	|Check for AA version first:
	/if (${Me.AltAbility[${strCurrentSpell}]}) {
		/echo I have an AA version of ${strCurrentSpell}.
		/if (${Me.AltAbilityReady[${strCurrentSpell}]}) {
			|/target ${Me.Pet.CleanName}
			/target id ${Me.Pet.ID}
			/call Cast ${strCurrentSpell} alt
			/squelch /target clear
		} else {
			/if (!${intBurn}) /echo ${strCurrentSpell} is not quite ready.
		}
		/return
	}
		
	:BuffHandlerRetry
	/if (${Me.SpellReady[${strCurrentSpell}]}) {
		/echo ${strCurrentSpell} is ready to cast...
		/if (${Spell[${strCurrentSpell}].Mana} < ${Me.CurrentMana}) {
			/echo I have enough mana to cast ${strCurrentSpell}, casting...
			|/target ${Me.Pet.CleanName}
			/target id ${Me.Pet.ID}
			/call Cast ${strCurrentSpell} gem${Param1} 0
			/squelch /target clear
		}
	} else {
		|The spell is not memmed:
		/if (!${Me.Gem[${strCurrentSpell}]}) {
			/if (${intLocalDebug}) /echo ${strCurrentSpell} needs to be memmed into slot ${Param1}...
			/if (${Me.Book[${strCurrentSpell}]}) {
				/echo ${strCurrentSpell} is in your book, memming now...
				/memspell ${Param1} ${strCurrentSpell}
				/varset intMemRetries 0
				:BuffHandlerMemTime
				/delay 1
				/doevents
				/varcalc intMemRetries ${intMemRetries} +1
				/if (${intMemRetries} > 200) /return
				/if (!${Me.SpellReady[${strCurrentSpell}]}) {
					/goto :BuffHandlerMemTime
				}
				/goto :BuffHandlerRetry
			}
		}
	}

/return

|==================================================================================================|
| Super Buff Handler - for Singles!
|==================================================================================================|
Sub SinglesBuffs

	|Don't Run this too frequently:
	/if (${Macro.RunTime} > ${intNextSinglesBuffTime}) {
		/if (!${Target.ID} && !${Me.XTarget}) {
			/varset strCurrentSpell "${Param0}"
			/varset strGroupSpell "${Param2}"
			/if (${Spell[${strGroupSpell}].Mana} < ${Me.CurrentMana}) {
				/echo Checking the group for ${strCurrentSpell}...
				/varset intSingleBuffTarget 0
			
				|Check The players first:
				/for intBuffLoop 0 to ${Group.Members} 
					/squelch /target clear
					/delay 2
					/target id ${Group.Member[${intBuffLoop}].ID}
					/call WaitForTarget
					/call CheckTargetBuffs

					/if (!${intSingleBuffTarget}) {
					
						|Check the pet action:
						/if (${Target.Pet.ID}) {
							/squelch /target clear
							/delay 2
							/target id ${Group.Member[${intBuffLoop}].Pet.ID}
							/call WaitForTarget
							|Some pet types can't be buffed.  If zero buffs, let's assume this is one:
							|Zero buffs broke - familiars names start with '#' so:
							/if (!${Target.Name.Left[1].Equal[#]}) {
								/call CheckTargetBuffs
							}
						}
					}
				/next intBuffLoop
				/squelch /target clear
				
				|Check for spell Aplication:
				/if (${intSingleBuffTarget}) {
					/target id ${intSingleBuffTarget}
					|/echo Casting ${strCurrentSpell} on ${Target.CleanName}.
					/if (${Target.Distance} < ${Spell[${strCurrentSpell}].MyRange}) {
	 					/call Cast ${strCurrentSpell} gem${Param1} 0
	 				} else {
	 					/echo ${Target.CleanName} needs ${strCurrentSpell}, but is too far away.
						/if (${Macro.RunTime} > ${intBuffNag}) {
							/varcalc intBuffNag ${Macro.RunTime} + ${Math.Calc[60*2]}
		 					/g Once ${Target.CleanName} is in range, I'll give ${strCurrentSpell}.
		 				}
	 				}
					/squelch /target clear
			
				} else {
					|/echo Nobody needed a singleton buff this time around.
					/varcalc intNextSinglesBuffTime ${Macro.RunTime} + 600
				}
			}
		}
	}
	
/return

|==================================================================================================|
Sub CheckTargetBuffs
	/declare	intLocalDebug		int		local	0

	/if (${Target.Type.Equal[Corpse]}) /return
	|Check for the real spell or it's group equivalent:
	/if (${intLocalDebug}) {
		/echo Current: ${Spell[${strCurrentSpell}].Name}
		/echo Group:   ${Spell[${strGroupSpell}].Name}
	}
	/if (!${Target.Buff[${strCurrentSpell}].ID} && !${Target.Buff[${strGroupSpell}].ID}) {
		|Check the actual buff stacks:
		|/echo EVALUATING ${strCurrentSpell}
		/varset intStackableSpell 1
		/for Looper 1 to ${Target.BuffCount}
			|Does it stack?
			/if (${Target.Buff[${Looper}].WillStack[${strCurrentSpell}]}) {
				|/echo ${Target.Buff[${Looper}].Name} = stacks
			} else {
				|/echo - ${Target.Buff[${Looper}].Name} = NO STACKY!
				/varset intStackableSpell 0
			}
		/next Looper
		/if (${intStackableSpell}) {
			|/echo ${Target.CleanName} needs some ${strCurrentSpell} action.
			/varset intSingleBuffTarget ${Target.ID}
			/varset intBuffLoop ${Group.Members}
		}
	}

/return

|==================================================================================================|
Sub BuyAA

	/varset strNewAA "${Param0}"

	|Buy Selected EXPENDABLE AA	
	|--------------------------
	
	/if (${Me.AAPointsSpent} > 2500) {
		/if (${Me.AAPoints} > 28) {
			/if (!${Me.AltAbilityReady[${strNewAA}]}) {

				/echo Buying ${strNewAA}.
				/mqlog "Buying ${strNewAA}."
				|Open Window:
				/windowstate AAWindow open
				/delay 5
				|Select Tab "Special":
				/notify AAWindow AAW_Subwindows tabselect 4
				/delay 5
				|Select correct Expendable AA:
				/nomodkey /notify AAWindow AAW_SpecialList listselect ${Window[AAWindow].Child[AAW_SpecialList].List[${strNewAA}]} 
				/nomodkey /notify AAWindow AAW_SpecialList leftmouse ${Window[AAWindow].Child[AAW_SpecialList].List[${strNewAA}]} 
				/delay 2s
				|Press the "Train" button:
				/notify AAWindow AAW_TrainButton leftmouseup
				/delay 5
				|Say "Yes" you are sure:
				/notify ConfirmationDialogBox Yes_Button leftmouseup
				/delay 5
				|Close Window:
				/windowstate AAWindow close
			}
		}
	}
	
/return

|==================================================================================================|
Sub DOTHandler
	/declare	intLocalDebug		int		local	0

	/varset strCurrentSpell "${Param0}"
	/if (${intLocalDebug}) /echo Handling DOT ${strCurrentSpell}
	
	|Drop out if Clericing!
	/if (${intJustHealed}) /return
	
	|Drop out if I just did a DOT:
	/if (${intDotTime} > ${Macro.RunTime}) /return
	
	|Drop out if killing too fast for DOT to be effective:
	/if (${intKillRate} > (${Target.PctHPs} * 4)) {
		/if (${intLocalDebug}) /echo Kill Rate: ${intKillRate}% versus health: ${Math.Calc[${Target.PctHPs} * 4]}%
		/if (${intLocalDebug}) /echo This rate is too fast to warrant another DOT.
		/return
	}
	
	|Require Group Leadership Ability "Inspect Buffs" at level 2 to DOT:
	/if (${Me.LAInspectBuffs} < 2) {
		|Manually track DOTs for Leadership Cheapskates:
		/if (${strDOTList.Find[${strCurrentSpell}]}) {
			/if (${intLocalDebug}) /echo Found ${strCurrentSpell} in ${strDOTList}
			/return
		}
	} else {
		|Drop out if they already have said DOT:
		/if (${Target.Buff[${strCurrentSpell}].ID}) /return
	}
	
	|Cast the DOT if ready:
	/if (${Me.SpellReady[${strCurrentSpell}]}) {
		/call cast ${strCurrentSpell}
		/varcalc intDotTime ${Macro.RunTime} + ${Math.Calc[${Spell[${strCurrentSpell}].MyCastTime.Float} + 2]}
		/varset strDOTList ${strDOTList}${strCurrentSpell}|
	}
	
/return

|==================================================================================================|
Sub GetBaseSpell
	|Look for base spell, check for versions:
	/declare	intLocalDebug		int		local	0

	/if (${intLocalDebug}) /echo Evaluating base version of ${strCurrentSpell}.
	/varset Looper 0
	:TryNextVersion
	/varcalc Looper ${Looper} + 1
	/varset CurrentVersion ${Ini[iBuffs.ini,Versions,Ranks].Arg[${Looper},|]}
	/if (${intLocalDebug}) /echo Searching for <${CurrentVersion}> in ${strCurrentSpell}.
	/if (${strCurrentSpell.Find[${CurrentVersion}]}) {
		/if (${intLocalDebug}) /echo Found string ${CurrentVersion}.
		/if (${intLocalDebug}) /echo strCurrentSpell length is ${strCurrentSpell.Length}
		/varset VersionSize ${Math.Calc[${CurrentVersion.Length} +3]}
		/if (${intLocalDebug}) /echo VersionSize is ${VersionSize}
		/varset BaseSpellSize ${Math.Calc[${strCurrentSpell.Length} - ${VersionSize}]}
		/if (${intLocalDebug}) /echo BaseSpellSize is ${BaseSpellSize}
		/varset BaseSpell ${strCurrentSpell.Mid[2,${BaseSpellSize}]}
		/if (${intLocalDebug}) /echo BaseSpell is *${BaseSpell}*

		/if (${intLocalDebug}) /echo Current Spell Active: ${Me.PetBuff[${strCurrentSpell}]}
		/if (${intLocalDebug}) /echo Base Spell Active: ${Me.PetBuff[${BaseSpell}]}

		/return
	}

	|Not found, look for next:
	/if (${intLocalDebug}) /echo Looper: ${Looper}, Parameters: ${Math.Calc[${Ini[iBuffs.ini,Versions,Ranks].Count[|]} + 1]}
	/if (${Looper} < ${Math.Calc[${Ini[iBuffs.ini,Versions,Ranks].Count[|]} + 1]}) /goto :TryNextVersion
	/if (${intLocalDebug}) /echo Version not found, returning full name as base.
	/varset BaseSpell ${strCurrentSpell}
	
/return

|==================================================================================================|
Sub WaitForTarget
	/declare	intLocalDebug		int		local	0
	/for Looper 1 to 10
		/doevents
		/if (${intLocalDebug}) /echo ${Target.CleanName} has ${Target.BuffCount} buffs.
		/if (${Target.BuffCount} > 0) /varset Looper 10
		/delay 1
	/next Looper
	/if (${intLocalDebug}) {
		/echo ${Target.CleanName} has ${Target.BuffCount} buffs.
		/if (!${Target.ID}) /echo No target acquired.
	}
/return

|==================================================================================================|
Sub GroupRune
	/declare	intLocalDebug		int		local	0

	|Only group Rune for named:
	/if (!${Target.Named}) /return
	|Check group for runes, if anyone needs it, let's roll:
	/varset intRunedFolks 0
	/if (${intLocalDebug}) /echo Checking the group for spell ${ENCgrouprune}
	/if (${intLocalDebug}) /echo Group Rune Stack:
	/for intRuneLoop 1 to ${Group.Members}
		/squelch /target clear
		/delay 2
		/target id ${Group.Member[${intRuneLoop}].ID}
		/call WaitForTarget
		/if (${intLocalDebug}) /echo ${Group.Member[${intRuneLoop}].Name}, ${Target.Buff[${ENCgrouprune}].ID}
		/if (!${Target.Buff[${ENCgrouprune}].ID}) {
			/varset intRuneLoop 9
			/varset intRunedFolks 1
		}
	/next intRuneLoop
	/if (${intRunedFolks}) {
		/echo Group rune faded, casting!
		/mqlog "Casting ${ENCgrouprune}."
		/call Cast ${ENCgrouprune} gem12 0
	}
/return

