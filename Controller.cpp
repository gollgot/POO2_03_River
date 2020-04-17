/**
 * File: Controller.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <iostream>
#include <iomanip>
#include "Controller.hpp"
#include "PersonConstraint.hpp"

using namespace std;

Controller::Controller():
        _leftBank(Bank("Gauche")),
        _rightBank(Bank("Droite")),
        _boat(Boat("Bateau", &_leftBank)),
        _turn(0) {

    // Create all people
    Person* pere = new Person("pere", true);
    Person* mere = new Person("mere", true);
    Person* paul = new Person("paul", false);
    Person* pierre = new Person("pierre", false);
    Person* julie = new Person("julie", false);
    Person* jeaaaaaaaanne = new Person("jeanne", false);
    Person* policier = new Person("policier", true);
    Person* voleur = new Person("voleur", false);

    // Temp containers used to group people (simplify constraints creation)
    std::list<Person*> boys;
    std::list<Person*> girls;
    std::list<Person*> family;

    // Separate boys and girls (without parents)
    boys.push_back(paul);
    boys.push_back(pierre);
    girls.push_back(julie);
    girls.push_back(jeaaaaaaaanne);

    // Create constraints for boys and girls
    _constraints.emplace_back(boys, mere, pere); // Boys cannot be with the mother without the father
    _constraints.emplace_back(girls, pere, mere); // Girls cannot be with the father without the mother

    // Bring the family together
    family.splice(family.begin(), boys);
    family.splice(family.begin(), girls);
    family.push_back(pere);
    family.push_back(mere);

    // Create constraints for family
    _constraints.emplace_back(family, voleur, policier); // Thief cannot be with family members without police officer

    // Regroup people in main container
    _people.splice(_people.begin(), family);
    _people.push_back(voleur);
    _people.push_back(policier);

    /* ****************************************** */
    /* ********** CONSTRAINT TEST AREA ********** */

    _leftBank.addPerson(pierre);
    _leftBank.addPerson(voleur);
    //_leftBank.addPerson(policier);

    for(auto& it : _constraints) // Test all constraints
        cout << "Constraint test: " << it.validateContainer(_leftBank.begin(), _leftBank.end()) << endl;
}

Controller::~Controller() {
    for(auto & it : _people)
        delete it;
}

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
    if(_boat.getBank() == &_leftBank){
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
    if(_boat.getBank() == &_leftBank) {
        _boat.setBank(&_rightBank);
    }else{
        _boat.setBank(&_leftBank);
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