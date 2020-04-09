//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_BOAT_H
#define POO2_03_RIVER_BOAT_H


#include <string>
#include "Container.h"
#include "Bank.h"

class Boat : public Container{

private:
    Bank bank;

public:
    Boat(std::string name, const Bank& bank);

    Bank getBank() const;

    void setBank(const Bank& bank);

};


#endif //POO2_03_RIVER_BOAT_H
