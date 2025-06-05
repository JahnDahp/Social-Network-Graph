cmake_minimum_required(VERSION 3.20)
project(SocialNetwork)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

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

set_target_properties(SocialNetwork PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Resources")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Source")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Include")

target_link_libraries(SocialNetwork PRIVATE GLEW::GLEW glfw glm::glm)
