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
    ComputerShop(const std::string& name, Address_t address, std::string workingDirectory);

    [[nodiscard]] inline CapString<MAX_SHOP_NAME_LENGTH> getName() const { return my_name; }
    [[nodiscard]] inline Address_t getAddress() const { return my_address; }
    [[nodiscard]] inline std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> getComponents() const { return my_components; }
    [[nodiscard]] inline std::vector<std::shared_ptr<Customer>> getCustomers() const { return my_customers; }
    [[nodiscard]] inline std::string getWorkingDirectory() const { return my_workingDirectory; }

    inline void setName(const std::string& name) { my_name = name; }
    inline void setAddress(const Address_t& address) { my_address = address; }
    inline void setWorkingDirectory(const std::string& workingDirectory) { my_workingDirectory = workingDirectory; }

    void addComponent(const std::shared_ptr<ComponentBase>& component);
    void addCustomer(const std::shared_ptr<Customer>& customer);

    // console input
    void createCustomer();
    void createComponent();
    std::weak_ptr<Customer> searchCustomer();
    std::weak_ptr<ComponentBase> searchComponent(ComponentType_t type = ComponentType_t::UNKNOWN, ComputerType_t computerType = ComputerType_t::UNKNOWN);
    void removeCustomer(const std::weak_ptr<Customer>& customer);
    void removeComponent(const std::weak_ptr<ComponentBase>& component);
    void updateCustomer(const std::weak_ptr<Customer>& customer);
    void updateComponent(const std::weak_ptr<ComponentBase>& component);
    Invoice buildSystem(const std::weak_ptr<Customer>& customer);

    // serialization
    void serializeComponentType(ComponentType_t type) const ;
    void serializeCustomerType(CustomerType_t type) const;
    void serializeShop() const;

    template<class T>
    void deserializeComponentType(ComponentType_t type) {
        // open file
        std::ifstream file{my_workingDirectory + "/" + componentTypeToString(type) + ".bin", std::ios::binary | std::ios::in};
        if (!file.is_open())
            return; // no components of this type are serialized
        // get size of component
        std::streamsize size = getComponentTypeSize(type);
        // read components
        while (file) {
            auto componentCase = std::make_shared<T>();
            file.read(reinterpret_cast<char*>(componentCase.get()), size);
            if (!file.eof())
                addComponent(componentCase);
        }
        file.close();
    }

    template<class T>
    void deserializeCustomerType(CustomerType_t type){
        // open file
        std::ifstream file{my_workingDirectory + "/" + customerTypeToString(type) + ".bin", std::ios::binary | std::ios::in};
        if (!file.is_open())
            return; // no components of this type are serialized
        // get size of component
        std::streamsize size = getCustomerTypeSize(type);
        // read components
        while (file) {
            std::shared_ptr<T> customerCase = std::make_shared<T>();
            file.read(reinterpret_cast<char*>(customerCase.get()), size);
            if (!file.eof())
                addCustomer(customerCase);
        }
        file.close();
    }
    void deserializeShop();
    void load(); // load all data from working directory

private:
    static std::streamsize getComponentTypeSize(ComponentType_t type);
    static std::streamsize getCustomerTypeSize(CustomerType_t type);

    CapString<MAX_SHOP_NAME_LENGTH> my_name;
    Address_t my_address;
    std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> my_components;
    std::vector<std::shared_ptr<Customer>> my_customers;
    unsigned int lastComponentID = 0;
    unsigned int lastCustomerID = 0;
    std::string my_workingDirectory = "./data";
};

#endif //PC_WINKLE_COMPUTERSHOP_H
