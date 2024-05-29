//
// Created by Test on 29/04/2024.
//

#include "../../headers/Exceptions/FileNotOpened.h"

const char *FileNotOpened::what() const noexcept {

    return "The specified file could not be opened! Make sure it exists and has text in it!";
}
