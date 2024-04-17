//
// Created by Test on 03/04/2024.
//

#include "../headers/Table.h"


int Table::staticId = 0;


// Constructors :

// Default constructor :
    Table::Table() {

        staticId++;
        this->tableId = staticId;
    }

// Constructor parametrizabil :
    Table::Table(bool occupied, Order &order)
            : occupied( occupied ), order( order ) {

        staticId++;
        this->tableId = staticId;
    }

// Copy constructor :
    Table::Table(Table &otherTable)
            : occupied( otherTable.occupied ), order( otherTable.order )  {

        staticId++;
        this->tableId = staticId;
    }


// Operators :

    Table &Table::operator=(const Table &otherTable) {

    this->occupied = otherTable.occupied;
    this->order = otherTable.order;

    return *this;
}

    std::ostream& operator<<(std::ostream &out, const Table &table) {

    if (table.occupied == true)
        out << "The table with the id " << table.tableId << " is occupied and has the order:\n" << table.order
            << "\n.";
    else
        out << "The table with the id " << table.tableId << " is free and has no orders.\n";

    return out;
}






