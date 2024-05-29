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

/**
 *  This class will be used to store the menu of the restaurant. It has only one field called MenuList,
 *  which is a list of MenuItems.
 */
class Menu {

private:

    /// This is the only field inside the Menu class, a std::vector of MenuItems, which contains all the items in the Menu.
    std::vector<MenuItem> MenuList;

public:

    // Constructors :
    /**
     *    Default constructor for Menu class. <br> <br>
     *    Called <b><i>to reserve</i></b> space for <u>all of the items that will be read in the menu</u>.
     */
    Menu();

    /**
     *    Constructor with parametres : <br> <br>
     *    Deleted because it has not been used.
     */
    Menu( std::vector<MenuItem>& list ) = delete;

    /**
     *   Copy constructor : <br> <br>
     *   A single menu will be implemented so a copy constructor is not necessary.
     */
    Menu( const Menu& otherMenu ) = delete;

    /// Destructor set to default.
    ~Menu() = default;

    /**
     *  Getter for the list of items inside the menu : <br> <br>
     *  Returns a const refference to a <i>std::vector</i> which contains all the items in the Menu.
     */
    [[nodiscard]] const std::vector<MenuItem> &getMenuList() const;


    // Class methods :

    /// Reads all the menu items from an input file. \n
    /// In this file, a Item is written on a single line, in the following form : \n
    /// Name; Category; Price; Pieces( set by default to 1 ); Quantity; Preparation time
    void readMenu( std::basic_ifstream<char>& file );


    // Operators :
    /// A single menu will be implemented so this operator is not necessary
    Menu& operator = (const Menu &otherMenu) = delete;

    /**
     *  Operator that is used to print the entire menu <br> <br>
     *  It uses the operator >> for each Item it prints so all of the fields of each Item will be printed,
     *  not just the name.
     */
     friend std::ostream& operator << (std::ostream& out, const Menu& menu);

};


#endif //REAL_TIME_RESTAURANT_MENU_H
