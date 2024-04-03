//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENU_H
#define REAL_TIME_RESTAURANT_MENU_H

#include "MenuItem.h"
#include <vector>

class Menu {
private:
    std::vector<MenuItem> MenuList;

public:

    // Constructors :


    // Constructor with parametres :
    Menu(std::vector<MenuItem> &list)
            : MenuList(list) {

    }


    // Getter :
    const std::vector<MenuItem> &getMenuList() const;

    void setMenuList(const std::vector<MenuItem> &newList);


    // Other vector methods:
    void clearMenu();

    void addItem(MenuItem &item);

    void removeItem(MenuItem &item);

    void replaceItem(MenuItem &oldItem, MenuItem &newItem);

    int MenuLength() const;


    // Operators :
    Menu &operator=(const Menu &otherMenu) = delete;

    friend std::ostream &operator<<(std::ostream &out, const Menu &menu);

};


#endif //REAL_TIME_RESTAURANT_MENU_H
