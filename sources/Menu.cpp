//
// Created by Test on 03/04/2024.
//

#include "../headers/Menu.h"


// Getter :
const std::vector<MenuItem> &Menu::getMenuList() const {
    return MenuList;
}

void Menu::setMenuList(const std::vector<MenuItem> &newList) {
    MenuList = newList;
}


// Other vector methods:
void Menu::clearMenu() {
    MenuList.clear();
}

void Menu::addItem(MenuItem &item) {
    MenuList.emplace_back(item);
}

void Menu::removeItem(MenuItem &item) {

    for (auto it = MenuList.begin(); it != MenuList.end(); it++) {
        if (item == *it) {
            MenuList.erase(it);
            break;
        }
    }
}

void Menu::replaceItem(MenuItem &oldItem, MenuItem &newItem) {

    for (auto &Item: MenuList) {
        if (oldItem == Item) {
            Item = newItem;
            break;
        }
    }
}

int Menu::MenuLength() const {
    return MenuList.size();
}


// Operators :


std::ostream& operator << (std::ostream &out, const Menu &menu) {
    out << "The list of items available to order is: \n";

    for (const auto &it: menu.MenuList)
        out << it;
    out << "\n\n";

    return out;
}
