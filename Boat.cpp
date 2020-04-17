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

void Boat::setBank(Bank* bank) {
    _bank = bank;
}