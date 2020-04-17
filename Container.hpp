//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_CONTAINER_HPP
#define POO2_03_RIVER_CONTAINER_HPP

#include <string>

#include "Person.hpp"


class Container {

private:
    std::string _name;
    std::list<Person*> _people;

public:

    Container(const std::string& name);

    std::string getName() const;

    std::list<Person*>::iterator begin();
    std::list<Person*>::iterator end();

    /**
     * Add new Person to container
     * @param person
     */
    void addPerson(Person* person);

    /**
     * Removes the specified Person from the container
     * @param person
     */
    void removePerson(Person* person);

    /**
     * Pure virtual destructor, to have a real abstract Container class
     */
    virtual ~Container() = 0;

};


#endif //POO2_03_RIVER_CONTAINER_HPP
