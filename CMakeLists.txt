cmake_minimum_required(VERSION 3.22)
project(PC_Winkle)

file(GLOB_RECURSE SRC
        src/*.h
        src/*.cpp
)

add_executable(PC_Winkle ${SRC})
include_directories(src)