//
// Created by arno on 2/12/23.
//

#include "Memory.h"
#include <iostream>
#include "Input.h"

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
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter size: ";
    size = input<unsigned int>();
    std::cout << "Enter clock speed: ";
    clockSpeed = input<float>();
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
        my_size = input<unsigned int>();
    }
    std::cout << "Current clock speed: " << my_clockSpeed << std::endl;
    if (changeQuestion("Change clock speed?")) {
        std::cout << "Enter new clock speed: ";
        my_clockSpeed = input<float>();
    }
}
