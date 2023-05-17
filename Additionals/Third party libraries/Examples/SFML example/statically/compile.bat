@echo off

set SFML_PATH=C:\Libraries\SFML
g++ main.cpp -I %SFML_PATH%\include -L %SFML_PATH%\lib -l sfml-graphics-s -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype -l winmm -l gdi32 -D SFML_STATIC -o main.exe
main.exe
del main.exe