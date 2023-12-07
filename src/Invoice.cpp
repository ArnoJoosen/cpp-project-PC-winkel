//
// Created by arno on 2/12/23.
//

#include "Invoice.h"

Invoice::Invoice(unsigned int invoiceID, const std::shared_ptr<Customer>& customer) :
    my_invoiceID(invoiceID), my_customer(customer), my_components({}){
}

void Invoice::print() const {
    // print components
    ComponentBase::printHeader();
    for (const auto& component : my_components)
        component->printBase();
}
