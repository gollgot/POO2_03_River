/**
 * File: Person.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_PERSON_HPP
#define POO2_03_RIVER_PERSON_HPP

#include "Container.hpp"
#include <string>
#include "PersonType.hpp"


class Container; // todo : dont know why I have to put that declaration here

class Person {

private:
    std::string _name;
    bool _canDrive;

public:
    Person(const std::string& name, bool canDrive);

    bool canDrive() const;

    virtual PersonType  type() const = 0;

    virtual bool isRuleRespected(const Container& c) const = 0;

};


#endif //POO2_03_RIVER_PERSON_HPP
