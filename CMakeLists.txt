cmake_minimum_required(VERSION 3.22)
project(PC_Winkle)

file(GLOB_RECURSE SRC
        src/*.h
        src/*.cpp
)

add_executable(PC_Winkle ${SRC}
        src/Components/ComponentBase.cpp
        src/Components/ComponentBase.h
        src/Components/GPU.cpp
        src/Components/GPU.h
        src/Filter.cpp
        src/Filter.h
        src/Components/CPU.cpp
        src/Components/CPU.h
        src/Components/Motherboard.cpp
        src/Components/Motherboard.h
        src/Components/Memory.cpp
        src/Components/Memory.h
        src/Components/Storage.cpp
        src/Components/Storage.h
        src/Components/PowerSupply.cpp
        src/Components/PowerSupply.h
        src/Components/Case.cpp
        src/Components/Case.h
        src/ComputerShop.cpp
        src/ComputerShop.h
        src/types.h
        src/Customer.cpp
        src/Customer.h
        src/Company.cpp
        src/Company.h
        src/Invoice.cpp
        src/Invoice.h
        src/Menus.h
        src/Menus.cpp
)
include_directories(src)