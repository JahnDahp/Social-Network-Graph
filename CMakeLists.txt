cmake_minimum_required(VERSION 3.20)
project(SocialNetwork)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/")

add_subdirectory("Dependencies/glfw")
add_subdirectory("Dependencies/glm")
add_subdirectory("Dependencies/gl3w")

add_executable(SocialNetwork 
	"Main.cpp" 
	"Source/IndexBuffer.cpp"
	"Source/Renderer.cpp"
	"Source/Shader.cpp"
	"Source/VertexArray.cpp"
	"Source/VertexBuffer.cpp"
	"Source/Network.cpp"
	"Source/User.cpp"
	"Source/Connection.cpp"
	"Source/Number.cpp" 
	"Source/Texture.cpp" 
	"Source/Exit.cpp" 
	"Source/Console.cpp"
	"Source/SocialNetwork.cpp")

target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Source")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Include")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Resources")

target_link_libraries(SocialNetwork PRIVATE gl3w glfw glm::glm)
