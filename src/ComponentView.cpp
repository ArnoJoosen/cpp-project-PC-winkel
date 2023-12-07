//
// Created by arno on 3/12/23.
//
#include "ComponentView.h"
#include "Components/ComponentBase.h"
#include "Components/Case.h"
#include "Components/CPU.h"
#include "Components/GPU.h"
#include "Components/Memory.h"
#include "Components/Motherboard.h"
#include "Components/PowerSupply.h"
#include "Components/Storage.h"
#include "Enumerate.hpp"

ComponentView::ComponentView(const std::vector<std::shared_ptr<ComponentBase>> &components,
                             ComponentType_t type, ComputerType_t computerType) : my_components(components), my_type(type) {
    if (type != ComponentType_t::UNKNOWN) {
        filter([type](const std::shared_ptr<ComponentBase>& component) {
            return component->getType() != type;
        });
    }
    if (computerType != ComputerType_t::UNKNOWN) {
        filter([computerType](const std::shared_ptr<ComponentBase>& component) {
            return component->getComputerType() != computerType;
        });
    }
}

void ComponentView::filter(const std::function<bool(const std::shared_ptr<ComponentBase>&)>& filter) {
    my_components.erase(std::remove_if(my_components.begin(), my_components.end(), filter), my_components.end());
}

void ComponentView::setType(ComponentType_t type) {
    my_type = type;
    filter([type](const std::shared_ptr<ComponentBase>& component) {
        return component->getType() != type;
    });
}

void ComponentView::printView() {
    switch (my_type) {
        case ComponentType_t::UNKNOWN:
            ComponentBase::printHeader(true);
            break;
        case ComponentType_t::CASE:
            Case::printHeader(true);
            break;
        case ComponentType_t::CPU:
            CPU::printHeader(true);
            break;
        case ComponentType_t::GPU:
            GPU::printHeader(true);
            break;
        case ComponentType_t::RAM:
            Memory::printHeader(true);
            break;
        case ComponentType_t::MOTHERBOARD:
            Motherboard::printHeader(true);
            break;
        case ComponentType_t::PSU:
            PowerSupply::printHeader(true);
            break;
        case ComponentType_t::STORAGE:
            Storage::printHeader(true);
            break;
    }

    for (auto [i, c] : Enumerate(my_components)) {
        if (my_type == ComponentType_t::UNKNOWN)
            c->printBase((int)i);
        else
            c->printRow((int)i);
        std::cout << std::endl;
    }
}
