/**
 * File: Container.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_CONTAINER_HPP
#define POO2_03_RIVER_CONTAINER_HPP

#include <string>

#include "Person.hpp"

// Abstract class
class Container {

private:
    std::string _name;
    std::list<Person*> _people;

public:

    /**
     * Constructor
     * @param name The Container's name
     */
    Container(const std::string& name);

    /**
     * Pure virtual destructor, to have a real abstract Container class
     * (because we don't have any other pure virtual method)
     */
    virtual ~Container() = 0;

    /**
     * Get display name of container
     * @return The container's name
     */
    std::string getName() const;

    /**
     * Get iterator at the beginning of the people list
     * @return The iterator at the beginning of the people group
     */
    std::list<Person*>::iterator begin();

    /**
     * Get iterator at the end of the people list
     * @return The iterator at the end of the people group
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
     * Get the number of people who are in the Container
     * @return The number of people in the container
     */
    size_t getPeopleCount() const;

    /**
     * Verify if a Person with given name is in the container or not.
     * @param name The name of the Person we want to fetch
     * @return A the Person pointer if it exists, nullptr otherwise
     */
    Person* getPersonByName(const std::string& name);

};


#endif //POO2_03_RIVER_CONTAINER_HPP
