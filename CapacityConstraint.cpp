/**
 * File: CapacityConstraint.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "CapacityConstraint.hpp"

using namespace std;

CapacityConstraint::CapacityConstraint(size_t capacity, const string& errorMessage, Container* target)
: Constraint(errorMessage), _capacity(capacity), _target(target) {}

bool CapacityConstraint::validateContainer(Container* c) {
    return c != _target || c->getPeopleCount() <= _capacity;
}
