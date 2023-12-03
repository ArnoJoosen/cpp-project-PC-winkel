//
// Created by arno on 2/12/23.
//

#include "PowerSupply.h"

PowerSupply::PowerSupply(std::string manufacturer, std::string name, float price, unsigned int stock,
                         ComponentType_t type, ComputerType_t computerType, unsigned int componentID, float power,
                         std::string certification) : ComponentBase(std::move(manufacturer), std::move(name), price,
                                                                    stock, type, computerType, componentID),
                                                      my_power(power), my_certification(std::move(certification)) {

}

std::shared_ptr<PowerSupply> PowerSupply::Create(unsigned int componentID) {
    return std::shared_ptr<PowerSupply>();
}
