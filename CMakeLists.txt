cmake_minimum_required(VERSION 3.22)
project(PC_Winkle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

option(ENABLE_TEST "Enable test" ON)

file(GLOB_RECURSE SRC
        src/*.h
        src/*.hpp
        src/*.cpp
)

add_executable(PC_Winkle ${SRC}
        src/Input.cpp
        src/CustomerProperties.cpp
        src/Enumerate.hpp
        src/FileSystem.h
        src/FileSystem.cpp)
target_include_directories(PC_Winkle PRIVATE src)

# test
if (ENABLE_TEST)
        file(GLOB_RECURSE test_SRCS
                src/*.h
                src/*.hpp
                src/*.cpp
        )
        get_filename_component(MAIN_FILE_ABSOLUTE "src/main.cpp" REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
        list(REMOVE_ITEM test_SRCS "${MAIN_FILE_ABSOLUTE}")

        find_package(GTest REQUIRED)
        add_executable(test test/test.cpp ${test_SRCS}
                test/SerializeTest.h
                test/DeserializeTest.h)
        target_include_directories(test PRIVATE test src)
        target_link_libraries(test GTest::GTest GTest::Main)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test_serialized)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/test_deserialized)
endif ()