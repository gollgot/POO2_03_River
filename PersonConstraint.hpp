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

private:
    std::list<Person*> _group;
    Person* _enemy;
    Person* _mediator;

public:

    /**
     * Constructor
     * @param group The List of Person
     * @param enemy The enemy Person
     * @param mediator The mediator Person
     * @param errorMessage the error message
     */
    PersonConstraint(std::list<Person*>& group, Person* enemy, Person* mediator, const std::string& errorMessage);

    /**
     * Validates if the constraint is respected depending on the given container.
     * @param c The Container for which we'll validate the Constraint
     * @return true if the constraint is respected
     */
    bool validateContainer(Container* c) const override;

};


#endif //POO2_03_RIVER_PERSONCONSTRAINT_HPP
