//
// Created by arno on 2/12/23.
//

#include "Customer.h"
#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Input.h"
#include "CustomerView.h"

#define ROW_WIDTH (MAX_CUSTOMER_ID_SIZE+MAX_NAME_LENGTH+MAX_LAST_NAME_LENGTH+MAX_CITY_NAME_LENGTH+ \
                    MAX_STREET_NAME_LENGTH+MAX_HOUSE_NUMBER_SIZE+MAX_POSTCODE_SIZE+MAX_CUSTOMERTYPE_SIZE+35)

Customer::Customer() : my_name(), my_address(), my_customerID(0), my_type(CustomerType_t::PARTICULIER) {}

Customer::Customer(Name_t name, Address_t address, unsigned int customerID, CustomerType_t type)
: my_name(std::move(name)),
my_address(std::move(address)),
my_customerID(customerID),
my_type(type){}

void Customer::printTopRow(bool indexed) {
    if (indexed) // true means print index column
        std::cout << std::setw(5) << "index" << " | ";
    // print column names
    std::cout << std::left
              << std::setw(MAX_CUSTOMER_ID_SIZE) << "ID" << " | "
              << std::setw(MAX_NAME_LENGTH) << "First name" << " | "
              << std::setw(MAX_LAST_NAME_LENGTH) << "Last name" << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << "City" << " | "
              << std::setw(MAX_STREET_NAME_LENGTH) << "Street" << " | "
              << std::setw(MAX_HOUSE_NUMBER_SIZE) << "House num" << " | "
              << std::setw(MAX_POSTCODE_SIZE) << "Postcode" <<  " | "
              << std::setw(MAX_CUSTOMERTYPE_SIZE) << "Type" << " | " << std::endl;
    // print horizontal line
    if (indexed)
        std::cout << std::string(5+ROW_WIDTH, '-') << std::endl;
    else
        std::cout << std::string(ROW_WIDTH, '-') << std::endl;
}

void Customer::printRow(int index) const {
    if (index != -1) // -1 means no index column
        std::cout << std::setw(5) << index << " | ";
    // print customer data
    std::cout << std::setw(MAX_CUSTOMER_ID_SIZE) << my_customerID << " | "
              << std::setw(MAX_NAME_LENGTH) << my_name.firstName.c_str() << " | "
              << std::setw(MAX_LAST_NAME_LENGTH) << my_name.lastName.c_str() << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << my_address.city.c_str() << " | "
              << std::setw(MAX_CITY_NAME_LENGTH) << my_address.street.c_str() << " | "
              << std::setw(MAX_HOUSE_NUMBER_SIZE) << my_address.houseNumber << " | "
              << std::setw(MAX_POSTCODE_SIZE) << my_address.postcode << " | "
              << std::setw(MAX_CUSTOMERTYPE_SIZE) << customerTypeToString(my_type) << " | ";
}

void Customer::update() {
    std::string temp;
    // ask for changes first name and change if needed
    std::cout << "Current first name: " << my_name.firstName.c_str() << std::endl;
    if (yesNoQuestion("Change first name? ")) {
        std::cout << "Enter first name: ";
        std::getline(std::cin, temp);
        my_name.firstName = temp;
    }
    // ask for changes last name and change if needed
    std::cout << "Current last name: " << my_name.lastName.c_str() << std::endl;
    if (yesNoQuestion("Change last name? ")) {
        std::cout << "Enter last name: ";
        std::getline(std::cin, temp);
        my_name.lastName = temp;
    }
    // ask for changes city and change if needed
    std::cout << "Current city: " << my_address.city.c_str() << std::endl;
    if (yesNoQuestion("Change city? ")) {
        std::cout << "Enter city: ";
        std::getline(std::cin, temp);
        my_address.city = temp;
    }
    // ask for changes street and change if needed
    std::cout << "Current street: " << my_address.street.c_str() << std::endl;
    if (yesNoQuestion("Change street? ")) {
        std::cout << "Enter street: ";
        std::getline(std::cin, temp);
        my_address.street = temp;
    }
    // ask for changes house number and change if needed
    std::cout << "Current house number: " << my_address.houseNumber << std::endl;
    if (yesNoQuestion("Change house number? ")) {
        std::cout << "Enter house number: ";
        my_address.houseNumber = input<unsigned int>();
    }
    // ask for changes postcode and change if needed
    std::cout << "Current postcode: " << my_address.postcode << std::endl;
    if (yesNoQuestion("Change postcode? ")) {
        std::cout << "Enter postcode: ";
        my_address.postcode = input<unsigned int>();
    }
}

std::shared_ptr<Customer> Customer::Create(unsigned int customerID) {
    Name_t name;
    Address_t address;
    std::string strTemp;

    // ask for first name
    std::cout << "Enter first name: ";
    std::getline(std::cin, strTemp);
    name.firstName = strTemp;

    // ask for last name
    std::cout << "Enter last name: ";
    std::getline(std::cin, strTemp);
    name.lastName = strTemp;

    // ask for city
    std::cout << "Enter city: ";
    std::getline(std::cin, strTemp);
    address.city = strTemp;

    // ask for street
    std::cout << "Enter street: ";
    std::getline(std::cin, strTemp);
    address.street = strTemp;

    // ask for house number
    std::cout << "Enter house number: ";
    address.houseNumber = input<unsigned int>();

    // ask for postcode
    std::cout << "Enter zip code: ";
    address.postcode = input<unsigned int>();

    return std::make_shared<Customer>(name, address, customerID, CustomerType_t::PARTICULIER);
}

void Customer::selectFilter(CustomerView &view) {
    std::cout   << "Select filter:"
                << "\n\t1. First name"
                << "\n\t2. Last name"
                << "\n\t3. City"
                << "\n\t4. Street"
                << "\n\t5. House number"
                << "\n\t6. Zip code"
                << "\n\t7. Customer type\n";
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
    view.filter([firstName](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getName().firstName != firstName;
    });
}

void Customer::filterLastName(CustomerView &view) {
    std::cout << "Enter last name: ";
    std::string lastName;
    std::getline(std::cin, lastName);
    view.filter([lastName](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getName().lastName != lastName;
    });
}

void Customer::filterCity(CustomerView &view) {
    std::cout << "Enter city: ";
    std::string city;
    std::getline(std::cin, city);
    view.filter([city](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getAddress().city != city;
    });
}

void Customer::filterStreet(CustomerView &view) {
    std::cout << "Enter street: ";
    std::string street;
    std::getline(std::cin, street);
    view.filter([street](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getAddress().street != street;
    });
}

void Customer::filterHouseNumber(CustomerView &view) {
    std::cout << "Enter house number: ";
    unsigned int houseNumber = input<unsigned int>();
    view.filter([houseNumber](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getAddress().houseNumber != houseNumber;
    });
}

void Customer::filterPostcode(CustomerView &view) {
    std::cout << "Enter postcode: ";
    unsigned int postcode = input<unsigned int>();
    view.filter([postcode](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getAddress().postcode != postcode;
    });
}
