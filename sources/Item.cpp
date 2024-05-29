//
// Created by Test on 03/04/2024.
//

#include "../headers/Item.h"

#include "../headers/Exceptions/InvalidTime.h"
#include "../headers/Exceptions/InvalidQuantity.h"
#include "../headers/Exceptions/InvalidId.h"
#include "../headers/Exceptions/InvalidPrice.h"



// Constructor with parametres :
Item::Item(const std::string &name, const std::string &category, float price, int quantity, std::chrono::minutes preparationTime)
        : name(name), category(category), price(price), quantity(quantity), preparationTime(preparationTime) {

    try{

        if( this->price <= 0 )
            throw InvalidPrice();

        if( this->quantity <= 0 )
            throw InvalidQuantity();

        if( this->preparationTime <= 0min )
            throw InvalidTime();
    }
    catch ( std::exception& e ){

        std::cout << e.what() << '\n';
    }

}

// Copy constructor :
Item::Item(Item const &Item)
        : name( Item.name ), category( Item.category ), price( Item.price ), quantity( Item.quantity ), preparationTime( Item.preparationTime ) {

    try{
        if( Item.price <= 0 )
            throw InvalidPrice();

        if( Item.quantity <= 0 )
            throw InvalidQuantity();

        if( Item.preparationTime <= 0min )
            throw InvalidTime();
    }
    catch ( std::exception& e ){

        std::cout << e.what() << '\n';
    }

}


std::string Item::unit = "Unknown";


// Getters :

float Item::getPrice() const {
    return this->price;
}


std::chrono::minutes Item::getPreparationTime() const {
    return this->preparationTime;
}


// Operators :

Item& Item::operator=(const Item &Item) {

    this->name = Item.name;
    this->category = Item.category;
    this->price = Item.price;
    this->quantity = Item.quantity;
    this->preparationTime = Item.preparationTime;
    this->unit = Item.unit;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration) {

    out << duration.count() << " minutes";
    return out;
}



std::ostream& operator << ( std::ostream &out, const Item &item ) {

    out << item.name;
    return out;
}


std::ostream& operator >> ( std::ostream &out, const Item &item ) {

    out << item.name
        <<  ", belongs to the categoty " << item.category
        << ", costs " << item.price
        << " euros, is prepared in " << item.preparationTime
        << " and the unit for this item is " << item.unit << ".\n";
    return out;
}


bool Item::operator==(const Item &item) const {
    return name == item.name &&
           category == item.category &&
           price == item.price &&
           unit == item.unit &&
           quantity == item.quantity &&
           preparationTime == item.preparationTime;
}


bool Item::operator!=(const Item &item) const {
    return !(item == *this);
}



