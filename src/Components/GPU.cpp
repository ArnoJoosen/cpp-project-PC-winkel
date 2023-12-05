//
// Created by arno on 2/12/23.
//

#include "GPU.h"

#include <utility>
#include <iostream>

GPU::GPU(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
         ComputerType_t computerType, unsigned int componentID, float power, float busSpeed) :
         ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
         my_power(power), my_busSpeed(busSpeed) {

}

std::shared_ptr<GPU> GPU::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    float power;
    float busSpeed;

    std::cout << "Enter manufacturer: ";
    std::cin >> manufacturer;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cout << "Enter power: ";
    std::cin >> power;
    std::cout << "Enter bus speed: ";
    std::cin >> busSpeed;
    type = selectComputerType();
    return std::make_shared<GPU>(manufacturer, name, price, stock, ComponentType_t::GPU, type, componentID, power, busSpeed);
}

void GPU::print() const {
    ComponentBase::print();
}

void GPU::update() {
    ComponentBase::update();
    std::cout << "Current power: " << my_power << std::endl;
    if (changeQuestion("Change power?")) {
        std::cout << "Enter new power: ";
        std::cin >> my_power;
    }
    std::cout << "Current bus speed: " << my_busSpeed << std::endl;
    if (changeQuestion("Change bus speed?")) {
        std::cout << "Enter new bus speed: ";
        std::cin >> my_busSpeed;
    }
}
