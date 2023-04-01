// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>

enum STATES {OFF, ON, ACCEPTING_COINS, CHOOSING_DRINK, CHECKING_AMOUNT, COOKING, FINISHED};

class Automata {
private:
    int cash;
    std::string menu[3] = {"Coffee", "Tea", "Cocoa"};
    int prices[3] = {50, 30, 40};
    STATES state;
    
public:
    Automata();
    void on();
    void off();
    void coin(int value);
    void getMenu();
    STATES getState();
    void choice(int drinkNumber);
    void check();
    void cancel();
    void cook();
    void finish();
};

#endif  // INCLUDE_AUTOMATA_H_
