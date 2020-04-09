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

    int turn();
public:
    Controller();

    void showMenu();
    void display();
    void nextTurn();
};


#endif //POO2_03_RIVER_RIVIERE_HHP
