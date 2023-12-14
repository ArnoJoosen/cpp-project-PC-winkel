//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_STORAGE_H
#define PC_WINKLE_STORAGE_H
#include <string>
#include <utility>
#include <memory>
#include "ComponentView.h"
#include "ComponentBase.h"
#define MAX_SLOT_STORAGE_LENGTH 20
#define MAX_STORAGE_SPEED_LENGTH 10
#define MAX_STORAGE_SIZE_LENGTH 10

class Storage : public ComponentBase {
public:

    Storage();

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
    [[nodiscard]] inline CapString<MAX_SLOT_STORAGE_LENGTH> getSlot() const { return my_slot; }

    inline void setSpeed(float speed) { my_speed = speed; }
    inline void setSize(unsigned int size) { my_size = size; }
    inline void setSlot(const std::string& slot) { my_slot = slot; }

    static void printHeader(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Storage> Create(unsigned int componentID);
    static void selectFilter(ComponentView &view);
private:

    static void filterSpeed(ComponentView &view);
    static void filterSize(ComponentView &view);
    static void filterSlot(ComponentView &view);

    float my_speed;
    unsigned int my_size;
    CapString<MAX_SLOT_STORAGE_LENGTH> my_slot;
};

#endif //PC_WINKLE_STORAGE_H
