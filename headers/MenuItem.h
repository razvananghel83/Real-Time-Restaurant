//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENUITEM_H
#define REAL_TIME_RESTAURANT_MENUITEM_H

#include <chrono>
#include <iostream>


using namespace std::chrono;

/// Override for the operator which prints time in the following form: \n
/// \b Duration \b ( an integer ) \b minutes \b.
std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration);
// nu stiu daca e bine sa il las aici din main nu e vizibil, daca il las doar in MenuItem.cpp


/** \a Base class without pure virtual functions.\a It has the following fields: \n
    - \b name \b → private std::string which stores the name of the item \n \n
    - \b category \b → private std::string which stores the name of the item's category \n \n
    - \b price \b → private float which stores how much the item costs. The default value is 0. \n \n
    - \b pieces \b → private int which stores how many items exist, according to where the item is used. \n \n

    For example, inside the Menu class which stores the menu of the restaurant, a number of pieces is not necesarry
because the MenuItem just has to be visible in the menu, so inside the menu, pieces is set to 1. \n \n
On the other hand, when the item is inside an order, multiple pieces of the same item might be ordered, so there the field
might be modified. \n \n

    - \b quantity \b → protected int which stores the quantity of each item. The unit for it is declared later. \n \n
    - \b preparationTime \b → private std::chrono::minutes field that stores the preparation time in minutes for each MenuItem
    \n \n
    - \b itemId \b → private int which, in combination with the static field staticItemId implements a counting sistem for
    all MenuItems created, providing an individual ID for each of them.
**/
class MenuItem {

private:

    std::string name;
    std::string category;
    float price{0.0f};
    int pieces{0};

protected:

    int quantity{0};

private:

    std::chrono::minutes preparationTime{0min};
    int itemId{0};
    static int staticItemId;
    static std::string unit;

public:

    // Constructors :


    // Default constructor :
    MenuItem();

    // Constructor with parametres :
    MenuItem(const std::string &name, const std::string &category, float price, int pieces, int quantity,
             std::chrono::minutes preparationTime);

    // Copy constructor :
    MenuItem(MenuItem const &Item);

    // Destructor :
    ~MenuItem() = default;


    // Getters :
    [[nodiscard]] float getPrice() const;
    [[nodiscard]] int getPieces() const;
    [[nodiscard]] std::chrono::minutes getPreparationTime() const;

    // Virtual function :
    virtual float getCalories();

    // Operators :
    [[nodiscard]] MenuItem& operator = (const MenuItem &Item);

    friend std::ostream& operator >> ( std::ostream &out, const MenuItem &item );
    friend std::ostream& operator << ( std::ostream &out, const MenuItem &item );

    bool operator == (const MenuItem &item) const;
    bool operator != (const MenuItem &item) const;
};

/// For the base class, the unit for the quantity is unknown. \n \n
/// It represents the acronim of the unit correspondent to a certain MenuItem. \n \n
/// Deserts and MainCourses are measured in grams, while FirstCourses and Drinks are measured in mililiters.
static std::string unit = "Unknown";

#endif //REAL_TIME_RESTAURANT_MENUITEM_H
