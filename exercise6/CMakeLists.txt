cmake_minimum_required(VERSION 3.8)
project(exercise6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp String/String.cpp String/String.h Utils/Utils.cpp Utils/Utils.h Operators/operators.cpp)
add_executable(exercise6 ${SOURCE_FILES})