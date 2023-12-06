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
#include "CustomerView.h"
#include "ComponentView.h"
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
        case UNKNOWN: // should never happen
            throw std::runtime_error("Unknown customer type");
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
        case ComponentType_t::UNKNOWN: // should never happen
            throw std::runtime_error("Unknown component type");
    }
}

std::shared_ptr<Customer> ComputerShop::searchCustomer() {
    CustomerView view(my_customers);
    bool found = false;
    int index;
    std::shared_ptr<Customer> customer = nullptr;

    // filter customers until one is selected
    while (!found) {
        Company::printTopRow(true);
        for (auto [i, c]: Enumerate(view)) {
            c->printRow((int) i);
            std::cout << std::endl;
        }
        std::cout << "Add filter (a), reset filter (r), select customer (index of customer): ";
        std::string input;
        std::getline(std::cin, input);
        if ((view.getType() == CustomerType_t::PARTICULIER ||  view.getType() == CustomerType_t::UNKNOWN) && input == "a") // add filter for particulier
            Customer::selectFilter(view);
        else if (view.getType() == CustomerType_t::BEDRIJF && input == "a") // add filter for bedrijf
            Company::selectFilter(view);
        else if (input == "r") { // reset filter
            view = CustomerView(my_customers);
        } else { // check if input is valid index for customer
            try {
                index = std::stoi(input);
                if (index < view.size()) { // valid index
                    customer = view[index];
                    found = true;
                } else // unknown index
                    std::cout << "Invalid input" << std::endl;
            } catch (std::exception& e) { // not a number
                std::cout << "Invalid input" << std::endl;
            }
        }
    }
    return customer;
}

std::shared_ptr<ComponentBase> ComputerShop::searchComponent() {
    ComponentView view(my_components);
    bool found = false;
    int index;
    std::shared_ptr<ComponentBase> component = nullptr;
    while(!found) {
        Company::printTopRow(true);
        for (auto [i, c]: Enumerate(view)) {
            c->printRow((int) i);
            std::cout << std::endl;
        }
        std::cout << "Add filter (a), reset filter (r), select component (index of component): ";
        std::string input;
        std::getline(std::cin, input);
        if (input == "a") // add filter
            ComponentBase::selectFilter(view);
        else if (input == "r") // reset filter
            view = ComponentView(my_components);
        else { // check if input is valid index for component
            try {
                index = std::stoi(input);
                if (index < view.size()) { // valid index
                    component = view[index];
                    found = true;
                } else // unknown index
                    std::cout << "Invalid input" << std::endl;
            } catch (std::exception& e) { // not a number
                std::cout << "Invalid input" << std::endl;
            }
        }
    }
    return nullptr;
}

void ComputerShop::removeCustomer(const std::shared_ptr<Customer>& customer) {
    my_customers.erase(std::remove(my_customers.begin(), my_customers.end(), customer), my_customers.end());
}

void ComputerShop::removeComponent(const std::shared_ptr<ComponentBase>& component) {
    my_components.erase(std::remove(my_components.begin(), my_components.end(), component), my_components.end());
}
