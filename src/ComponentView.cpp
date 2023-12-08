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

ComponentView::ComponentView(const std::multimap<ComponentType_t, std::shared_ptr<ComponentBase>> &components,
                             ComponentType_t type, ComputerType_t computerType): my_type(type) {
    if (type != ComponentType_t::UNKNOWN) // if type is not unknown, only get components of that type using lower_bound and upper_bound
        std::transform(components.lower_bound(type), components.upper_bound(type), std::back_inserter(my_components),
                       [](const std::pair<ComponentType_t, std::shared_ptr<ComponentBase>>& pair) {
                           return pair.second;
                       });
    else // if type is unknown, get all components
        std::transform(components.begin(), components.end(), std::back_inserter(my_components),
                       [](const std::pair<ComponentType_t, std::shared_ptr<ComponentBase>>& pair) {
                           return pair.second;
                       });
    // filter out components that are not compatible with the computer type
    if (computerType != ComputerType_t::UNKNOWN)
        filter([computerType](const std::shared_ptr<ComponentBase>& component) {
            return component->getComputerType() != computerType;
        });
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
