//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_CASE_H
#define PC_WINKLE_CASE_H
#include <string>
#include <utility>
#include "ComponentBase.h"
#include <memory>
#include "ComponentView.h"

#define MAX_COLOR_LENGTH 16
#define MAX_MOTHERBOARD_SIZE_LENGTH 16
#define MAX_MATERIAL_LENGTH 16

class Case : public ComponentBase {
public:

    Case();

    Case(std::string manufacturer,
         std::string name,
         float price,
         unsigned int stock,
         ComputerType_t computerType,
         unsigned int componentID,
         const std::string& color,
         const std::string& MotherboardSize,
         const std::string& material);

    [[nodiscard]] inline CapString<MAX_COLOR_LENGTH> get_color() const { return my_color; }
    [[nodiscard]] inline CapString<MAX_MOTHERBOARD_SIZE_LENGTH> get_MotherboardSize() const { return MotherboardSize; }
    [[nodiscard]] inline CapString<MAX_MATERIAL_LENGTH> get_material() const { return my_material; }

    inline void set_color(const std::string& color) { my_color = color; }
    inline void set_MotherboardSize(const std::string& size) { MotherboardSize = size; }
    inline void set_material(const std::string& material) { my_material = material; }

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Case> Create(unsigned int componentID);

    static void selectFilter(class ComponentView& view);

private:

    static void filterColor(class ComponentView& view);
    static void filterMotherboardSize(class ComponentView& view);
    static void filterMaterial(class ComponentView& view);

    CapString<MAX_MATERIAL_LENGTH> my_material;
    CapString<MAX_MOTHERBOARD_SIZE_LENGTH> MotherboardSize;
    CapString<MAX_COLOR_LENGTH> my_color;
};


#endif //PC_WINKLE_CASE_H
