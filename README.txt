BUILD INSTRUCTIONS

Install CMake -> https://cmake.org/download/

git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git submodule update --init --recursive
cmake --preset Default
cmake --build --preset Default --config Release
cd Bin
.\SocialNetwork.exe
