//
// Created by arno on 2/12/23.
//

#include "Storage.h"
#include <iostream>
#include <iomanip>
#include "Input.h"

#define ROW_WIDTH (MAX_COMPONENT_ID_LENGTH + MAX_MANUFACTURER_LENGTH + MAX_COMPONENT_NAME_LENGTH + MAX_PRICE_LENGTH + \
                  MAX_STOCK_LENGTH + MAX_COMPONENT_TYPE_LENGTH + MAX_COMPUTER_TYPE_LENGTH + MAX_STORAGE_SPEED_LENGTH +\
                  MAX_STORAGE_SIZE_LENGTH + MAX_SLOT_STORAGE_LENGTH + 30)

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
    std::cout   << std::setw(MAX_COMPONENT_ID_LENGTH) << "ID" << " | "
                << std::setw(MAX_MANUFACTURER_LENGTH) << "Manufacturer" << " | "
                << std::setw(MAX_COMPONENT_NAME_LENGTH) << "Name" << " | "
                << std::setw(MAX_PRICE_LENGTH) << "Price" << " | "
                << std::setw(MAX_STOCK_LENGTH) << "Stock" << " | "
                << std::setw(MAX_COMPONENT_TYPE_LENGTH) << "Type" << " | "
                << std::setw(MAX_COMPUTER_TYPE_LENGTH) << "Computer Type" << " | "
                << std::setw(MAX_STORAGE_SPEED_LENGTH) << "Speed" << " | "
                << std::setw(MAX_STORAGE_SIZE_LENGTH) << "Size" << " | "
                << std::setw(MAX_SLOT_STORAGE_LENGTH) << "Slot" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+3+ROW_WIDTH, '-') << std::endl;
    else
        std::cout << std::string(ROW_WIDTH, '-') << std::endl;
}

void Storage::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(MAX_STORAGE_SPEED_LENGTH) << my_speed << " | "
                << std::setw(MAX_STORAGE_SIZE_LENGTH) << my_size << " | "
                << std::setw(MAX_SLOT_STORAGE_LENGTH) << my_slot.c_str() << " | ";
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
