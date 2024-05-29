//
// Created by Test on 16/04/2024.
//

#include "../headers/MainCourse.h"

std::string MainCourse::unit = "g";

MainCourse::MainCourse() : MenuItem() {

}

MainCourse::MainCourse( const MenuItem &item) : MenuItem(item) {

}

MainCourse::MainCourse( const std::string &name, const std::string &category, float price, int quantity, const minutes &preparationTime)
        : MenuItem(name, category, price, quantity, preparationTime) {

}


float MainCourse::getCalories() {

    // average calories of a main course per 100 grams
    return 200 * this->quantity / 100;
}
