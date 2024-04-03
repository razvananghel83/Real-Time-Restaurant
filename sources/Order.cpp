//
// Created by Test on 03/04/2024.
//

#include "../headers/Order.h"



/* Every Items field will have 5 locations reserved for it in the memory because I considered that most people tipically order maximum
 * 5 MenuItems, beverages included. In other words, I am assuming that a client will order:
 * First Beverage, First course, Second Beverage, Second Course, Desert
 */


// Getters and setters:


// Order_Id field:
int Order::getOrderId() const {
    return orderId;
}

void Order::setOrderId(int newOrderId) {
    orderId = newOrderId;
}


// Items field:
const std::vector<MenuItem> &Order::getItems() const {
    return Items;
}

void Order::setItems(const std::vector<MenuItem> &newItems) {
    Items = newItems;
}


// Other vector methods:
void Order::clearOrder() {
    Items.clear();
}

void Order::addItem(MenuItem &item) {
    Items.emplace_back(item);
}

void Order::removeItem(MenuItem &item) {

    for (auto it = Items.begin(); it != Items.end(); it++) {
        if (item == *it) {
            Items.erase(it);
            break;
        }
    }
}

void Order::replaceItem(MenuItem &oldItem, MenuItem &newItem) {

    for (auto &Item: Items) {
        if (oldItem == Item) {
            Item = newItem;
            break;
        }
    }
}

float Order::calculatePrice() {       // the float sum of the prices of order items

    float price = 0;
    for (auto &Item: Items)
        price += (Item.getPieces() * Item.getPrice());

    return price;
}

std::chrono::minutes Order::calculateTimpPreparareComanda() {

    // I am defining the preparation time of an order, as the maximum between the preparations times of each item of an Order

    std::chrono::minutes maximum = Items[0].getPreparationTime();

    for (auto &Item: Items)
        if (Item.getPreparationTime() > maximum)
            maximum = Item.getPreparationTime();

    return maximum;
}

int Order::orderItems() const {
    return this->Items.size();
}


// Operators :

std::ostream &operator<<(std::ostream &os, const Order &order) {
    os << "The order with the id: " << order.orderId << " is made out of the next items: " << '\n';

    for (const auto &Item: order.Items)
        os << Item << ", ";
    os << ".\n";

    return os;
}

