/**
 * File: Controller.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "Controller.hpp"
#include "PersonConstraint.hpp"
#include "CapacityConstraint.hpp"

using namespace std;

Controller::Controller():
        _leftBank(Bank("Gauche")),
        _rightBank(Bank("Droite")),
        _boat(Boat("Bateau", &_leftBank, 2)),
        _turn(0)
{
    createConstraints();

    // Add all people to initial bank (left)
    for(auto& it : _people){
        _leftBank.addPerson(it);
    }
}

Controller::~Controller() {
    // Delete people
    for(auto& it : _people)
        delete it;

    // Delete constraints
    for(auto& it : _constraints)
        delete it; // TODO warning à la compilation car pas de destructeur...
}

/* ------------------------ PUBLIC METHODS ------------------------ */

void Controller::showMenu() const {
    cout << setfill(' ') << DISPLAY_CHAR << setw(MENU_WIDTH) << ": " << "afficher" << endl;
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
    // Create all people
    Person* _pere = new Person("pere", true);
    Person* _mere = new Person("mere", true);
    Person* _paul = new Person("paul", false);
    Person* _pierre = new Person("pierre", false);
    Person* _julie = new Person("julie", false);
    Person* _jeanne = new Person("jeanne", false);
    Person* _policier = new Person("policier", true);
    Person* _voleur = new Person("voleur", false);

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
    // Boys cannot be with the mother without the father
    _constraints.push_back(new PersonConstraint(boys, _mere, _pere, "garcon avec sa mere sans son pere"));
    // Girls cannot be with the father without the mother
    _constraints.push_back(new PersonConstraint(girls, _pere, _mere, "fille avec son pere sans sa mere"));

    // Bring the family together
    family.push_back(_pere);
    family.push_back(_mere);
    family.splice(family.end(), boys);
    family.splice(family.end(), girls);

    // Create constraints for family
    // Thief cannot be with family members without police officer
    _constraints.push_back(new PersonConstraint(family, _voleur, _policier, "voleur avec famille sans le policier"));

    // Regroup people in main container
    _people.splice(_people.end(), family);
    _people.push_back(_voleur);
    _people.push_back(_policier);

    // Boat capacity
    _constraints.push_back(new CapacityConstraint(_boat.getCapacity(), "plus de place sur le bateau", &_boat));
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
        cout << _boat.getName() << ": <";
        for(Person* p : _boat.getPeople()){
            cout << " " << p->getName();
        }
        cout << " >" << endl;
    }
}

void Controller::moveBoat() {
    if(_boat.containDriver()){
        if(_boat.getBank() == &_leftBank) {
            _boat.setBank(&_rightBank);
        } else {
            _boat.setBank(&_leftBank);
        }
    }else{
        displayError(ERROR_NOT_DRIVER);
    }
}

void Controller::askAndRunCommand() {
    const size_t BUFFER_SIZE = 256; // Max input buffer for command + argument
    char buffer[BUFFER_SIZE + 1];
    cout << _turn << "> ";
    cin.getline(buffer, BUFFER_SIZE);

    string userInput = buffer;
    // Command with no argument (command with one char)
    if(userInput.length() == 1) {
        char c = userInput[0];
        // Quit
        if(c == QUIT_CHAR){
            _isFinish = true;
        }
        // Help
        else if(c == MENU_CHAR){
            showMenu();
        }
        // Display
        else if(c == DISPLAY_CHAR) {
            display();
        }
        // Display
        else if(c == RESET_CHAR) {
            resetGame();
            display();
        }
        // Move boat
        else if(c == MOVE_CHAR){
            moveBoat();
            nextTurn();
        }
        // Invalid command
        else{
            displayError(ERROR_CMD_INVALID);
        }
    }
    // Commands with one argument
    else {
        // Fetch the command and arg
        string command = userInput.substr(0, userInput.find(' '));
        string arg = userInput.substr(userInput.find(' ') + 1);

        // Command must be 1 char
        if(command.length() == 1){
            char c = command[0];

            // Load person
            if(c == LOAD_CHAR){
                // Verify move validity
                movePersonSafely(_boat.getBank()->getPersonByName(arg), _boat.getBank(), &_boat);
            }
            // Unload person
            else if(c == UNLOAD_CHAR) {
                // Verify move validity
                movePersonSafely(_boat.getPersonByName(arg), &_boat, _boat.getBank());
            }
            // Invalid command
            else {
                displayError(ERROR_CMD_INVALID);
                return;
            }

            nextTurn();
        }
        // Invalid command
        else {
            displayError(ERROR_CMD_INVALID);
        }
    }

}

void Controller::displayError(const string& message) const {
    cout << ERROR_PREFIX << message << endl;
}

Constraint* Controller::validateAllContainers() {
    for(Constraint* c : _constraints)
        if(!c->validateContainer(&_leftBank)
        || !c->validateContainer(&_rightBank)
        || !c->validateContainer(&_boat))
            return c;

    return nullptr;
}

void Controller::movePerson(Person* p, Container* from, Container* to) const {
    from->removePerson(p);
    to->addPerson(p);
}

void Controller::movePersonSafely(Person* p, Container* from, Container* to) {
    if(p != nullptr){
        // Try move
        movePerson(p, from, to);

        // Verify
        Constraint* c = validateAllContainers();
        if(c != nullptr) {
            // Rollback and display error
            movePerson(p, to, from);
            displayError(c->getErrorMessage());
        }
    }else{
        displayError(ERROR_ARG_MESSAGE);
    }
}

void Controller::reset(Container* c) {
    for(Person* p : c->getPeople()) {
        movePerson(p, c, &_leftBank);
    }
}

void Controller::resetGame() {
    reset(&_rightBank);
    reset(&_boat);
    _boat.setBank(&_leftBank);
}
