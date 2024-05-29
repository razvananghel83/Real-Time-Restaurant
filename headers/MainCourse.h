//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_MAINCOURSE_H
#define REAL_TIME_RESTAURANT_V1_MAINCOURSE_H

#include "MenuItem.h"

class MainCourse : public MenuItem {

private:

    /// The unit for main courses is grams.
    static std::string unit;

public:

    // Constructors:
    /// Default constructor which calls Item's constructor.
    MainCourse();

    /// Copy constructor which calls Item's copy constructor.
    explicit MainCourse(const MenuItem &item);

    /// Constructor with parameters which calls Item's constructor with parameterss.
    MainCourse(const std::string &name, const std::string &category, float price, int quantity,
           const minutes &preparationTime);

    float getCalories();
};



#endif //REAL_TIME_RESTAURANT_V1_MAINCOURSE_H
