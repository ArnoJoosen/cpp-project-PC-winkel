//
// Created by arno on 2/12/23.
//

#include "Memory.h"

Memory::Memory(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
               ComputerType_t computerType, unsigned int componentID, unsigned int size, float clockSpeed) :
               ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
               my_size(size), my_clockSpeed(clockSpeed) {

}
