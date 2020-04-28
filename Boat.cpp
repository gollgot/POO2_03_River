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

void Boat::setBank(Bank* bank) {
    _bank = bank;
}

bool Boat::containsDriver() const {
    for(Person* p : getPeople()){
        if(p->canDrive()){
            return true;
        }
    }
    return false;
}
