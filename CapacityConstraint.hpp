/**
 * File: CapacityConstraint.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_CAPACITYCONSTRAINT_HPP
#define POO2_03_RIVER_CAPACITYCONSTRAINT_HPP


#include <cstdlib>
#include "Constraint.hpp"

class CapacityConstraint : public Constraint {

private:
    size_t _capacity;
    Container* _target; // Container on which the Constraint is applied (only Boat is our case)

public:
    CapacityConstraint(size_t capacity, const std::string& errorMessage, Container* target);

    /**
     * Verifies if the given Container exceeds the capacity or not.
     * @param c
     * @return true if the capacity is not exceeded.
     */
    bool validateContainer(Container* c) const override;
};


#endif //POO2_03_RIVER_CAPACITYCONSTRAINT_HPP
