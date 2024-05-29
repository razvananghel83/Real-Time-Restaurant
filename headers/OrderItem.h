//
// Created by Test on 27/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_ORDERITEM_H
#define REAL_TIME_RESTAURANT_V1_ORDERITEM_H


#include "Item.h"

/**
 *  Class which inherrits Item. Its main purpose is to differentiate between the items that make up the menu and
 *  the items that will be ordered by customers. <br> <br>
 *  The main difference between them is that OrderItem has an extra field called <i>number</i>.
 *  This allows for ordering multiple instances of the same item without having to construct a Item for each of the instances.
 */

class OrderItem : public Item {

private:

/**
 *    Private int which stores <i>how many items of the same kind exist</i>. <br> <br>
  *   It is used for orders, as the kitchen needs to know how many instances of an item it needs to cook for
  *   one order. <br> <br>
  *   <i>The <b>default value</b> is 0</i>.
 **/
    int number{0};

public:

    /// Getter for <i>number</i> field.
    int getNumber() const;


    // Constructors :

    OrderItem() = default;

    /**
     * Copy constructor for an OrderItem. It has the following parameters:
     * @param item    → a const Item& used to call the copy constructor for Item.
     * @param number  → an integer which specifies how many instances of the current item have been included in an order.
     */
    OrderItem(const Item &item, int number)
        : Item(item), number(number) {

    }


    /// Constructor with parameters. Calls Item's constructor with parameters.
    OrderItem(const std::string &name, const std::string &category, float price, int quantity,
              const std::chrono::minutes &preparationTime, int number )
                    : Item(name, category, price, quantity, preparationTime), number(number) {

    }


    /// Destructor set to default
    ~OrderItem() = default;

    void printInfo() override;
};


#endif //REAL_TIME_RESTAURANT_V1_ORDERITEM_H
