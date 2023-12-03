cmake_minimum_required(VERSION 3.22)
project(PC_Winkle)

file(GLOB_RECURSE SRC
        src/*.h
        src/*.hpp
        src/*.cpp
)

add_executable(PC_Winkle ${SRC}
        src/ComponentView.cpp
        src/Components/ComponentProperties.h
        src/CustomerView.cpp
        src/CustomerView.h
        src/CustomerProperties.h)
target_include_directories(PC_Winkle PRIVATE src)

# test
set(test_SRCS
        src/CapString.hpp
        )
find_package(GTest REQUIRED)
add_executable(test test/test.cpp ${test_SRCS})
target_include_directories(test PRIVATE test src)
target_link_libraries(test GTest::GTest GTest::Main)