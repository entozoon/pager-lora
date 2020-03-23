@echo off
.\fontconvert.exe .\nokiafc22.ttf 4 > nokia-myke.h

echo then shove it up in the src folders
echo BUT ALSO IT HAS INSANE HIDDEN CHARACTERS SO YOU MUST..
echo open it, save with encoding to like.. DOS CP437, then back to UTF-8
echo THEN ALSO
echo edit the very last value in the file from 11 to 9, because it's a better line height. #LuckyGuess

pause