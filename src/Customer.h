//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_CUSTOMER_H
#define PC_WINKLE_CUSTOMER_H
#include <memory>
#include "CustomerProperties.h"
#include "types.h"

class Customer {
public:
    Customer(Name_t name, Address_t address, unsigned int customerID);

    [[nodiscard]] inline Name_t getName() const { return my_name; }
    [[nodiscard]] inline Address_t getAddress() const { return my_address; }
    [[nodiscard]] inline unsigned int getCustomerID() const { return my_customerID; }
    [[nodiscard]] inline CustomerType_t getType() const { return my_type; }

    inline void setName(Name_t name) { my_name = std::move(name); }
    inline void setAddress(Address_t address) { my_address = std::move(address); }
    inline void setCustomerID(unsigned int customerID) { my_customerID = customerID; }
    inline void setType(CustomerType_t type) { my_type = type; }

    static std::shared_ptr<Customer> create(unsigned int customerID);

protected:
    Name_t my_name;
    Address_t my_address;
    unsigned int my_customerID;
    CustomerType_t my_type;
};


#endif //PC_WINKLE_CUSTOMER_H
