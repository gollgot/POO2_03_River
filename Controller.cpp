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
        delete it;
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
    _constraints.push_back(new PersonConstraint(boys, _mere, _pere));
    // Girls cannot be with the father without the mother
    _constraints.push_back(new PersonConstraint(girls, _pere, _mere));

    // Bring the family together
    family.splice(family.begin(), boys);
    family.splice(family.begin(), girls);
    family.push_back(_pere);
    family.push_back(_mere);

    // Create constraints for family
    // Thief cannot be with family members without police officer
    _constraints.push_back(new PersonConstraint(family, _voleur, _policier));

    // Regroup people in main container
    _people.splice(_people.begin(), family);
    _people.push_back(_voleur);
    _people.push_back(_policier);
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

bool Controller::moveBoat() {
    if(_boat.getBank() == &_leftBank) {
        return _boat.setBank(&_rightBank);
    } else {
        return _boat.setBank(&_leftBank);
    }
}

void Controller::askAndRunCommand() {
    const string ERROR_ARG_MESSAGE = "Argument invalide";
    const string ERROR_CMD_INVALID = "Commande invalide";

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
        // Move boat
        else if(c == MOVE_CHAR){
            if(moveBoat())
                nextTurn();
            else {
                cout << "### " << ERROR_ARG_MESSAGE << endl;
            }
        } else{
            cout << "### " << ERROR_CMD_INVALID << endl;
        }
    }
    // Commands with one argument
    else {
        // Fetch the command and arg
        string command = userInput.substr(0, userInput.find(' '));
        string arg = userInput.substr(userInput.find(' ') + 1);

        // Command must be 1 char
        if(command.length() == 1){ // TODO clean/refactor code bellow
            char c = command[0];
            // Load person
            if(c == LOAD_CHAR){
                Person* personFromBank = _boat.getBank()->getPersonByName(arg);
                if(personFromBank != nullptr) {
                    // Verify move validity
                    if(movePersonSafely(personFromBank, _boat.getBank(), &_boat)) {
                        nextTurn();
                    }
                    else {
                        cout << "### " << ERROR_ARG_MESSAGE << endl;
                    }
                }else {
                    cout << "### " << ERROR_ARG_MESSAGE << endl;
                }
            }
            // Unload person
            else if(c == UNLOAD_CHAR) {
                Person* personFromBoat = _boat.getPersonByName(arg);

                if(personFromBoat != nullptr) {
                    // Verify move validity
                    if(movePersonSafely(personFromBoat, &_boat, _boat.getBank())) {
                        nextTurn();
                    }
                    else {
                        cout << "### " << ERROR_ARG_MESSAGE << endl;
                    }
                }

            } else {
                cout << "### " << ERROR_CMD_INVALID << endl;
            }
        } else {
            cout << "### " << ERROR_CMD_INVALID << endl;
        }

    }

}

bool Controller::validateAllContainers() {
    for(Constraint* c : _constraints)
        if(!c->validateContainer(_leftBank.begin(), _leftBank.end())
        || !c->validateContainer(_rightBank.begin(), _rightBank.end())
        || !c->validateContainer(_boat.begin(), _boat.end()))
            return false;

    return true;
}

void Controller::movePerson(Person* p, Container* from, Container* to) {
    from->removePerson(p);
    to->addPerson(p);
}

bool Controller::movePersonSafely(Person* p, Container* from, Container* to) {
    // Try move
    movePerson(p, from, to);

    // Verify
    if(!validateAllContainers()) {
        // Rollback juli
        movePerson(p, to, from);
        return false;
    }

    return true;
}
