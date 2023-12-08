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
#include "Input.h"


ComputerShop::ComputerShop(std::string name, Address_t address) : my_name(name), my_address(address) {}

void ComputerShop::addComponent(const std::shared_ptr<ComponentBase>& component) {
    my_components.insert({component->getType(), component});
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
            my_components.insert({ComponentType_t::CASE, std::static_pointer_cast<ComponentBase>(Case::Create(lastComponentID++))});
            break;
        case ComponentType_t::CPU:
            my_components.insert({ComponentType_t::CPU, std::static_pointer_cast<ComponentBase>(CPU::Create(lastComponentID++))});
            break;
        case ComponentType_t::GPU:
            my_components.insert({ComponentType_t::GPU, std::static_pointer_cast<ComponentBase>(GPU::Create(lastComponentID++))});
            break;
        case ComponentType_t::STORAGE:
            my_components.insert({ComponentType_t::STORAGE, std::static_pointer_cast<ComponentBase>(Storage::Create(lastComponentID++))});
            break;
        case ComponentType_t::MOTHERBOARD:
            my_components.insert({ComponentType_t::MOTHERBOARD, std::static_pointer_cast<ComponentBase>(Motherboard::Create(lastComponentID++))});
            break;
        case ComponentType_t::PSU:
            my_components.insert({ComponentType_t::PSU, std::static_pointer_cast<ComponentBase>(PowerSupply::Create(lastComponentID++))});
            break;
        case ComponentType_t::RAM:
            my_components.insert({ComponentType_t::RAM, std::static_pointer_cast<ComponentBase>(Memory::Create(lastComponentID++))});
            break;
        case ComponentType_t::UNKNOWN: // should never happen
            throw std::runtime_error("Unknown component type");
    }
}

std::weak_ptr<Customer> ComputerShop::searchCustomer() {
    CustomerView view(my_customers);
    bool found = false;
    int index;
    std::shared_ptr<Customer> customer = nullptr;

    // filter customers until one is selected
    while (!found) {
        // print customers in view
        Company::printTopRow(true);
        for (auto [i, c]: Enumerate(view)) {
            c->printRow((int) i);
            std::cout << std::endl;
        }

        // add filter for customer type or select customer or reset filter
        std::cout << "Add filter (a), reset filter (r), create customer (c), select customer (index of customer): ";
        std::string input;
        std::getline(std::cin, input);
        if ((view.getType() == CustomerType_t::PARTICULIER ||  view.getType() == CustomerType_t::UNKNOWN) && input == "a") // add filter for particulier
            Customer::selectFilter(view);
        else if (view.getType() == CustomerType_t::BEDRIJF && input == "a") // add filter for bedrijf
            Company::selectFilter(view);
        else if (input == "r") { // reset filter
            view = CustomerView(my_customers);
        } else if (input == "c") { // create customer
            createCustomer();
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

std::weak_ptr<ComponentBase> ComputerShop::searchComponent(ComponentType_t type, ComputerType_t computerType) {
    ComponentView view(my_components, type, computerType);
    bool found = false;
    int index;
    std::weak_ptr<ComponentBase> component;
    while(!found) {
        // print components in view
        view.printView();

        // add filter for component type or select component or reset filter
        std::cout << "Add filter (a), reset filter (r), select component (index of component): ";
        std::string input;
        std::getline(std::cin, input);
        if (view.getType() == ComponentType_t::UNKNOWN && input == "a") // add filter for unknown
            ComponentBase::selectFilter(view);
        else if (view.getType() != ComponentType_t::CASE && input == "a") // add filter for case
            Case::selectFilter(view);
        else if (view.getType() == ComponentType_t::CPU && input == "a") // add filter for CPU
            CPU::selectFilter(view);
        else if (view.getType() == ComponentType_t::GPU && input == "a") // add filter for GPU
            GPU::selectFilter(view);
        else if (view.getType() == ComponentType_t::RAM && input == "a") // add filter for RAM
            Memory::selectFilter(view);
        else if (view.getType() == ComponentType_t::MOTHERBOARD && input == "a") // add filter for motherboard
            Motherboard::selectFilter(view);
        else if (view.getType() == ComponentType_t::PSU && input == "a") // add filter for PSU
            PowerSupply::selectFilter(view);
        else if (view.getType() == ComponentType_t::STORAGE && input == "a") // add filter for storage
            Storage::selectFilter(view);
        else if (input == "r") // reset filter
            view = ComponentView(my_components, type, computerType);
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
    return component;
}

void ComputerShop::removeCustomer(const std::weak_ptr<Customer>& customer) {

    auto c = customer.lock();
    if (c != nullptr)
        throw std::runtime_error("Customer does not exist"); // should never happen

    my_customers.erase(std::remove(my_customers.begin(), my_customers.end(), c), my_customers.end());
}

void ComputerShop::removeComponent(const std::weak_ptr<ComponentBase>& component) {
    auto c = component.lock();
    if (c != nullptr)
        throw std::runtime_error("Component does not exist"); // should never happen

    auto range = my_components.equal_range(c->getType());
    for (auto it = range.first; it != range.second; ++it)
        if (it->second == c) {
            my_components.erase(it);
            break;
        }
}

std::shared_ptr<Invoice> ComputerShop::buildSystem(const std::weak_ptr<Customer>& customer) {
    std::shared_ptr<Invoice> invoice = std::make_shared<Invoice>(1, customer); // TODO invoiceID
    // select system type
    ComputerType_t systemType = selectComputerType();

    // select components
    // select CPU
    invoice->addComponents(searchComponent(ComponentType_t::CPU, systemType));
    // select Motherboard
    invoice->addComponents(searchComponent(ComponentType_t::MOTHERBOARD, systemType));
    // select RAM
    invoice->addComponents(searchComponent(ComponentType_t::RAM, systemType));
    // select GPU
    invoice->addComponents(searchComponent(ComponentType_t::GPU, systemType));
    // select Storage
    invoice->addComponents(searchComponent(ComponentType_t::STORAGE, systemType));
    // select PSU
    invoice->addComponents(searchComponent(ComponentType_t::PSU, systemType));
    // select Case
    invoice->addComponents(searchComponent(ComponentType_t::CASE, systemType));

    // additional components
    while (yesNoQuestion("Do you want to add additional components?"))
        invoice->addComponents(searchComponent(ComponentType_t::UNKNOWN, systemType));


    // TODO calculate price bast on components and customer type
    // TODO update stock
    // TODO if business customer: update yearlybuy
    // print invoice
    invoice->print();
}
