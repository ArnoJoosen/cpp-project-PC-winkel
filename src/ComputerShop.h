//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPUTERSHOP_H
#define PC_WINKLE_COMPUTERSHOP_H
#include <string>
#include <vector>
#include "Components/ComponentBase.h"
#include "Customer.h"
#include "types.h"

class ComputerShop {
public:
    ComputerShop(std::string name, Address_t address);

    [[nodiscard]] inline std::string getName() const { return my_name; }
    [[nodiscard]] inline Address_t getAddress() const { return my_address; }
    [[nodiscard]] inline std::vector<ComponentBase*> getComponents() const { return my_components; }
    [[nodiscard]] inline std::vector<Customer*> getCustomers() const { return my_customers; }

    inline void setName(std::string name) { my_name = std::move(name); }
    inline void setAddress(Address_t address) { my_address = address; }

    void addComponent(ComponentBase* component);
    void addCustomer(Customer* customer);
    void removeComponent(unsigned int componentID);
    void removeCustomer(unsigned int customerID);

    // console input
    void createCustomer();
    void createComponent();
    Customer* searchCustomer();
    ComponentBase* searchComponent();
    void updateCustomer(unsigned int customerID);
    void updateComponent(unsigned int componentID);

private:
    std::string my_name;
    Address_t my_address;
    std::vector<ComponentBase*> my_components;
    std::vector<Customer*> my_customers;
};


#endif //PC_WINKLE_COMPUTERSHOP_H
