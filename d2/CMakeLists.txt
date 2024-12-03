cmake_minimum_required(VERSION 3.30)
project(d2)

set(CMAKE_CXX_STANDARD 20)

add_executable(d2
        main.cpp
        ../utils/utils.cpp
        ../utils/utils.h
)
