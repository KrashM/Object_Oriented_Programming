@echo off
g++ -o main.exe Program.cpp Models/*.cpp
main.exe
del main.exe