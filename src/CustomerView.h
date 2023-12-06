//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_CUSTOMERVIEW_H
#define PC_WINKLE_CUSTOMERVIEW_H
#include <vector>
#include <functional>
#include <memory>
#include "CustomerProperties.h"

class CustomerView {
public:
    using value_type = std::shared_ptr<class Customer>;
    using iterator = std::vector<std::shared_ptr<class Customer>>::iterator;
    using const_iterator = std::vector<std::shared_ptr<class Customer>>::const_iterator;

    CustomerView(const std::vector<std::shared_ptr<class Customer>>& customers, CustomerType_t type = CustomerType_t::UNKNOWN);

    void filter(const std::function<bool(const std::shared_ptr<class Customer>&)> &filter);
    void setType(CustomerType_t type);

    inline const_iterator begin() const { return my_customers.begin(); }
    inline const_iterator end() const { return my_customers.end(); }

    [[nodiscard]] inline size_t size() const { return my_customers.size(); }
    inline bool empty() { return my_customers.empty(); }
    inline CustomerType_t getType() { return my_type; }

    inline std::shared_ptr<Customer> operator[](int index) { return my_customers[index]; }

private:
    std::vector<std::shared_ptr<class Customer>> my_customers;
    CustomerType_t my_type;
};


#endif //PC_WINKLE_CUSTOMERVIEW_H
