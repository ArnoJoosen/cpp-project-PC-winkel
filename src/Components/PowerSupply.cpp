//
// Created by arno on 2/12/23.
//

#include "PowerSupply.h"
#include <iostream>

PowerSupply::PowerSupply(std::string manufacturer, std::string name, float price, unsigned int stock,
                         ComponentType_t type, ComputerType_t computerType, unsigned int componentID, float power,
                         std::string certification) : ComponentBase(std::move(manufacturer), std::move(name), price,
                                                                    stock, type, computerType, componentID),
                                                      my_power(power), my_certification(std::move(certification)) {

}

std::shared_ptr<PowerSupply> PowerSupply::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    float power;
    std::string certification;

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
    std::cout << "Enter certification: ";
    std::cin >> certification;
    type = selectComputerType();
    return std::make_shared<PowerSupply>(manufacturer, name, price, stock, ComponentType_t::PSU, type,
                                         componentID, power, certification);
}

void PowerSupply::print() const {
    ComponentBase::print();
}

void PowerSupply::update() {
    ComponentBase::update();
    std::cout << "current power: " << my_power << std::endl;
    if (changeQuestion("Change power?")) {
        std::cout << "Enter new power: ";
        std::cin >> my_power;
    }
    std::cout << "current certification: " << my_certification << std::endl;
    if (changeQuestion("Change certification?")) {
        std::cout << "Enter new certification: ";
        std::cin >> my_certification;
    }
}
