//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_POWERSUPPLY_H
#define PC_WINKLE_POWERSUPPLY_H
#include <string>
#include <utility>
#include <memory>
#include "ComponentBase.h"
#include "ComponentView.h"
#define MAX_CERTIFICATION_LENGTH 10

class PowerSupply : public ComponentBase {
public:
    PowerSupply(std::string manufacturer,
                std::string name,
                float price,
                unsigned int stock,
                ComponentType_t type,
                ComputerType_t computerType,
                unsigned int componentID,
                float power,
                std::string certification);

    [[nodiscard]] inline float get_power() const { return my_power; }
    [[nodiscard]] inline CapString<MAX_CERTIFICATION_LENGTH> get_certification() const { return my_certification; }

    inline void set_power(float power) { my_power = power; }
    inline void set_certification(const std::string& certification) { my_certification = certification; }

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<PowerSupply> Create(unsigned int componentID);
    static void selectFilter(ComponentView &view);

private:

    static void filterPower(ComponentView &view);
    static void filterCertification(ComponentView &view);

    float my_power;
    CapString<MAX_CERTIFICATION_LENGTH> my_certification;
};


#endif //PC_WINKLE_POWERSUPPLY_H
