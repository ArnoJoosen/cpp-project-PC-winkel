//
// Created by arno on 2/12/23.
//

#include "Storage.h"
#include <iostream>
#include <iomanip>
#include "Input.h"

Storage::Storage(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
                 ComputerType_t computerType, unsigned int componentID, float speed, unsigned int size,
                 std::string slot) :
                 ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                 my_speed(speed), my_size(size), my_slot(std::move(slot)) {

}

std::shared_ptr<Storage> Storage::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    float speed;
    unsigned int size;
    std::string slot;

    std::cout << "Enter manufacturer: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter speed: ";
    speed = input<float>();
    std::cout << "Enter size: ";
    size = input<unsigned int>();
    std::cout << "Enter slot: ";
    std::getline(std::cin, slot);
    type = selectComputerType();
    return std::make_shared<Storage>(manufacturer, name, price, stock, ComponentType_t::STORAGE, type, componentID,
                                     speed, size, slot);
}


void Storage::printHeader(bool indexed) {
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
                << std::setw(10) << "Speed" << " | "
                << std::setw(10) << "Size" << " | "
                << std::setw(15) << "Slot" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15, '-') << std::endl; // TODO add speed, size and slot
    else
        std::cout << std::string(10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15, '-') << std::endl; // TODO add speed, size and slot
}

void Storage::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(10) << my_speed << " | "
                << std::setw(10) << my_size << " | "
                << std::setw(15) << my_slot << " | " << std::endl;
}

void Storage::update() {
    ComponentBase::update();
    std::cout << "current speed: " << my_speed << std::endl;
    if (changeQuestion("Change speed?")) {
        std::cout << "Enter new speed: ";
        my_speed = input<float>();
    }
    std::cout << "current size: " << my_size << std::endl;
    if (changeQuestion("Change size?")) {
        std::cout << "Enter new size: ";
        my_size = input<unsigned int>();
    }
    std::cout << "current slot: " << my_slot << std::endl;
    if (changeQuestion("Change slot?")) {
        std::cout << "Enter new slot: ";
        std::getline(std::cin, my_slot);
    }
}
