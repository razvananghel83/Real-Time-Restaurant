//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_TABLE_H
#define REAL_TIME_RESTAURANT_TABLE_H

#include "Order.h"

class Table {

private:

    bool occupied{false};
    Order order;

    int tableId{0};
    static int staticId;

public:

    // Constructors :

    // Default constructor :
    Table();

    // Constructor parametrizabil :
    Table(bool occupied, Order &order);

    // Copy constructor :
    Table(Table &otherTable);


    // Destructor :
    ~Table() = default;



    // Operators :
    [[nodiscard]] Table &operator=(const Table &otherTable);
    friend std::ostream &operator<<(std::ostream &out, const Table &table);

};


#endif //REAL_TIME_RESTAURANT_TABLE_H
