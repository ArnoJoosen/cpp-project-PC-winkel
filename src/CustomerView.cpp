//
// Created by arno on 3/12/23.
//

#include "CustomerView.h"
#include "Customer.h"

CustomerView::CustomerView(const std::vector<Customer *> &customers, CustomerType_t type) : my_customers(customers), my_type(type) {
    if (type != CustomerType_t::UNKNOWN) {
        filter([type](Customer *component) {
            return component->getType() == type;
        });
    }
}

void CustomerView::filter(const std::function<bool(Customer *)> &filter) {
    my_customers.erase(std::remove_if(my_customers.begin(), my_customers.end(), filter), my_customers.end());
}

void CustomerView::setType(CustomerType_t type) {
    my_type = type;
    filter([type](Customer *component) {
        return component->getType() == type;
    });
}
