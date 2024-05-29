//
// Created by Test on 03/04/2024.
//

#include "../headers/Order.h"


// Construstors:

// Default constructor:
Order::Order() {

    staticOrderId++;
    this->orderId = staticOrderId;
}

// Constructor with parametres :
Order::Order(  const std::vector< std::shared_ptr<OrderItem> >& list) : Items(list)  {

    staticOrderId++;
    this->orderId = staticOrderId;
}

// Copy constructor :
Order::Order (Order &order) : Items( order.Items ){

    staticOrderId++;
    this->orderId = staticOrderId;
}



// Initialisation of static orderId field :
int Order::staticOrderId = 100;



// Getters :
// Items field :
const  std::vector< std::shared_ptr<OrderItem> > &Order::getItems() const {
    return this->Items;
}


// Other vector methods :
void Order::clearOrder() {
    Items.clear();
}

void Order::addItem( OrderItem &item ) {
    Items.emplace_back(&item);
}

void Order::removeItem( std::shared_ptr<OrderItem> item) {

    for (auto it = Items.begin(); it != Items.end(); it++) {
        if (item == *it) {
            Items.erase(it);
            break;
        }
    }
}

// modificare cu index
void Order::replaceItem( std::shared_ptr<OrderItem> oldItem, std::shared_ptr<OrderItem> newItem) {

    for (auto &Item: Items) {
        if ( oldItem == Item) {
            Item = newItem;
            break;
        }
    }
}

float Order::calculatePrice() {       // the float sum of the prices of order items

    float price = 0;
    for (auto &Item: Items)
        price += (Item->getNumber() * Item->getPrice());

    return price;
}

std::chrono::minutes Order::calculatePreparationTime() {

    // I am defining the preparation time of an order, as the maximum between the preparations times of each item of an Order

    std::chrono::minutes maximum = Items[0]->getPreparationTime();

    for (auto &Item: Items)
        if (Item->getPreparationTime() > maximum)
            maximum = Item->getPreparationTime();

    return maximum;
}


void Order::addTime(std::chrono::minutes extraMinutes) {

        this->timerTime += extraMinutes;
}




// Operators :
Order &Order::operator=(const Order &otherOrder) {

    this->Items = otherOrder.Items;
    return *this;
}


std::ostream &operator<<(std::ostream &out, const Order &order) {

    if( !order.Items.empty() )
    {

        out << "The order with the id: " << order.orderId << " is made out of the next items: " << '\n';
        auto it = order.getItems().begin();

        while (it != prev(order.getItems().end())) {

            std::cout << (**it) << "; ";
            ++it;
        }

        std::cout << (**it) << ".\n\n";
    }
    else
        out << "The order is empty!\n\n";

    return out;
}


