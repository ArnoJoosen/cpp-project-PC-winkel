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
                                           my_vat(vat), my_discount(discount), my_yearlyBuy(yearlyBuy) {}

void Company::printTopRow(bool indexed) {
    if (indexed) // Print index column
        std::cout << std::setw(5) << "index" << " | ";

    // Print the rest of the columns
    std::cout << std::left
              << std::setw(5) << "ID" << " | "
              << std::setw(MAX_NAME_LENGTH) << "First name" << " | "
              << std::setw(MAX_LAST_NAME_LENGTH) << "Last name" << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << "City" << " | "
              << std::setw(MAX_STREET_NAME_LENGTH) << "Street" << " | "
              << std::setw(10) << "House num" << " | "
              << std::setw(10) << "Postcode" <<  " | "
              << std::setw(11) << "Type" << " | "
              << std::setw(3) << "VAT" << " | "
              << std::setw(3) << "DIS" << " | "
              << std::setw(4) << "YEAR" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
    else
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
}

void Company::printRow(int index) const {
    // print customer data
    Customer::printRow(index);
    // print company data
    std::cout << std::setw(3) << my_vat << " | "
              << std::setw(3) << my_discount << " | "
              << std::setw(4) << my_yearlyBuy << " | " << std::endl;
}

void Company::update() {
    // Update customer data
    Customer::update();

    // Ask for changes vat and change if needed
    std::cout << "Current vat: " << my_vat << std::endl;
    if (changeQuestion("Change vat? ")) {
        std::cout << "Enter vat: ";
        my_vat = input<float>();
    }
    // Ask for changes discount and change if needed
    std::cout << "Current discount: " << my_discount << std::endl;
    if (changeQuestion("Change discount? ")) {
        std::cout << "Enter discount: ";
        my_discount = input<float>();
    }
}

std::shared_ptr<Company> Company::create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    float vat, discount;
    std::string strTemp;

    // Ask for first name
    std::cout << "Enter first name: ";
    std::getline(std::cin, strTemp);
    name.firstName = strTemp;

    // Ask for last name
    std::cout << "Enter last name: ";
    std::getline(std::cin, strTemp);
    name.lastName = strTemp;

    // Ask for city
    std::cout << "Enter city: ";
    std::getline(std::cin, strTemp);
    address.city = strTemp;

    // Ask for street
    std::cout << "Enter street: ";
    std::getline(std::cin, strTemp);
    address.street = strTemp;

    // Ask for house number
    std::cout << "Enter house number: ";
    address.houseNumber = input<unsigned int>();

    // Ask for zip code
    std::cout << "Enter zip code: ";
    address.postcode = input<unsigned int>();

    // Ask for vat
    std::cout << "Enter var: ";
    vat = input<float>();

    // Ask for discount
    std::cout << "Enter discount: ";
    discount = input<float>();

    return std::make_shared<Company>(name, address, customerID, vat, discount, 0);
}
