//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_ORDER_H
#define REAL_TIME_RESTAURANT_ORDER_H

#include "MenuItem.h"
#include <vector>


class Order {

private:
    int orderId{0};
    std::vector<MenuItem> Items;


public:

    /* Every Items field will have 5 locations reserved for it in the memory because I considered that most people tipically order maximum
     * 5 MenuItems, beverages included. In other words, I am assuming that a client will order:
     * First Beverage, First course, Second Beverage, Second Course, Desert
     */

    // Construstors:

    // Default constructor:
    Order() = default;

    // Constructor with parametres :
    Order(int id)
            : orderId(id) {
    }

    Order(int id, std::vector<MenuItem> &Items)
            : orderId(id), Items(Items) {
    }

    // Copy constructor :
    Order(Order &order)
            : orderId(order.orderId), Items(order.Items) {

    }

    // Destructor :
    ~Order() = default;




    // Getters and setters:


    // Order_Id field:
    int getOrderId() const;

    void setOrderId(int newOrderId);


    // Items field:
    const std::vector<MenuItem> &getItems() const;

    void setItems(const std::vector<MenuItem> &newItems);


    // Other vector methods:
    void clearOrder();

    void addItem(MenuItem &item);

    void removeItem(MenuItem &item);

    void replaceItem(MenuItem &oldItem, MenuItem &newItem);

    float calculatePrice();      // the float sum of the prices of order items


    std::chrono::minutes calculateTimpPreparareComanda();
    // I am defining the preparation time of an order, as the maximum between the preparations times of each item of an Order


    int orderItems() const;


    // Operators :
    Order &operator=(const Order &otherOrder) = default;

    friend std::ostream &operator<<(std::ostream &os, const Order &order);

};

#endif //REAL_TIME_RESTAURANT_ORDER_H
