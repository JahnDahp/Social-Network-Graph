@echo off
IF NOT EXIST "vcpkg\bootstrap-vcpkg.bat" (
    git submodule update --init --recursive
)

CALL vcpkg\bootstrap-vcpkg.bat

cmake --preset windows-default
cmake --build --preset windows-default