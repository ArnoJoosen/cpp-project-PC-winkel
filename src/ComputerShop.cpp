//
// Created by arno on 2/12/23.
//

#include "ComputerShop.h"

ComputerShop::ComputerShop(std::string name, Address_t address) : my_name(std::move(name)), my_address(address) {

}

void ComputerShop::addComponent(ComponentBase *component) {
    my_components.push_back(component);
}

void ComputerShop::addCustomer(Customer *customer) {
    my_customers.push_back(customer);
}

void ComputerShop::removeComponent(unsigned int componentID) {
    // TODO: implement
}

void ComputerShop::removeCustomer(unsigned int customerID) {
    // TODO: implement
}

void ComputerShop::createCustomer() {
    // TODO create customer from console input
}

void ComputerShop::createComponent() {
    // TODO create component from console input
}

Customer* ComputerShop::searchCustomer() {
    // TODO search customer from console input
    return nullptr;
}

ComponentBase* ComputerShop::searchComponent() {
    // TODO search component from console input
    return nullptr;
}

void ComputerShop::updateCustomer(unsigned int customerID) {
    // TODO update customer from console input
}

void ComputerShop::updateComponent(unsigned int componentID) {
    // TODO update component from console input
}
