/**
 * File: Constraint.cpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#include "Constraint.hpp"


Constraint::Constraint(const std::string &errorMessage) : _errorMessage(errorMessage) {}

/**
 * Need an empty implementation to works with pur virtual destructor
 */
 Constraint::~Constraint(){}

std::string Constraint::getErrorMessage() const {
    return _errorMessage;
}

