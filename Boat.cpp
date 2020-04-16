//
// Created by loic on 4/9/20.
//

#include "Boat.hpp"

using namespace std;

Boat::Boat(std::string name, const Bank &bank): Container(name), _bank(bank) {}


Bank Boat::getBank() const {
    return _bank;
}

void Boat::setBank(const Bank &bank) {
    _bank = bank;
}