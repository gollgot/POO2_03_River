/**
 * File: Constraint.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_CONSTRAINT_HPP
#define POO2_03_RIVER_CONSTRAINT_HPP


#include <list>

#include "Container.hpp"
#include "Person.hpp"

class Constraint {

private:
    std::string _errorMessage;

public:

    Constraint(const std::string& errorMessage);

    /**
     * Validates the implemented constraint on a list of people.
     * @param begin
     * @param end
     * @return
     */
    virtual bool validateContainer(Container* c) const = 0;

    /**
     * Return the error message (e.g. "This person is with his enemy.")
     * @return The error message
     */
     std::string getErrorMessage() const;

};


#endif //POO2_03_RIVER_CONSTRAINT_HPP
