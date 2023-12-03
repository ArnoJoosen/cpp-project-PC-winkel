//
// Created by arno on 2/12/23.
//

#include "Company.h"
#include <iostream>
#include <string>

Company::Company(Name_t name, Address_t address, unsigned int customerID, float vat, float discount,
                 unsigned int yearlyBuy) : Customer(std::move(name), std::move(address), customerID),
                                           my_vat(vat), my_discount(discount), my_yearlyBuy(yearlyBuy) {

}

void Company::print() const {
    Customer::print();
}

void Company::update() {
    Customer::update();
    std::cout << "Enter vat and discount: ";
    std::cin >> my_vat >> my_discount;
}

std::shared_ptr<Company> Company::create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    int vat, discount;
    std::cout << "Enter first name and last name: ";
    std::cin >> name.firstName >> name.lastName;
    std::cout << "Enter city, street num and street postcode: ";
    std::cin >> address.city >> address.street >> address.street >> address.postcode;
    std::cout << "Enter vat and discount: ";
    std::cin >> vat >> discount;

    return std::make_shared<Company>(name, address, customerID, vat, discount, 0);
}
