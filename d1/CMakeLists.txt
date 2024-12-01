cmake_minimum_required(VERSION 3.30)
project(d1)

set(CMAKE_CXX_STANDARD 20)

add_executable(d1 
        main.cpp
        ../utils/utils.cpp
        ../utils/utils.h
)
