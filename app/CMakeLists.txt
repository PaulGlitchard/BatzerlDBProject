# version 3.11 or later of CMake or needed later for installing GoogleTest
cmake_minimum_required(VERSION 3.11-3.18)

project(main)

add_executable(main main.cpp)
# We need batzerlDB.hpp and the batzerlDB library
target_link_libraries(main
    PRIVATE batzerlDB)

# Tell C++ compiler to use C++20 features. We don't actually use any of them.
target_compile_features(main PUBLIC cxx_std_20)