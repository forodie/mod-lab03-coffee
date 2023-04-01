// Copyright 2022 GHA Test Team
#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, InitialState) {
  Automata a;
  EXPECT_EQ(a.getState(), "OFF");
}

TEST(AutomataTest, TurnOn) {
  Automata a;
  a.on();
  EXPECT_EQ(a.getState(), "ON");
}

TEST(AutomataTest, TurnOff) {
  Automata a;
  a.on();
  a.off();
  EXPECT_EQ(a.getState(), "OFF");
}

TEST(AutomataTest, Coin) {
  Automata a;
  a.on();
  a.coin(10);
  EXPECT_EQ(a.getCash(), 10);
  a.coin(20);
  EXPECT_EQ(a.getCash(),30);
}

TEST(AutomataTest, Cancel) {
  Automata a;
  a.on();
  a.coin(10);
  a.cancel();
  EXPECT_EQ(a.getState(), "ON");
}

TEST(AutomataTest, CheckSuccess) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_TRUE(a.check());
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(AutomataTest, Cook) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(2);
    a.check();
    a.cook();
    EXPECT_EQ(a.getState(), Automata::COOK);
}