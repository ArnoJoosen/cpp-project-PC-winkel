//
// Created by arno on 2/12/23.
//

#include "GPU.h"
#include "Input.h"
#include <utility>
#include <iostream>
#include <iomanip>

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
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter power: ";
    power = input<float>();
    std::cout << "Enter bus speed: ";
    busSpeed = input<float>();
    type = selectComputerType();
    return std::make_shared<GPU>(manufacturer, name, price, stock, ComponentType_t::GPU, type, componentID, power, busSpeed);
}

void GPU::printHeader(bool indexed) {
    // Print index column
    if (indexed)
        std::cout << std::setw(5) << "Index" << " | ";

    // Print header columns
    std::cout   << std::setw(10) << "ID" << " | "
                << std::setw(MAX_MANUFACTURER_LENGTH) << "Manufacturer" << " | "
                << std::setw(MAX_COMPONENT_NAME_LENGTH) << "Name" << " | "
                << std::setw(10) << "Price" << " | "
                << std::setw(10) << "Stock" << " | "
                << std::setw(11) << "Type" << " | "
                << std::setw(15) << "Computer Type" << " | "
                << std::setw(5) << "Power" << " | "
                << std::setw(5) << "Bus Speed" << " | " << std::endl;


    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+24, '-') << std::endl; // TODO add power and bus speed
    else
        std::cout << std::string(10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+21, '-') << std::endl; // TODO add power and bus speed
}

void GPU::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(5) << my_power << " | "
                << std::setw(5) << my_busSpeed << " | " << std::endl;
}

void GPU::update() {
    ComponentBase::update();
    std::cout << "Current power: " << my_power << std::endl;
    if (changeQuestion("Change power?")) {
        std::cout << "Enter new power: ";
        my_power = input<float>();
    }
    std::cout << "Current bus speed: " << my_busSpeed << std::endl;
    if (changeQuestion("Change bus speed?")) {
        std::cout << "Enter new bus speed: ";
        my_busSpeed = input<float>();
    }
}
