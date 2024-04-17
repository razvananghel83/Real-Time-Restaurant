//
// Created by Test on 03/04/2024.
//

#include "../headers/MenuItem.h"
#include "../headers/MyExceptions.h"

// Constructors :


// Default constructor :
MenuItem::MenuItem() {

    try{
        if( this->itemId <= 0 )
            throw InvalidId();

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

    staticItemId++;
    this->itemId = staticItemId;
}

// Constructor with parametres :
MenuItem::MenuItem(const std::string &name, const std::string &category, float price, int pieces, int quantity, std::chrono::minutes preparationTime)
             : name(name), category(category), price(price), pieces(pieces), quantity(quantity), preparationTime(preparationTime) {

    try{
        if( this->itemId <= 0 )
            throw InvalidId();

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

    staticItemId++;
    this->itemId = staticItemId;
}

// Copy constructor :
MenuItem::MenuItem(MenuItem const &Item)
    : name( Item.name ), category( Item.category ), price( Item.price ), pieces( Item.pieces ), quantity( Item.quantity ), preparationTime( Item.preparationTime ) {

    try{
        if( Item.itemId <= 0 )
            throw InvalidId();

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

    staticItemId++;
    this->itemId = staticItemId;
}

// Initialisation of staticItemId field:
int MenuItem::staticItemId = 10;


// Getters :

// Price field :
float MenuItem::getPrice() const {
    return this->price;
}


// Pieces field:
int MenuItem::getPieces() const {
    return pieces;
}


// PreparationTime field :
std::chrono::minutes MenuItem::getPreparationTime() const {
    return this->preparationTime;
}

float MenuItem::getCalories() {
    return 0;
}

// Operators :

MenuItem& MenuItem::operator=(const MenuItem &Item) {

    this->name = Item.name;
    this->category = Item.category;
    this->price = Item.price;
    this->itemId = Item.itemId;
    this->quantity = Item.quantity;
    this->pieces = Item.pieces;
    this->preparationTime = Item.preparationTime;

    return *this;
}
// unde sa pun operatorul acesta? Din main nu e accesibil decat daca il copiez si acolo
std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration) {

    out << duration.count() << " minutes";
    return out;
}


std::ostream& operator << ( std::ostream &out, const MenuItem &item ) {

    out << item.name;
    return out;
}

std::ostream& operator >> ( std::ostream &out, const MenuItem &item ) {

    out << item.name << " with the id: " << item.itemId
        <<  ", belongs to the categoty " << item.category
        << ", costs " << item.price
        << " euros, is prepared in " << item.preparationTime
        << " and " << item.pieces << " pieces have been ordered.\n";
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





