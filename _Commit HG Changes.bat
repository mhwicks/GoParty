@echo off

rem Update Mercurial Information:
hg commit

pause

rem Push to the Web Repository;
hg push http://mynetplanner.com/hg/Macros

echo '
echo See the following url for the full change information:
echo http://mynetplanner.com/hg/Macros

Pause