BUILD INSTRUCTIONS

Install CMake -> https://cmake.org/download/

git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git clone https://github.com/microsoft/vcpkg.git
cmake --preset Release
cmake --build --preset Release
cd Bin
.\SocialNetwork.exe
