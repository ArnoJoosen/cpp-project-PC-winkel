//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_COMPONENTPROPERTIES_H
#define PC_WINKLE_COMPONENTPROPERTIES_H

enum class ComponentType_t {
    CPU = 1,
    GPU = 2,
    MOTHERBOARD = 3,
    RAM = 4,
    STORAGE = 5,
    PSU = 6,
    CASE = 7,
    UNKNOWN = 0
};

enum class ComputerType_t {
    DESKTOP = 1,
    LAPTOP = 2,
    UNKNOWN = 0
};

#endif //PC_WINKLE_COMPONENTPROPERTIES_H
