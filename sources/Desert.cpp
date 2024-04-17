//
// Created by Test on 16/04/2024.
//

#include "../headers/Desert.h"


float Desert::getCalories() {

    // sugar calories + other ingredients ( fats )
    return this->quantity / 200 * 4 + this->quantity / 200 * 5;
}
