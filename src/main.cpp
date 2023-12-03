//
// Created by arno on 10/25/23.
//
#include "Menus.h"
#include "ComputerShop.h"
#include <iostream>

int main(int argc, char** argv){
    ComputerShop shop("ComputerShop1", {"bb", "aa", 1515});
    AccessLevel_t accessLevel = login();
    std::cout << "Access level: " << static_cast<int>(accessLevel) << std::endl;
    Action_t action;
    do {
        action = chooseAction(accessLevel);
        std::cout << "Action: " << static_cast<int>(action) << std::endl;
        switch (action) {
            case Action_t::SearchCustomer:
                break;
            case Action_t::AddCustomer:
                shop.createCustomer();
                break;
            case Action_t::UpdateCustomer:
                break;
            case Action_t::RemoveCustomer:
                break;
            case Action_t::BuildSystem:
                break;
            case Action_t::AddComponent:
                shop.createComponent();
                break;
            case Action_t::RemoveComponent:
                break;
            case Action_t::UpdateComponent:
                break;
            case Action_t::SearchInvoice:
                break;
        }
    } while (action != Action_t::Exit);
    return 0;
}