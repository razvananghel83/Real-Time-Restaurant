//
// Created by Test on 16/04/2024.
//

#include "../headers/Drinks.h"

template <typename T>
std::string Drinks<T>::unit = "ml";

template <typename T>
Drinks<T>::Drinks( const MenuItem &item, int alcohol )
    : MenuItem(item), alcohol( alcohol ) {

}

template <typename T>
Drinks<T>::Drinks( const std::string &name, const std::string &category, float price, int quantity, const minutes &preparationTime, int alcohol )
        : MenuItem(name, category, price, quantity, preparationTime), alcohol( alcohol ) {

}


template <typename T>
float Drinks<T>::getCalories() {

    // sugar calories + other ingredients
    return this->quantity / 4 + this->quantity * 0.87;
}