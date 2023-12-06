//
// Created by arno on 3/12/23.
//
#include "ComponentProperties.h"
#include <iostream>
#include "Input.h"

const char* componentTypeToString(ComponentType_t type) {
    switch (type) {
        case ComponentType_t::CPU:
            return "CPU";
        case ComponentType_t::MOTHERBOARD:
            return "Motherboard";
        case ComponentType_t::RAM:
            return "Memory";
        case ComponentType_t::GPU:
            return "GPU";
        case ComponentType_t::STORAGE:
            return "Storage";
        case ComponentType_t::PSU:
            return "PowerSupply";
        case ComponentType_t::CASE:
            return "Case";
        case ComponentType_t::UNKNOWN:
            return "Unknown";
    }
    throw std::runtime_error("Unknown component type");
}

ComponentType_t selectComponentType(){
    std::cout << "Select component type: \n"
              << "\t1. CPU\n"
              << "\t2. Motherboard\n"
              << "\t3. Memory\n"
              << "\t4. GPU\n"
              << "\t5. Storage\n"
              << "\t6. PowerSupply\n"
              << "\t7. Case\n" << std::endl;
    do {
        std::cout << "Enter choice: ";
        switch (inputRange(1, 7)) {
            case 1:
                return ComponentType_t::CPU;
            case 2:
                return ComponentType_t::MOTHERBOARD;
            case 3:
                return ComponentType_t::RAM;
            case 4:
                return ComponentType_t::GPU;
            case 5:
                return ComponentType_t::STORAGE;
            case 6:
                return ComponentType_t::PSU;
            case 7:
                return ComponentType_t::CASE;
        }
    } while (true);
}

const char* computerTypeToString(ComputerType_t type) {
    switch (type) {
        case ComputerType_t::DESKTOP:
            return "Desktop";
        case ComputerType_t::LAPTOP:
            return "Laptop";
        case ComputerType_t::UNKNOWN:
            return "Unknown";
    }
    throw std::runtime_error("Unknown computer type");
}

ComputerType_t selectComputerType(){
    std::cout << "Select computer type:\n"
              << "\t1. Desktop\n"
              << "\t2. Laptop\n" << std::endl;
    do {
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        std::cin.clear();
        switch (choice) {
            case 1:
                return ComputerType_t::DESKTOP;
            case 2:
                return ComputerType_t::LAPTOP;
        }
    } while (true);
}