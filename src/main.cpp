//
// Created by arno on 10/25/23.
//
#include "Menus.h"
#include "ComputerShop.h"
#include <iostream>

int main(int argc, char** argv){
    ComputerShop shop("ComputerShop", {"bb", "aa", 1515});
    AccessLevel_t accessLevel = login();
    std::cout << "Access level: " << static_cast<int>(accessLevel) << std::endl;
    Action_t action;
    do {
        action = chooseAction(accessLevel);
        std::cout << "Action: " << static_cast<int>(action) << std::endl;
    } while (action != Action_t::Exit);
    return 0;
}