cmake_minimum_required(VERSION 3.22)
project(PC_Winkle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

option(ENABLE_TEST "Enable test" OFF)

file(GLOB_RECURSE SRC
        src/*.h
        src/*.hpp
        src/*.cpp
)

add_executable(PC_Winkle ${SRC}
        src/Input.cpp
        src/CustomerProperties.cpp
        src/Enumerate.hpp)
target_include_directories(PC_Winkle PRIVATE src)

# test
if (ENABLE_TEST)
        set(test_SRCS
                src/CapString.hpp
                )
        find_package(GTest REQUIRED)
        add_executable(test test/test.cpp ${test_SRCS})
        target_include_directories(test PRIVATE test src)
        target_link_libraries(test GTest::GTest GTest::Main)
endif ()