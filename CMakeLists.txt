cmake_minimum_required(VERSION 3.27)
project(Real_Time_Restaurant_v1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Real_Time_Restaurant_v1 main.cpp
        headers/Menu.h
        sources/Menu.cpp
        sources/MenuItem.cpp
        sources/Order.cpp
        sources/Table.cpp
        headers/Exceptions/InvalidTime.h
        headers/Desert.h
        headers/MainCourse.h
        headers/FirstCourse.h
        sources/FirstCourse.cpp
        sources/MainCourse.cpp
        headers/Drinks.h
        sources/Drinks.cpp
        sources/Desert.cpp
        headers/OrderItem.h
        sources/OrderItem.cpp
        headers/Exceptions/InvalidPrice.h
        sources/Exceptions/InvalidPrice.cpp
        sources/Exceptions/InvalidTime.cpp
        headers/Exceptions/InvalidId.h
        sources/Exceptions/InvalidId.cpp
        headers/Exceptions/FileNotOpened.h
        sources/Exceptions/FileNotOpened.cpp
        headers/Exceptions/InvalidQuantity.h
        sources/Exceptions/InvalidQuantity.cpp
        headers/ItemFactory.h
        headers/Item.h
        sources/Item.cpp
        sources/ItemFactory.cpp
        headers/MenuItem.h
        sources/MenuItem.cpp)

target_link_libraries(Real_Time_Restaurant_v1 PRIVATE ws2_32)
