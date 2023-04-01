// Copyright 2022 UNN-IASR
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
}

void Automata::on() {
    state = ON;
    std::cout << "Automata is turned on." << std::endl;
}

void Automata::off() {
    state = OFF;
    std::cout << "Automata is turned off." << std::endl;
}

void Automata::coin(int value) {
    if (state == ON) {
        cash += value;
        std::cout << "Cash: " << cash << std::endl;
    } else {
        std::cout << "Invalid state" << std::endl;
    }
}

int Automata::getCash() {
    return cash;
}

void Automata::getMenu() {
    if (state == ON) {
        for (int i = 0; i < 3; i++) {
            std::cout << menu[i] << '-' << prices[i] << " rub" << std::endl;
        }
    } else {
        std::cout << "Cannot get menu in this state." << std::endl;
    }
}

void Automata::choice(int drinkNumber) {
    if (state == ON) {
        if (drinkNumber >= 1 && drinkNumber <=3) {
            state = ACCEPT;
            chosen = drinkNumber-1;
            std::cout << "You have chosen " << menu[drinkNumber-1] << std::endl;
        } else {
            std::cout << "Invalid drink number." << std::endl;
        }
    } else {
        std::cout << "Cannot choose drink in this state." << std::endl;
    }
}

int Automata::getChosenDrink() {
    return chosen;
}

bool Automata::check() {
    if (cash >= prices[chosen]) {
        return true;
    } else {
        std::cout << "Not enough money." << std::endl;
        state = ON;
        return false;
    }
}

void Automata::cancel() {
    cash = 0;
    chosen = -1;
    state = ON;
    std::cout << "succesfull canceled" << std::endl;
}

void Automata::cook() {
    state == COOK;
    std::cout << "Cooking " << menu[chosen] << std::endl;
}

void Automata::finish() {
    if (state == COOK) {
        cash -= prices[chosen];
        chosen = -1;
        state = ON;
        std::cout << "Thank you!" << std::endl;
    } else {
        std::cout << "Cannot finish in this state." << std::endl;
    }
}
