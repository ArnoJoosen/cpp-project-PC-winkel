//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_CPU_H
#define PC_WINKLE_CPU_H
#include <string>
#include <memory>
#include "ComponentBase.h"
#include "ComponentView.h"
#define MAX_SOCKET_LENGTH 20

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
    [[nodiscard]] inline CapString<MAX_SOCKET_LENGTH> getSocket() const { return my_socket; }

    inline void setClockSpeed(float clockSpeed) { this->my_clockSpeed = clockSpeed; }
    inline void setCoreCount(int coreCount) { this->my_coreCount = coreCount; }
    inline void setSocket(const std::string& socket) { this->my_socket = socket; }

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<CPU> Create(unsigned int componentID);

    static void selectFilter(ComponentView &view);

private:

    static void filterClockSpeed(ComponentView &view);
    static void filterCoreCount(ComponentView &view);
    static void filterSocket(ComponentView &view);

    float my_clockSpeed;
    int my_coreCount;
    CapString<MAX_SOCKET_LENGTH> my_socket;
};

#endif //PC_WINKLE_CPU_H
