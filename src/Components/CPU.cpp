//
// Created by arno on 2/12/23.
//

#include "CPU.h"
#include <iostream>

CPU::CPU(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
         ComputerType_t computerType, unsigned int componentID, float clockSpeed, int coreCount, std::string socket) :
        ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
        my_clockSpeed(clockSpeed), my_coreCount(coreCount), my_socket(std::move(socket)){

}

std::shared_ptr<CPU> CPU::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    float clockSpeed;
    int coreCount;
    std::string socket;


    std::cout << "Enter manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cout << "Enter clock speed: ";
    std::cin >> clockSpeed;
    std::cout << "Enter core count: ";
    std::cin >> coreCount;
    std::cout << "Enter socket: ";
    std::cin >> socket;
    type = selectComputerType();
    return std::make_shared<CPU>(manufacturer, name, price, stock, ComponentType_t::CPU, type, componentID, clockSpeed, coreCount, socket);
}

void CPU::print() const {
    ComponentBase::print();
}

void CPU::update() {
    ComponentBase::update();
    ComponentBase::update();
    std::cout << "Current clock speed: " << my_clockSpeed << std::endl;
    if (changeQuestion("Change clock speed? ")) {
        std::cout << "Enter new clock speed: ";
        std::cin >> my_clockSpeed;
    }
    std::cout << "Current core count: " << my_coreCount << std::endl;
    if (changeQuestion("Change core count? ")) {
        std::cout << "Enter new core count: ";
        std::cin >> my_coreCount;
    }
    std::cout << "Current socket: " << my_socket.c_str() << std::endl;
    if (changeQuestion("Change socket? ")) {
        std::cout << "Enter new socket: ";
        std::cin >> my_socket;
    }
}
