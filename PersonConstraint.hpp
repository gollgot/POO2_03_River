/**
 * File: PersonConstraint.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_PERSONCONSTRAINT_HPP
#define POO2_03_RIVER_PERSONCONSTRAINT_HPP


#include <list>

#include "Person.hpp"
#include "Constraint.hpp"

/**
 * Defines people constraints.
 * People in _group cannot be with _enemy unless _mediator is present too.
 */
class PersonConstraint : public Constraint {
    std::list<Person*> _group;
    Person* _enemy;
    Person* _mediator;
    std::string _errorMessage;

public:
    PersonConstraint(std::list<Person*>& group, Person* enemy, Person* mediator, const std::string& errorMessage);
    ~PersonConstraint() override {}

    /**
     * Validates if the constraint is respected depending on the given container.
     * @param begin Iterator to the beginning of the container to validate
     * @param end  Iterator to the end of the container to validate
     * @return true if the constraint is respected
     */
    bool validateContainer(std::list<Person*>::iterator begin, std::list<Person*>::iterator end) override;

};


#endif //POO2_03_RIVER_PERSONCONSTRAINT_HPP
