/**
 * File: Constraint.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_CONSTRAINT_HPP
#define POO2_03_RIVER_CONSTRAINT_HPP


#include <list>

#include "Person.hpp"

class Constraint {
public:

    /**
     * Validates the implemented constraint on a list of people.
     * @param begin
     * @param end
     * @return
     */
    virtual bool validateContainer(std::list<Person*>::iterator begin, std::list<Person*>::iterator end) = 0;

    /**
     * Pure virtual destructor, to have a real abstract Container class
     */
    virtual ~Constraint() = 0;
};


#endif //POO2_03_RIVER_CONSTRAINT_HPP
