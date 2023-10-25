//
// Created by arno on 10/25/23.
//

#ifndef PC_WINKLE_SHOP_H
#define PC_WINKLE_SHOP_H
#include <string>
#include <vector>
#include <memory>
#include "Component.h"
#include "Customer.h"

class Shop {
public:
    using CompoentList_t = std::vector<std::shared_ptr<Component>>;
    using CustomerList_t = std::vector<std::shared_ptr<Customer>>;

    Shop(const char* name, const char* address);

    [[nodiscard]] inline std::string getName() const {return my_name;}
    inline void setName(std::string name) {my_name = name;}

    [[nodiscard]] inline std::string getAddress() {return my_address;}
    inline void setAddress(std::string address) {my_address = address;}

    inline CompoentList_t& getComponents() {return components;}
    void addComponent(Component component);

    inline CustomerList_t& getCustomers() {return customers;}
    void addCustomer(Customer customer);

private:
    std::string my_name;
    std::string my_address;
    CompoentList_t components;
    CustomerList_t customers;
};


#endif //PC_WINKLE_SHOP_H