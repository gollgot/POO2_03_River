/**
 * File: Boat.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_BOAT_HPP
#define POO2_03_RIVER_BOAT_HPP


#include <string>
#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container{

private:
    Bank* _bank;
    size_t _capacity;

public:

    /**
     * Constructor
     * @param name The Boat name
     * @param bank The current Bank where the boat is
     * @param capacity The Boat max capacity
     */
    Boat(const std::string& name, Bank* bank, size_t capacity);

    /**
     * Bank getter
     * @return The current linked Bank
     */
    Bank* getBank() const;

    /**
     * Capacity getter
     * @return The Boat capacity
     */
    size_t getCapacity() const;

    /**
     * Moves the boat to another Bank if there's a driver.
     * @param bank The new Bank
     * @return true if there was a driver and if the boat moved.
     */
    void setBank(Bank* bank);

    /**
     * Check if there is a driver inside the boat
     * @return True if there is a driver inside the boat, false otherwise
     */
    bool containsDriver() const;

};


#endif //POO2_03_RIVER_BOAT_HPP
