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
         ComponentBase(manufacturer, name, price, stock, type, computerType, componentID),
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
                << std::setw(5) << my_busSpeed << " | ";
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

void GPU::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Computer Type"
                << "\n\t8. Power"
                << "\n\t9. Bus Speed" << std::endl;

    switch (inputRange(1, 9)) {
        case 1:
            ComponentBase::filterManufacturer(view);
            break;
        case 2:
            ComponentBase::filterName(view);
            break;
        case 3:
            ComponentBase::filterPrice(view);
            break;
        case 4:
            ComponentBase::filterPriceHigher(view);
            break;
        case 5:
            ComponentBase::filterPriceLower(view);
            break;
        case 6:
            ComponentBase::filterStock(view);
            break;
        case 7:
            ComponentBase::filterComputerType(view);
            break;
        case 8:
            filterPower(view);
            break;
        case 9:
            filterBusSpeed(view);
            break;
    }
}

void GPU::filterPower(ComponentView &view) {
    std::cout << "Enter power: ";
    float power = input<float>();
    view.filter([&power](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<GPU>(component.lock())->my_power != power;
    });
}

void GPU::filterBusSpeed(ComponentView &view) {
    std::cout << "Enter bus speed: ";
    float busSpeed = input<float>();
    view.filter([&busSpeed](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<GPU>(component.lock())->my_busSpeed != busSpeed;
    });
}
