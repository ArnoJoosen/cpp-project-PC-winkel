//
// Created by arno on 9/12/23.
//

#ifndef PC_WINKLE_DESERIALIZETEST_H
#define PC_WINKLE_DESERIALIZETEST_H
#include <gtest/gtest.h>
#include <fstream>
#include <memory>
#include <Components/CPU.h>
#include "ComputerShop.h"
#include "Components/Case.h"
#include "Components/GPU.h"
#include "Components/Memory.h"
#include "Components/Motherboard.h"
#include "Components/PowerSupply.h"
#include "Components/Storage.h"

class deserialize : public ::testing::Test {
protected:
    void SetUp() override {
        // components
        ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
        case1 = std::make_shared<Case>(
                "Cooler Master",
                "MasterBox MB520",
                70,
                10,
                ComputerType_t::DESKTOP,
                1,
                "Black",
                "ATX",
                "Steel"
        );
        shop.addComponent(case1);
        cpu1 = std::make_shared<CPU>(
                "Intel",
                "i7-9700K",
                300,
                10,
                ComponentType_t::CPU,
                ComputerType_t::DESKTOP,
                1,
                3.6,
                8,
                "LGA1151"
        );
        shop.addComponent(cpu1);
        cpu2 = std::make_shared<CPU>(
                "Intel",
                "i5-9600K",
                200,
                10,
                ComponentType_t::CPU,
                ComputerType_t::DESKTOP,
                2,
                3.7,
                6,
                "LGA1151"
        );
        shop.addComponent(cpu2);
        gpu1 = std::make_shared<GPU>(
                "Nvidia",
                "RTX 2080",
                700,
                10,
                ComponentType_t::GPU,
                ComputerType_t::DESKTOP,
                1,
                3,
                1.5
        );
        shop.addComponent(gpu1);
        memory1 = std::make_shared<Memory>(
                "Corsair",
                "Vengeance LPX",
                100,
                10,
                ComponentType_t::RAM,
                ComputerType_t::DESKTOP,
                1,
                16,
                3200
        );
        shop.addComponent(memory1);
        motherboard1 = std::make_shared<Motherboard>(
                "Asus",
                "ROG Strix Z390-E",
                200,
                10,
                ComponentType_t::MOTHERBOARD,
                ComputerType_t::DESKTOP,
                1,
                "LGA1151",
                "ATX",
                4
        );
        shop.addComponent(motherboard1);
        powerSupply1 = std::make_shared<PowerSupply>(
                "Corsair",
                "RM750x",
                100,
                10,
                ComponentType_t::PSU,
                ComputerType_t::DESKTOP,
                1,
                750,
                "80+ Gold"
        );
        shop.addComponent(powerSupply1);
        storage1 = std::make_shared<Storage>(
                "Samsung",
                "860 EVO",
                100,
                10,
                ComponentType_t::STORAGE,
                ComputerType_t::DESKTOP,
                1,
                500.5,
                500,
                "M.2"
        );
        shop.addComponent(storage1);

        shop.serializeComponentType(pwd, ComponentType_t::CPU);
        shop.serializeComponentType(pwd, ComponentType_t::CASE);
        shop.serializeComponentType(pwd, ComponentType_t::GPU);
        shop.serializeComponentType(pwd, ComponentType_t::RAM);
        shop.serializeComponentType(pwd, ComponentType_t::MOTHERBOARD);
        shop.serializeComponentType(pwd, ComponentType_t::PSU);
        shop.serializeComponentType(pwd, ComponentType_t::STORAGE);

        // customers
        // customer
        customer1 = std::make_shared<Customer>(
                Name_t{"Arno", "Joosen"},
                Address_t{"Kerkstraat", "Zwolle", 8011, 1},
                1,
                CustomerType_t::PARTICULIER
        );
        shop.addCustomer(customer1);
        customer2 = std::make_shared<Customer>(
                Name_t{"Mram", "Pos"},
                Address_t{"Achterstraat", "Luttenberg", 8105, 1},
                2,
                CustomerType_t::PARTICULIER
        );
        shop.addCustomer(customer2);
        company1 = std::make_shared<Company>(
                Name_t{"Bos", "Bos"},
                Address_t{"Luttenbergstraat", "Bosberg", 9000, 1},
                3,
                5.2,
                1.2,
                5
        );
        shop.addCustomer(company1);
        shop.serializeCustomerType(pwd, CustomerType_t::PARTICULIER);
        shop.serializeCustomerType(pwd, CustomerType_t::BEDRIJF);
    }
    std::string pwd = ".";

    // components
    std::shared_ptr<Case> case1;
    std::shared_ptr<CPU> cpu1;
    std::shared_ptr<CPU> cpu2;
    std::shared_ptr<GPU> gpu1;
    std::shared_ptr<Memory> memory1;
    std::shared_ptr<Motherboard> motherboard1;
    std::shared_ptr<PowerSupply> powerSupply1;
    std::shared_ptr<Storage> storage1;

    // customers
    // customer
    std::shared_ptr<Customer> customer1;
    std::shared_ptr<Customer> customer2;
    std::shared_ptr<Company> company1;
};

TEST_F(deserialize, deserializeCPU) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<CPU>(pwd, ComponentType_t::CPU);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first CPU
    auto c1 = std::dynamic_pointer_cast<CPU>(it->second);
    ASSERT_EQ(c1->getName(), cpu1->getName());
    ASSERT_EQ(c1->getManufacturer(), cpu1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), cpu1->getPrice());
    ASSERT_EQ(c1->getStock(), cpu1->getStock());
    ASSERT_EQ(c1->getComputerType(), cpu1->getComputerType());
    ASSERT_EQ(c1->getType(), cpu1->getType());
    ASSERT_EQ(c1->getComponentID(), cpu1->getComponentID());
    ASSERT_EQ(c1->getClockSpeed(), cpu1->getClockSpeed());
    ASSERT_EQ(c1->getCoreCount(), cpu1->getCoreCount());
    ASSERT_EQ(c1->getSocket(), cpu1->getSocket());

    // test second CPU
    it++;
    auto c2 = std::dynamic_pointer_cast<CPU>(it->second);
    ASSERT_EQ(c2->getName(), cpu2->getName());
    ASSERT_EQ(c2->getManufacturer(), cpu2->getManufacturer());
    ASSERT_EQ(c2->getPrice(), cpu2->getPrice());
    ASSERT_EQ(c2->getStock(), cpu2->getStock());
    ASSERT_EQ(c2->getComputerType(), cpu2->getComputerType());
    ASSERT_EQ(c2->getType(), cpu2->getType());
    ASSERT_EQ(c2->getComponentID(), cpu2->getComponentID());
    ASSERT_EQ(c2->getClockSpeed(), cpu2->getClockSpeed());
    ASSERT_EQ(c2->getCoreCount(), cpu2->getCoreCount());
    ASSERT_EQ(c2->getSocket(), cpu2->getSocket());
}

TEST_F(deserialize, deserializeCase) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<Case>(pwd, ComponentType_t::CASE);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first Case
    auto c1 = std::dynamic_pointer_cast<Case>(it->second);
    ASSERT_EQ(c1->getName(), case1->getName());
    ASSERT_EQ(c1->getManufacturer(), case1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), case1->getPrice());
    ASSERT_EQ(c1->getStock(), case1->getStock());
    ASSERT_EQ(c1->getComputerType(), case1->getComputerType());
    ASSERT_EQ(c1->getType(), case1->getType());
    ASSERT_EQ(c1->getComponentID(), case1->getComponentID());
    ASSERT_EQ(c1->get_color(), case1->get_color());
    ASSERT_EQ(c1->get_MotherboardSize(), case1->get_MotherboardSize());
    ASSERT_EQ(c1->get_material(), case1->get_material());
}

TEST_F(deserialize, deserializeGPU) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<GPU>(pwd, ComponentType_t::GPU);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first GPU
    auto c1 = std::dynamic_pointer_cast<GPU>(it->second);
    ASSERT_EQ(c1->getName(), gpu1->getName());
    ASSERT_EQ(c1->getManufacturer(), gpu1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), gpu1->getPrice());
    ASSERT_EQ(c1->getStock(), gpu1->getStock());
    ASSERT_EQ(c1->getComputerType(), gpu1->getComputerType());
    ASSERT_EQ(c1->getType(), gpu1->getType());
    ASSERT_EQ(c1->getComponentID(), gpu1->getComponentID());
    ASSERT_EQ(c1->getBusSpeed(), gpu1->getBusSpeed());
    ASSERT_EQ(c1->getPower(), gpu1->getPower());
}

TEST_F(deserialize, deserializeMemory) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<Memory>(pwd, ComponentType_t::RAM);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first Memory
    auto c1 = std::dynamic_pointer_cast<Memory>(it->second);
    ASSERT_EQ(c1->getName(), memory1->getName());
    ASSERT_EQ(c1->getManufacturer(), memory1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), memory1->getPrice());
    ASSERT_EQ(c1->getStock(), memory1->getStock());
    ASSERT_EQ(c1->getComputerType(), memory1->getComputerType());
    ASSERT_EQ(c1->getType(), memory1->getType());
    ASSERT_EQ(c1->getComponentID(), memory1->getComponentID());
    ASSERT_EQ(c1->getSize(), memory1->getSize());
    ASSERT_EQ(c1->getClockSpeed(), memory1->getClockSpeed());
}

TEST_F(deserialize, deserializeMotherboard) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<Motherboard>(pwd, ComponentType_t::MOTHERBOARD);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first Motherboard
    auto c1 = std::dynamic_pointer_cast<Motherboard>(it->second);
    ASSERT_EQ(c1->getName(), motherboard1->getName());
    ASSERT_EQ(c1->getManufacturer(), motherboard1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), motherboard1->getPrice());
    ASSERT_EQ(c1->getStock(), motherboard1->getStock());
    ASSERT_EQ(c1->getComputerType(), motherboard1->getComputerType());
    ASSERT_EQ(c1->getType(), motherboard1->getType());
    ASSERT_EQ(c1->getComponentID(), motherboard1->getComponentID());
    ASSERT_EQ(c1->getSocket(), motherboard1->getSocket());
    ASSERT_EQ(c1->getFormFactor(), motherboard1->getFormFactor());
    ASSERT_EQ(c1->getMaxMemorySlots(), motherboard1->getMaxMemorySlots());
}

TEST_F(deserialize, deserializePowerSupply) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<PowerSupply>(pwd, ComponentType_t::PSU);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first PowerSupply
    auto c1 = std::dynamic_pointer_cast<PowerSupply>(it->second);
    ASSERT_EQ(c1->getName(), powerSupply1->getName());
    ASSERT_EQ(c1->getManufacturer(), powerSupply1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), powerSupply1->getPrice());
    ASSERT_EQ(c1->getStock(), powerSupply1->getStock());
    ASSERT_EQ(c1->getComputerType(), powerSupply1->getComputerType());
    ASSERT_EQ(c1->getType(), powerSupply1->getType());
    ASSERT_EQ(c1->getComponentID(), powerSupply1->getComponentID());
    ASSERT_EQ(c1->get_power(), powerSupply1->get_power());
    ASSERT_EQ(c1->get_certification(), powerSupply1->get_certification());
}

TEST_F(deserialize, deserializeStorage) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeComponentType<Storage>(pwd, ComponentType_t::STORAGE);
    auto components = shop.getComponents();
    auto it = components.begin();

    // test first Storage
    auto c1 = std::dynamic_pointer_cast<Storage>(it->second);
    ASSERT_EQ(c1->getName(), storage1->getName());
    ASSERT_EQ(c1->getManufacturer(), storage1->getManufacturer());
    ASSERT_EQ(c1->getPrice(), storage1->getPrice());
    ASSERT_EQ(c1->getStock(), storage1->getStock());
    ASSERT_EQ(c1->getComputerType(), storage1->getComputerType());
    ASSERT_EQ(c1->getType(), storage1->getType());
    ASSERT_EQ(c1->getComponentID(), storage1->getComponentID());
    ASSERT_EQ(c1->getSize(), storage1->getSize());
    ASSERT_EQ(c1->getSpeed(), storage1->getSpeed());
    ASSERT_EQ(c1->getSlot(), storage1->getSlot());
}

TEST_F(deserialize, deserializeCustomer) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeCustomerType<Customer>(pwd, CustomerType_t::PARTICULIER);
    auto customers = shop.getCustomers();
    auto it = customers.begin();

    // test first Customer
    auto c1 = std::dynamic_pointer_cast<Customer>(*it);
    ASSERT_EQ(c1->getName().firstName, customer1->getName().firstName);
    ASSERT_EQ(c1->getName().lastName, customer1->getName().lastName);
    ASSERT_EQ(c1->getAddress().street, customer1->getAddress().street);
    ASSERT_EQ(c1->getAddress().city, customer1->getAddress().city);
    ASSERT_EQ(c1->getAddress().postcode, customer1->getAddress().postcode);
    ASSERT_EQ(c1->getAddress().houseNumber, customer1->getAddress().houseNumber);
    ASSERT_EQ(c1->getCustomerID(), customer1->getCustomerID());
    ASSERT_EQ(c1->getType(), customer1->getType());

    // test second Customer
    it++;
    auto c2 = std::dynamic_pointer_cast<Customer>(*it);
    ASSERT_EQ(c2->getName().firstName, customer2->getName().firstName);
    ASSERT_EQ(c2->getName().lastName, customer2->getName().lastName);
    ASSERT_EQ(c2->getAddress().street, customer2->getAddress().street);
    ASSERT_EQ(c2->getAddress().city, customer2->getAddress().city);
    ASSERT_EQ(c2->getAddress().postcode, customer2->getAddress().postcode);
    ASSERT_EQ(c2->getAddress().houseNumber, customer2->getAddress().houseNumber);
    ASSERT_EQ(c2->getCustomerID(), customer2->getCustomerID());
    ASSERT_EQ(c2->getType(), customer2->getType());
}

TEST_F(deserialize, deserializeCompany) {
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651});
    shop.deserializeCustomerType<Company>(pwd, CustomerType_t::BEDRIJF);
    auto customers = shop.getCustomers();
    auto it = customers.begin();

    // test first Company
    auto c1 = std::dynamic_pointer_cast<Company>(*it);
    ASSERT_EQ(c1->getName().firstName, company1->getName().firstName);
    ASSERT_EQ(c1->getName().lastName, company1->getName().lastName);
    ASSERT_EQ(c1->getAddress().street, company1->getAddress().street);
    ASSERT_EQ(c1->getAddress().city, company1->getAddress().city);
    ASSERT_EQ(c1->getAddress().postcode, company1->getAddress().postcode);
    ASSERT_EQ(c1->getAddress().houseNumber, company1->getAddress().houseNumber);
    ASSERT_EQ(c1->getCustomerID(), company1->getCustomerID());
    ASSERT_EQ(c1->getType(), company1->getType());
    ASSERT_EQ(c1->getDiscount(), company1->getDiscount());
    ASSERT_EQ(c1->getVat(), company1->getVat());
}


#endif //PC_WINKLE_DESERIALIZETEST_H
