//
// Created by arno on 2/12/23.
//

#include "Case.h"

Case::Case(std::string manufacturer, std::string name, float price, unsigned int stock, ComponentType_t type,
           ComputerType_t computerType, unsigned int componentID, std::string color, std::string MotherboardSize,
           std::string material) : ComponentBase(std::move(manufacturer), std::move(name), price, stock, type,
                                                 computerType, componentID), my_color(std::move(color)),
                                   MotherboardSize(std::move(MotherboardSize)), my_material(std::move(material)) {

}

void Case::print() const {
    ComponentBase::print();
}

std::shared_ptr<Case> Case::Create(unsigned int componentID) {
    return std::shared_ptr<Case>();
}
