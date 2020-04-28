/**
 * File: Bank.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Bank.hpp"

using namespace std;

Bank::Bank(const string& name) : Container(name){}

bool Bank::operator==(const Bank &rhs) {
    return this->getName() == rhs.getName();
}
