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
#include "PersonConstraint.hpp"


class Controller {

private:
    std::list<Person*> _people;
    std::list<PersonConstraint> _constraints;
    Bank _leftBank;
    Bank _rightBank;
    Boat _boat;
    int _turn;
    bool _isFinish = false;

    // Create all people
    Person* _pere;
    Person* _mere;
    Person* _paul;
    Person* _pierre;
    Person* _julie;
    Person* _jeanne;
    Person* _policier;
    Person* _voleur;

    const int WIDTH = 58;
    const int MENU_WIDTH = 8;
    const char DISPLAY_CHAR = 'p';
    const char LOAD_CHAR = 'e';
    const char UNLOAD_CHAR = 'd';
    const char MOVE_CHAR = 'm';
    const char RESET_CHAR = 'r';
    const char QUIT_CHAR = 'q';
    const char MENU_CHAR = 'h';
    const char RIVER_CHAR = '=';
    const char BANK_CHAR = '-';

public:
    Controller();
    ~Controller();

    void showMenu() const;
    void display() const;
    void nextTurn();
    void beginGame();

private:
    void createConstraints();
    void displayLeftBank() const;
    void displayRightBank() const;
    void displayBoat() const;
    void moveBoat();
    void askAndRunCommand();
};


#endif //POO2_03_RIVER_RIVIERE_HHP
