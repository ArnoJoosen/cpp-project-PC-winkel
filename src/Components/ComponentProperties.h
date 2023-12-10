//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_COMPONENTPROPERTIES_H
#define PC_WINKLE_COMPONENTPROPERTIES_H

#define MAX_COMPONENT_TYPE_LENGTH 12
#define MAX_COMPUTER_TYPE_LENGTH 15

enum class ComponentType_t {
    CPU = 1,
    GPU = 2,
    MOTHERBOARD = 3,
    RAM = 4,
    STORAGE = 5,
    PSU = 6,
    CASE = 7,
    UNKNOWN = 0,
};

const char* componentTypeToString(ComponentType_t type);
ComponentType_t selectComponentType();

enum class ComputerType_t {
    DESKTOP = 1,
    LAPTOP = 2,
    UNKNOWN = 0
};

const char* computerTypeToString(ComputerType_t type);
ComputerType_t selectComputerType();

#endif //PC_WINKLE_COMPONENTPROPERTIES_H
