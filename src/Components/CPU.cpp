//
// Created by arno on 2/12/23.
//

#include "CPU.h"

CPU::CPU(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
         ComputerType_t computerType, unsigned int componentID, float clockSpeed, int coreCount, std::string socket) :
        ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
        my_clockSpeed(clockSpeed), my_coreCount(coreCount), my_socket(std::move(socket)){

}

std::shared_ptr<CPU> CPU::Create(unsigned int componentID) {
    return std::shared_ptr<CPU>();
}
