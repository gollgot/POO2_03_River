/**
 * File: Person.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Person.hpp"
#include <string>

using namespace std;

Person::Person(const std::string& name, bool canDrive) : _name(name), _canDrive(canDrive) {}

bool Person::canDrive() {
    return _canDrive;
}

string Person::getName() const {
    return _name;
}