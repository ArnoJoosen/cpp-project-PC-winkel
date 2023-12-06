//
// Created by arno on 2/12/23.
//

#include "ComputerShop.h"
#include <iostream>
#include "Input.h"
#include "Company.h"
#include "Components/CPU.h"
#include "Components/GPU.h"
#include "Components/Motherboard.h"
#include "Components/Memory.h"
#include "Components/Storage.h"
#include "Components/PowerSupply.h"
#include "Components/Case.h"
#include "Enumerate.hpp"


ComputerShop::ComputerShop(std::string name, Address_t address) : my_name(name), my_address(address) {

}

void ComputerShop::addComponent(const std::shared_ptr<ComponentBase>& component) {
    my_components.push_back(component);
}

void ComputerShop::addCustomer(const std::shared_ptr<Customer>& customer) {
    my_customers.push_back(customer);
}

void ComputerShop::createCustomer() {
    switch (selectCustomerType()) {
        case PARTICULIER:
            my_customers.push_back(Customer::create(lastCustomerID++));
            break;
        case BEDRIJF:
            my_customers.push_back(std::static_pointer_cast<Customer>(Company::create(lastComponentID++)));
            break;
    }
}

void ComputerShop::createComponent() {
    switch (selectComponentType()) {
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
    CustomerView view(my_customers);
    bool found = false;
    std::shared_ptr<Customer> customer = nullptr;
    while (!found) {
        if (view.getType() == CustomerType_t::UNKNOWN) {
            Customer::printTopRow(true);
            for (auto [i, customer]: Enumerate(view)) {
                customer->printRow((int) i);
                std::cout << std::endl;
            }
            std::cout << "Add filter (a), reset filter (r), select customer (index of customer): ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "a") {
                Customer::selectFilter(view);
            } else if (input == "r") {
                view = CustomerView(my_customers);
            } else {
                customer = view[std::stoi(input)]; // TODO error handling if input is not a number
                found = true;
            }
        } else if (view.getType() == CustomerType_t::PARTICULIER) {
            Company::printTopRow(true);
            for (auto [i, customer]: Enumerate(view)) {
                std::static_pointer_cast<Company>(customer)->printRow((int) i);
                std::cout << std::endl;
            }
            std::cout << "Add filter (a), reset filter (r), select customer (index of customer): ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "a") {
                Company::selectFilter(view);
            } else if (input == "r") {
                view = CustomerView(my_customers);
            } else {
                customer = view[std::stoi(input)]; // TODO error handling if input is not a number
                found = true;
            }
        } else
            throw std::runtime_error("Unknown customer type");
    }
    return customer;
}

std::shared_ptr<ComponentBase> ComputerShop::searchComponent() {
    // TODO search component from console input
    return nullptr;
}

void ComputerShop::removeCustomer() {
    // TODO remove customer from console input
}

void ComputerShop::removeComponent() {
    // TODO remove component from console input
}
