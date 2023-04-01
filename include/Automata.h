// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <string>

class Automata {
 private:
    enum STATES {OFF, ON, ACCEPT, CHECK, COOK};
    int cash;
    int chosen;
    std::string menu[3] = {"Cappuccino", "Lungo", "Risutto"};
    int prices[3] = {50, 30, 40};
    STATES state;

 public:
    Automata();
    void on();
    void off();
    void coin(int value);
    int getCash();
    void getMenu();
    STATES getState();
    void choice(int drinkNumber);
    int getChosenDrink();
    bool check();
    void cancel();
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
