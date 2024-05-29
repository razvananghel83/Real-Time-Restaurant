//
// Created by Test on 16/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_DESERT_H
#define REAL_TIME_RESTAURANT_V1_DESERT_H

#include "MenuItem.h"

class Desert : public MenuItem {

private:
    /// The unit for deserts is grams.
    static std::string unit;

public:

    // Constructors:
    /// Default constructor which calls Item's constructor.
    Desert();

    /// Copy constructor which calls Item's copy constructor.
    explicit Desert(const MenuItem &item);

    /// Constructor with parameters which calls Item's constructor with parameterss.
    Desert(const std::string &name, const std::string &category, float price, int quantity,
           const minutes &preparationTime);

    float getCalories();
};

#endif //REAL_TIME_RESTAURANT_V1_DESERT_H
