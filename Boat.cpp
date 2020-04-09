//
// Created by loic on 4/9/20.
//

#include "Boat.h"

using namespace std;

Boat::Boat(std::string name, const Bank &bank): Container(name), bank(bank) {}


Bank Boat::getBank() const {
    return bank;
}

void Boat::setBank(const Bank &bank) {
    this->bank = bank;
}