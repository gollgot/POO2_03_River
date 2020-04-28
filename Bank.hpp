/**
 * File: Bank.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_BANK_HPP
#define POO2_03_RIVER_BANK_HPP

#include <string>
#include "Container.hpp"

class Bank : public Container{

public:
    /**
     * Constructor
     * @param name The name of the Bank
     */
    Bank(const std::string& name);

};


#endif //POO2_03_RIVER_BANK_HPP
