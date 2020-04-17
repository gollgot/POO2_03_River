/**
 * File: PersonConstraint.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_PERSONCONSTRAINT_HPP
#define POO2_03_RIVER_PERSONCONSTRAINT_HPP


#include <list>
#include <vector>
#include "Person.hpp"

/**
 * Defines which Person a group of people should never be with (except if the mediator is present).
 */
class PersonConstraint {
    std::list<Person*> _group;
    Person* _enemy;
    Person* _mediator;

public:
    PersonConstraint(std::list<Person*>& group, Person* enemy, Person* mediator);

    bool validateContainer(std::list<Person*>::iterator begin, std::list<Person*>::iterator end);

    /**
     * Checks if a Person is concerned by this rule or not.
     * @param p
     * @return
     */
    bool concerns(const Person& p);
};


#endif //POO2_03_RIVER_PERSONCONSTRAINT_HPP
