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


ComputerShop::ComputerShop(const std::string& name, Address_t address, std::string workingDirectory) :
my_name(name), my_address(address), my_workingDirectory(workingDirectory) {}

void ComputerShop::addComponent(const std::shared_ptr<ComponentBase>& component) {
    my_components.insert({component->getType(), component});
}

void ComputerShop::addCustomer(const std::shared_ptr<Customer>& customer) {
    my_customers.push_back(customer);
}

void ComputerShop::createCustomer() {
    switch (selectCustomerType()) {
        case PARTICULIER:
            addCustomer(Customer::Create(lastCustomerID++));
            serializeCustomerType(CustomerType_t::PARTICULIER);
            serializeShop();
            break;
        case BEDRIJF:
            addCustomer(std::static_pointer_cast<Customer>(Company::Create(lastComponentID++)));
            serializeCustomerType(CustomerType_t::BEDRIJF);
            serializeShop();
            break;
        case UNKNOWN: // should never happen
            throw std::runtime_error("Unknown customer type");
    }
}

void ComputerShop::createComponent() {
    switch (selectComponentType()) {
        case ComponentType_t::CASE:
            my_components.insert({ComponentType_t::CASE, std::static_pointer_cast<ComponentBase>(Case::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::CASE);
            serializeShop();
            break;
        case ComponentType_t::CPU:
            my_components.insert({ComponentType_t::CPU, std::static_pointer_cast<ComponentBase>(CPU::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::CPU);
            serializeShop();
            break;
        case ComponentType_t::GPU:
            my_components.insert({ComponentType_t::GPU, std::static_pointer_cast<ComponentBase>(GPU::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::GPU);
            serializeShop();
            break;
        case ComponentType_t::STORAGE:
            my_components.insert({ComponentType_t::STORAGE, std::static_pointer_cast<ComponentBase>(Storage::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::STORAGE);
            serializeShop();
            break;
        case ComponentType_t::MOTHERBOARD:
            my_components.insert({ComponentType_t::MOTHERBOARD, std::static_pointer_cast<ComponentBase>(Motherboard::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::MOTHERBOARD);
            serializeShop();
            break;
        case ComponentType_t::PSU:
            my_components.insert({ComponentType_t::PSU, std::static_pointer_cast<ComponentBase>(PowerSupply::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::PSU);
            serializeShop();
            break;
        case ComponentType_t::RAM:
            my_components.insert({ComponentType_t::RAM, std::static_pointer_cast<ComponentBase>(Memory::Create(lastComponentID++))});
            serializeComponentType(ComponentType_t::RAM);
            serializeShop();
            break;
        case ComponentType_t::UNKNOWN: // should never happen
            throw std::runtime_error("Unknown component type");
    }
}

std::weak_ptr<Customer> ComputerShop::searchCustomer() {
    CustomerView view(my_customers);
    if (view.size() == 0)
        throw std::runtime_error("No customers found");
    bool found = false;
    int index;
    std::weak_ptr<Customer> customer;

    // filter customers until one is selected
    while (!found) {
        // print customers in view
        Company::printTopRow(true);
        for (auto [i, c]: Enumerate(view)) {
            c.lock()->printRow((int) i);
            std::cout << std::endl;
        }

        // add filter for customer type or select customer or reset filter
        std::cout << "Add filter (a), reset filter (r), Create customer (c), select customer (index of customer): ";
        std::string input;
        std::getline(std::cin, input);
        if ((view.getType() == CustomerType_t::PARTICULIER ||  view.getType() == CustomerType_t::UNKNOWN) && input == "a") // add filter for particulier
            Customer::selectFilter(view);
        else if (view.getType() == CustomerType_t::BEDRIJF && input == "a") // add filter for bedrijf
            Company::selectFilter(view);
        else if (input == "r") { // reset filter
            view = CustomerView(my_customers);
        } else if (input == "c") { // Create customer
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
    if (view.size() == 0)
        throw std::runtime_error("No components found");

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
    CustomerType_t type = customer.lock()->getType();
    auto c = customer.lock();
    if (c == nullptr)
        throw std::runtime_error("Customer does not exist"); // should never happen

    my_customers.erase(std::remove(my_customers.begin(), my_customers.end(), c), my_customers.end());
    serializeCustomerType(type);
}

void ComputerShop::removeComponent(const std::weak_ptr<ComponentBase>& component) {
    ComponentType_t type = component.lock()->getType();
    auto c = component.lock();
    if (c != nullptr)
        throw std::runtime_error("Component does not exist"); // should never happen

    auto range = my_components.equal_range(c->getType());
    for (auto it = range.first; it != range.second; ++it)
        if (it->second == c) {
            my_components.erase(it);
            break;
        }
    serializeComponentType(type);
}

void ComputerShop::updateCustomer(const std::weak_ptr<Customer> &customer) {
    customer.lock()->update();
    serializeCustomerType(customer.lock()->getType());
}

void ComputerShop::updateComponent(const std::weak_ptr<ComponentBase> &component) {
    component.lock()->update();
    serializeComponentType(component.lock()->getType());
}

Invoice ComputerShop::buildSystem(const std::weak_ptr<Customer>& customer) {
    Invoice invoice(1, customer);
    // select system type
    ComputerType_t systemType = selectComputerType();

    try {
        // select components
        // select CPU
        invoice.addComponents(searchComponent(ComponentType_t::CPU, systemType));
        // select Motherboard
        invoice.addComponents(searchComponent(ComponentType_t::MOTHERBOARD, systemType));
        // select RAM
        invoice.addComponents(searchComponent(ComponentType_t::RAM, systemType));
        // select GPU
        invoice.addComponents(searchComponent(ComponentType_t::GPU, systemType));
        // select Storage
        invoice.addComponents(searchComponent(ComponentType_t::STORAGE, systemType));
        // select PSU
        invoice.addComponents(searchComponent(ComponentType_t::PSU, systemType));
        // select Case
        invoice.addComponents(searchComponent(ComponentType_t::CASE, systemType));

        // additional components
        while (yesNoQuestion("Do you want to add additional components?"))
            invoice.addComponents(searchComponent(ComponentType_t::UNKNOWN, systemType));
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        throw std::runtime_error("Could not build system");
    }

    invoice.calculatePrice();
    invoice.print();
    return invoice;
}

void ComputerShop::serializeComponentType(ComponentType_t type) const {
    // open file
    std::ofstream file{my_workingDirectory + "/" + componentTypeToString(type) + ".bin", std::ios::binary | std::ios::out};
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    // get size of component
    std::streamsize size = getComponentTypeSize(type);
    // write components
    for (auto c = my_components.lower_bound(type); c != my_components.upper_bound(type); ++c) {
        ComponentBase* component = c->second.get();
        file.write(reinterpret_cast<const char *>(component), size);
    }
    file.close();
}

void ComputerShop::serializeCustomerType(CustomerType_t type) const {
    // open file
    std::ofstream file{my_workingDirectory + "/" + customerTypeToString(type) + ".bin", std::ios::binary | std::ios::out};
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    // get size of component
    std::streamsize size = getCustomerTypeSize(type);
    // write components
    for (const auto& c: my_customers) {
        if (c->getType() == type) {
            Customer *customer = c.get();
            file.write(reinterpret_cast<const char *>(customer), size);
        }
    }
    file.close();
}

void ComputerShop::serializeShop() const {
    std::ofstream file{my_workingDirectory + "/shop.bin", std::ios::binary};
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    file.write((char*)(&lastComponentID), sizeof(lastComponentID));
    file.write((char*)(&lastCustomerID), sizeof(lastCustomerID));
    file.close();
}

void ComputerShop::deserializeShop() {
    std::ifstream file{my_workingDirectory + "/shop.bin", std::ios::binary};
    if (!file.is_open())
        return; // no shop data is serialized
    file.read((char*)(&lastComponentID), sizeof(lastComponentID));
    file.read((char*)(&lastCustomerID), sizeof(lastCustomerID));
    file.close();
}

void ComputerShop::load() {
    // load customers
    deserializeCustomerType<Customer>(CustomerType_t::PARTICULIER);
    deserializeCustomerType<Company>(CustomerType_t::BEDRIJF);
    // load components
    deserializeComponentType<Case>(ComponentType_t::CASE);
    deserializeComponentType<CPU>(ComponentType_t::CPU);
    deserializeComponentType<GPU>(ComponentType_t::GPU);
    deserializeComponentType<Memory>(ComponentType_t::RAM);
    deserializeComponentType<Motherboard>(ComponentType_t::MOTHERBOARD);
    deserializeComponentType<PowerSupply>(ComponentType_t::PSU);
    deserializeComponentType<Storage>(ComponentType_t::STORAGE);
    // load shop data
    deserializeShop();
}

std::streamsize ComputerShop::getComponentTypeSize(ComponentType_t type) {
    switch (type) {
        case ComponentType_t::CASE:
            return sizeof(Case);
        case ComponentType_t::CPU:
            return sizeof(CPU);
        case ComponentType_t::GPU:
            return sizeof(GPU);
        case ComponentType_t::STORAGE:
            return sizeof(Storage);
        case ComponentType_t::MOTHERBOARD:
            return sizeof(Motherboard);
        case ComponentType_t::PSU:
            return sizeof(PowerSupply);
        case ComponentType_t::RAM:
            return sizeof(Memory);
        case ComponentType_t::UNKNOWN: // should never happen
            throw std::runtime_error("Unknown component type");
    }
}

std::streamsize ComputerShop::getCustomerTypeSize(CustomerType_t type) {
    switch (type) {
        case CustomerType_t::PARTICULIER:
            return sizeof(Customer);
        case CustomerType_t::BEDRIJF:
            return sizeof(Company);
        case CustomerType_t::UNKNOWN: // should never happen
            throw std::runtime_error("Unknown customer type");
    }
}
