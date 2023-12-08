//
// Created by arno on 2/12/23.
//

#include "Memory.h"
#include <iostream>
#include <iomanip>
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

void Memory::printHeader(bool indexed) {
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
                << std::setw(2) << "Size" << " | "
                << std::setw(5) << "Clock Speed" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+24, '-') << std::endl; // TODO add size and clock speed
    else
        std::cout << std::string(10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+21, '-') << std::endl; // TODO add size and clock speed
}

void Memory::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(2) << my_size << " | "
                << std::setw(5) << my_clockSpeed << " | ";
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

void Memory::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Computer Type"
                << "\n\t8. Size"
                << "\n\t9. Clock Speed" << std::endl;

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
            filterSize(view);
            break;
        case 9:
            filterClockSpeed(view);
            break;
    }
}

void Memory::filterSize(ComponentView &view) {
    std::cout << "Enter size: ";
    unsigned int size = input<unsigned int>();
    view.filter([&size](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Memory>(component.lock())->my_size != size;
    });
}

void Memory::filterClockSpeed(ComponentView &view) {
    std::cout << "Enter clock speed: ";
    float clockSpeed = input<float>();
    view.filter([&clockSpeed](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Memory>(component.lock())->my_clockSpeed != clockSpeed;
    });
}
