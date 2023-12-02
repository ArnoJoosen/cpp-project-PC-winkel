//
// Created by arno on 2/12/23.
//

#include "Customer.h"

Customer::Customer(Name_t name, Address_t address, unsigned int customerID)
: my_name(std::move(name)),
my_address(std::move(address)),
my_customerID(customerID) {}
