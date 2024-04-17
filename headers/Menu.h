//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENU_H
#define REAL_TIME_RESTAURANT_MENU_H

#include "MenuItem.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>

class Menu {

private:
    std::vector<MenuItem> MenuList;

public:

    // Constructors :

    // Default constructor :
    Menu();

    // Constructor with parametres :
    Menu( std::vector<MenuItem>& list ) = delete;
    // Deleted because it has not been used

    // Copy constructor :
    // A single menu will be implemented so a copy constructor is not necessary
    Menu( const Menu& otherMenu ) = delete;

    // Destructor :
    ~Menu() = default;


    // Getter for the list of items :
    [[nodiscard]] const std::vector<MenuItem> &getMenuList() const;


    // Class methods :
    void readMenu( std::basic_ifstream<char>& file );


    // Operators :
    // A single menu will be implemented so this operator is not necessary
    Menu& operator = (const Menu &otherMenu) = delete;
    friend std::ostream& operator << (std::ostream& out, const Menu& menu);

};


#endif //REAL_TIME_RESTAURANT_MENU_H
