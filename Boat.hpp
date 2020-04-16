//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_BOAT_HPP
#define POO2_03_RIVER_BOAT_HPP


#include <string>
#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container{

private:
    Bank _bank;

public:
    Boat(std::string name, const Bank& bank);

    Bank getBank() const;

    void setBank(const Bank& bank);

};


#endif //POO2_03_RIVER_BOAT_HPP
