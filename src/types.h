//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_TYPES_H
#define PC_WINKLE_TYPES_H
#include <string>

struct Address_t {
    std::string my_street;
    std::string my_gemeente;
    unsigned int my_postcode;
};

struct Name_t {
    std::string my_firstName;
    std::string my_lastName;
};

#endif //PC_WINKLE_TYPES_H
