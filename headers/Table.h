//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_TABLE_H
#define REAL_TIME_RESTAURANT_TABLE_H

#include "Order.h"

/**
 *  Class used to organise orders by the tables who are placing them. <br> <br>
 *  Each table has an unique id implamented via a static field. <br> <br>
 *  It also has an <i>Order</i> object as a field.
 */
class Table {

private:

    /// Bool field which tells whether the table is occupied or not. The default value is 0.
    bool occupied{false};

    /// Order object which stores the order that the table is passing onto the kitchen.
    Order order;

    /// This field stores the id of the current table.
    int tableId{0};
    /// Static field which increases as more tables are constructed. Starts with 0.
    static int staticId;

public:

    // Constructors :

    /// Default constructor which increses the staticId.
    Table();

    /**
     * Constructor with parameters:
     * @param occupied -> bool which signifies that a table is free or not.
     * @param order    -> an Order which belongs to the table.
     */
    Table(bool occupied, Order &order);

    /**
    *   Copy constructor which does not copy the id field. <br> <br>
    *   For each new copied Table, the copy constructor will generate a new unique id.
    */
    Table(Table &otherTable);


    /// Destructor set to default
    ~Table() = default;


    // Operators :
    /// Assignment operator. Does not copy the <i>tableId</i> field.
    [[nodiscard]] Table &operator=(const Table &otherTable);
    /// Operator which prints out if the table is occupied and the order that corresponds to it.
    friend std::ostream &operator<<(std::ostream &out, const Table &table);

};


#endif //REAL_TIME_RESTAURANT_TABLE_H
