@echo off

set SFML_PATH=C:\Libraries\SFML
g++ main.cpp -I %SFML_PATH%\include -L %SFML_PATH%\lib -l sfml-graphics -l sfml-window -l sfml-system -o bin\main.exe
bin\main.exe
del bin\main.exe