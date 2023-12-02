//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_FILTER_H
#define PC_WINKLE_FILTER_H
#include <vector>
#include <functional>
#include "Components/ComponentBase.h"

class Filter {
public:
    using LamdaFilter = std::function<bool(ComponentBase*)>; // return true if the component should be removed
    using ComponentIterator = std::vector<ComponentBase*>::iterator;

    Filter(const std::vector<ComponentBase*>& components, ComponentType_t type);

    // add a filter to the filter list
    void addFilter(const LamdaFilter& filter);
    void setComponentType(ComponentType_t type);

    ComponentIterator begin() { return my_components.begin(); }
    ComponentIterator end() { return my_components.end(); }

private:
    // apply all filters to the components and remove the components that don't pass the filter
    void filter();

    std::vector<ComponentBase*> my_components;
    std::vector<LamdaFilter> filters;
    ComponentType_t my_type;
};

#endif //PC_WINKLE_FILTER_H
