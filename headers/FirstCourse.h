//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H
#define REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H

#include "MenuItem.h"

class FirstCourse : public MenuItem {

private:

    /// The unit for first courses is mililiters.
    static std::string unit;

public:

    // Constructors:
    /// Default constructor which calls MenuItem's constructor.
    FirstCourse();

    /// Copy constructor which calls MenuItem's copy constructor.
    explicit FirstCourse(const MenuItem & Item );

    /// Constructor with parameters which calls MenuItem<T>'s constructor with parameterss.
    FirstCourse(const std::string &name, const std::string &category, float price, int quantity,
           const minutes &preparationTime);

    float getCalories();
};


#endif //REAL_TIME_RESTAURANT_V1_FIRSTCOURSE_H
