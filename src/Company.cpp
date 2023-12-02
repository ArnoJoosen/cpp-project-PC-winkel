//
// Created by arno on 2/12/23.
//

#include "Company.h"

Company::Company(Name_t name, Address_t address, unsigned int customerID, float vat, float discount,
                 unsigned int yearlyBuy) : Customer(std::move(name), std::move(address), customerID),
                                           my_vat(vat), my_discount(discount), my_yearlyBuy(yearlyBuy) {

}
