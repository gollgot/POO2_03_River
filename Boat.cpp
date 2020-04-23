/**
 * File: Boat.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Boat.hpp"

using namespace std;

Boat::Boat(const std::string& name, Bank* bank) : Container(name), _bank(bank) {}


Bank* Boat::getBank() const {
    return _bank;
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