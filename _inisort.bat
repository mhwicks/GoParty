@echo off
xcopy "P:\Games\EverQuest\MacroQuest\Macros\iLoot.ini" "P:\Games\EverQuest\MacroQuest\Macros\iLoot.bak" /Y
cscript inisort.vbs "P:\Games\EverQuest\MacroQuest\Macros\iLoot.ini" Keepers
