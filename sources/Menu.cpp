//
// Created by Test on 03/04/2024.
//

#include "../headers/Menu.h"
#include "../headers/MyExceptions.h"


Menu::Menu() {

    this->MenuList.reserve(50);
}


// Getter for the list of items :
const std::vector<MenuItem> &Menu::getMenuList() const {
    return MenuList;
}


// Class methods :

void Menu::readMenu(std::basic_ifstream<char> &file) {

    try {
        if( !file.is_open() )
            throw FileNotOpened();
    }
    catch ( FileNotOpened& e ) {
        std::cout << e.what();
    }

    std::string line;

    while (std::getline(file, line)) {

        // reads an actual MenuItem as a string

        std::vector<std::string> sections;
        std::istringstream stringStream(line);
        std::string section;

        while (std::getline(stringStream, section, ';')) {

            int index = 0;
            if( section[index] == ' ' )
                while ( index < section.length() ) {
                    section[ index ] = section[ index + 1 ];
                    index++;
                }

            sections.push_back(section);
        }

        int number = 0;

        for (int index = 0; isdigit(sections[5][index]); index++) {

            int digit = sections[5][index] - 48;
            number = number * 10 + digit;
        }

        std::chrono::minutes duration(number);

        this->MenuList.emplace_back(sections[0], sections[1], std::stof(sections[2]),
                                    std::stoi( sections[ 3 ] ), std::stoi(sections[4]),
                                    duration);
        std::getline(file, line);  // reads an empty new line
    }

}



// Operators :


std::ostream &operator<<(std::ostream &out, const Menu &menu) {

    out << "The list of items available to order is: \n";
    auto it = menu.getMenuList().begin();


    while (it != std::prev(menu.getMenuList().end())) {
        out >> (*it);
        ++it;
    }
    out >> (*it) << "\n\n";

    return out;
}

