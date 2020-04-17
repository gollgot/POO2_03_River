/**
 * File: PersonConstraint.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include <algorithm>
#include "PersonConstraint.hpp"

using namespace std;

PersonConstraint::PersonConstraint(list<Person*>& group, Person* enemy, Person* mediator)
: _group(group), _enemy(enemy), _mediator(mediator) {}

bool PersonConstraint::concerns(const Person& p) {
    return find(_group.begin(), _group.end(), &p) != _group.end();
}

bool PersonConstraint::validateContainer(list<Person*>::iterator begin, list<Person*>::iterator end) {

    // If the enemy is here and mediator is not, nobody of _group should be here
    if(find(begin, end, _enemy) != end && find(begin, end, _mediator) == end) {
        for(list<Person*>::iterator it = _group.begin(); it != _group.end(); it++) {
            if(find(begin, end, *it) != end)
                return false;
        }
    }

    return true;
}
