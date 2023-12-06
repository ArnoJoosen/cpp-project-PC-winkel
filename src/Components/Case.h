//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_CASE_H
#define PC_WINKLE_CASE_H
#include <string>
#include <utility>
#include "ComponentBase.h"
#include <memory>

class Case : public ComponentBase {
public:

    Case(std::string manufacturer,
         std::string name,
         float price,
         unsigned int stock,
         ComputerType_t computerType,
         unsigned int componentID,
         std::string color,
         std::string MotherboardSize,
         std::string material);

    [[nodiscard]] inline std::string get_color() const { return my_color; }
    [[nodiscard]] inline std::string get_MotherboardSize() const { return MotherboardSize; }
    [[nodiscard]] inline std::string get_material() const { return my_material; }

    inline void set_color(std::string color) { my_color = std::move(color); }
    inline void set_MotherboardSize(std::string size) { MotherboardSize = std::move(size); }
    inline void set_material(std::string material) { my_material = std::move(material); }

    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Case> Create(unsigned int componentID);

private:
    std::string my_color;
    std::string MotherboardSize;
    std::string my_material;
};


#endif //PC_WINKLE_CASE_H
