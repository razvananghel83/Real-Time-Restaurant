//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_DESERT_H
#define REAL_TIME_RESTAURANT_V1_DESERT_H

#include "MenuItem.h"

class Desert : public MenuItem {

private:

    static std::string unit;

public:
    float getCalories() override;
};

std::string Desert::unit = "g";

#endif //REAL_TIME_RESTAURANT_V1_DESERT_H
