@echo off

rem Get the latest files to the PCs:
robocopy "\\nas1\public$\Games\EverQuest\MacroQuest\Macros" "C:\Program Files\MQ2\Macros" /XO
robocopy "\\nas1\public$\Games\EverQuest\MacroQuest\Macros" "C:\Users\doug_\Google Drive\Macros" /XO
robocopy "\\nas1\public$\Games\EverQuest\MacroQuest\Macros" "\\djo-2\MQ2$\Macros" /XO

rem Collect any .ini file updates from the PCs:
robocopy "C:\Program Files\MQ2\Macros" "\\nas1\public$\Games\EverQuest\MacroQuest\Macros" iLoot.ini /XO
robocopy "\\djo-2\MQ2$\Macros" "\\nas1\public$\Games\EverQuest\MacroQuest\Macros" iLoot.ini /XO

rem robocopy /?
rem Pause