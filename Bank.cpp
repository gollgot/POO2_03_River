//
// Created by loic on 4/9/20.
//

#include "Bank.hpp"

using namespace std;

Bank::Bank(string name) : Container(name){}

bool Bank::operator==(const Bank &rhs) {
    return this->getName() == rhs.getName();
}
