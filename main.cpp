#include "headers/Order.h"
#include "headers/Menu.h"
#include "headers/MenuItem.h"
#include "headers/Table.h"
#include <cstdlib>

using namespace std::chrono;   // For using 'min' literal, which refers to minutes


// unde pun operatorul pentru std::chrono? Acum e in MenuItem.h
// E ok daca am folosit operatorul >> pentru o alta afisare?
// orders[ 1 ] modifica orders[ 2 ] ( linia 37 )
// Probleme github actions
// Trebuie ca operatorul = sa copieze si id-ul sau sa faca unul nou? Exemplu: MenuItem.cpp
// Cum scriu documentatia pentru clase? Toate campurile deasupra clasei sau fiecare camp individual?

int main() {

    std::ifstream f( "menu.txt" );
    Menu menu;
    menu.readMenu( f );
    std::cout << menu;

    std::vector<Order> orders( 5 );

    for( int i = 0; i < 5; i++ )
    {
        for (int j = 0; j < 5; j++)
            orders.at(i).addItem(const_cast<MenuItem &>(menu.getMenuList().at(rand() % menu.getMenuList().size())));
        std::cout << orders.at( i );
        std::cout << "The price is: " << orders.at( i ).calculatePrice() << '\n';
        std::cout << "The preparation time is: " << orders.at( i ).calculatePreparationTime() << '\n';

    }


    orders.at( 1 ).replaceItem( orders.at(1).getItems().at(4), orders.at(0).getItems().at(2) );

    std::cout << orders.at( 1 );

    orders.at( 1 ).replaceItem( orders.at(2).getItems().at(4), orders.at(0).getItems().at(2) ) ;

    orders.at( 2 ).clearOrder();
    std::cout << orders.at( 2 );

    std::shared_ptr<MenuItem> test( orders.at(3).getItems().at(3) );
    orders.at( 3 ).removeItem( test );
    std::cout << orders.at( 3 );

    Table t1;
    Table t2( false, orders.at(3));
    Table t3( t1 );

    std::cout << t1 << t2 << t3;

}