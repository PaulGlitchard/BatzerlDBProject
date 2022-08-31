# version 3.11 or later of CMake or needed later for installing GoogleTest
cmake_minimum_required(VERSION 3.11-3.18)

project(batzerlDB)

add_library(batzerlDB source/batzerlDB.cpp)

# PUBLIC needed to make both batzerlDB.cpp and batzerlDB library available elsewhere in project
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Tell compiler to use C++20 features. The code doesn't actually use any of them.
target_compile_features(batzerlDB PUBLIC cxx_std_20)