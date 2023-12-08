//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPUTERSHOP_H
#define PC_WINKLE_COMPUTERSHOP_H
#include <string>
#include <vector>
#include <map>
#include "CapString.hpp"
#include "Components/ComponentBase.h"
#include "Customer.h"
#include "types.h"
#include <memory>
#include "Invoice.h"
#define MAX_SHOP_NAME_LENGTH 50

class ComputerShop {
public:
    ComputerShop(std::string name, Address_t address);

    [[nodiscard]] inline CapString<MAX_SHOP_NAME_LENGTH> getName() const { return my_name; }
    [[nodiscard]] inline Address_t getAddress() const { return my_address; }
    [[nodiscard]] inline std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> getComponents() const { return my_components; }
    [[nodiscard]] inline std::vector<std::shared_ptr<Customer>> getCustomers() const { return my_customers; }

    inline void setName(const std::string& name) { my_name = name; }
    inline void setAddress(const Address_t& address) { my_address = address; }

    void addComponent(const std::shared_ptr<ComponentBase>& component);
    void addCustomer(const std::shared_ptr<Customer>& customer);

    // console input
    void createCustomer();
    void createComponent();
    std::shared_ptr<Customer> searchCustomer();
    std::shared_ptr<ComponentBase> searchComponent(ComponentType_t type = ComponentType_t::UNKNOWN, ComputerType_t computerType = ComputerType_t::UNKNOWN);
    void removeCustomer(const std::shared_ptr<Customer>& customer);
    void removeComponent(const std::shared_ptr<ComponentBase>& component);
    std::shared_ptr<Invoice> buildSystem(const std::shared_ptr<Customer>& customer);

private:
    CapString<MAX_SHOP_NAME_LENGTH> my_name;
    Address_t my_address;
    std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> my_components;
    std::vector<std::shared_ptr<Customer>> my_customers;
    unsigned int lastComponentID = 0;
    unsigned int lastCustomerID = 0;
};

#endif //PC_WINKLE_COMPUTERSHOP_H
