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
#include <fstream>
#define MAX_SHOP_NAME_LENGTH 50

class ComputerShop {
public:
    ComputerShop(const std::string& name, Address_t address);

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
    std::weak_ptr<Customer> searchCustomer();
    std::weak_ptr<ComponentBase> searchComponent(ComponentType_t type = ComponentType_t::UNKNOWN, ComputerType_t computerType = ComputerType_t::UNKNOWN);
    void removeCustomer(const std::weak_ptr<Customer>& customer);
    void removeComponent(const std::weak_ptr<ComponentBase>& component);
    std::shared_ptr<Invoice> buildSystem(const std::weak_ptr<Customer>& customer);

    // serialization
    void serializeComponentType(const std::string& pwd, ComponentType_t type) const ; // pwd = phat to working directory
    void serializeCustomerType(const std::string& pwd, CustomerType_t type) const; // pwd = phat to working directory
    void shopSerialize(const std::string& pwd) const; // pwd = phat to working directory

    // pwd = phat to working directory
    template<class T>
    void deserializeComponentType(const std::string &pwd, ComponentType_t type) {
        // open file
        std::ifstream file{pwd + "/" + componentTypeToString(type) + ".bin", std::ios::binary | std::ios::in};
        if (!file.is_open())
            return; // no components of this type are serialized
        // get size of component
        std::streamsize size = getComponentTypeSize(type);
        // read components
        while (file) {
            std::shared_ptr<T> componentCase = std::make_shared<T>();
            file.read(reinterpret_cast<char*>(componentCase.get()), size);
            addComponent(componentCase);
        }
        file.close();
    }

    // pwd = phat to working directory
    template<class T>
    void deserializeCustomerType(const std::string& pwd, CustomerType_t type){
        // open file
        std::ifstream file{pwd + "/" + customerTypeToString(type) + ".bin", std::ios::binary | std::ios::in};
        if (!file.is_open())
            return; // no components of this type are serialized
        // get size of component
        std::streamsize size = getCustomerTypeSize(type);
        // read components
        while (file) {
            std::shared_ptr<T> customerCase = std::make_shared<T>();
            file.read(reinterpret_cast<char*>(customerCase.get()), size);
            addCustomer(customerCase);
        }
        file.close();
    }
    void deserialize(const std::string& pwd); // pwd = phat to working directory

private:
    static std::streamsize getComponentTypeSize(ComponentType_t type);
    static std::streamsize getCustomerTypeSize(CustomerType_t type);

    CapString<MAX_SHOP_NAME_LENGTH> my_name;
    Address_t my_address;
    std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> my_components;
    std::vector<std::shared_ptr<Customer>> my_customers;
    unsigned int lastComponentID = 0;
    unsigned int lastCustomerID = 0;
};

#endif //PC_WINKLE_COMPUTERSHOP_H
