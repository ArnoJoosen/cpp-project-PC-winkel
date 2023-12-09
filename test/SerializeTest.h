//
// Created by arno on 9/12/23.
//

#ifndef PC_WINKLE_SERIALIZETEST_H
#define PC_WINKLE_SERIALIZETEST_H
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

class serialize : public ::testing::Test {
public:
    serialize() : shop("ComputerShop1", {"bb", "aa", 15, 1651}) {}

protected:
    void SetUp() override {
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
    }
    std::string pwd = ".";
    std::shared_ptr<Case> case1;
    std::shared_ptr<CPU> cpu1;
    std::shared_ptr<CPU> cpu2;
    std::shared_ptr<GPU> gpu1;
    std::shared_ptr<Memory> memory1;
    std::shared_ptr<Motherboard> motherboard1;
    std::shared_ptr<PowerSupply> powerSupply1;
    std::shared_ptr<Storage> storage1;
    ComputerShop shop;
};

TEST_F(serialize, serializeCPUTest){
    CPU component("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, 0, 0, "");
    std::ifstream file{pwd + "/" + componentTypeToString(ComponentType_t::CPU) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file.is_open()) << "Could not open file CPU.bin";

    // check for cpu1
    file.read(reinterpret_cast<char*>(&component), sizeof(component));
    ASSERT_EQ(component.getComponentID(), cpu1->getComponentID());
    ASSERT_EQ(component.getManufacturer(), cpu1->getManufacturer());
    ASSERT_EQ(component.getName(), cpu1->getName());
    ASSERT_EQ(component.getPrice(), cpu1->getPrice());
    ASSERT_EQ(component.getStock(), cpu1->getStock());
    ASSERT_EQ(component.getType(), cpu1->getType());
    ASSERT_EQ(component.getComputerType(), cpu1->getComputerType());
    ASSERT_EQ(component.getClockSpeed(), cpu1->getClockSpeed());
    ASSERT_EQ(component.getCoreCount(), cpu1->getCoreCount());
    ASSERT_EQ(component.getSocket(), cpu1->getSocket());

    // check for cpu2
    file.read(reinterpret_cast<char*>(&component), sizeof(component));
    ASSERT_EQ(component.getComponentID(), cpu2->getComponentID());
    ASSERT_EQ(component.getManufacturer(), cpu2->getManufacturer());
    ASSERT_EQ(component.getName(), cpu2->getName());
    ASSERT_EQ(component.getPrice(), cpu2->getPrice());
    ASSERT_EQ(component.getStock(), cpu2->getStock());
    ASSERT_EQ(component.getType(), cpu2->getType());
    ASSERT_EQ(component.getComputerType(), cpu2->getComputerType());
    ASSERT_EQ(component.getClockSpeed(), cpu2->getClockSpeed());
    ASSERT_EQ(component.getCoreCount(), cpu2->getCoreCount());
    ASSERT_EQ(component.getSocket(), cpu2->getSocket());
    file.close();
}

TEST_F(serialize, serializeCaseTest) {
    Case component2("", "", 0, 0, ComputerType_t::UNKNOWN, 0, "", "", "");
    std::ifstream file2{pwd + "/" + componentTypeToString(ComponentType_t::CASE) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file2.is_open()) << "Could not open file Case.bin";
    file2.read(reinterpret_cast<char*>(&component2), sizeof(component2));
    ASSERT_EQ(component2.getComponentID(), case1->getComponentID());
    ASSERT_EQ(component2.getManufacturer(), case1->getManufacturer());
    ASSERT_EQ(component2.getName(), case1->getName());
    ASSERT_EQ(component2.getPrice(), case1->getPrice());
    ASSERT_EQ(component2.getStock(), case1->getStock());
    ASSERT_EQ(component2.getType(), case1->getType());
    ASSERT_EQ(component2.getComputerType(), case1->getComputerType());
    ASSERT_EQ(component2.get_color(), case1->get_color());
    ASSERT_EQ(component2.get_MotherboardSize(), case1->get_MotherboardSize());
    ASSERT_EQ(component2.get_material(), case1->get_material());
    file2.close();
}

TEST_F(serialize, serializeGPUTest) {
    GPU component3("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, 0, 0);
    std::ifstream file3{pwd + "/" + componentTypeToString(ComponentType_t::GPU) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file3.is_open()) << "Could not open file GPU.bin";
    file3.read(reinterpret_cast<char*>(&component3), sizeof(component3));
    ASSERT_EQ(component3.getComponentID(), gpu1->getComponentID());
    ASSERT_EQ(component3.getManufacturer(), gpu1->getManufacturer());
    ASSERT_EQ(component3.getName(), gpu1->getName());
    ASSERT_EQ(component3.getPrice(), gpu1->getPrice());
    ASSERT_EQ(component3.getStock(), gpu1->getStock());
    ASSERT_EQ(component3.getType(), gpu1->getType());
    ASSERT_EQ(component3.getComputerType(), gpu1->getComputerType());
    ASSERT_EQ(component3.getPower(), gpu1->getPower());
    ASSERT_EQ(component3.getBusSpeed(), gpu1->getBusSpeed());
    file3.close();
}

TEST_F(serialize, serializeMemoryTest) {
    Memory component4("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, 0, 0);
    std::ifstream file4{pwd + "/" + componentTypeToString(ComponentType_t::RAM) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file4.is_open()) << "Could not open file Memory.bin";
    file4.read(reinterpret_cast<char*>(&component4), sizeof(component4));
    ASSERT_EQ(component4.getComponentID(), memory1->getComponentID());
    ASSERT_EQ(component4.getManufacturer(), memory1->getManufacturer());
    ASSERT_EQ(component4.getName(), memory1->getName());
    ASSERT_EQ(component4.getPrice(), memory1->getPrice());
    ASSERT_EQ(component4.getStock(), memory1->getStock());
    ASSERT_EQ(component4.getType(), memory1->getType());
    ASSERT_EQ(component4.getComputerType(), memory1->getComputerType());
    ASSERT_EQ(component4.getSize(), memory1->getSize());
    ASSERT_EQ(component4.getClockSpeed(), memory1->getClockSpeed());
    file4.close();
}

TEST_F(serialize, serializeMotherboardTest) {
    Motherboard component5("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, "", "", 0);
    std::ifstream file5{pwd + "/" + componentTypeToString(ComponentType_t::MOTHERBOARD) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file5.is_open()) << "Could not open file Motherboard.bin";
    file5.read(reinterpret_cast<char*>(&component5), sizeof(component5));
    ASSERT_EQ(component5.getComponentID(), motherboard1->getComponentID());
    ASSERT_EQ(component5.getManufacturer(), motherboard1->getManufacturer());
    ASSERT_EQ(component5.getName(), motherboard1->getName());
    ASSERT_EQ(component5.getPrice(), motherboard1->getPrice());
    ASSERT_EQ(component5.getStock(), motherboard1->getStock());
    ASSERT_EQ(component5.getType(), motherboard1->getType());
    ASSERT_EQ(component5.getComputerType(), motherboard1->getComputerType());
    ASSERT_EQ(component5.getSocket(), motherboard1->getSocket());
    ASSERT_EQ(component5.getFormFactor(), motherboard1->getFormFactor());
    ASSERT_EQ(component5.getMaxMemorySlots(), motherboard1->getMaxMemorySlots());
    file5.close();
}

TEST_F(serialize, serializePowerSupplyTest) {
    PowerSupply component6("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, 0, "");
    std::ifstream file6{pwd + "/" + componentTypeToString(ComponentType_t::PSU) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file6.is_open()) << "Could not open file PowerSupply.bin";
    file6.read(reinterpret_cast<char*>(&component6), sizeof(component6));
    ASSERT_EQ(component6.getComponentID(), powerSupply1->getComponentID());
    ASSERT_EQ(component6.getManufacturer(), powerSupply1->getManufacturer());
    ASSERT_EQ(component6.getName(), powerSupply1->getName());
    ASSERT_EQ(component6.getPrice(), powerSupply1->getPrice());
    ASSERT_EQ(component6.getStock(), powerSupply1->getStock());
    ASSERT_EQ(component6.getType(), powerSupply1->getType());
    ASSERT_EQ(component6.getComputerType(), powerSupply1->getComputerType());
    ASSERT_EQ(component6.get_power(), powerSupply1->get_power());
    ASSERT_EQ(component6.get_certification(), powerSupply1->get_certification());
    file6.close();
}

TEST_F(serialize, serializeStorage) {
    Storage component7("", "", 0, 0, ComponentType_t::UNKNOWN, ComputerType_t::UNKNOWN, 0, 0, 0, "");
    std::ifstream file7{pwd + "/" + componentTypeToString(ComponentType_t::STORAGE) + ".bin", std::ios::binary | std::ios::in};
    ASSERT_TRUE(file7.is_open()) << "Could not open file Storage.bin";
    file7.read(reinterpret_cast<char*>(&component7), sizeof(component7));
    ASSERT_EQ(component7.getComponentID(), storage1->getComponentID());
    ASSERT_EQ(component7.getManufacturer(), storage1->getManufacturer());
    ASSERT_EQ(component7.getName(), storage1->getName());
    ASSERT_EQ(component7.getPrice(), storage1->getPrice());
    ASSERT_EQ(component7.getStock(), storage1->getStock());
    ASSERT_EQ(component7.getType(), storage1->getType());
    ASSERT_EQ(component7.getComputerType(), storage1->getComputerType());
    ASSERT_EQ(component7.getSize(), storage1->getSize());
    ASSERT_EQ(component7.getSpeed(), storage1->getSpeed());
    ASSERT_EQ(component7.getSlot(), storage1->getSlot());
    file7.close();
}




#endif //PC_WINKLE_SERIALIZETEST_H
