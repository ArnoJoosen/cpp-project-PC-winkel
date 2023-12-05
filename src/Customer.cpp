//
// Created by arno on 2/12/23.
//

#include "Customer.h"
#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Input.h"
#include "CustomerView.h"

Customer::Customer(Name_t name, Address_t address, unsigned int customerID, CustomerType_t type)
: my_name(std::move(name)),
my_address(std::move(address)),
my_customerID(customerID),
my_type(type){}

void Customer::printTopRow(bool indexed) {
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
              << std::setw(11) << "Type" << " | " << std::endl;
    if (indexed)
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
    else
        std::cout << std::string(5+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+MAX_STREET_NAME_LENGTH+10+10+11+24, '-') << std::endl;
}

void Customer::printRow(int index) const {
    if (index != -1)
        std::cout << std::setw(5) << index << " | ";
    std::cout << std::setw(5) << my_customerID << '|'
              << std::setw(MAX_NAME_LENGTH) << my_name.firstName.c_str() << '|'
              << std::setw(MAX_LAST_NAME_LENGTH) << my_name.lastName.c_str() << '|'
              << std::setw(MAX_CITY_NAME_LENGTH) << my_address.city.c_str() << '|'
              << std::setw(MAX_CITY_NAME_LENGTH) << my_address.street.c_str() << '|'
              << std::setw(10) << my_address.houseNumber << '|'
              << std::setw(10) << my_address.postcode << '|'
              << std::setw(11) << customerTypeToString(my_type) << '|';
}

void Customer::update() {
    std::cout << "Enter first name and last name: ";
    std::cin >> my_name.firstName >> my_name.lastName;
    std::cout << "Enter city, street num and street postcode: ";
    std::cin >> my_address.city >> my_address.street >> my_address.street >> my_address.postcode;
}

std::shared_ptr<Customer> Customer::create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    std::string strTemp;
    std::cout << "Enter first name: ";
    std::getline(std::cin, strTemp);
    name.firstName = strTemp;
    std::cout << "Enter last name: ";
    std::getline(std::cin, strTemp);
    name.lastName = strTemp;
    std::cout << "Enter city: ";
    std::getline(std::cin, strTemp);
    address.city = strTemp;
    std::cout << "Enter street: ";
    std::getline(std::cin, strTemp);
    address.street = strTemp;
    std::cout << "Enter house number: ";
    address.houseNumber = input<unsigned int>();
    std::cout << "Enter postcode: ";
    address.postcode = input<unsigned int>();
    return std::make_shared<Customer>(name, address, customerID, CustomerType_t::PARTICULIER);
}

void Customer::selectFilter(CustomerView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. First name"
                << "\n\t2. Last name"
                << "\n\t3. City"
                << "\n\t4. Street"
                << "\n\t5. Street number"
                << "\n\t6. postcode"
                << "\n\t7. Customer type";
    switch (inputRange(1, 7)) {
        case 1:
            filterFirstName(view);
            break;
        case 2:
            filterLastName(view);
            break;
        case 3:
            filterCity(view);
            break;
        case 4:
            filterStreet(view);
            break;
        case 5:
            filterHouseNumber(view);
            break;
        case 6:
            filterPostcode(view);
            break;
        case 7:
            view.setType(selectCustomerType());
            break;
    }
}

void Customer::filterFirstName(CustomerView &view) {
    std::cout << "Enter first name: ";
    std::string firstName;
    std::getline(std::cin, firstName);
    view.filter([firstName](const std::shared_ptr<class Customer>& customer) {
        return customer->getName().firstName == firstName;
    });
}

void Customer::filterLastName(CustomerView &view) {
    std::cout << "Enter last name: ";
    std::string lastName;
    std::getline(std::cin, lastName);
    view.filter([lastName](const std::shared_ptr<class Customer>& customer) {
        return customer->getName().lastName == lastName;
    });
}

void Customer::filterCity(CustomerView &view) {
    std::cout << "Enter city: ";
    std::string city;
    std::getline(std::cin, city);
    view.filter([city](const std::shared_ptr<class Customer>& customer) {
        return customer->getAddress().city == city;
    });
}

void Customer::filterStreet(CustomerView &view) {
    std::cout << "Enter street: ";
    std::string street;
    std::getline(std::cin, street);
    view.filter([street](const std::shared_ptr<class Customer>& customer) {
        return customer->getAddress().street == street;
    });
}

void Customer::filterHouseNumber(CustomerView &view) {
    std::cout << "Enter house number: ";
    unsigned int houseNumber = input<unsigned int>();
    view.filter([houseNumber](const std::shared_ptr<class Customer>& customer) {
        return customer->getAddress().houseNumber == houseNumber;
    });
}

void Customer::filterPostcode(CustomerView &view) {
    std::cout << "Enter postcode: ";
    unsigned int postcode = input<unsigned int>();
    view.filter([postcode](const std::shared_ptr<class Customer>& customer) {
        return customer->getAddress().postcode == postcode;
    });
}
