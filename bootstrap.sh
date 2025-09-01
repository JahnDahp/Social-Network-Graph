set -e

git submodule update --init --recursive
cmake --preset Default
cmake --build --preset Default --config Release
