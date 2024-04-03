//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_TABLE_H
#define REAL_TIME_RESTAURANT_TABLE_H

#include "Order.h"

class Table {
private:
    int tableId{0};
    bool occupied{false};
    Order order;


public:

    // Constructors :

    // Default constructor :
    Table() = default;

    // Constructor parametrizabil :
    Table(int tableId, bool occupied, Order &order)
            : tableId(tableId), occupied(occupied), order(order) {

    }

    // Copy constructor :
    Table(Table &otherTable) = default;


    // Destructor :
    ~Table() = default;




    // Getters and setters :

    // Id field :
    int getId() const;

    void setId(int newId);

    // Occupied field :
    bool getOccupied() const;

    void setOccupied(bool newState);

    void placeOrder(Order &order);

    // Operators :
    Table &operator=(const Table &otherTable) = default;

    friend std::ostream &operator<<(std::ostream &out, const Table &table);

};


#endif //REAL_TIME_RESTAURANT_TABLE_H
