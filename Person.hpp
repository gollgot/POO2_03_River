/**
 * File: Person.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_PERSON_HPP
#define POO2_03_RIVER_PERSON_HPP


#include <string>
#include <list>

class Person {

private:
    std::string _name;
    bool _canDrive;

public:
    Person(const std::string& name, bool canDrive);
    bool canDrive();
    std::string getName() const;
};


#endif //POO2_03_RIVER_PERSON_HPP
