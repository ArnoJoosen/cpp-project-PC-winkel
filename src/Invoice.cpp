//
// Created by arno on 2/12/23.
//

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