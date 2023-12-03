//
// Created by arno on 2/12/23.
//

#include "Customer.h"
#include <iostream>

Customer::Customer(Name_t name, Address_t address, unsigned int customerID)
: my_name(std::move(name)),
my_address(std::move(address)),
my_customerID(customerID) {}

std::shared_ptr<Customer> Customer::create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    std::cout << "Enter first name and last name: ";
    std::cin >> name.firstName >> name.lastName;
    std::cout << "Enter city, street num and street postcode: ";
    std::cin >> address.city >> address.street >> address.street >> address.postcode;
    return std::make_shared<Customer>(name, address, customerID);
}
