cmake_minimum_required(VERSION 3.10)

# Project Name
project(vault)

# Use C++17 (can be changed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/lib)

# Add sources
add_executable(vault
src/main.cpp
src/cmd_parser.cpp
src/file_handler.cpp
)