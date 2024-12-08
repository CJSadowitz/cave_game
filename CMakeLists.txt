cmake_minimum_required(VERSION 3.10)

# Project Name
project(cave_game)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Link the include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(glfw3 REQUIRED)
find_package(Vulkan REQUIRED)

# Add the executable
add_executable(cave_game src/main.cpp src/Game.cpp)
target_link_libraries(cave_game glfw Vulkan::Vulkan)

# To add other source files:
# add_executable(cave_game src/main.cpp src/other.cpp)
