//
#include "shooter.h"
#include <iostream>

Roll* Shooter::throw_dice(Die& die1, Die& die2) {
    Roll* roll = new Roll(die1, die2);
    roll->roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() {
    for (Roll* rollPtr: rolls) {
        std::cout << "Roll value " << rollPtr->roll_value() << std::endl;
    }
}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}

