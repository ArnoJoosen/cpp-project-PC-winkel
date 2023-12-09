//
// Created by arno on 3/12/23.
//
#include <gtest/gtest.h>
#include "CapStringTest.h"
#include "MenuTest.h"
#include "SerializeTest.h"
#include "DeserializeTest.h"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}