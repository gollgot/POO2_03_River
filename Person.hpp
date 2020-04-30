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

    /**
     * Constructor
     * @param name The Person name
     * @param canDrive Boolean to check if the person can drive the boat or not
     */
    Person(const std::string& name, bool canDrive);

    /**
     * canDrive getter
     * @return True if the person can drive, false otherwise
     */
    bool canDrive() const;

    /**
     * Name getter
     * @return The Person name
     */
    std::string getName() const;

    /**
     * Compares a Person pointer's name with a name.
     * @param s The name of the second Person
     * @return True if the Person has same name has the name in parameter
     */
    bool equals(const std::string& s) const;
};


#endif //POO2_03_RIVER_PERSON_HPP
