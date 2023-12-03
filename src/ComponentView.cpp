//
// Created by arno on 3/12/23.
//
#include "ComponentView.h"
#include "Components/ComponentBase.h"

ComponentView::ComponentView(const std::vector<std::shared_ptr<ComponentBase>> &components, ComponentType_t type) : my_components(components), my_type(type) {
    if (type != ComponentType_t::UNKNOWN) {
        filter([type](const std::shared_ptr<ComponentBase>& component) {
            return component->getType() == type;
        });
    }
}

void ComponentView::filter(const std::function<bool(const std::shared_ptr<ComponentBase>&)>& filter) {
    my_components.erase(std::remove_if(my_components.begin(), my_components.end(), filter), my_components.end());
}

void ComponentView::setType(ComponentType_t type) {
    my_type = type;
    filter([type](const std::shared_ptr<ComponentBase>& component) {
        return component->getType() == type;
    });
}
