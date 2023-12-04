//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_COMPONENTVIEW_H
#define PC_WINKLE_COMPONENTVIEW_H
#include <vector>
#include <functional>
#include <memory>
#include "Components/ComponentProperties.h"

class ComponentView {
public:
    using ViewIderator = std::vector<std::shared_ptr<class ComponentBase>>::iterator;

    ComponentView(const std::vector<std::shared_ptr<class ComponentBase>>& components, ComponentType_t type = ComponentType_t::UNKNOWN);

    void filter(const std::function<bool(const std::shared_ptr<class ComponentBase>&)>& filter);
    void setType(ComponentType_t type);

    inline ViewIderator begin() { return my_components.begin(); }
    inline ViewIderator end() { return my_components.end();}

    inline size_t size() { return my_components.size(); }
    inline bool empty() { return my_components.empty(); }
    inline ComponentType_t getType() { return my_type; }

private:

    std::vector<std::shared_ptr<class ComponentBase>> my_components;
    ComponentType_t my_type;
};

#endif //PC_WINKLE_COMPONENTVIEW_H