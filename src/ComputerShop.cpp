//
// Created by arno on 2/12/23.
//

#include "ComputerShop.h"
#include <iostream>
#include "Company.h"
#include "Components/CPU.h"
#include "Components/GPU.h"
#include "Components/Motherboard.h"
#include "Components/Memory.h"
#include "Components/Storage.h"
#include "Components/PowerSupply.h"
#include "Components/Case.h"


ComputerShop::ComputerShop(std::string name, Address_t address) : my_name(std::move(name)), my_address(address) {

}

void ComputerShop::addComponent(const std::shared_ptr<ComponentBase>& component) {
    my_components.push_back(component);
}

void ComputerShop::addCustomer(const std::shared_ptr<Customer>& customer) {
    my_customers.push_back(customer);
}

void ComputerShop::removeComponent(unsigned int componentID) {
    // TODO: implement
}

void ComputerShop::removeCustomer(unsigned int customerID) {
    // TODO: implement
}

void ComputerShop::createCustomer() {
    CustomerType_t choice = UNKNOWN;
    do {
        std::cout << "Choose customer type: \n\t1. Particulier\n\t2. Bedrijf\n";
        int input;
        std::cin >> input;
        choice = static_cast<CustomerType_t>(input);
    } while (choice != PARTICULIER && choice != BEDRIJF);

    switch (choice) {
        case PARTICULIER:
            my_customers.push_back(Customer::create(lastCustomerID++));
            break;
        case BEDRIJF:
            my_customers.push_back(std::static_pointer_cast<Customer>(Company::create(lastComponentID++)));
            break;
    }
}

void ComputerShop::createComponent() {
    ComponentType_t choice = ComponentType_t::UNKNOWN;
    do {
        std::cout << "Choose component type: \n\t1. Case\n\t2. CPU\n\t3. GPU\n\t4. HDD\n\t5. Motherboard\n\t6. PSU\n\t7. RAM\n";
        int input;
        std::cin >> input;
        choice = static_cast<ComponentType_t>(input);
    } while (!(choice >= ComponentType_t::CPU && choice <= ComponentType_t::CASE));

    switch (choice) {
        case ComponentType_t::CASE:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(Case::Create(lastComponentID++)));
            break;
        case ComponentType_t::CPU:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(CPU::Create(lastComponentID++)));
            break;
        case ComponentType_t::GPU:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(GPU::Create(lastComponentID++)));
            break;
        case ComponentType_t::STORAGE:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(Storage::Create(lastComponentID++)));
            break;
        case ComponentType_t::MOTHERBOARD:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(Motherboard::Create(lastComponentID++)));
            break;
        case ComponentType_t::PSU:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(PowerSupply::Create(lastComponentID++)));
            break;
        case ComponentType_t::RAM:
            my_components.push_back(std::static_pointer_cast<ComponentBase>(Memory::Create(lastComponentID++)));
            break;
    }
}

std::shared_ptr<Customer> ComputerShop::searchCustomer() {
    // TODO search customer from console input
    return nullptr;
}

std::shared_ptr<ComponentBase> ComputerShop::searchComponent() {
    // TODO search component from console input
    return nullptr;
}

void ComputerShop::updateCustomer(unsigned int customerID) {
    // TODO update customer from console input
}

void ComputerShop::updateComponent(unsigned int componentID) {
    // TODO update component from console input
}
