//
// Created by arno on 2/12/23.
//

#include "Invoice.h"

Invoice::Invoice(unsigned int invoiceID, Customer *customer, const std::vector<ComponentBase *> &components) :
    my_invoiceID(invoiceID), my_customer(customer), my_components(components){

}
