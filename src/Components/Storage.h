//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_STORAGE_H
#define PC_WINKLE_STORAGE_H
#include <string>
#include <utility>
#include <memory>
#include "ComponentBase.h"

class Storage : public ComponentBase {
public:

    Storage(std::string manufacturer,
            std::string name,
            float price,
            unsigned int stock,
            ComponentType_t type,
            ComputerType_t computerType,
            unsigned int componentID,
            float speed,
            unsigned int size,
            std::string slot);

    [[nodiscard]] inline float getSpeed() const { return my_speed; }
    [[nodiscard]] inline unsigned int getSize() const { return my_size; }
    [[nodiscard]] inline std::string getSlot() const { return my_slot; }

    inline void setSpeed(float speed) { my_speed = speed; }
    inline void setSize(unsigned int size) { my_size = size; }
    inline void setSlot(std::string slot) { my_slot = std::move(slot); }

    static std::shared_ptr<Storage> Create(unsigned int componentID);
private:
    float my_speed;
    unsigned int my_size;
    std::string my_slot;
};

#endif //PC_WINKLE_STORAGE_H
