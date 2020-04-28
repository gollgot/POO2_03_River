/**
 * File: Constraint.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Constraint.hpp"

Constraint::Constraint(const std::string& errorMessage) : _errorMessage(errorMessage) {}

std::string Constraint::getErrorMessage() const {
    return _errorMessage;
}