//
// Created by Test on 29/04/2024.
//

#include "../../headers/Exceptions//InvalidTime.h"

const char *InvalidTime::what() const noexcept {

    return "The preparation time is invalid! It should be greater than 0!";
}