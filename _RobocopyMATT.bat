@echo off

rem Get the latest files to the PCs:
robocopy "c:\macros\macros" "c:\mq2\macros" /XO
robocopy "\\c:\macros\macros" "\\eq-cnote\MQ2\Macros" /XO
robocopy "\\c:\macros\macros" "\\eq-exxit\MQ2\Macros" /XO
robocopy "\\c:\macros\macros" "\\eq-sabby\MQ2\Macros" /XO
