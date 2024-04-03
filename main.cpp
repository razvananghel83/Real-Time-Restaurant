#include "headers/Order.h"
#include "headers/Menu.h"
#include "headers/MenuItem.h"
#include "headers/Table.h"

using namespace std::chrono;       // For using 'min' literal, which referrs to minutes


int main() {

    MenuItem I1( "Lasagna", "Paste la cuptor", 12, 10, 1, 25min );
    std::cout << I1;
    
}