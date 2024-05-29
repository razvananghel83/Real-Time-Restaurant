//
// Created by Test on 29/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_INVALIDPRICE_H
#define REAL_TIME_RESTAURANT_V1_INVALIDPRICE_H


#include <exception>

class InvalidPrice : public std::exception {

public:

    const char * what() const noexcept override;

};


#endif //REAL_TIME_RESTAURANT_V1_INVALIDPRICE_H
