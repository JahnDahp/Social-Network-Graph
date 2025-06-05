BUILD INSTRUCTIONS

Install CMake -> https://cmake.org/download/

WINDOWS
git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
.\vcpkg.exe install
cd ..
cmake -S . -B Build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cd Build/Release
.\socialnetwork.exe

MAC / LINUX
git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install
cd ..
cmake -S . -B Build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build Build --config Release
cd Build/Release
./socialnetwork
