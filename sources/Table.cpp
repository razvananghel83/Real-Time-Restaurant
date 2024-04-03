//
// Created by Test on 03/04/2024.
//

#include "../headers/Table.h"


// Getters and setters :

// Id field :
int Table::getId() const {
    return this->tableId;
}

void Table::setId(int newId) {
    this->tableId = newId;
}

// Occupied field :
bool Table::getOccupied() const {
    return this->occupied;
}

void Table::setOccupied(bool newState) {
    this->occupied = newState;
}

void Table::placeOrder(Order &order) {

}

// Operators :

std::ostream& operator<<(std::ostream &out, const Table &table) {
    if (table.occupied == 1)
        out << "The table with the id: " << table.tableId << " is occupied and has the order:\n" << table.order
            << "\n.";
    else
        out << "The table with the id: " << table.tableId << " is free.\n";

    return out;
}

