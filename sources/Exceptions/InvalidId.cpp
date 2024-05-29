//
// Created by Test on 29/04/2024.
//

#include "../../headers/Exceptions/InvalidId.h"

const char *InvalidId::what() const noexcept {

    return "The ID is invalid! It should be unique and greater than 0!";
}