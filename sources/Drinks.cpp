//
// Created by Test on 16/04/2024.
//

#include "../headers/Drinks.h"


float Drinks::getCalories() {

    return this->quantity / 4 + this->quantity * 0.87;
}