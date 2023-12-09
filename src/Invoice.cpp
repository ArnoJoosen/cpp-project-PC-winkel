//
// Created by arno on 2/12/23.
//

#include <fstream>
#include "Invoice.h"
#include "Company.h"

Invoice::Invoice(unsigned int invoiceID, const std::weak_ptr<Customer>& customer) :
    my_invoiceID(invoiceID), my_customer(customer), my_components({}){
}

void Invoice::calculatePrice() {
    totalPrice = 0;
    for (const auto& component : my_components) {
        if (auto component_ptr = component.lock()) // check if component still exists
            totalPrice += component_ptr->getPrice();
        else
            std::cout << "Component no longer exists" << std::endl;
    }
    if (auto customer_ptr = my_customer.lock()) {
        if (customer_ptr->getType() == CustomerType_t::BEDRIJF) {
            auto company_ptr = std::static_pointer_cast<Company>(customer_ptr);
            totalPrice *= (company_ptr->getDiscount()/100);
            totalPrice *= 1 + (company_ptr->getVat()/100);
        } else {
            totalPrice *= 1.21;
        }
    } else
        throw std::runtime_error("Customer no longer exists");
}

void Invoice::print() const {
    // print components
    ComponentBase::printHeader();
    for (const auto& component : my_components) {
        if (auto component_ptr = component.lock()) { // check if component still exists
            component_ptr->printBase();
            std::cout << std::endl;
        }
        else
            std::cout << "Component no longer exists" << std::endl;
    }
    std::cout << "Total price: " << totalPrice << " €" << std::endl;
}

void Invoice::serialize(const std::string& pwd) const {
    std::ofstream file(pwd + "/" + std::to_string(my_invoiceID) + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Kan het bestand niet openen");
    }
    file << my_invoiceID << "\n";

    // write customer ID
    auto customerID = my_customer.lock()->getCustomerID();
    file << customerID << "\n";

    file << totalPrice << "\n";

    // write number of components and their ID's
    auto numComponents = my_components.size();
    file << numComponents << "\n";
    for (const auto& component : my_components) {
        auto componentID = component.lock()->getComponentID();
        file << componentID << "\n";
    }

    file.close();
}

//TODO Invoice Invoice::deserialize(const std::string& pwd) {
//    std::ifstream file(pwd + "/" + std::to_string(my_invoiceID) + ".txt");
//    if (!file.is_open()) {
//        throw std::runtime_error("Kan het bestand niet openen");
//    }
//
//    auto invoice();
//    file >> invoice->my_invoiceID;
//    unsigned int customerID;
//    file >> customerID;
//    // TODO
//    if (customer.lock()->getCustomerID() != customerID) {
//        throw std::runtime_error("Klant-ID komt niet overeen");
//    }
//    file >> invoice->totalPrice;
//
//    // Lees het aantal componenten uit het bestand
//    unsigned int numComponents;
//    file >> numComponents;
//
//    // Lees de component-ID's uit het bestand
//    for (unsigned int i = 0; i < numComponents; ++i) {
//        unsigned int componentID;
//        file >> componentID;
//        //auto component = getComponentByID(componentID);
//        invoice->my_components.push_back(component);
//    }
//
//    file.close();
//
//    return invoice;
//}
