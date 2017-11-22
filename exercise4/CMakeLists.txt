cmake_minimum_required(VERSION 3.8)
project(exercise4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Array/Array.cpp src/Array/Array.h src/Utils/Utils.cpp src/Utils/Utils.h src/Array/operators.h src/Array/operators.cpp)
add_executable(exercise4 ${SOURCE_FILES})