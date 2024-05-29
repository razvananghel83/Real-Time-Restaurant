//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENUITEM_H
#define REAL_TIME_RESTAURANT_MENUITEM_H

#include <chrono>
#include <iostream>


using namespace std::chrono;

/**
 *  Override for the operator which prints time in the following form: <br>
 *  "<b>Duration</b> ( an integer ) <b>minutes</b>".
**/
std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration);


/**
 * <i>Base class without pure virtual functions.</i> <br>
 *
**/
class Item {

protected:

    /// Protected <i>std::string</i> which stores the name of the item.
    std::string name;
    /// Protected <i>std::string</i> which stores the name of the category the item belongs to.
    std::string category;

    /**
     * Protected <i>float</i> which stores how much the item costs. <br>
     * <i>The <b>default value</b> is 0</i>.
    **/
    float price{0.0f};

   /**
    *    This protected field stores the quantity of an Item. In combination with the static <i>std::string <b>unit</b></i>,
    *    which can only have the values <i>grams</i> or <i>mililiters</i>, it represents a real-life way of expressing
    *    food quantity. \n
    *    For example, a drink can be described as 350 mililiters and a main course can be described as 560 grams.
    **/
   float quantity{0};

   /**
    *   Protected <i>std::chrono::minutes</i> field that stores the preparation time in minutes for each Item. <br> <br>
    *   Can also be expressed using the <i>min</i> literal ( 35min ). <br> <br>
    *   <i>The <b>default value</b> is 0</i>.
   **/
   std::chrono::minutes preparationTime{0min};

   /**
    *  Static <i>std::string</i> which stores the unit used to measure each Item. The number of units is
    *  stored by the quantity field. <br> <br>
    *  For the base class, the unit for the quantity is <i>Unknown</i>. <br> <br>
    *  It represents the acronim of the unit correspondent to a certain Item. <br> <br>
    *  <i>Deserts</i> and <i>MainCourses</i> are measured in <b>grams</b>, while <i>FirstCourses</i>
    *  and <i>Drinks</i> are measured in <b>mililiters</b>.
   **/
   static std::string unit;

public:

   // Constructors :
   /// Default constructor which increses the <i>staticItemId</i>.
   Item() = default;

   /// Constructor with parametres which increses the <i>staticItemId</i>.
   Item(const std::string &name, const std::string &category, float price, int quantity,
        std::chrono::minutes preparationTime);

   /// Copy constructor which increses the <i>staticItemId</i>.
   Item(Item const &Item);

   /// Destructor set to default.
   ~Item() = default;


   // Getters :
   /// Getter for price field. <br> Returns how much the item costs.
   [[nodiscard]] float getPrice() const;
   /// Getter for preparationTime field. <br> Returns how long the item takes to be prepared.
   [[nodiscard]] std::chrono::minutes getPreparationTime() const;

   /// Pure virtual function used to make this class an interface
   virtual void printInfo() = 0;

   // Operators :
   /**
    *    Move operator, used to assing a value from one Item to another. <br> <br>
    *    It does not copy the field <i>itemId</i> as it has to be unique for each Item.
   **/
   [[nodiscard]] Item& operator = (const Item &Item);

   /// This operator prints out all the fields inside the current item and gives explanations accordingly.
   /// <br> It is followed by a new line.
   friend std::ostream& operator >> ( std::ostream &out, const Item &item );
   /// This operator only prints out the name of the current item, followed by a new line.
   friend std::ostream& operator << ( std::ostream &out, const Item &item );

   /// Equality operator. Verifies that all of the fields inside Item, except itemId are equal.
   bool operator == (const Item &item) const;

   /// Inequality operator. Verifies that at least one of the fields inside Item, except itemId are equal, are different.
   /// <br> <br> It returns the negation of the operator <i>==</i>.
   bool operator != (const Item &item) const;
};



#endif //REAL_TIME_RESTAURANT_MENUITEM_H
