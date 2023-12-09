//
// Created by arno on 10/25/23.
//
#include "Menus.h"
#include "ComputerShop.h"

#if defined(_WIN32)
#include <windows.h>
bool createDirectory(const std::string& dirPath) {
    if (CreateDirectory(dirPath.c_str(), NULL) == 0) {
        return false;
    }
    return true;
}
bool directoryExists(const std::string& dirPath) {
    struct stat info;

    if (stat(dirPath.c_str(), &info) != 0) {
        return false;
    } else if (info.st_mode & S_IFDIR) {
        return true;
    } else {
        return false;
    }
}
#elif defined(__unix__)
#include <sys/types.h>
#include <sys/stat.h>
bool createDirectory(const std::string& dirPath) {
    if (mkdir(dirPath.c_str(), 0777) == -1) {
        return false;
    }
    return true;
}
bool directoryExists(const std::string& dirPath) {
    struct stat info;

    if (stat(dirPath.c_str(), &info) != 0) {
        return false;
    } else if (info.st_mode & S_IFDIR) {
        return true;
    } else {
        return false;
    }
}
#endif

int main(int argc, char** argv){
    ComputerShop shop("ComputerShop1", {"bb", "aa", 15, 1651}, "./data");

    // create data dir if it exists and load data
    if (!directoryExists("./data")) {
        if (!createDirectory("./data"))
            throw std::runtime_error("Could not create data directory");
    }
    else {
        shop.load();
    }

    // main loop
    AccessLevel_t accessLevel = login();
    Action_t action;
    do {
        action = chooseAction(accessLevel);
        switch (action) {
            case Action_t::SearchCustomer:
                try {
                    shop.searchCustomer();
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::AddCustomer:
                shop.createCustomer();
                break;
            case Action_t::UpdateCustomer:
                try {
                    shop.updateCustomer(shop.searchCustomer());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::RemoveCustomer:
                try {
                    shop.removeCustomer(shop.searchCustomer());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::BuildSystem:
                shop.buildSystem(shop.searchCustomer());
                break;
            case Action_t::SearchComponent:
                try {
                    shop.searchComponent();
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::AddComponent:
                shop.createComponent();
                break;
            case Action_t::RemoveComponent:
                try {
                    shop.removeComponent(shop.searchComponent());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::UpdateComponent:
                try {
                    shop.updateComponent(shop.searchComponent());
                } catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case Action_t::SearchInvoice:
                // TODO: implement
                break;
            case Action_t::Logout:
                std::cout << "Logging out..." << std::endl;
                accessLevel = login();
                break;
            case Action_t::Exit:
                std::cout << "Exiting..." << std::endl;
                break;
        }
    } while (action != Action_t::Exit);
    return 0;
}