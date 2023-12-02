//
// Created by arno on 2/12/23.
//

#include "Storage.h"

Storage::Storage(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
                 ComputerType_t computerType, unsigned int componentID, float speed, unsigned int size,
                 std::string slot) :
                 ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                 my_speed(speed), my_size(size), my_slot(std::move(slot)) {

}
