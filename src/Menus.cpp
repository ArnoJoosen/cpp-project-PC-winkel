//
// Created by arno on 2/12/23.
//
#include "Menus.h"
#include <iostream>

AccessLevel_t login() {
    int choice;
    std::cout   << "Choose your access level:" << "\n"
                << "\t 1. Employee" << "\n"
                << "\t 2. Owner" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            return AccessLevel_t::Employee;
        case 2:
            return AccessLevel_t::Owner;
        default:
            std::cout << "Invalid choice" << std::endl;
            return login();
    }
}

Action_t chooseAction(AccessLevel_t accessLevel) {
    int action;
    // collective actions
    std::cout   << "Choose an action:" << "\n"
                << "\t 1. Search customer" << "\n"
                << "\t 2. Add customer" << "\n"
                << "\t 3. Update customer" << "\n"
                << "\t 4. Search invoice "<< std::endl;

    // owner actions
    if(accessLevel == AccessLevel_t::Owner)
        std::cout   << "\t 5. Remove customer" << "\n"
                    << "\t 6. Add component" << "\n"
                    << "\t 7. Remove component" << "\n"
                    << "\t 8. Update component" << "\n"
                    << "\t 9. Exit" << std::endl;

    // Employee actions
    if(accessLevel == AccessLevel_t::Employee)
        std::cout   << "\t 5. Build system" << "\n"
                    << "\t 6. Exit" << std::endl;

    std::cin >> action;
    switch (action) {
        case 1:
            return Action_t::SearchCustomer;
        case 2:
            return Action_t::AddCustomer;
        case 3:
            return Action_t::UpdateCustomer;
        case 4:
            return Action_t::SearchInvoice;
        case 5:
            if(accessLevel == AccessLevel_t::Owner)
                return Action_t::RemoveCustomer;
            else
                return Action_t::BuildSystem;
        case 6:
            if(accessLevel == AccessLevel_t::Owner)
                return Action_t::AddComponent;
            else
                return Action_t::Exit;
        case 7:
            if(accessLevel == AccessLevel_t::Owner)
                return Action_t::RemoveComponent;
            else {
                std::cout << "Invalid action" << std::endl;
                return chooseAction(accessLevel);
            }
        case 8:
            if(accessLevel == AccessLevel_t::Owner)
                return Action_t::UpdateComponent;
            else {
                std::cout << "Invalid action" << std::endl;
                return chooseAction(accessLevel);
            }
        case 9:
            if(accessLevel == AccessLevel_t::Owner)
                return Action_t::Exit;
            else {
                std::cout << "Invalid action" << std::endl;
                return chooseAction(accessLevel);
            }
        default:
            std::cout << "Invalid action" << std::endl;
            return chooseAction(accessLevel);
    }
}