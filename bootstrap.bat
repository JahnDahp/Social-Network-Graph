@echo off
setlocal enabledelayedexpansion

REM Initialize submodules
git submodule update --init --recursive

REM Create build directory
if not exist Build mkdir Build
cd Build

REM Generate Visual Studio project (Release config)
cmake .. -DCMAKE_BUILD_TYPE=Release

REM Build the project
cmake --build . --config Release

endlocal
pause
