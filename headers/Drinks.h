//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_DRINKS_H
#define REAL_TIME_RESTAURANT_V1_DRINKS_H

#include "MenuItem.h"

template <typename T>
class Drinks : public MenuItem {

private:

    /// The unit for drinks is militers.
    static std::string unit;
    /// The percentage of alcohol inside a drink. Can be float or int.
    T alcohol;

public:

    // Constructors:
    /// Default constructor which calls MenuItem's constructor.
    Drinks() = default;

    /// Copy constructor which calls MenuItem's copy constructor.
    explicit Drinks(const MenuItem &item, int alcohol );


    /// Constructor with parameters which calls MenuItem's constructor with parameterss.
    Drinks(const std::string &name, const std::string &category, float price, int quantity,
           const minutes &preparationTime, int alcohol );

    float getCalories();
};

#endif //REAL_TIME_RESTAURANT_V1_DRINKS_H
