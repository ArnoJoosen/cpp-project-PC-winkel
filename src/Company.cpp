//
// Created by arno on 2/12/23.
//

#include "Company.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Input.h"
#include "CustomerView.h"

#define ROW_WIDTH (MAX_CUSTOMER_ID_SIZE+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+ \
                    MAX_STREET_NAME_LENGTH+MAX_HOUSE_NUMBER_SIZE+MAX_POSTCODE_SIZE+MAX_CUSTOMERTYPE_SIZE+MAX_VAT_SIZE+\
                    MAX_DISCOUNT_SIZE+MAX_YEARLY_BUY_SIZE+35)

Company::Company() : Customer(Name_t(), Address_t(), 0, CustomerType_t::BEDRIJF), my_vat(""), my_discount(0), my_yearlyBuy(0) {}

Company::Company(Name_t name, Address_t address, unsigned int customerID, const std::string& vat, float discount,
                 float yearlyBuy) : Customer(std::move(name), std::move(address), customerID, CustomerType_t::BEDRIJF),
                                           my_vat(vat), my_discount(discount), my_yearlyBuy(yearlyBuy) {}

void Company::printTopRow(bool indexed) {
    if (indexed) // Print index column
        std::cout << std::setw(5) << "index" << " | ";

    // Print the rest of the columns
    std::cout << std::left
              << std::setw(MAX_CUSTOMER_ID_SIZE) << "ID" << " | "
              << std::setw(MAX_NAME_LENGTH) << "First name" << " | "
              << std::setw(MAX_LAST_NAME_LENGTH) << "Last name" << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << "City" << " | "
              << std::setw(MAX_STREET_NAME_LENGTH) << "Street" << " | "
              << std::setw(MAX_HOUSE_NUMBER_SIZE) << "House num" << " | "
              << std::setw(MAX_POSTCODE_SIZE) << "Postcode" <<  " | "
              << std::setw(MAX_CUSTOMERTYPE_SIZE) << "Type" << " | "
              << std::setw(MAX_VAT_SIZE) << "VAT" << " | "
              << std::setw(MAX_DISCOUNT_SIZE) << "Discount" << " | "
              << std::setw(MAX_YEARLY_BUY_SIZE) << "Yearly buy" << " | " << std::endl;

    // Print horizontal line
    if (indexed)
        std::cout << std::string(5+ROW_WIDTH, '-') << std::endl;
    else
        std::cout << std::string(ROW_WIDTH, '-') << std::endl;
}

void Company::printRow(int index) const {
    // print customer data
    Customer::printRow(index);
    // print company data
    std::cout << std::setw(MAX_VAT_SIZE) << my_vat.c_str() << " | "
              << std::setw(MAX_DISCOUNT_SIZE) << my_discount << " | "
              << std::setw(MAX_YEARLY_BUY_SIZE) << my_yearlyBuy << " | ";
}

void Company::update() {
    // Update customer data
    Customer::update();
    std::string temp;

    // Ask for changes vat and change if needed
    std::cout << "Current vat: " << my_vat.c_str() << std::endl;
    if (yesNoQuestion("Change vat? ")) {
        std::cout << "Enter vat: ";
        std::getline(std::cin, temp);
        my_vat = temp;
    }
    // Ask for changes discount and change if needed
    std::cout << "Current discount: " << my_discount << std::endl;
    if (yesNoQuestion("Change discount? ")) {
        std::cout << "Enter discount: ";
        my_discount = input<float>();
    }
}

std::shared_ptr<Company> Company::Create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    std::string vat;
    float discount;
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
    std::cout << "Enter vat: ";
    std::getline(std::cin, vat);

    // Ask for discount
    std::cout << "Enter discount: ";
    discount = input<float>();

    return std::make_shared<Company>(name, address, customerID, vat, discount, 0);
}

void Company::selectFilter(CustomerView &view) {
    std::cout   << "Select filter:"
               << "\n\t1. First name"
               << "\n\t2. Last name"
               << "\n\t3. City"
               << "\n\t4. Street"
               << "\n\t5. House number"
               << "\n\t6. Zip code"
               << "\n\t7. Vat"
               << "\n\t8. Discount" << std::endl;

    switch (inputRange(1, 7)) {
        case 1:
            Customer::filterFirstName(view);
            break;
        case 2:
            Customer::filterLastName(view);
            break;
        case 3:
            Customer::filterCity(view);
            break;
        case 4:
            Customer::filterStreet(view);
            break;
        case 5:
            Customer::filterHouseNumber(view);
            break;
        case 6:
            Customer::filterPostcode(view);
            break;
        case 7:
            filterVat(view);
            break;
        case 8:
            filterDiscount(view);
            break;
    }
}

void Company::filterVat(CustomerView &view) {
    std::string vat;
    std::cout << "Enter vat: ";
    getline(std::cin, vat);
    view.filter([vat](const std::weak_ptr<class Customer>& customer) {
        return std::static_pointer_cast<Company>(customer.lock())->getVat() != vat;
    });
}

void Company::filterDiscount(CustomerView &view) {
    float discount;
    std::cout << "Enter discount: ";
    discount = input<float>();
    view.filter([discount](const std::weak_ptr<class Customer>& customer) {
        return std::static_pointer_cast<Company>(customer.lock())->getDiscount() != discount;
    });
}
