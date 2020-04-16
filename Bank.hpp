//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_BANK_HPP
#define POO2_03_RIVER_BANK_HPP


#include <string>
#include "Container.hpp"

class Bank : public Container{

public:
    Bank(std::string name);

    bool operator==(const Bank& rhs);

private:

};


#endif //POO2_03_RIVER_BANK_HPP
