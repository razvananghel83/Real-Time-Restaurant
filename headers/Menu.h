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

    /// This is the only field inside the Menu class, a a std::vector of MenuItems \n
    std::vector<MenuItem> MenuList;

public:

    // Constructors :

    /// Default constructor for menu class \n
    /// Called to reserve space for all of the items that will be read in the menu.
    Menu();

    /// Constructor with parametres : \n
    /// Deleted because it has not been used
    Menu( std::vector<MenuItem>& list ) = delete;

    /// Copy constructor : \n
    /// A single menu will be implemented so a copy constructor is not necessary
    Menu( const Menu& otherMenu ) = delete;

    /// Destructor for menu
    ~Menu() = default;


    /// Getter for the list of items inside the menu : \n
    /// Returns a const std::vector which contains all the items in the Menu
    [[nodiscard]] const std::vector<MenuItem> &getMenuList() const;


    // Class methods :

    /// Reads all the menu items from an input file. \n
    /// In this file, a MenuItem is written on a single line, in the following form : \n
    /// Name; Category; Price; Pieces( set by default to 1 ); Quantity; Preparation time
    void readMenu( std::basic_ifstream<char>& file );


    // Operators :
    /// A single menu will be implemented so this operator is not necessary
    Menu& operator = (const Menu &otherMenu) = delete;

    /// Operator that is used to print the entire menu \n
    /// It uses the operator >> for each MenuItem it prints so all of the fields of each MenuItem will be printed,
    /// not just the name.
    friend std::ostream& operator << (std::ostream& out, const Menu& menu);

};


#endif //REAL_TIME_RESTAURANT_MENU_H
