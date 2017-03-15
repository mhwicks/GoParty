@echo off

echo =====
echo DJO-1
echo =====
xcopy *.mac "c:\program files\MQ2\Macros" /Y
xcopy *.inc "c:\program files\MQ2\Macros" /Y
xcopy *.ini "c:\program files\MQ2\Macros" /Y

echo =====
echo DJO-2
echo =====
Xcopy *.mac "\\djo-2\MQ2$\Macros" /Y
Xcopy *.inc "\\djo-2\MQ2$\Macros" /Y
Xcopy *.ini "\\djo-2\MQ2$\Macros" /Y

echo =====
echo DJO-3
echo =====
Xcopy *.mac "\\djo-3\MQ2$\Macros" /Y
Xcopy *.inc "\\djo-3\MQ2$\Macros" /Y
Xcopy *.ini "\\djo-3\MQ2$\Macros" /Y

echo =====
echo DJO-4
echo =====
Xcopy *.mac "\\djo-4\MQ2$\Macros" /Y
Xcopy *.inc "\\djo-4\MQ2$\Macros" /Y
Xcopy *.ini "\\djo-4\MQ2$\Macros" /Y

rem Pause