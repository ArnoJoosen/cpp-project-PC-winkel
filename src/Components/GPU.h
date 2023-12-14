//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_GPU_H
#define PC_WINKLE_GPU_H
#include "ComponentBase.h"
#include <memory>
#include "ComponentView.h"
#define MAX_GPU_POWER_LENGTH 5
#define MAX_GPU_BUS_SPEED_LENGTH 9

class GPU : public ComponentBase {
public:

    GPU();

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

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<GPU> Create(unsigned int componentID);
    static void selectFilter(ComponentView &view);

private:

    static void filterPower(ComponentView &view);
    static void filterBusSpeed(ComponentView &view);

    float my_power;
    float my_busSpeed;
};


#endif //PC_WINKLE_GPU_H
