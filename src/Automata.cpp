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
    std::cout<<"Automata is turned off." << std::endl;
}

void Automata::coin(int value) {
    if (state == ACCEPTING_COINS) {
        cash += value;
        std::cout<<"Cash: " << cash << std::endl;
    }
}

void Automata::getMenu() {
    if (state == ON) {
        for (int i = 0; i < 3; i++) {
            std::cout << i+1 << "." << menu[i] << '-' << prices[i] << " rubles" << std::endl;
        }
    } else {
        std::cout << "Cannot get menu in this state." << std::endl;
    }
}

STATES Automata::getState() {
    return state;
}

void Automata::choice(int drinkNumber) {
    if (state == CHOOSING_DRINK) {
        if (drinkNumber >= 1 && drinkNumber <=3) {
            state = CHECKING_AMOUNT;
            int price = prices[drinkNumber-1];
            std::cout << "You have chosen " << menu[drinkNumber-1] << " for " << price << " rubles." << std::endl;
        } else {
            std::cout << "Invalid drink number." << std::endl;
        }
    } else {
        std::cout << "Cannot choose drink in this state." << std::endl; 
    }
}


void Automata::check() {
    if (state == CHECKING_AMOUNT) {
        if (cash >= prices[0]) {
            state = COOKING;
            std::cout << "Cooking..." << std::endl;
        } else {
            std::cout << "Not enough money." << std::endl;
            state = ACCEPTING_COINS;
        }
    } else {
        std::cout << "Cannot check amount in this state." << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPTING_COINS || state == CHOOSING_DRINK) {
        cash = 0;
        state = ON;
        std::cout << "Canceled." << std::endl;
    } else {
        std::cout << "Cannot cancel in this state." << std::endl;
    }
}

void Automata::cook() {
    if (state == COOKING) {
        std::cout << "Done. Please take your drink." << std::endl;
        cash -= prices[0];
        state = FINISHED;
    } else {
        std::cout << "Cannot cook in this state." << std::endl;
    }
}

void Automata::finish() {
    if (state == FINISHED) {
        cash = 0;
        state = ON;
        std::cout << "Thank you for using our automata!" << std::endl;
    } else {
        std::cout << "Cannot finish in this state." << std::endl;
    }
}
