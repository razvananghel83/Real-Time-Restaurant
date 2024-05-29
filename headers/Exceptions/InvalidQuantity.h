//
// Created by Test on 29/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_INVALIDQUANTITY_H
#define REAL_TIME_RESTAURANT_V1_INVALIDQUANTITY_H


#include <exception>

class InvalidQuantity : public std::exception {

public:

    const char * what() const noexcept override;

};


#endif //REAL_TIME_RESTAURANT_V1_INVALIDQUANTITY_H
