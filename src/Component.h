//
// Created by arno on 10/25/23.
//

#ifndef PC_WINKLE_COMPONENT_H
#define PC_WINKLE_COMPONENT_H
#include <string>

enum class ComponentType {
    None = 0,
    CPU,
    GPU,
    PS,
    MB,
    RAM,
    HDD,
    Case
};

enum class ComputerType {
    None = 0,
    desktop,
    laptop
};

class Component {
public:
    Component(std::string name,
              std::string manufacture,
              float price, int stock,
              ComputerType computerType,
              ComponentType componentType);

    [[nodiscard]] inline std::string getName() const {return my_name;}
    inline void setName(std::string name){my_name = name;}

    [[nodiscard]] inline std::string getManufacture() const {return my_manufacture;}
    inline void setManufacture(std::string manufacture){my_manufacture = manufacture;}

    [[nodiscard]] inline float getPrice() const {return  my_price;}
    inline void setPrice(float price) {my_price = price;}

    [[nodiscard]] inline int getStock() const {return my_stock;}
    inline void setStock(int stock) { my_stock = stock; }

    [[nodiscard]] inline ComponentType getComponentType() const {return my_type;}
    inline void setComponentType(ComponentType type) {my_type = type;}

    [[nodiscard]] inline ComputerType getComputerType() const {return my_cType;}
    inline void setComputerType(ComputerType type) {my_cType = type;}

private:
    std::string my_name;
    std::string my_manufacture;
    float my_price;
    int my_stock;
    ComponentType my_type;
    ComputerType my_cType;
};


#endif //PC_WINKLE_COMPONENT_H
