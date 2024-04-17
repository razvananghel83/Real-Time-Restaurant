cmake_minimum_required(VERSION 3.27)
project(Real_Time_Restaurant_v1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Real_Time_Restaurant_v1 main.cpp
        headers/Menu.h
        sources/Menu.cpp
        sources/MenuItem.cpp
        sources/Order.cpp
        sources/Table.cpp
        headers/MyExceptions.h
        headers/Desert.h
        headers/MainCourse.h
        headers/FirstCourse.h
        sources/FirstCourse.cpp
        sources/MainCourse.cpp
        headers/Drinks.h
        sources/Drinks.cpp
        sources/Desert.cpp)
