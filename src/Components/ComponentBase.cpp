//
// Created by arno on 2/12/23.
//

#include "ComponentBase.h"

ComponentBase::ComponentBase(std::string manufacturer, std::string name, float price, unsigned int stock,
                             ComponentType_t type, ComputerType_t computerType, unsigned int componentID) {

}

void ComponentBase::print() const {

}

void ComponentBase::update() {
    std::cout << "Current Manufacturer: " << my_manufacturer.c_str() << std::endl;
    if (changeQuestion("Change manufacturer? ")) {
        std::cout << "Enter new manufacturer: ";
        std::cin >> my_manufacturer;
    }

    std::cout << "Current name: " << my_name.c_str() << std::endl;
    if (changeQuestion("Change name? ")) {
        std::cout << "Enter new name: ";
        std::cin >> my_name;
    }

    std::cout << "Current price: " << my_price << std::endl;
    if (changeQuestion("Change price? ")) {
        std::cout << "Enter new price:";
        std::cin >> my_price;
    }

    std::cout << "Current stock: " << my_stock << std::endl;
    if (changeQuestion("Change stock? ")) {
        std::cout << "Enter new stock: ";
        std::cin >> my_stock;
    }

    std::cout << "Current component type: " << componentTypeToString(my_type) << std::endl;
    if (changeQuestion("Change computer type? ")) {
        std::cout << "Enter new type: ";
        my_computerType = selectComputerType();
    }
}

bool ComponentBase::changeQuestion(const char *question) const {
    std::cout << question << "yes or no: " << std::endl;
    std::string input;
    std::cin >> input;
    if (input == "y") {
        std::cout << "Enter new value: ";
        return true;
    }
    return false;
}
