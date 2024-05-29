//
// Created by Test on 27/04/2024.
//

#include "../headers/OrderItem.h"

// Getter for the number field

int OrderItem::getNumber() const {
    return this->number;
}

void OrderItem::printInfo() {

    std::cout << "Override\n";
}


