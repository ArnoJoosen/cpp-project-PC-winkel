//
// Created by arno on 2/12/23.
//

#include "Storage.h"
#include <iostream>
#include <iomanip>
#include "Input.h"

Storage::Storage() : ComponentBase("", "", 0, 0, ComponentType_t::STORAGE, ComputerType_t::DESKTOP, 0),
                     my_speed(0), my_size(0), my_slot("") {}

Storage::Storage(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
                 ComputerType_t computerType, unsigned int componentID, float speed, unsigned int size,
                 std::string slot) :
                 ComponentBase(std::move(manufacturer), std::move(name), price, stock, type, computerType, componentID),
                 my_speed(speed), my_size(size), my_slot(slot) {

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
                << std::setw(15) << my_slot.c_str() << " | ";
}

void Storage::update() {
    ComponentBase::update();
    std::string temp;
    std::cout << "current speed: " << my_speed << std::endl;
    if (yesNoQuestion("Change speed?")) {
        std::cout << "Enter new speed: ";
        my_speed = input<float>();
    }
    std::cout << "current size: " << my_size << std::endl;
    if (yesNoQuestion("Change size?")) {
        std::cout << "Enter new size: ";
        my_size = input<unsigned int>();
    }
    std::cout << "current slot: " << my_slot.c_str() << std::endl;
    if (yesNoQuestion("Change slot?")) {
        std::cout << "Enter new slot: ";
        std::getline(std::cin, temp);
        my_slot = temp;
    }
}

void Storage::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Computer Type"
                << "\n\t8. Speed"
                << "\n\t9. Size"
                << "\n\t10. Slot" << std::endl;

    switch (inputRange(1, 10)) {
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
            filterSpeed(view);
            break;
        case 9:
            filterSize(view);
            break;
        case 10:
            filterSlot(view);
            break;
    }
}

void Storage::filterSpeed(ComponentView &view) {
    std::cout << "Enter speed: ";
    float speed = input<float>();
    view.filter([&speed](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Storage>(component.lock())->my_speed != speed;
    });
}

void Storage::filterSize(ComponentView &view) {
    std::cout << "Enter size: ";
    unsigned int size = input<unsigned int>();
    view.filter([&size](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Storage>(component.lock())->my_size != size;
    });
}

void Storage::filterSlot(ComponentView &view) {
    std::cout << "Enter slot: ";
    std::string slot;
    std::getline(std::cin, slot);
    view.filter([&slot](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Storage>(component.lock())->my_slot != slot;
    });
}
