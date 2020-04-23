/**
 * File: Container.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Container.hpp"

using namespace std;

Container::Container(const string& name): _name(name) {}

string Container::getName() const {
    return _name;
}

/**
 * Need an empty implementation to works with pur virtual destructor
 */
Container::~Container(){}

void Container::addPerson(Person* person) {
    _people.push_back(person);
}

void Container::removePerson(Person* person) {
    _people.remove(person);
}

std::list<Person*>::iterator Container::begin() {
    return _people.begin();
}

std::list<Person*>::iterator Container::end() {
    return _people.end();
}

std::list<Person*> Container::getPeople() const{
    return _people;
}

bool Container::checkIfPersonByName(std::string name) {
    for(Person* p : _people)
        if(p->getName() == name)
            return true;

    return false;
}
