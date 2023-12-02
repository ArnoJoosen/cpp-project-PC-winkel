//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_GPU_H
#define PC_WINKLE_GPU_H
#include "ComponentBase.h"

class GPU : public ComponentBase {
public:
    GPU(std::string manufacturer,
        std::string name,
        float price,
        unsigned int stock,
        ComponentType_t type,
        ComputerType_t computerType,
        unsigned int componentID,
        float power,
        float busSpeed);

    [[nodiscard]] inline float getPower() const { return my_power; }
    [[nodiscard]] inline float getBusSpeed() const { return my_busSpeed; }

    inline void setPower(float power) { my_power = power; }
    inline void setBusSpeed(float busSpeed) { my_busSpeed = busSpeed; }

private:
    float my_power;
    float my_busSpeed;
};


#endif //PC_WINKLE_GPU_H
