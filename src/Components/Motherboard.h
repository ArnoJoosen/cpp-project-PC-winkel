//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_MOTHERBOARD_H
#define PC_WINKLE_MOTHERBOARD_H
#include <string>
#include "ComponentBase.h"

class Motherboard : public ComponentBase {
public:
    Motherboard(std::string manufacturer,
                std::string name,
                float price,
                unsigned int stock,
                ComponentType_t type,
                ComputerType_t computerType,
                unsigned int componentID,
                std::string socket,
                std::string formFactor,
                unsigned int maxMemorySlots);

    [[nodiscard]] inline std::string getSocket() const { return my_socket; }
    [[nodiscard]] inline std::string getFormFactor() const { return my_formFactor; }
    [[nodiscard]] inline unsigned int getMaxMemorySlots() const { return my_maxMemorySlots; }

    inline void setSocket(std::string socket) { this->my_socket = std::move(socket); }
    inline void setFormFactor(std::string formFactor) { this->my_formFactor = std::move(formFactor); }
    inline void setMaxMemorySlots(unsigned int maxMemorySlots) { this->my_maxMemorySlots = maxMemorySlots; }

private:
    std::string my_socket;
    std::string my_formFactor;
    unsigned int my_maxMemorySlots;
};


#endif //PC_WINKLE_MOTHERBOARD_H
