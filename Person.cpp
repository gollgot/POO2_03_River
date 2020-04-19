/**
 * File: Person.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Person.hpp"

Person::Person(const std::string &name, bool canDrive) :
    _name(name),
    _canDrive(canDrive)
{}

bool Person::canDrive() const {
    return _canDrive;
}