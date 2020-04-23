/**
 * File: Controller.hpp
 * Authors: Robin Demarta & Loïc Dessaules
 * Date: 09.04.2020
 */

#ifndef POO2_03_RIVER_RIVIERE_HHP
#define POO2_03_RIVER_RIVIERE_HHP


#include "Person.hpp"
#include "Bank.hpp"
#include "Boat.hpp"
#include "PersonConstraint.hpp"


class Controller {

private:
    std::list<Person*> _people; // TODO ? store as Person
    std::list<Constraint*> _constraints; // TODO ? store as ptr
    Bank _leftBank;
    Bank _rightBank;
    Boat _boat;
    int _turn;
    bool _isFinish = false;

    // Create all people
    // TODO ? not useful to store those ptr as attribute ; only used in constructor
    Person* _pere;
    Person* _mere;
    Person* _paul;
    Person* _pierre;
    Person* _julie;
    Person* _jeanne;
    Person* _policier;
    Person* _voleur;

    const int WIDTH = 58;
    const int MENU_WIDTH = 8;
    static constexpr char DISPLAY_CHAR = 'p';
    static constexpr char LOAD_CHAR = 'e';
    static constexpr char UNLOAD_CHAR = 'd';
    static constexpr char MOVE_CHAR = 'm';
    static constexpr char RESET_CHAR = 'r';
    static constexpr char QUIT_CHAR = 'q';
    static constexpr char MENU_CHAR = 'h';
    const char RIVER_CHAR = '=';
    const char BANK_CHAR = '-';

public:
    Controller();
    ~Controller();

    void showMenu() const;
    void display() const;
    void nextTurn();
    void beginGame();

private:
    void createConstraints();
    void displayLeftBank() const;
    void displayRightBank() const;
    void displayBoat() const;
    void moveBoat();
    void askAndRunCommand();

    /**
     * Verifies all Constraints on all Containers.
     * @return true if all Constraints are respected everywhere.
     */
    bool validateAllContainers();

    /**
     * Moves a Person from a container to another.
     * @param personName
     * @param from
     * @param to
     * @return true if the action performed successfully.
     */
    bool movePersonSafely(const std::string& personName, Container* from, Container* to);
};


#endif //POO2_03_RIVER_RIVIERE_HHP
