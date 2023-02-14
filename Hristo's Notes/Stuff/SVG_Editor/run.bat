@echo off
@echo Compiling the program!
g++ -o main.exe main.cpp src/*.cpp
@echo Executing the exe!
main.exe
@echo Deleting exe file!
del main.exe
@echo Finished!