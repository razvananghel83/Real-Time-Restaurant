//
// Created by Test on 03/04/2024.
//

#include "../headers/MenuItem.h"



// Getters and setters :

// Name field
const std::string &MenuItem::getName() const {
    return this->name;
}

void MenuItem::setName(const std::string &newName) {
    this->name = newName;
}


// Categoty field
const std::string &MenuItem::getCategoty() const {
    return this->category;
}

void MenuItem::setCategory(const std::string &newCategory) {
    this->category = newCategory;
}


// Price field
float MenuItem::getPrice() const {
    return this->price;
}

void MenuItem::setPrice(const float &newPrice) {
    this->price = newPrice;
}


// Id field
int MenuItem::getId() const {
    return this->itemId;
}

void MenuItem::setId(const int &newId) {
    this->itemId = newId;
}


// Pieces field:
int MenuItem::getPieces() const {
    return pieces;
}

void MenuItem::setPieces(const int &newNumberOfPieces) {
    this->pieces = newNumberOfPieces;
}

// preparationTime field
std::chrono::minutes MenuItem::getPreparationTime() const {
    return this->preparationTime;
}

void MenuItem::setPreparationTime(const std::chrono::minutes &duration) {
    this->preparationTime = duration;
}

// Operators :

std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration) {
    out << duration.count() << " minutes";
    return out;
}


//std::ostream& operator << ( std::ostream &out, const MenuItem &item ) {
//    out << item.name << " with the id: " << item.itemId << ", belongs to the categoty " << item.category << ", costs "
//        << item.price <<
//        " euros, is prepared in " << item.preparationTime << " and " << item.pieces << " pieces have been ordered.\n";
//    return out;
//}

std::ostream& operator << ( std::ostream &out, const MenuItem &item ) {
    out << item.name << ' ';
    return out;
}

bool MenuItem::operator==(const MenuItem &item) const {
    return name == item.name &&
           category == item.category &&
           price == item.price &&
           itemId == item.itemId &&
           pieces == item.pieces &&
           preparationTime == item.preparationTime;
}

bool MenuItem::operator!=(const MenuItem &item) const {
    return !(item == *this);
}
