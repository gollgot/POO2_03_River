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

// Abstract class
class Constraint {

private:
    std::string _errorMessage;

public:

    /**
     * Constructor
     * @param errorMessage The error message
     */
    Constraint(const std::string& errorMessage);

    /**
     * Default destructor
     */
    virtual ~Constraint() = default;

    /**
     * Validates the implemented constraint on a specific Container
     * @param c The Container for which we'll apply the constraint
     * @return True if the container pass the constraint, false otherwise
     */
    virtual bool validateContainer(Container* c) const = 0;

    /**
     * Return the error message (e.g. "This person is with his enemy.")
     * @return The error message
     */
     std::string getErrorMessage() const;

};


#endif //POO2_03_RIVER_CONSTRAINT_HPP
