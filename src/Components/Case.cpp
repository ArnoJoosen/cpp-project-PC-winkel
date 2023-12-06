//
// Created by arno on 2/12/23.
//

#include "Case.h"
#include "Input.h"
#include <iostream>
#include <iomanip>
#include "ComponentView.h"

Case::Case(std::string manufacturer, std::string name, float price, unsigned int stock, ComputerType_t computerType,
           unsigned int componentID, std::string color, std::string MotherboardSize,
           std::string material) : ComponentBase(std::move(manufacturer), std::move(name), price, stock, ComponentType_t::CASE,
                                                 computerType, componentID), my_color(std::move(color)),
                                   MotherboardSize(std::move(MotherboardSize)), my_material(std::move(material)) {

}

void Case::printRow(int index) const {
    ComponentBase::printBase(index);
    std::cout   << std::setw(10) << my_color << " | "
                << std::setw(15) << MotherboardSize << " | "
                << std::setw(15) << my_material << " | " << std::endl;
}

void Case::update() {
    ComponentBase::update();
    std::cout << "Current color: " << my_color.c_str() << std::endl;
    if (changeQuestion("Change color? ")) {
        std::cout << "Enter new color: ";
        std::getline(std::cin, my_color);
    }
    std::cout << "Current MotherboardSize: " << MotherboardSize.c_str() << std::endl;
    if (changeQuestion("Change MotherboardSize? ")) {
        std::cout << "Enter new MotherboardSize: ";
        std::getline(std::cin, MotherboardSize);
    }
    std::cout << "Current material: " << my_material.c_str() << std::endl;
    if (changeQuestion("Change material? ")) {
        std::cout << "Enter new material: ";
        std::getline(std::cin, my_material);
    }
}

std::shared_ptr<Case> Case::Create(unsigned int componentID) {
    std::string manufacturer;
    std::string name;
    float price;
    unsigned int stock;
    ComputerType_t type;
    std::string color;
    std::string MotherboardSize;
    std::string material;

    std::cout << "Enter manufacturer: ";
    std::getline(std::cin, manufacturer);
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter price: ";
    price = input<float>();
    std::cout << "Enter stock: ";
    stock = input<unsigned int>();
    std::cout << "Enter color: ";
    std::getline(std::cin, color);
    std::cout << "Enter MotherboardSize: ";
    std::getline(std::cin, MotherboardSize);
    std::cout << "Enter material: ";
    std::getline(std::cin, material);
    type = selectComputerType();

    return std::make_shared<Case>(manufacturer, name, price, stock, type, componentID, color, MotherboardSize, material);
}

void Case::selectFilter(ComponentView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. Manufacturer"
                << "\n\t2. Name"
                << "\n\t3. Price"
                << "\n\t4. Price higher than"
                << "\n\t5. Price lower than"
                << "\n\t6. Stock"
                << "\n\t7. Computer Type"
                << "\n\t8. Color"
                << "\n\t9. MotherboardSize"
                << "\n\t10. Material" << std::endl;

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
            filterColor(view);
            break;
        case 9:
            filterMotherboardSize(view);
            break;
        case 10:
            filterMaterial(view);
            break;
    }
}

void Case::filterColor(ComponentView &view) {
    std::string color;
    std::cout << "Enter color: ";
    std::getline(std::cin, color);
    view.filter([&color](const std::shared_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Case>(component)->my_color != color;
    });
}

void Case::filterMotherboardSize(ComponentView &view) {
    std::string MotherboardSize;
    std::cout << "Enter MotherboardSize: ";
    std::getline(std::cin, MotherboardSize);
    view.filter([&MotherboardSize](const std::shared_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Case>(component)->MotherboardSize != MotherboardSize;
    });
}

void Case::filterMaterial(ComponentView &view) {
    std::string material;
    std::cout << "Enter material: ";
    std::getline(std::cin, material);
    view.filter([&material](const std::shared_ptr<ComponentBase>& component) {
        return std::dynamic_pointer_cast<Case>(component)->my_material != material;
    });
}
