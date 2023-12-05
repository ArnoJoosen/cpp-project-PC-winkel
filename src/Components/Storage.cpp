//
// Created by arno on 2/12/23.
//

#include "Storage.h"
#include <iostream>

Storage::Storage(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
                 ComputerType_t computerType, unsigned int componentID, float speed, unsigned int size,
                 std::string slot) :
                 ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                 my_speed(speed), my_size(size), my_slot(std::move(slot)) {

}

std::shared_ptr<Storage> Storage::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    float speed;
    unsigned int size;
    std::string slot;

    std::cout << "Enter manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cout << "Enter speed: ";
    std::cin >> speed;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cout << "Enter slot: ";
    std::cin >> slot;
    type = selectComputerType();
    return std::make_shared<Storage>(manufacturer, name, price, stock, ComponentType_t::STORAGE, type, componentID,
                                     speed, size, slot);
}

void Storage::print() const {
    ComponentBase::print();
}

void Storage::update() {
    ComponentBase::update();
    std::cout << "current speed: " << my_speed << std::endl;
    if (changeQuestion("Change speed?")) {
        std::cout << "Enter new speed: ";
        std::cin >> my_speed;
    }
    std::cout << "current size: " << my_size << std::endl;
    if (changeQuestion("Change size?")) {
        std::cout << "Enter new size: ";
        std::cin >> my_size;
    }
    std::cout << "current slot: " << my_slot << std::endl;
    if (changeQuestion("Change slot?")) {
        std::cout << "Enter new slot: ";
        std::cin >> my_slot;
    }
}
