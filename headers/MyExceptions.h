//
// Created by Test on 15/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_MYEXCEPTIONS_H
#define REAL_TIME_RESTAURANT_V1_MYEXCEPTIONS_H

// Exceptions : invalid input

#include <exception>

class InvalidPrice : public std::exception {

public:

    const char * what() const noexcept override{

        return "The price is invalid! It should be greater than 0!";
    }

};

class InvalidTime : public std::exception {

public:

    const char * what() const noexcept override{

        return "The preparation time is invalid! It should be greater than 0!";
    }

};

class InvalidId : public std::exception {

public:

    const char * what() const noexcept override{

        return "The ID is invalid! It should be unique and greater than 0!";
    }

};

class FileNotOpened : public std::exception {

public:

    const char * what() const noexcept override{

        return "The specified file could not be opened! Make sure it exists and has text in it!";
    }

};

class InvalidQuantity : public std::exception {

public:

    const char * what() const noexcept override{

        return "The quantity provided should be pozitive and greater than 0!";
    }

};

#endif //REAL_TIME_RESTAURANT_V1_MYEXCEPTIONS_H
