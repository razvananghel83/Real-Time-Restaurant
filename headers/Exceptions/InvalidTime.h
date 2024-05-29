//
// Created by Test on 15/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_INVALIDTIME_H
#define REAL_TIME_RESTAURANT_V1_INVALIDTIME_H

// Exceptions : invalid input

#include <exception>

class InvalidTime : public std::exception {

public:

    const char * what() const noexcept override;

};

#endif //REAL_TIME_RESTAURANT_V1_INVALIDTIME_H
