// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>

class Automata {
 public:
    enum STATES {OFF, ON, ACCEPT, CHECK, COOK};
    Automata();
    void on();
    void off();
    void coin(int value);
    int getCash();
    void getMenu();
    STATES getState() { return state; }
    void choice(int drinkNumber);
    int getChosenDrink();
    bool check();
    void cancel();
    void cook();
    void finish();
 private:
    int cash;
    int chosen;
    std::string menu[3] = {"Cappuccino", "Lungo", "Risutto"};
    int prices[3] = {50, 30, 40};
    STATES state = OFF;
};

#endif  // INCLUDE_AUTOMATA_H_
