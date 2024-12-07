cmake_minimum_required(VERSION 3.10)

# Project Name
project(cave_game)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Link the include directories
include_directories(include)

# Add the executable
add_executable(cave_game src/main.cpp)

# To add other source files:
# add_executable(cave_game src/main.cpp src/other.cpp)
