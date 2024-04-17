//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H
#define REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H

#include "MenuItem.h"

class FirstCourse : public MenuItem {

private:

    static std::string unit;

public:

    float getCalories() override;

};

std::string FirstCourse::unit = "ml";



#endif //REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H
