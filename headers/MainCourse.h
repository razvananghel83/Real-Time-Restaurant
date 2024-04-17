//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_MAINCOURSE_H
#define REAL_TIME_RESTAURANT_V1_MAINCOURSE_H

#include "MenuItem.h"

class MainCourse : public MenuItem {

private:

    static std::string unit;

public:
    float getCalories() override;
};

std::string MainCourse::unit = "g";


#endif //REAL_TIME_RESTAURANT_V1_MAINCOURSE_H
