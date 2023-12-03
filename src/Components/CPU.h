//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_CPU_H
#define PC_WINKLE_CPU_H
#include <string>
#include <memory>
#include "ComponentBase.h"

class CPU : public ComponentBase {
public:
    CPU(std::string manufacturer,
        std::string name,
        float price,
        unsigned int stock,
        ComponentType_t type,
        ComputerType_t computerType,
        unsigned int componentID,
        float clockSpeed,
        int coreCount,
        std::string socket);

    [[nodiscard]] inline float getClockSpeed() const { return my_clockSpeed; }
    [[nodiscard]] inline int getCoreCount() const { return my_coreCount; }
    [[nodiscard]] inline std::string getSocket() const { return my_socket; }

    inline void setClockSpeed(float clockSpeed) { this->my_clockSpeed = clockSpeed; }
    inline void setCoreCount(int coreCount) { this->my_coreCount = coreCount; }
    inline void setSocket(std::string socket) { this->my_socket = std::move(socket); }

    static std::shared_ptr<CPU> Create(unsigned int componentID);

private:
    float my_clockSpeed;
    int my_coreCount;
    std::string my_socket;
};

#endif //PC_WINKLE_CPU_H
