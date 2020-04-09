/**
 * File: Controller.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_RIVIERE_HHP
#define POO2_03_RIVER_RIVIERE_HHP


#include <vector>
#include "Person.hpp"


class Controller {
private:
    std::vector<Person> persons;
    Bank leftBank;
    Bank rightBank;
    Boat boat;

    const int WIDTH = 58;
    const int MENU_WIDTH = 8;
    const char DISPLAY_CHAR = 'p';
    const char LOAD_CHAR = 'e';
    const char UNLOAD_CHAR = 'd';
    const char MOVE_CHAR = 'm';
    const char RESET_CHAR = 'r';
    const char QUIT_CHAR = 'q';
    const char MENU_CHAR = 'h';

    int turn();
public:
    Controller();

    void showMenu() const;
    void display() const;
    void nextTurn();
};


#endif //POO2_03_RIVER_RIVIERE_HHP
