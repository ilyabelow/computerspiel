
# You are free to modify this file

cmake_minimum_required(VERSION 3.0)
project(computerspiel)
find_package(X11 REQUIRED)
set(CMAKE_CONFIGURATION_TYPES "Debug" "Release")
file(GLOB SRC *.cpp */*.cpp *.h)
add_executable(game ${SRC} render/Canvas.cpp render/Canvas.h render/Color.h entities/Entity.cpp entities/Entity.h math/Point.h math/Math.h entities/Player.cpp entities/Player.h math/Math.cpp entities/Particle.cpp entities/Particle.h entities/Bullet.cpp entities/Bullet.h utils/Clock.cpp utils/Clock.h)
target_link_libraries(game m X11)
