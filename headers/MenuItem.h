//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENUITEM_H
#define REAL_TIME_RESTAURANT_MENUITEM_H

#include <chrono>
#include <iostream>


using namespace std::chrono;

class MenuItem {

private:
    std::string name;
    std::string category;
    float price{0.0f};
    int itemId{0};
    int pieces{0};
    std::chrono::minutes preparationTime{0min};


public:

    // Constructors :

    // Default constructor :
    MenuItem() = default;

    // Constructor with parametres :
    MenuItem(const std::string &name, const std::string &category, float price, int itemId, int pieces,
             std::chrono::minutes preparationTime)
            : name(name), category(category), price(price), itemId(itemId), pieces(pieces),
              preparationTime(preparationTime) {

    }

    // Copy constructor :
    MenuItem(MenuItem const &Item) = default;

    // Destructor :
    ~MenuItem() = default;


    // Getters and setters :

    // Name field
    const std::string &getName() const;

    void setName(const std::string &newName);


    // Categoty field
    const std::string &getCategoty() const;

    void setCategory(const std::string &newCategory);


    // Price field
    float getPrice() const;

    void setPrice(const float &newPrice);


    // Id field
    int getId() const;

    void setId(const int &newId);


    // Pieces field:
    int getPieces() const;

    void setPieces(const int &newNumberOfPieces);

    // preparationTime field
    std::chrono::minutes getPreparationTime() const;

    void setPreparationTime(const std::chrono::minutes &duration);


    // Operators :
    MenuItem& operator = (const MenuItem &item) = default;

//    friend std::ostream& operator <*< ( std::ostream &out, const MenuItem &item );
    friend std::ostream& operator << ( std::ostream &out, const MenuItem &item );

    bool operator == (const MenuItem &item) const;

    bool operator != (const MenuItem &item) const;
};

#endif //REAL_TIME_RESTAURANT_MENUITEM_H
