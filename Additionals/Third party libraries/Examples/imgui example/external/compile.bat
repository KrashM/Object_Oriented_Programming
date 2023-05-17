@echo off

set IMGUI_DIR=C:/Libraries/imgui

g++ main.cpp %IMGUI_DIR%/backends/imgui_impl_dx11.cpp %IMGUI_DIR%/backends/imgui_impl_win32.cpp %IMGUI_DIR%/imgui*.cpp -I %IMGUI_DIR% -I %IMGUI_DIR%/backends -ld3d11 -ld3dcompiler -lgdi32  -ldwmapi -o program.exe
program.exe
del program.exe