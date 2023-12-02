//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPONENTBASE_H
#define PC_WINKLE_COMPONENTBASE_H
#include <string>
#include <utility>

enum class ComponentType_t {
    CPU = 1,
    GPU = 2,
    MOTHERBOARD = 3,
    RAM = 4,
    STORAGE = 5,
    PSU = 6,
    CASE = 7,
    UNKNOWN = 0
};

enum class ComputerType_t {
    DESKTOP = 1,
    LAPTOP = 2,
    UNKNOWN = 0
};

class ComponentBase {
public:
    ComponentBase(std::string manufacturer,
                  std::string name,
                  float price,
                  unsigned int stock,
                  ComponentType_t type,
                  ComputerType_t computerType,
                  unsigned int componentID);

    [[nodiscard]] inline std::string getManufacturer() const { return my_manufacturer; }
    [[nodiscard]] inline std::string getName() const { return my_name; }
    [[nodiscard]] inline float getPrice() const { return my_price; }
    [[nodiscard]] inline unsigned int getStock() const { return my_stock; }
    [[nodiscard]] inline ComponentType_t getType() const { return my_type; }
    [[nodiscard]] inline ComputerType_t getComputerType() const { return my_computerType; }
    [[nodiscard]] inline unsigned int getComponentID() const { return my_componentID; }

    inline void setManufacturer(std::string manufacturer) { my_manufacturer = std::move(manufacturer); }
    inline void setName(std::string name) { my_name = std::move(name); }
    inline void setPrice(float price) { my_price = price; }
    inline void setStock(unsigned int stock) { my_stock = stock; }
    inline void setType(ComponentType_t type) { my_type = type; }
    inline void setComputerType(ComputerType_t computerType) { my_computerType = computerType; }
    inline void setComponentID(unsigned int componentID) { my_componentID = componentID; }

private:
    std::string my_manufacturer;
    std::string my_name;
    float my_price;
    unsigned int my_stock;
    ComponentType_t my_type;
    ComputerType_t my_computerType;
    unsigned int my_componentID;
};


#endif //PC_WINKLE_COMPONENTBASE_H
