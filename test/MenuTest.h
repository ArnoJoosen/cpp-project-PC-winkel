//
// Created by arno on 7/12/23.
//

#ifndef PC_WINKLE_MENUTEST_H
#define PC_WINKLE_MENUTEST_H

#include <gtest/gtest.h>
#include <sstream>
#include "Menus.h"

TEST(ChooseActionTest, login) {
    // stdout to buffer
    std::ostringstream buffer;
    auto *oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::streambuf* oldCinBuffer = std::cin.rdbuf();
    std::istringstream simulatedInput(
            "1\n"
            "2\n"
    );
    std::cin.rdbuf(simulatedInput.rdbuf());

    EXPECT_EQ(login(), AccessLevel_t::Employee);
    EXPECT_EQ(login(), AccessLevel_t::Owner);

    std::cin.rdbuf(oldCinBuffer);
    std::cout.rdbuf(oldBuf);
}

TEST(ChooseActionTest, ActionEmployee) {
    // stdout to buffer
    std::ostringstream buffer;
    auto *oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::streambuf* oldCinBuffer = std::cin.rdbuf();
    std::istringstream simulatedInput(
            "1\n"
            "2\n"
            "3\n"
            "4\n"
            "5\n"
            "6\n"
    );
    std::cin.rdbuf(simulatedInput.rdbuf());

    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::SearchCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::AddCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::UpdateCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::BuildSystem);
    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::Exit);
    EXPECT_EQ(chooseAction(AccessLevel_t::Employee), Action_t::Logout);

    std::cin.rdbuf(oldCinBuffer);
    std::cout.rdbuf(oldBuf);
}

TEST(ChooseActionTest, ActionOwener) {
    // stdout to buffer
    std::ostringstream buffer;
    auto *oldBuf = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    std::streambuf* oldCinBuffer = std::cin.rdbuf();
    std::istringstream simulatedInput(
            "1\n"
            "2\n"
            "3\n"
            "4\n"
            "5\n"
            "6\n"
            "7\n"
            "8\n"
            "9\n"
            "10\n"
    );
    std::cin.rdbuf(simulatedInput.rdbuf());

    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::SearchCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::AddCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::UpdateCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::RemoveCustomer);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::SearchComponent);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::AddComponent);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::RemoveComponent);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::UpdateComponent);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::Exit);
    EXPECT_EQ(chooseAction(AccessLevel_t::Owner), Action_t::Logout);

    std::cin.rdbuf(oldCinBuffer);
    std::cout.rdbuf(oldBuf);
}

#endif //PC_WINKLE_MENUTEST_H
