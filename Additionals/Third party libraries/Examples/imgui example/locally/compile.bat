@echo off

g++ main.cpp ./backends/imgui_impl_dx11.cpp ./backends/imgui_impl_win32.cpp ./imgui*.cpp -I . -I ./backends -ld3d11 -ld3dcompiler -lgdi32  -ldwmapi -o program.exe
program.exe
del program.exe