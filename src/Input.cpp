//
// Created by arno on 5/12/23.
//
#include "Input.h"
#include <limits>
#include <iostream>

bool inputInvalid() {
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
    }
    return false;
}