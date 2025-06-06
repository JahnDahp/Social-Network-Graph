BUILD INSTRUCTIONS

Install CMake -> https://cmake.org/download/
Install Ninja
Install MSVC Build Tools -> https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022

git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git submodule update --init --recursive
cmake --preset Default
cmake --build --preset Default --config Release
cd Bin
.\SocialNetwork.exe
