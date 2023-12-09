//
// Created by arno on 2/12/23.
//

#include "PowerSupply.h"
#include <iostream>
#include <iomanip>
#include "Input.h"

PowerSupply::PowerSupply() : ComponentBase("", "", 0, 0, ComponentType_t::PSU, ComputerType_t::DESKTOP, 0),
                             my_power(0), my_certification("") {}

PowerSupply::PowerSupply(std::string manufacturer, std::string name, float price, unsigned int stock,
                         ComponentType_t type, ComputerType_t computerType, unsigned int componentID, float power,
                         std::string certification) : ComponentBase(std::move(manufacturer), std::move(name), price,
                                                                    stock, type, computerType, componentID),
                                                      my_power(power), my_certification(certification) {

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
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter power: ";
    power = input<float>();
    std::cout << "Enter certification: ";
    std::getline(std::cin, certification);
    type = selectComputerType();
    return std::make_shared<PowerSupply>(manufacturer, name, price, stock, ComponentType_t::PSU, type,
                                         componentID, power, certification);
}

void PowerSupply::printHeader(bool indexed) {
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
                << std::setw(MAX_CERTIFICATION_LENGTH) << "Certification" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+24, '-') << std::endl;
    else
        std::cout << std::string(10+MAX_MANUFACTURER_LENGTH+MAX_COMPONENT_NAME_LENGTH+10+10+11+15+21, '-') << std::endl;
}

void PowerSupply::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(5) << my_power << " | "
                << std::setw(MAX_CERTIFICATION_LENGTH) << my_certification.c_str() << " | ";
}

void PowerSupply::update() {
    std::string temp;
    ComponentBase::update();
    std::cout << "current power: " << my_power << std::endl;
    if (yesNoQuestion("Change power?")) {
        std::cout << "Enter new power: ";
        my_power = input<float>();
    }
    std::cout << "current certification: " << my_certification.c_str() << std::endl;
    if (yesNoQuestion("Change certification?")) {
        std::cout << "Enter new certification: ";
        std::getline(std::cin, temp);
        my_certification = temp;
    }
}

void PowerSupply::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Computer Type"
                << "\n\t8. Power"
                << "\n\t9. Certification" << std::endl;

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
            filterPower(view);
            break;
        case 9:
            filterCertification(view);
            break;
    }
}

void PowerSupply::filterPower(ComponentView &view) {
    std::cout << "Enter power: ";
    float power = input<float>();
    view.filter([&power](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<PowerSupply>(component.lock())->my_power != power;
    });
}

void PowerSupply::filterCertification(ComponentView &view) {
    std::cout << "Enter certification: ";
    std::string certification;
    std::getline(std::cin, certification);
    view.filter([&certification](const std::weak_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<PowerSupply>(component.lock())->my_certification != certification;
    });
}
