//
// Created by arno on 3/12/23.
//

#include "CustomerView.h"
#include "Customer.h"

CustomerView::CustomerView(const std::vector<std::shared_ptr<class Customer>> &customers, CustomerType_t type) : my_type(type), my_customers(customers.begin(), customers.end()) {
    if (type != CustomerType_t::UNKNOWN) {
        filter([type](const std::weak_ptr<class Customer>& customer) {
            return customer.lock()->getType() != type;
        });
    }
}

void CustomerView::filter(const std::function<bool(const std::weak_ptr<class Customer>&)> &filter) {
    my_customers.erase( std::remove_if(my_customers.begin(), my_customers.end(), filter), my_customers.end());
}

void CustomerView::setType(CustomerType_t type) {
    my_type = type;
    filter([type](const std::weak_ptr<class Customer>& customer) {
        return customer.lock()->getType() != type;
    });
}
