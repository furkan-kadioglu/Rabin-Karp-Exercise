cmake_minimum_required(VERSION 2.8)
project(project5)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -O2")

set(SOURCE_FILES main.cpp)
add_executable(project5 ${SOURCE_FILES})