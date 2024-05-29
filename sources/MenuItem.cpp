//
// Created by Test on 28/05/2024.
//

#include "../headers/MenuItem.h"


// Constructors

MenuItem::MenuItem() {

    this->itemId = ++staticItemId;
}


MenuItem::MenuItem(const Item &item) : Item(item) {

    this->itemId = ++staticItemId;
}


MenuItem::MenuItem(const std::string &name, const std::string &category, float price, int quantity,
                      const minutes &preparationTime) : Item(name, category, price, quantity, preparationTime) {

    this->itemId = ++staticItemId;
}


int MenuItem::staticItemId = 0;

void MenuItem::printInfo() {
    std::cout << "Info\n";
}

