/**
 * File: Controller.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_RIVIERE_HHP
#define POO2_03_RIVER_RIVIERE_HHP


#include <vector>
#include "Person.hpp"
#include "Bank.hpp"
#include "Boat.hpp"


class Controller {

private:
    std::vector<Person> _people;
    Bank _leftBank;
    Bank _rightBank;
    Boat _boat;
    int _turn;

    const int WIDTH = 58;
    const int MENU_WIDTH = 8;
    const char DISPLAY_CHAR = 'p';
    const char LOAD_CHAR = 'e';
    const char UNLOAD_CHAR = 'd';
    const char MOVE_CHAR = 'm';
    const char RESET_CHAR = 'r';
    const char QUIT_CHAR = 'q';
    const char MENU_CHAR = 'h';

public:
    Controller();

    void showMenu() const;
    void display() const;
    void nextTurn();

private:
    void displayLeftBank() const;
    void displayRightBank() const;
    void displayBoat() const;

};


#endif //POO2_03_RIVER_RIVIERE_HHP
