//
// Created by arno on 2/12/23.
//

#include "Motherboard.h"

Motherboard::Motherboard(std::string manufacturer, std::string name, float price, unsigned int stock,
                         ComponentType_t type, ComputerType_t computerType, unsigned int componentID,
                         std::string socket, std::string formFactor, unsigned int maxMemorySlots) :
                         ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                         my_socket(std::move(socket)), my_formFactor(std::move(formFactor)), my_maxMemorySlots(maxMemorySlots){

}
