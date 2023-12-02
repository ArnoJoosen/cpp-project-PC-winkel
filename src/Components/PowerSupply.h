//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_POWERSUPPLY_H
#define PC_WINKLE_POWERSUPPLY_H
#include <string>
#include <utility>
#include "ComponentBase.h"

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
    [[nodiscard]] inline std::string get_certification() const { return my_certification; }

    inline void set_power(float power) { my_power = power; }
    inline void set_certification(std::string certification) { my_certification = std::move(certification); }

private:
    float my_power;
    std::string my_certification;
};


#endif //PC_WINKLE_POWERSUPPLY_H
