/**
 * File: Container.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

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

    /**
     * Get display name of container
     * @return
     */
    std::string getName() const;

    /**
     * Get iterator at the beginning of group list
     * @return
     */
    std::list<Person*>::iterator begin();

    /**
     * Get iterator at the end of group list
     * @return
     */
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
     * Get all people
     * @return A list of pointer on Person contains in the container
     */
    std::list<Person*> getPeople() const;

    /**
     * Pure virtual destructor, to have a real abstract Container class
     */
    virtual ~Container() = 0;

};


#endif //POO2_03_RIVER_CONTAINER_HPP
