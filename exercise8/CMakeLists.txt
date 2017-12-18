cmake_minimum_required(VERSION 3.9)
project(exercise8)

set(CMAKE_CXX_STANDARD 11)

add_executable(exercise8 main.cpp Vector/Vector.cpp Vector/Vector.h Utils/Utils.cpp Utils/Utils.h Vector/SVector.cpp Vector/SVector.h)