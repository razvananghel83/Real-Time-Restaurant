//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_ORDER_H
#define REAL_TIME_RESTAURANT_ORDER_H

#include "Item.h"
#include <vector>
#include <memory>
#include "OrderItem.h"

/// Class used to handle orders from customers. Uses a list of OrderItems as its main field.
class Order {

private:

    /// A private list of OrderItems.
    std::vector< std::shared_ptr<OrderItem>> Items;

    /// This field will be used for printing the timer out to the client in real time.
    std::chrono::minutes timerTime{ this->calculatePreparationTime() };

    /// Private int field which stores the id of the current order. Its value depends on the <i>staticOrderId</i> field.
    int orderId{0};

    /**
     *  Static id field used to give an unique id to each order. Starts with 100. <br> <br>
     *  It increments every time an Order object is constructed.
     */
    static int staticOrderId;


public:

    // Construstors:

    /// Default constructor which increses the staticId.
    Order();

    /// Constructor with parametres has been deleted because the id will be implemented automatically via the staticId field.
    Order(int id, std::vector< std::shared_ptr<OrderItem> > list) = delete;
    /// Constructor that just takes a list of OrderItems as a parameter and assigns the order an unique id.
    explicit Order( const std::vector< std::shared_ptr<OrderItem> >& list );

    /**
     *   Copy constructor which does not copy the id field. <br> <br>
     *   For each new copied Order, the copy constructor will generate a new unique id.
     */
    Order(Order &order);

    /// Destructor :
    ~Order() = default;



    // Getters:
    /// Getter for the items field:
    [[nodiscard]] const std::vector< std::shared_ptr<OrderItem> > &getItems() const;


    // Other vector methods :
    /// Clears out the list of items inside an Order.
    void clearOrder();
    /// Adds an OrderItem to an Orders's list.
    void addItem(OrderItem &item);

    /// de modificat
    /// Removes an item from the list of OrderItems.
    void removeItem( std::shared_ptr<OrderItem>item );
    /// Replaces an item to the list of OrderItems.
    void replaceItem( std::shared_ptr<OrderItem> oldItem, std::shared_ptr<OrderItem> newItem);

    /// This function is used by the kitchen to add extra time for preparing an Order
    void addTime( std::chrono::minutes extraMinutes );

    /**
     * Calculates the price of an order and returns the result as a float. <br> <br>
     * The price of an order is the sum of the prices of all individual items that the order contains.
     */
    [[nodiscard]] float calculatePrice();

    /**
     *  Calculates how long a complete order will take to be served. <br> <br>
     *  I am defining the preparation time of an order, as the maximum between the preparations times of each item of an Order.
     */
    [[nodiscard]] std::chrono::minutes calculatePreparationTime();


    // Operators :
    /// Assignment operator
    [[nodiscard]] Order &operator=(const Order &otherOrder);
    /// Operator which prints all of the items inside an order, along with the order's id.
    friend std::ostream &operator<<(std::ostream &os, const Order &order);

};

#endif //REAL_TIME_RESTAURANT_ORDER_H
