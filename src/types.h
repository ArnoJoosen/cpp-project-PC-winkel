//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_TYPES_H
#define PC_WINKLE_TYPES_H
#include "CapString.hpp"
#define MAX_STREET_NAME_LENGTH 20
#define MAX_CITY_NAME_LENGTH 20
#define MAX_NAME_LENGTH 20
#define MAX_LAST_NAME_LENGTH 20

struct Address_t {
    CapString<MAX_STREET_NAME_LENGTH> street;
    CapString<MAX_CITY_NAME_LENGTH> city;
    unsigned int houseNumber;
    unsigned int postcode;
};

struct Name_t {
    CapString<MAX_NAME_LENGTH> firstName;
    CapString<MAX_LAST_NAME_LENGTH>lastName;
};

#endif //PC_WINKLE_TYPES_H
