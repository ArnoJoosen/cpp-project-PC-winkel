//
// Created by arno on 2/12/23.
//

#include "Motherboard.h"
#include <iostream>
#include "Input.h"

Motherboard::Motherboard(std::string manufacturer, std::string name, float price, unsigned int stock,
                         ComponentType_t type, ComputerType_t computerType, unsigned int componentID,
                         std::string socket, std::string formFactor, unsigned int maxMemorySlots) :
                         ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                         my_socket(std::move(socket)), my_formFactor(std::move(formFactor)), my_maxMemorySlots(maxMemorySlots){

}

std::shared_ptr<Motherboard> Motherboard::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    std::string socket;
    std::string formFactor;
    unsigned int maxMemorySlots;

    std::cout << "Enter manufacturer: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter socket: ";
    std::getline(std::cin,socket);
    std::cout << "Enter form factor: ";
    std::getline(std::cin, formFactor);
    std::cout << "Enter max memory slots: ";
    maxMemorySlots = input<unsigned int>();
    type = selectComputerType();
    return std::make_shared<Motherboard>(manufacturer, name, price, stock, ComponentType_t::MOTHERBOARD, type, componentID, socket, formFactor, maxMemorySlots);
}

void Motherboard::print() const {
    ComponentBase::print();
}

void Motherboard::update() {
    ComponentBase::update();
    std::cout << "Current socket: " << my_socket << std::endl;
    if (changeQuestion("Change socket?")) {
        std::cout << "Enter new socket: ";
        std::getline(std::cin, my_socket);
    }
    std::cout << "Current form factor: " << my_formFactor << std::endl;
    if (changeQuestion("Change form factor?")) {
        std::cout << "Enter new form factor: ";
        std::getline(std::cin, my_formFactor);
    }
    std::cout << "Current max memory slots: " << my_maxMemorySlots << std::endl;
    if (changeQuestion("Change max memory slots?")) {
        std::cout << "Enter new max memory slots: ";
        my_maxMemorySlots = input<unsigned int>();
    }
}
