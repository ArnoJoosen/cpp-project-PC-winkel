//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_CUSTOMERPROPERTIES_H
#define PC_WINKLE_CUSTOMERPROPERTIES_H
#include <string>

#define MAX_CUSTOMERTYPE_SIZE 11

enum CustomerType_t {
    UNKNOWN = 0,
    PARTICULIER = 1,
    BEDRIJF = 2
};

std::string customerTypeToString(CustomerType_t type);
CustomerType_t selectCustomerType();

#endif //PC_WINKLE_CUSTOMERPROPERTIES_H
