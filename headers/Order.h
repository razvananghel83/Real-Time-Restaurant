//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_ORDER_H
#define REAL_TIME_RESTAURANT_ORDER_H

#include "MenuItem.h"
#include <vector>
#include <memory>


class Order {

private:

    std::vector< std::shared_ptr<MenuItem> > Items;
    int orderId{0};
    static int staticOrderId;


public:

    // Construstors:

    // Default constructor:
    Order();

    // Constructor with parametres :
    Order(int id,  std::vector< std::shared_ptr<MenuItem> > list) = delete;     // deleted because the id will be implemented automatically via the staticId field
    Order(  std::vector< std::shared_ptr<MenuItem> > list );

    // Copy constructor :
    Order(Order &order);

    // Destructor :
    ~Order() = default;



    // Getters:
    // Items field:
    [[nodiscard]] const std::vector< std::shared_ptr<MenuItem> > &getItems() const;


    // Other vector methods :
    void clearOrder();
    void addItem(MenuItem &item);

    void removeItem( std::shared_ptr<MenuItem>item );
    void replaceItem( std::shared_ptr<MenuItem> oldItem, std::shared_ptr<MenuItem> newItem);

    [[nodiscard]] float calculatePrice();      // the float sum of the prices of order items
    [[nodiscard]] std::chrono::minutes calculatePreparationTime();
    // I am defining the preparation time of an order, as the maximum between the preparations times of each item of an Order



    // Operators :
    [[nodiscard]] Order &operator=(const Order &otherOrder);

    friend std::ostream &operator<<(std::ostream &os, const Order &order);

};

#endif //REAL_TIME_RESTAURANT_ORDER_H
