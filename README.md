This is an interactive graphical represetation of a social network. Each node in the circle represents a user in the network, and each line between nodes is a connection.

Nodes can be clicked to isolate only the selected user and their connections. Clicking a selected node will reset the graph. The network can also be modified in the console.

Features
--------
  - Selecting a node outputs the user's name and all connections in the console.
  - The user's ID is displayed next to each node.
  - The network can be modified to add users, add connections, remove connections, and save data all within the console.
  - Exiting the program in the console allows the graph to be traversed again.
  - Navigate the graph with WASD, and zoom in/out with shift/space.

Code Details
--------
The social network uses an undirected graph to represent users and their connections.

Libraries used
  - [glew](https://github.com/nigels-com/glew) for loading OpenGL.
  - [glfw](https://github.com/StudioClockWork/GLFW) for creating the window.
  - [glm](https://github.com/g-truc/glm) for matrix operations.
  - [stb_image](https://github.com/nothings/stb) for image rendering.
  - [vcpkg](https://github.com/microsoft/vcpkg.git) for managing dependencies.

Build Instructions
--------
Requirements:
  - [CMake](https://cmake.org/)
  - C++20 compiler/build tools ([MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/), [GCC](https://gcc.gnu.org/install/), [Ninja](https://github.com/ninja-build/ninja), or [Clang](https://github.com/llvm/llvm-project/releases). On Windows, this comes with Visual Studio or Build Tools for Visual Studio.

Run the bootstrap to generate in the executable in Bin. Run bootstrap.bat for windows, bootstrap.sh for MacOS/Linux.
