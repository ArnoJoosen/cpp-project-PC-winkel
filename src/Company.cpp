//
// Created by arno on 2/12/23.
//

#include "Company.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Input.h"

Company::Company(Name_t name, Address_t address, unsigned int customerID, float vat, float discount,
                 unsigned int yearlyBuy) : Customer(std::move(name), std::move(address), customerID, CustomerType_t::BEDRIJF),
                                           my_vat(vat), my_discount(discount), my_yearlyBuy(yearlyBuy) {

}

void Company::printTopRow(bool indexed) {
    if (indexed)
        std::cout << std::setw(5) << "index" << " | ";
    std::cout << std::left
              << std::setw(5) << "ID" << " | "
              << std::setw(MAX_NAME_LENGTH) << "First name" << " | "
              << std::setw(MAX_LAST_NAME_LENGTH) << "Last name" << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << "City" << " | "
              << std::setw(MAX_STREET_NAME_LENGTH) << "Street" << " | "
              << std::setw(10) << "House num" << " | "
              << std::setw(10) << "Postcode" <<  " | "
              << std::setw(11) << "Type" << " | "
              << std::setw(3) << "VAT"
              << std::setw(3) << "DIS"
              << std::setw(4) << "YEAR" << std::endl;
    if (indexed)
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
    else
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
}

void Company::printRow(int index) const {
    Customer::printRow(index);
    std::cout << std::setw(3) << my_vat << " | "
              << std::setw(3) << my_discount << " | "
              << std::setw(4) << my_yearlyBuy << " | " << std::endl;
}

void Company::update() {
    Customer::update();
    std::cout << "Enter vat and discount: ";
    std::cin >> my_vat >> my_discount;
}

std::shared_ptr<Company> Company::create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    float vat, discount;
    std::string strTemp;
    std::cout << "Enter first name";
    std::getline(std::cin, strTemp);
    name.firstName = strTemp;
    std::cout << "Enter last name";
    std::getline(std::cin, strTemp);
    name.lastName = strTemp;
    std::cout << "Enter city";
    std::getline(std::cin, strTemp);
    address.city = strTemp;
    std::cout << "Enter street";
    std::getline(std::cin, strTemp);
    address.street = strTemp;
    std::cout << "Enter house number";
    address.houseNumber = input<unsigned int>();
    std::cout << "Enter postcode";
    address.postcode = input<unsigned int>();
    std::cout << "Enter var";
    vat = input<float>();
    std::cout << "Enter discount";
    discount = input<float>();

    return std::make_shared<Company>(name, address, customerID, vat, discount, 0);
}
