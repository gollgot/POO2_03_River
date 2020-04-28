/**
 * File: main.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <iostream>

#include "Container.hpp"
#include "Boat.hpp"
#include "Controller.hpp"

using namespace std;

int main() {

    // Create a game controller
    Controller c;

    // Show the menu display the initial game state and launch the game loop
    c.showMenu();
    c.display();
    c.beginGame();

    return 0;
}