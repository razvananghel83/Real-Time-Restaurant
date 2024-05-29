//
// Created by Test on 16/04/2024.
//

#include "../headers/Desert.h"

std::string Desert::unit = "g";

Desert::Desert() : MenuItem() {

}

Desert::Desert( const MenuItem &item) : MenuItem(item) {

}

Desert::Desert( const std::string &name, const std::string &category, float price, int quantity, const minutes &preparationTime)
                    : MenuItem(name, category, price, quantity, preparationTime) {

}

float Desert::getCalories() {

    // sugar calories + other ingredients ( fats )
    return this->quantity / 200 * 4 + this->quantity / 200 * 5;
}
