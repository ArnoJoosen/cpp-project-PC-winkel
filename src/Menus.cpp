//
// Created by arno on 2/12/23.
//
#include "Menus.h"
#include <iostream>
#include <cstdio>
#include <limits>
#include "Input.h"

AccessLevel_t login() {
    std::cout   << "Choose your access level:" << "\n"
                << "\t 1. Employee" << "\n"
                << "\t 2. Owner" << std::endl;
    switch (inputRange(1, 2)) {
        case 1:
            return AccessLevel_t::Employee;
        case 2:
            return AccessLevel_t::Owner;
    }
    throw std::runtime_error("Invalid access level");
}

Action_t chooseAction(AccessLevel_t accessLevel) {

    // collective actions
    std::cout << "Choose an action:" << "\n"
    << "\t 1. Search customer" << "\n"
    << "\t 2. Add customer" << "\n"
    << "\t 3. Update customer" << std::endl;

    // owner actions
    if (accessLevel == AccessLevel_t::Owner)
        std::cout << "\t 4. Remove customer" << "\n"
        << "\t 5. Search component" << "\n"
        << "\t 6. Add component" << "\n"
        << "\t 7. Remove component" << "\n"
        << "\t 8. Update component" << "\n"
        << "\t 9. Update component stock" << "\n"
        << "\t 10. Exit" << "\n"
        << "\t 11. Logout" << std::endl;

    // Employee actions
    if (accessLevel == AccessLevel_t::Employee)
        std::cout << "\t 4. Build system" << "\n"
        << "\t 5. Exit" << "\n"
        << "\t 6. Logout" << std::endl;

    while (true) {
        switch (inputRange(1, 11)) {
            case 1:
                return Action_t::SearchCustomer;
            case 2:
                return Action_t::AddCustomer;
            case 3:
                return Action_t::UpdateCustomer;
            case 4:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::RemoveCustomer;
                else
                    return Action_t::BuildSystem;
            case 5:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::SearchComponent;
                else
                    return Action_t::Exit;
            case 6:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::AddComponent;
                else {
                    return Action_t::Logout;
                }
            case 7:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::RemoveComponent;

                else {
                    std::cout << "Invalid action" << std::endl;
                    continue;
                }
            case 8:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::UpdateComponent;
                else {
                    std::cout << "Invalid action" << std::endl;
                    continue;
                }
            case 9:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::UpdateComponentStock;
                else {
                    std::cout << "Invalid action" << std::endl;
                    continue;
                }
            case 10:
                if (accessLevel == AccessLevel_t::Owner)
                    return Action_t::Exit;
                else {
                    std::cout << "Invalid action" << std::endl;
                    continue;
                }
            case 11:
                if (accessLevel == AccessLevel_t::Employee)
                    return Action_t::Logout;
                else {
                    std::cout << "Invalid action" << std::endl;
                    continue;
                }
        }
    }
}