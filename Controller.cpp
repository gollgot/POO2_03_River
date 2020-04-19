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
        _turn(0)
{
    _pere = new Person("pere", true);
    _mere = new Person("mere", true);
    _paul = new Person("paul", false);
    _pierre = new Person("pierre", false);
    _julie = new Person("julie", false);
    _jeanne = new Person("jeanne", false);
    _policier = new Person("policier", true);
    _voleur = new Person("voleur", false);

    createConstraints();

    // Add all personne
    for(auto& it : _people){
        _leftBank.addPerson(it);
    }

}

Controller::~Controller() {
    for(auto& it : _people)
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

void Controller::createConstraints() {
    // Temp containers used to group people (simplify constraints creation)
    std::list<Person*> boys;
    std::list<Person*> girls;
    std::list<Person*> family;

    // Separate boys and girls (without parents)
    boys.push_back(_paul);
    boys.push_back(_pierre);
    girls.push_back(_julie);
    girls.push_back(_jeanne);

    // Create constraints for boys and girls
    _constraints.emplace_back(boys, _mere, _pere); // Boys cannot be with the mother without the father
    _constraints.emplace_back(girls, _pere, _mere); // Girls cannot be with the father without the mother

    // Bring the family together
    family.splice(family.begin(), boys);
    family.splice(family.begin(), girls);
    family.push_back(_pere);
    family.push_back(_mere);

    // Create constraints for family
    _constraints.emplace_back(family, _voleur, _policier); // Thief cannot be with family members without police officer

    // Regroup people in main container
    _people.splice(_people.begin(), family);
    _people.push_back(_voleur);
    _people.push_back(_policier);

    /* ****************************************** */
    /* ********** CONSTRAINT TEST AREA ********** */

    //_leftBank.addPerson(pierre);
    //_leftBank.addPerson(voleur);
    //_leftBank.addPerson(policier);

    /*
    for(auto& it : _constraints) // Test all constraints
        cout << "Constraint test: " << it.validateContainer(_leftBank.begin(), _leftBank.end()) << endl;
    */
 }

void Controller::displayLeftBank() const {
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
    cout << _leftBank.getName() << ":";
    for(Person* p : _leftBank.getPeople()){
        cout << " " << p->getName();
    }
    cout << endl;
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
}

void Controller::displayRightBank() const {
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
    cout << _rightBank.getName() << ":";
    for(Person* p : _rightBank.getPeople()){
        cout << " " << p->getName();
    }
    cout << endl;
    cout << setfill(BANK_CHAR) << setw(WIDTH) << "" << endl;
}

void Controller::displayBoat() const {
    if(_boat.getBank() == &_leftBank){
        cout << _boat.getName() << ": <";
        for(Person* p : _boat.getPeople()){
            cout << " " << p->getName();
        }
        cout << " >" << endl;
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