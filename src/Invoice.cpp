//
// Created by arno on 2/12/23.
//

#include "Invoice.h"

Invoice::Invoice(unsigned int invoiceID, const std::weak_ptr<Customer>& customer) :
    my_invoiceID(invoiceID), my_customer(customer), my_components({}){
}

void Invoice::print() const {
    // print components
    ComponentBase::printHeader();
    for (const auto& component : my_components)
        if (auto component_ptr = component.lock()) // check if component still exists
            component_ptr->printBase();
        else
            std::cout << "Component no longer exists" << std::endl;
}
