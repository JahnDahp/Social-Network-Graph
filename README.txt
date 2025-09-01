BUILD INSTRUCTIONS

Make sure to have CMake and a C++20 compiler (MSVC, GCC, or Clang). On Windows, this comes with Visual Studio or Build Tools for Visual Studio.

git clone https://github.com/JahnDahp/SocialNetwork.git
cd SocialNetwork
git submodule update --init --recursive
cmake --preset Default
cmake --build --preset Default --config Release
cd Bin
.\SocialNetwork.exe
