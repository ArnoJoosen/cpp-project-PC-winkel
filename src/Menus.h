//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_MENUS_H
#define PC_WINKLE_MENUS_H

enum class AccessLevel_t{
    Employee,
    Owner
};

enum class Action_t{
    SearchCustomer,
    AddCustomer,
    UpdateCustomer,
    RemoveCustomer,

    BuildSystem,

    SearchComponent,
    AddComponent,
    RemoveComponent,
    UpdateComponent,

    Logout,
    Exit
};

AccessLevel_t login();

Action_t chooseAction(AccessLevel_t accessLevel);

#endif //PC_WINKLE_MENUS_H
