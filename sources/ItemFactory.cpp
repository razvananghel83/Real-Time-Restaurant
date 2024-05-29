//
// Created by Test on 27/05/2024.
//

#include "../headers/ItemFactory.h"



Item* ItemFactory::createItem(itemType type) {

    Item* item;

    switch (type) {
        case MENU: {
            item = new MenuItem;
            break;
        }
        case ORDER: {
            item = new OrderItem;
            break;
        }
        default:
            return nullptr;
    }

    return item;
}
