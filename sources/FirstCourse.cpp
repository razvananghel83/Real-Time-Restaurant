//
// Created by Test on 16/04/2024.
//

#include "../headers/FirstCourse.h"


std::string FirstCourse::unit = "ml";

FirstCourse::FirstCourse() : MenuItem() {

}

FirstCourse::FirstCourse( const MenuItem &item) : MenuItem(item) {

}

FirstCourse::FirstCourse( const std::string &name, const std::string &category, float price, int quantity, const minutes &preparationTime)
        : MenuItem(name, category, price, quantity, preparationTime) {

}

float FirstCourse::getCalories() {

    // average calories of soups per 100 ml
    return 29.5 * this->quantity / 100;
}