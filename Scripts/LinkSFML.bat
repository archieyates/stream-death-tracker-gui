@echo off

set libs=%SFML%\3.0\Build\lib
set include=%SFML%\3.0\Source\SFML\include\SFML
set debug=%libs%\Debug
set release=%libs%\Release
set shared=%libs%\Shared

echo Copying Debug Libs
if not exist "../App/bin/sfml/lib/Debug/" mkdir ..\App\bin\sfml\lib\Debug
echo copying %debug%\sfml-window-s-d.lib
copy /d /b "%debug%\sfml-window-s-d.lib" "../App/bin/sfml/lib/Debug/sfml-window-s-d.lib"
echo copying %debug%\sfml-system-s-d.lib
copy /d /b "%debug%\sfml-system-s-d.lib" "../App/bin/sfml/lib/Debug/sfml-system-s-d.lib"
echo copying %debug%\sfml-graphics-s-d.lib
copy /d /b "%debug%\sfml-graphics-s-d.lib" "../App/bin/sfml/lib/Debug/sfml-graphics-s-d.lib"

echo Copying Release Libs
if not exist "../App/bin/sfml/lib/Release/" mkdir ..\App\bin\sfml\lib\Release
echo copying %release%\sfml-window-s.lib
copy /d /b "%release%\sfml-window-s.lib" "../App/bin/sfml/lib/Release/sfml-window-s.lib"
echo copying %release%\sfml-system-s.lib
copy /d /b "%release%\sfml-system-s.lib" "../App/bin/sfml/lib/Release/sfml-system-s.lib"
echo copying %release%\sfml-graphics-s.lib
copy /d /b "%release%\sfml-graphics-s.lib" "../App/bin/sfml/lib/Release/sfml-graphics-s.lib"

echo Copying Shared Libs
if not exist "../App/bin/sfml/lib/Shared/" mkdir ..\App\bin\sfml\lib\Shared
echo copying %shared%\freetype.lib
copy /d /b "%shared%\freetype.lib" "../App/bin/sfml/lib/Shared/freetype.lib"

echo copying Includes
xcopy /E /Y /I /D "%include%" "../App/source/Vendor/SFML"