//
// Created by Test on 29/04/2024.
//

#include "../../headers/Exceptions/InvalidPrice.h"

const char *InvalidPrice::what() const noexcept {

     return "The price is invalid! It should be greater than 0!";
}
