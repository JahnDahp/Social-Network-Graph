This is an interactive graphical represetation of a social network. Each node in the circle represents a user in the network, and each line between nodes is a connection.

Nodes can be clicked to isolate only the selected user and their connections. The network can also be modified in the console.

Features
--------
  - Selecting a node outputs the user's name and all connections in the console.
  - The user's ID is displayed next to each node
  - The network can be modified to add users, add connections, remove connections, and save data all within the console.
  - Exiting the program in the console allows the graph to be traversed again.
  - Navigate the graph with WASD, and zoom in/out with shift/space.

Build Instructions
--------
Requirements:
  - CMake
  - C++20 compiler (MSVC, GCC, or Clang). On Windows, this comes with Visual Studio or Build Tools for Visual Studio.

Run the bootstrap to generate in the executable in Bin. Run bootstrap.bat for windows, bootstrap.sh for MacOS/Linux.