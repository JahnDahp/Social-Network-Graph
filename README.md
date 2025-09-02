This is an interactive graphical representation of a social network. Each node in the circle represents a user in the network, and each line between nodes is a connection.

![SN1](https://github.com/user-attachments/assets/8579b0a0-dd8a-4211-87a3-4d76bcf263cc)

Nodes can be clicked to isolate only the selected user and their connections. Clicking a selected node will reset the graph. The network can also be modified in the console.

![SN2](https://github.com/user-attachments/assets/d8c07921-8c5a-4801-abf0-d00b3f652dde)

Features
--------
  - Selecting a node outputs the user's name and all connections in the console.
  - The user's ID is displayed next to each node.
  - The network can be modified to add users, add connections, remove connections, and save data all within the console.
  - Exiting the program in the console allows the graph to be traversed again.
  - Navigate the graph with WASD, and zoom in/out with shift/space.

![SN3](https://github.com/user-attachments/assets/355ab275-8ce5-445f-b721-e45a90335677)

Code Details
--------
The social network uses an undirected graph to represent users and their connections.

Libraries used
  - [gl3w](https://github.com/skaslev/gl3w) for loading OpenGL.
  - [glfw](https://github.com/StudioClockWork/GLFW) for creating the window.
  - [glm](https://github.com/g-truc/glm) for matrix operations.
  - [stb_image](https://github.com/nothings/stb) for image rendering.

Build Instructions
--------
Requirements:
  - [CMake](https://cmake.org/)
  - C++20 compiler/build tools ([MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/), [GCC](https://gcc.gnu.org/install/), [Ninja](https://github.com/ninja-build/ninja), or [Clang](https://github.com/llvm/llvm-project/releases). On Windows, this comes with Visual Studio or Build Tools for Visual Studio.

Run `git clone --recursive https://github.com/JahnDahp/Social-Network-Graph/`.
Then `cd Social-Network-Graph && mkdir Build && cd Build && cmake .. -DCMAKE_BUILD_TYPE=Release && cmake --build . --config Release`.
