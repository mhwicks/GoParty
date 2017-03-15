
|==================================================================================================|
Sub DeclarePromise

/declare strPRTarget[3]		string	outer	NONE
/declare intPRTime[3]		int		outer 	0
/declare intPromisedHealth	int		outer	70

/return

|==================================================================================================|
|Promised Healing Code:
|---------------------------------------------------
Sub Promise

	|Check Timer Details:
	/for Looper 1 to 2
		|Check for outdated timers:
		/if (${intPRTime[${Looper}]} + 2 < ${Macro.RunTime}) {
			/varset strPRTarget[${Looper}] "NONE"
			/varset intPRTime[${Looper}] 0
		}

		|Work Active Timers by HealTarget:
		/if (${Spawn[${intHealTargetID}].Name.Equal[${strPRTarget[${Looper}]}]}) {
			|This person has the Promise on them
			/if (${intPRTime[${Looper}]} > 0) {
				|The timer is active
				/if (${Macro.RunTime} > ${intPRTime[${Looper}]}) {
					|Too late to heal
					/echo ${strPRTarget[${Looper}]} - Past Remedy Deadline.
					/varset intCastHeal 0
				}
			}
		}
	/next Looper

	|Needs a Promise Heal:
	/if (${intCastHeal}) {
		|/echo Promised Heal required, targeting #${intHealTargetID}.
		/target id ${intHealTargetID}
		/call Cast ${CLRpromise} gem2
		/varset intCastHeal 0
		
   		|Log Heals:	   		
		/mqlog HEALING ${Target.Name} WITH ${CLRpromise}.

		|/echo Heal complete - retargeting if needed.
		/squelch /target clear
		/if (${intRealMobID} > 0) /target id ${intRealMobID}
	}
	
	:SkipPromise
	/varset intJustHealed 1
	
/Return

