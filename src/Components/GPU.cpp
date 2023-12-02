//
// Created by arno on 2/12/23.
//

#include "GPU.h"

#include <utility>

GPU::GPU(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
         ComputerType_t computerType, unsigned int componentID, float power, float busSpeed) :
         ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
         my_power(power), my_busSpeed(busSpeed) {

}
