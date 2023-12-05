//
// Created by arno on 2/12/23.
//

#include "Motherboard.h"
#include <iostream>

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
    std::cin >> manufacturer;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cout << "Enter socket: ";
    std::cin >> socket;
    std::cout << "Enter form factor: ";
    std::cin >> formFactor;
    std::cout << "Enter max memory slots: ";
    std::cin >> maxMemorySlots;
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
        std::cin >> my_socket;
    }
    std::cout << "Current form factor: " << my_formFactor << std::endl;
    if (changeQuestion("Change form factor?")) {
        std::cout << "Enter new form factor: ";
        std::cin >> my_formFactor;
    }
    std::cout << "Current max memory slots: " << my_maxMemorySlots << std::endl;
    if (changeQuestion("Change max memory slots?")) {
        std::cout << "Enter new max memory slots: ";
        std::cin >> my_maxMemorySlots;
    }
}
