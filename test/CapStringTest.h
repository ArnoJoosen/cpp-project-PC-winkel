//
// Created by arno on 3/12/23.
//

#ifndef PC_WINKLE_CAPSTRINGTEST_H
#define PC_WINKLE_CAPSTRINGTEST_H
#include <gtest/gtest.h>
#include "CapString.hpp"

TEST(CapStringTest, test_default_constructor) {
    CapString<10> capString;
    ASSERT_EQ(capString.size(), 0) << "Size should be 0, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "") << R"(String should be "", but is ")" << capString.c_str();
}

TEST(CapStringTest, test_string_literal_constructor) {
    CapString<10> capString("Hello");
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString.c_str();
}

TEST(CapStringTest, test_string_CapString_constructor) {
    CapString<10> capString("Hello");
    CapString<10> capString2(capString);
    ASSERT_EQ(capString2.size(), 5) << "Size should be 5, but is " << capString2.size();
    ASSERT_STREQ(capString2.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString2.c_str();
}

TEST(CapStringTest, test_std_string_constructor) {
    std::string str = "World";
    CapString<10> capString(str);
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "World") << R"(String should be "World", but is ")" << capString.c_str();
}

TEST(CapStringTest, test_size) {
    CapString<10> capString("Hello");
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
}

TEST(CapStringTest, test_capstring_set) {
    CapString<10> capString("Hello");
    CapString<10> capString2;
    capString2.set(capString);
    ASSERT_EQ(capString2.size(), 5) << "Size should be 5, but is " << capString2.size();
    ASSERT_STREQ(capString2.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString2.c_str();
}

TEST(CapStringTest, test_set_const_char_ptr) {
    CapString<10> capString;
    capString.set("Hello");
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString.c_str();
    ASSERT_THROW(capString.set("Hello World"), std::runtime_error) << "Should throw runtime_error";
}

TEST(CapStringTest, test_set_std_string) {
    CapString<10> capString;
    std::string str = "Hello";
    capString.set(str);
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString.c_str();
    ASSERT_THROW(capString.set("Hello World"), std::runtime_error) << "Should throw runtime_error";
}

TEST(CapStringTest, test_assignment_operator_const_char_ptr) {
    CapString<10> capString;
    capString = "Hello";
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString.c_str();
    ASSERT_THROW(capString = "Hello World", std::runtime_error) << "Should throw runtime_error";
}

TEST(CapStringTest, test_assignment_operator_std_string) {
    CapString<10> capString;
    std::string str = "Hello";
    capString = str;
    ASSERT_EQ(capString.size(), 5) << "Size should be 5, but is " << capString.size();
    ASSERT_STREQ(capString.c_str(), "Hello") << R"(String should be "Hello", but is ")" << capString.c_str();
    ASSERT_THROW(capString = std::string("Hello World"), std::runtime_error) << "Should throw runtime_error";
}

TEST(CapStringTest, test_equality_operator) {
    CapString<10> capString("Hello");
    CapString<10> capString2("Hello");
    CapString<10> capString3("World");
    CapString<10> capString4("Helbo");
    ASSERT_TRUE(capString == capString2) << "Should be equal";
    ASSERT_FALSE(capString == capString3) << "Should not be equal";
    ASSERT_FALSE(capString == capString4) << "Should not be equal";
}

TEST(CapStringTest, test_equality_operator_str_string) {
    std::string str = "Hello";
    CapString<10> capString("Hello");
    CapString<10> capString2("Helbo");
    CapString<10> capString3("World");
    ASSERT_TRUE(capString == str) << "capString should be equal";
    ASSERT_FALSE(capString2 == str) << "capString2 should not be equal";
    ASSERT_FALSE(capString3 == str) << "capString3 should not be equal";
}

TEST(CapStringTest, test_equality_operator_str_char_ptr) {
    CapString<10> capString("Hello");
    CapString<10> capString2("Helbo");
    CapString<10> capString3("World");
    ASSERT_TRUE(capString == "Hello") << "capString should be equal";
    ASSERT_FALSE(capString2 == "Hello") << "capString2 should not be equal";
    ASSERT_FALSE(capString3 == "Hello") << "capString3 should not be equal";
}

TEST(CapStringTest, test_inequality_operator) {
    CapString<10> capString("Hello");
    CapString<10> capString2("Hello");
    CapString<10> capString3("World");
    CapString<10> capString4("Helbo");
    ASSERT_FALSE(capString != capString2) << "Should not be unequal";
    ASSERT_TRUE(capString != capString3) << "Should be unequal";
    ASSERT_TRUE(capString != capString4) << "Should be unequal";
}

TEST(CapStringTest, test_inequality_operator_str_string) {
    std::string str = "Hello";
    CapString<10> capString("Hello");
    CapString<10> capString2("Helbo");
    CapString<10> capString3("World");
    ASSERT_FALSE(capString != str) << "capString should not be unequal";
    ASSERT_TRUE(capString2 != str) << "capString2 should be unequal";
    ASSERT_TRUE(capString3 != str) << "capString3 should be unequal";
}

TEST(CapStringTest, test_inequality_operator_str_char_ptr) {
    CapString<10> capString("Hello");
    CapString<10> capString2("Helbo");
    CapString<10> capString3("World");
    ASSERT_FALSE(capString != "Hello") << "capString should not be unequal";
    ASSERT_TRUE(capString2 != "Hello") << "capString2 should be unequal";
    ASSERT_TRUE(capString3 != "Hello") << "capString3 should be unequal";
}

#endif //PC_WINKLE_CAPSTRINGTEST_H
