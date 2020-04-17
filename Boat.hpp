/**
 * File: Boat.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_BOAT_HPP
#define POO2_03_RIVER_BOAT_HPP


#include <string>
#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container{

private:
    Bank* _bank;

public:
    Boat(const std::string& name, Bank* bank);

    Bank* getBank() const;

    void setBank(Bank* bank);

};


#endif //POO2_03_RIVER_BOAT_HPP
