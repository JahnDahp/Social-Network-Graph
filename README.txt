BUILD INSTRUCTIONS

Install CMake -> https://cmake.org/download/
Install Ninja -> https://github.com/ninja-build/ninja/releases

WINDOWS
Add ninja.exe to Windows Environment Varaibles Path if Ninja is not already installed.

git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
.\vcpkg.exe install
cd ..
cmake --preset x64-release-windows
cmake --build --preset x64-release-windows
cd Out/Build/Release/
.\socialnetwork.exe

MAC / LINUX
git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install
cd ..
cmake --preset x64-release
cmake --build --preset x64-release
cd Out/build/x64-release
./socialnetwork
