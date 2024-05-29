//
// Created by Test on 28/05/2024.
//

#ifndef REAL_TIME_RESTAURANT_V1_MENUITEM_H
#define REAL_TIME_RESTAURANT_V1_MENUITEM_H

#include "Item.h"


class MenuItem : public Item {

private:
    /**
      *   Potected int which, in combination with the static field <i>staticItemId</i> implements a counting sistem for
      *   all MenuItems created, providing an individual ID for each of them.
    **/
    int itemId{0};

    /**
     *   Protected static int which, in combination with the field <i>itemId</i> implements a counting sistem for
     *   all MenuItems created, providing an individual ID for each of them. <br> <br>
     *   It stores the actual number of items and is incremented in each Item constructor. It starts from <i>10</i>.
    **/
    static int staticItemId;

public:

    // Constructors:
    /// Default constructor:
    MenuItem();

    /// Constructor with parameters
    MenuItem(const std::string &name, const std::string &category, float price, int quantity,
             const minutes &preparationTime);

    /// Copy constructor
    explicit MenuItem(const Item &item);

    /// Default destructor
    ~MenuItem() = default;

    /// Virtual function which calculates the calories for each type of course based on the unit it has.
//    virtual float getCalories();
    void printInfo() override;


};



#endif //REAL_TIME_RESTAURANT_V1_MENUITEM_H
