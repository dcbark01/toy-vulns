# file: CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(StackOverflowExample)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectory for the actual project
add_subdirectory(src/tools/type-generator)
