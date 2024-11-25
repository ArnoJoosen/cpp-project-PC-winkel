//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_MEMORY_H
#define PC_WINKLE_MEMORY_H
#include "ComponentBase.h"
#include <memory>
#include "ComponentView.h"
#define MAX_MEMORY_SIZE_LENGTH 5
#define MAX_MEMORY_CLOCK_SPEED_LENGTH 10

class Memory : public ComponentBase {
public:

    Memory();

    Memory(std::string manufacturer,
           std::string name,
           float price,
           unsigned int stock,
           ComponentType_t type,
           ComputerType_t computerType,
           unsigned int componentID,
           unsigned int size,
           float clockSpeed);

    [[nodiscard]] inline unsigned int getSize() const { return my_size; }
    [[nodiscard]] inline float getClockSpeed() const { return my_clockSpeed; }

    inline void setSize(unsigned int size) { this->my_size = size; }
    inline void setClockSpeed(float clockSpeed) { this->my_clockSpeed = clockSpeed; }

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Memory> Create(unsigned int componentID);
    static void selectFilter(ComponentView &view);

private:

    static void filterSize(ComponentView &view);
    static void filterClockSpeed(ComponentView &view);

    unsigned int my_size;
    float my_clockSpeed;
};


#endif //PC_WINKLE_MEMORY_H
