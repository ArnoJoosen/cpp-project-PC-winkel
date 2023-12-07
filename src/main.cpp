//
// Created by arno on 10/25/23.
//
#include "Menus.h"
#include "ComputerShop.h"

int main(int argc, char** argv){
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    AccessLevel_t accessLevel = login();
    Action_t action;
    do {
        action = chooseAction(accessLevel);
        switch (action) {
            case Action_t::SearchCustomer:
                shop.searchCustomer();
                break;
            case Action_t::AddCustomer:
                shop.createCustomer();
                break;
            case Action_t::UpdateCustomer:
                shop.searchCustomer()->update();
                break;
            case Action_t::RemoveCustomer:
                shop.removeCustomer(shop.searchCustomer());
                break;
            case Action_t::BuildSystem:
                shop.buildSystem(shop.searchCustomer());
                break;
            case Action_t::SearchComponent:
                shop.searchComponent();
                break;
            case Action_t::AddComponent:
                shop.createComponent();
                break;
            case Action_t::RemoveComponent:
                shop.removeComponent(shop.searchComponent());
                break;
            case Action_t::UpdateComponent:
                shop.searchComponent()->update();
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