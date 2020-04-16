/**
 * File: Controller.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <iostream>
#include <iomanip>
#include "Controller.hpp"

using namespace std;


Controller::Controller():
        _leftBank(Bank("Gauche")),
        _rightBank(Bank("Droite")),
        _boat(Boat("Bateau", _leftBank)),
        _turn(0)
{}

/* ------------------------ PUBLIC METHODS ------------------------ */

void Controller::showMenu() const {
    cout << DISPLAY_CHAR << setw(MENU_WIDTH) << ": " << "afficher" << endl;
    cout << LOAD_CHAR << setw(MENU_WIDTH) << " <nom>: " << "embarquer <nom>" << endl;
    cout << UNLOAD_CHAR << setw(MENU_WIDTH) << " <nom>: " << "debarquer <nom>" << endl;
    cout << MOVE_CHAR << setw(MENU_WIDTH) << ": " << "deplacer bateau" << endl;
    cout << RESET_CHAR << setw(MENU_WIDTH) << ": " << "reinitialiser" << endl;
    cout << QUIT_CHAR << setw(MENU_WIDTH) << ": " << "quitter" << endl;
    cout << MENU_CHAR << setw(MENU_WIDTH) << ": " << "menu" << endl;
    cout << endl;
}

void Controller::display() const {
    displayLeftBank();
    displayBoat();
    displayRightBank();
}

void Controller::nextTurn() {
    ++_turn;
    display();
}

void Controller::beginGame() {
    while(!_isFinish){
        askAndRunCommand();
    }
}


/* ------------------------ PRIVATE METHODS ------------------------ */

void Controller::displayLeftBank() const {
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
    cout << _leftBank.getName() << ": " << endl;
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
}

void Controller::displayRightBank() const {
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
    cout << _rightBank.getName() << ": " << endl;
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
}

void Controller::displayBoat() const {
    if(_boat.getBank() == _leftBank){
        cout << _boat.getName() << ": " << endl;
        cout << setfill(RIVER_CHAR) << setw(WIDTH) << "" << endl;
        cout << endl;
    }else{
        cout << endl;
        cout << setfill(RIVER_CHAR) << setw(WIDTH) << "" << endl;
        cout << _boat.getName() << ": " << endl;
    }
}

void Controller::moveBoat() {
    if(_boat.getBank() == _leftBank){
        _boat.setBank(_rightBank);
    }else{
        _boat.setBank(_leftBank);
    }
}

void Controller::askAndRunCommand() {
    string command;
    cout << _turn << "> ";
    cin >> command;

    // Single char command with no argument
    if(command.length() == 1){
        char c = command[0];
        // Quit
        if(c == QUIT_CHAR){
            _isFinish = true;
        }
        // Help
        else if(c == MENU_CHAR){
            showMenu();
        }
        // Move boat
        else if(c == MOVE_CHAR){
            moveBoat();
            nextTurn();
        }
    }

}