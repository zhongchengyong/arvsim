cmake_minimum_required(VERSION 3.19)
project(arvsim)

add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(arvsim main.cpp)