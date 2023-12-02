//
// Created by arno on 2/12/23.
//

#include <stdexcept>
#include <algorithm>
#include "Filter.h"

Filter::Filter(const std::vector<ComponentBase*>& components, ComponentType_t type = ComponentType_t::UNKNOWN)
: my_components(components), my_type(type) {
    if (type != ComponentType_t::UNKNOWN) {
        filters.emplace_back([type](ComponentBase *component) {
            return component->getType() != type;
        });
        filter();
    }
}

void Filter::addFilter(const Filter::LamdaFilter& filter) {
    filters.push_back(filter);
}

void Filter::setComponentType(ComponentType_t type) {
    if (my_type != ComponentType_t::UNKNOWN)
        throw std::runtime_error("Component type already set");
    filters.emplace_back([type](ComponentBase* component) {
        return component->getType() != type;
    });
    filter();
}

void Filter::filter() {
    for (auto& filter : filters)
        my_components.erase(
                std::remove_if(my_components.begin(), my_components.end(), filter),
                my_components.end());
}
