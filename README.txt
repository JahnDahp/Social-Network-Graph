cd socialnetwork
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
.\vcpkg.exe install
cd ..
cmake -S . -B Build -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
cd Build/Release
.\socialnetwork.exe
