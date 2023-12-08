//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_COMPONENTVIEW_H
#define PC_WINKLE_COMPONENTVIEW_H
#include <vector>
#include <functional>
#include <memory>
#include <map>
#include "Components/ComponentProperties.h"

class ComponentView {
public:
    using value_type = std::shared_ptr<class ComponentBase>;
    using const_iterator = std::vector<std::shared_ptr<class ComponentBase>>::const_iterator;

    ComponentView(const std::multimap<ComponentType_t, std::shared_ptr<class ComponentBase>>& components,
            ComponentType_t type = ComponentType_t::UNKNOWN,
            ComputerType_t computerType = ComputerType_t::UNKNOWN);

    void filter(const std::function<bool(const std::shared_ptr<class ComponentBase>&)>& filter);
    void setType(ComponentType_t type);

    [[nodiscard]] inline const_iterator begin() const { return my_components.begin(); }
    [[nodiscard]] inline const_iterator end() const { return my_components.end(); }

    [[nodiscard]] inline size_t size() const { return my_components.size(); }
    [[nodiscard]] inline bool empty() const { return my_components.empty(); }
    inline ComponentType_t getType() { return my_type; }

    inline std::shared_ptr<ComponentBase> operator[](int index) { return my_components[index]; }

    void printView();

private:

    std::vector<std::shared_ptr<class ComponentBase>> my_components;
    ComponentType_t my_type;
};

#endif //PC_WINKLE_COMPONENTVIEW_H
