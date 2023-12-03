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
                shop.removeCustomer();
                break;
            case Action_t::BuildSystem:
                // TODO: implement
                break;
            case Action_t::AddComponent:
                shop.createComponent();
                break;
            case Action_t::RemoveComponent:
                shop.removeComponent();
                break;
            case Action_t::UpdateComponent:
                shop.searchComponent()->update();
                break;
            case Action_t::SearchInvoice:
                // TODO: implement
                break;
        }
    } while (action != Action_t::Exit);
    return 0;
}