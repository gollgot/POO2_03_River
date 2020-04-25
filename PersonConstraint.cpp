/**
 * File: PersonConstraint.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <algorithm>

#include "PersonConstraint.hpp"

using namespace std;

PersonConstraint::PersonConstraint(list<Person*>& group, Person* enemy, Person* mediator, const string& errorMessage)
: _group(group), _enemy(enemy), _mediator(mediator), _errorMessage(errorMessage) {}

bool PersonConstraint::validateContainer(list<Person*>::iterator begin, list<Person*>::iterator end) {
    if(find(begin, end, _enemy) != end && find(begin, end, _mediator) == end) {
        // If the enemy is here and mediator is not, nobody of _group should be present
        for(auto& it : _group) { // Check given container
            if(find(begin, end, it) != end)
                return false;
        }
    }

    return true;
}

std::string PersonConstraint::errorMessage() {
    return _errorMessage;
}
