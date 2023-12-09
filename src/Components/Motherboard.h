//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_MOTHERBOARD_H
#define PC_WINKLE_MOTHERBOARD_H
#include <string>
#include <memory>
#include "ComponentView.h"
#include "ComponentBase.h"
#define MAX_SOCKET_LENGTH 10
#define MAX_FORM_FACTOR_LENGTH 15

class Motherboard : public ComponentBase {
public:

    Motherboard();

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

    [[nodiscard]] inline CapString<MAX_SOCKET_LENGTH> getSocket() const { return my_socket; }
    [[nodiscard]] inline CapString<MAX_SOCKET_LENGTH> getFormFactor() const { return my_formFactor; }
    [[nodiscard]] inline unsigned int getMaxMemorySlots() const { return my_maxMemorySlots; }

    inline void setSocket(std::string socket) { this->my_socket = std::move(socket); }
    inline void setFormFactor(std::string formFactor) { this->my_formFactor = std::move(formFactor); }
    inline void setMaxMemorySlots(unsigned int maxMemorySlots) { this->my_maxMemorySlots = maxMemorySlots; }

    static void printHeader(bool indexed);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Motherboard> Create(unsigned int componentID);
    static void selectFilter(ComponentView &view);

private:

    static void filterSocket(ComponentView &view);
    static void filterFormFactor(ComponentView &view);
    static void filterMaxMemorySlots(ComponentView &view);

    unsigned int my_maxMemorySlots;
    CapString<MAX_SOCKET_LENGTH> my_socket;
    CapString<MAX_SOCKET_LENGTH> my_formFactor;
};


#endif //PC_WINKLE_MOTHERBOARD_H
