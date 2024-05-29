//
// Created by Test on 27/05/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_ITEMFACTORY_H
#define REAL_TIME_RESTAURANT_V1_ITEMFACTORY_H

#include "Item.h"
#include "MenuItem.h"
#include "OrderItem.h"

enum itemType {

    MENU = 1,
    ORDER = 2
};

class ItemFactory {

public:
    static Item* createItem(itemType type );

};


#endif //REAL_TIME_RESTAURANT_V1_ITEMFACTORY_H
