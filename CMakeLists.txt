# version 3.11 or later of CMake needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(
    batzerlDB
    VERSION 0.1
    DESCRIPTION "CMake for batzerlDB")

add_subdirectory(batzerlDB)   # look in batzerlDB subdirectory for CMakeLists.txt to process
add_subdirectory(app)         # look in app subdirectory for CMakeLists.txt to process