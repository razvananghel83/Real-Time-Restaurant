//
// Created by Test on 29/04/2024.
//

#include "../../headers/Exceptions/InvalidQuantity.h"

const char *InvalidQuantity::what() const noexcept {

    return "The quantity provided should be pozitive and greater than 0!";
}