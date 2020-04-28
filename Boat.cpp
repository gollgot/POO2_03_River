/**
 * File: Boat.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Boat.hpp"

using namespace std;

Boat::Boat(const std::string& name, Bank* bank, size_t capacity) : Container(name), _bank(bank), _capacity(capacity) {}


Bank* Boat::getBank() const {
    return _bank;
}

size_t Boat::getCapacity() const {
    return _capacity;
}

bool Boat::setBank(Bank* bank) {
    bool hasDriver = false;

    // There must be a driver
    for(Person* p : getPeople()) {
        if(p->canDrive()) {
            hasDriver = true;
            break;
        }
    }

    if(!hasDriver)
        return false;

    _bank = bank;
    return true;
}