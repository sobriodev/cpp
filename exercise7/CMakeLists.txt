cmake_minimum_required(VERSION 3.8)
project(exercise7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Complex.cpp Complex.h TabComplex.cpp TabComplex.h)
add_executable(exercise7 ${SOURCE_FILES})