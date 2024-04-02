# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1)

# Project's name
project(stringComps)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)

# Define the library
add_library(stringComps stringComps.cpp)

# Specify the include directory for the library
target_include_directories(stringComps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
