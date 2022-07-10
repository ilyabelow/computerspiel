
# You are free to modify this file

cmake_minimum_required(VERSION 3.0)
project(computerspiel)
find_package(X11 REQUIRED)
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")
set (CMAKE_CXX_STANDARD 20)
file(GLOB SRC core/*.cpp entities/*/*.cpp math/*.cpp *.cpp utils/*.cpp render/*.cpp)
add_executable(game ${SRC})
target_link_libraries(game m X11)
