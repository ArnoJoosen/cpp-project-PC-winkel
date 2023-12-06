//
// Created by arno on 5/12/23.
//
#include "CustomerProperties.h"
#include <iostream>
#include "Input.h"

std::string customerTypeToString(CustomerType_t type){
    switch (type)  {
        case CustomerType_t::PARTICULIER:
            return "Particulier";
        case CustomerType_t::BEDRIJF:
            return "Bedrijf";
        default:
            return "Unknown";
    }
}

CustomerType_t selectCustomerType(){
    std::cout << "Select computer type:\n"
              << "\t1. Particulier\n"
                << "\t2. Bedrijf\n";
    do {
        std::cout << "Enter choice: ";
        switch (inputRange(1, 2)) {
            case 1:
                return CustomerType_t::PARTICULIER;
            case 2:
                return CustomerType_t::BEDRIJF;
        }
    } while (true);
}