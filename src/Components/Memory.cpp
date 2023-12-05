//
// Created by arno on 2/12/23.
//

#include "Memory.h"
#include <iostream>

Memory::Memory(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
               ComputerType_t computerType, unsigned int componentID, unsigned int size, float clockSpeed) :
               ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
               my_size(size), my_clockSpeed(clockSpeed) {

}

std::shared_ptr<Memory> Memory::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    unsigned int size;
    float clockSpeed;

    std::cout << "Enter manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cout << "Enter size: ";
    std::cin >> size;
    std::cout << "Enter clock speed: ";
    std::cin >> clockSpeed;
    type = selectComputerType();


    return std::make_shared<Memory>(manufacturer, name, price, stock, ComponentType_t::RAM, type, componentID, size, clockSpeed);
}

void Memory::print() const {
    ComponentBase::print();
}

void Memory::update() {
    ComponentBase::update();
    std::cout << "Current size: " << my_size << std::endl;
    if (changeQuestion("Change size?")) {
        std::cout << "Enter new size: ";
        std::cin >> my_size;
    }
    std::cout << "Current clock speed: " << my_clockSpeed << std::endl;
    if (changeQuestion("Change clock speed?")) {
        std::cout << "Enter new clock speed: ";
        std::cin >> my_clockSpeed;
    }
}
