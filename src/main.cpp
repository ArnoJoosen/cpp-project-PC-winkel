//
// Created by arno on 10/25/23.
//
#include "Menus.h"
#include "ComputerShop.h"
#include "FileSystem.h"

int main(int argc, char** argv){
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651}, "./data");

    // create data dir if it exists and load data
    if (!directoryExists("./data")) {
        if (!createDirectory("./data"))
            throw std::runtime_error("Could not create data directory");
    }
    else {
        shop.load();
    }

    // create invoices dir
    if (!directoryExists("./invoices")) {
        if (!createDirectory("./invoices"))
            throw std::runtime_error("Could not create invoices directory");
    }

    // main loop
    AccessLevel_t accessLevel = login();
    Action_t action;
    do {
        action = chooseAction(accessLevel);
        switch (action) {
            case Action_t::SearchCustomer:
                try {
                    shop.searchCustomer();
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::AddCustomer:
                shop.createCustomer();
                break;
            case Action_t::UpdateCustomer:
                try {
                    shop.updateCustomer(shop.searchCustomer());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::RemoveCustomer:
                try {
                    shop.removeCustomer(shop.searchCustomer());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::BuildSystem:
                try {
                    shop.buildSystem(shop.searchCustomer()).save("./invoices");
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::SearchComponent:
                try {
                    shop.searchComponent();
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::AddComponent:
                shop.createComponent();
                break;
            case Action_t::RemoveComponent:
                try {
                    shop.removeComponent(shop.searchComponent());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::UpdateComponent:
                try {
                    shop.updateComponent(shop.searchComponent());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::SearchInvoice:
                // TODO: implement
                break;
            case Action_t::Logout:
                std::cout << "Logging out..." << std::endl;
                accessLevel = login();
                break;
            case Action_t::Exit:
                std::cout << "Exiting..." << std::endl;
                break;
        }
    } while (action != Action_t::Exit);
    return 0;
}