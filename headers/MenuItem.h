//
// Created by Test on 03/04/2024.
//

#ifndef REAL_TIME_RESTAURANT_MENUITEM_H
#define REAL_TIME_RESTAURANT_MENUITEM_H

#include <chrono>
#include <iostream>


using namespace std::chrono;
std::ostream &operator<<(std::ostream &out, const std::chrono::minutes &duration);  // nu stiu daca e bine sa il las aici
// din main nu e vizibil, daca il las doar in MenuItem.cpp


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
    MenuItem(const std::string &name, const std::string &category, float price, int pieces, int quantity, std::chrono::minutes preparationTime);

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

static std::string unit = "Unknown";

#endif //REAL_TIME_RESTAURANT_MENUITEM_H
