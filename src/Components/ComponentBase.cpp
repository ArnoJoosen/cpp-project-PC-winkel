//
// Created by arno on 2/12/23.
//

#include <iomanip>
#include "ComponentBase.h"
#include "Input.h"

ComponentBase::ComponentBase(std::string manufacturer, std::string name, float price, unsigned int stock,
                             ComponentType_t type, ComputerType_t computerType, unsigned int componentID) {

}

void ComponentBase::printHeader(bool indexed) {
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
                << std::setw(15) << "Computer Type" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+24, '-') << std::endl;
    else
        std::cout << std::string(10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+21, '-') << std::endl;
}

void ComponentBase::printBase(int index) const {
    // Print index column if index is not -1
    if (index != -1)
        std::cout << std::setw(5) << index << " | ";

    // print base columns
    std::cout   << std::setw(MAX_MANUFACTURER_LENGTH) << my_manufacturer.c_str() << " | "
                << std::setw(MAX_COMPONENT_NAME_LENGTH) << my_name.c_str() << " | "
                << std::setw(10) << my_price << " | "
                << std::setw(10) << my_stock << " | "
                << std::setw(11) << componentTypeToString(my_type) << " | "
                << std::setw(15) << computerTypeToString(my_computerType) << " | " << std::endl;
}

void ComponentBase::update() {
    std::string temp;
    std::cout << "Current Manufacturer: " << my_manufacturer.c_str() << std::endl;
    if (changeQuestion("Change manufacturer? ")) {
        std::cout << "Enter new manufacturer: ";
        std::getline(std::cin, temp);
        my_manufacturer = temp;
    }

    std::cout << "Current name: " << my_name.c_str() << std::endl;
    if (changeQuestion("Change name? ")) {
        std::cout << "Enter new name: ";
        std::getline(std::cin, temp);
        my_name = temp;
    }

    std::cout << "Current price: " << my_price << std::endl;
    if (changeQuestion("Change price? ")) {
        std::cout << "Enter new price:";
        float price;
        do {
            price = input<float>();
            if (price < 0)
                std::cout << "Price cannot be negative. Try again: ";
        } while (price < 0);
        my_price = price;
    }

    std::cout << "Current stock: " << my_stock << std::endl;
    if (changeQuestion("Change stock? ")) {
        std::cout << "Enter new stock: ";
        my_stock = input<unsigned int>();
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
    std::getline(std::cin, input);
    if (strcasecmp(input.c_str(), "y") == 0) {
        std::cout << "Enter new value: ";
        return true;
    }
    return false;
}

void ComponentBase::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Component Type"
                << "\n\t8. Computer Type" << std::endl;
    switch (inputRange(1, 6)) {
        case 1:
            filterManufacturer(view);
            break;
        case 2:
            filterName(view);
            break;
        case 3:
            filterPrice(view);
            break;
        case 4:
            filterPriceHigher(view);
            break;
        case 5:
            filterPriceLower(view);
            break;
        case 6:
            filterStock(view);
            break;
        case 7:
            view.setType(selectComponentType());
            break;
        case 8:
            filterComputerType(view);
            break;
    }
}

void ComponentBase::filterManufacturer(ComponentView &view) {
    std::cout << "Enter manufacturer: ";
    std::string manufacturer;
    std::getline(std::cin, manufacturer);
    view.filter([&manufacturer](const std::shared_ptr<ComponentBase>& component) {
        return component->my_manufacturer != manufacturer;
    });
}

void ComponentBase::filterName(ComponentView &view) {
    std::cout << "Enter name: ";
    std::string name;
    std::getline(std::cin, name);
    view.filter([&name](const std::shared_ptr<ComponentBase>& component) {
        return component->my_name != name;
    });
}


void ComponentBase::filterPrice(ComponentView &view) {
    float price;
    std::cout << "Enter price: ";
    price = input<float>();
    view.filter([&price](const std::shared_ptr<ComponentBase>& component) {
        return component->my_price != price;
    });
}

void ComponentBase::filterPriceHigher(ComponentView &view) {
    float price;
    std::cout << "Enter price: ";
    price = input<float>();
    view.filter([&price](const std::shared_ptr<ComponentBase>& component) {
        return component->my_price <= price;
    });
}

void ComponentBase::filterPriceLower(ComponentView &view) {
    float price;
    std::cout << "Enter price: ";
    price = input<float>();
    view.filter([&price](const std::shared_ptr<ComponentBase>& component) {
        return component->my_price >= price;
    });
}


void ComponentBase::filterStock(ComponentView &view) {
    unsigned int stock;
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    view.filter([&stock](const std::shared_ptr<ComponentBase>& component) {
        return component->my_stock != stock;
    });
}

void ComponentBase::filterComputerType(ComponentView &view) {
    std::cout << "Enter computer type: ";
    ComputerType_t computerType = selectComputerType();
    view.filter([&computerType](const std::shared_ptr<ComponentBase>& component) {
        return component->my_computerType != computerType;
    });
}