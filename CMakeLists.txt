cmake_minimum_required(VERSION 3.20)
project(SocialNetwork)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  "${CMAKE_SOURCE_DIR}/Bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/Bin/")

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

target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../Resources")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Source")
target_include_directories(SocialNetwork PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Include")

target_link_libraries(SocialNetwork PRIVATE GLEW::GLEW glfw glm::glm)
