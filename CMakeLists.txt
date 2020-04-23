cmake_minimum_required(VERSION 3.14)
project(POO2_03_River)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(POO2_03_River
        main.cpp
        Boat.cpp
        Boat.hpp
        Bank.cpp
        Bank.hpp
        Controller.hpp
        Controller.cpp
        Container.cpp
        Container.hpp
        Person.cpp
        Person.hpp
        PersonConstraint.cpp
        PersonConstraint.hpp)