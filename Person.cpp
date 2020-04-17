/**
 * File: Person.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Person.hpp"

Person::Person(const std::string& name) : _name(name) {}

bool Person::canDrive() {
    return _canDrive;
}
