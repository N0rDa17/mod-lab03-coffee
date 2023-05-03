// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;


TEST(test1, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = CHECK;
    try {
        drinking_machine.on();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = OFF;
    try {
        drinking_machine.coin(100);
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}


TEST(test3, incorrect_operation) {
    Automata drinking_machine;
    drinking_machine.state = OFF;
    try {
        drinking_machine.cook();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Error! Incorrect operation.", err.what());
    }
}


TEST(test4, states) {
    Automata drinking_machine;
    drinking_machine.on();
    EXPECT_EQ(WAIT, drinking_machine.state);
}


TEST(test5, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    EXPECT_EQ(ACCEPT, drinking_machine.state);
}

TEST(test6, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    EXPECT_EQ(CHECK, drinking_machine.state);
}

TEST(test7, states) {
    Automata drinking_machine;
    drinking_machine.on();
    drinking_machine.coin(1000);
    drinking_machine.choice(5);
    drinking_machine.cook();
    drinking_machine.finish();
    drinking_machine.off();
    EXPECT_EQ(OFF, drinking_machine.state);
}

