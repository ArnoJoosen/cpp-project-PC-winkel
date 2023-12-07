//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPONENTBASE_H
#define PC_WINKLE_COMPONENTBASE_H
#include <string>
#include <utility>
#include <iostream>
#include "ComponentProperties.h"
#include "CapString.hpp"
#define MAX_MANUFACTURER_LENGTH 30
#define MAX_COMPONENT_NAME_LENGTH 30

class ComponentBase {
public:
    ComponentBase(std::string manufacturer,
                  std::string name,
                  float price,
                  unsigned int stock,
                  ComponentType_t type,
                  ComputerType_t computerType,
                  unsigned int componentID);

    [[nodiscard]] inline CapString<MAX_MANUFACTURER_LENGTH> getManufacturer() const { return my_manufacturer; }
    [[nodiscard]] inline CapString<MAX_COMPONENT_NAME_LENGTH> getName() const { return my_name; }
    [[nodiscard]] inline float getPrice() const { return my_price; }
    [[nodiscard]] inline unsigned int getStock() const { return my_stock; }
    [[nodiscard]] inline ComponentType_t getType() const { return my_type; }
    [[nodiscard]] inline ComputerType_t getComputerType() const { return my_computerType; }
    [[nodiscard]] inline unsigned int getComponentID() const { return my_componentID; }

    inline void setManufacturer(const std::string& manufacturer) { my_manufacturer = manufacturer; }
    inline void setName(const std::string& name) { my_name = name; }
    inline void setPrice(float price) { my_price = price; }
    inline void setStock(unsigned int stock) { my_stock = stock; }
    inline void setType(ComponentType_t type) { my_type = type; }
    inline void setComputerType(ComputerType_t computerType) { my_computerType = computerType; }
    inline void setComponentID(unsigned int componentID) { my_componentID = componentID; }

    static void printHeader(bool indexed = false);
    void printBase(int index = -1) const;
    virtual void printRow(int index = -1) const = 0;
    virtual void update();

    static void selectFilter(class ComponentView& view);

protected:

    bool changeQuestion(const char* question) const;

    static void filterManufacturer(class ComponentView& view);
    static void filterName(class ComponentView& view);
    static void filterPrice(class ComponentView& view);
    static void filterPriceHigher(class ComponentView& view);
    static void filterPriceLower(class ComponentView& view);
    static void filterStock(class ComponentView& view);
    static void filterComputerType(class ComponentView& view);

    CapString<MAX_MANUFACTURER_LENGTH> my_manufacturer;
    CapString<MAX_COMPONENT_NAME_LENGTH> my_name;
    float my_price;
    unsigned int my_stock;
    ComponentType_t my_type;
    ComputerType_t my_computerType;
    unsigned int my_componentID;
};


#endif //PC_WINKLE_COMPONENTBASE_H
