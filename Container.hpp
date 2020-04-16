//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_CONTAINER_HPP
#define POO2_03_RIVER_CONTAINER_HPP

#include <string>
#include <vector>

#include "Person.hpp"


class Container {

private:
    std::string _name;
    std::vector<Person*> _people;

public:

    Container(const std::string& name);

    std::string getName() const;

    /**
     * Pur virtual destructor, to have a real abstract Container class
     */
    virtual ~Container() = 0;

};


#endif //POO2_03_RIVER_CONTAINER_HPP
