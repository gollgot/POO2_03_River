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
    std::list<Constraint*> _constraints;
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
    static constexpr char DISPLAY_CHAR = 'p'; // TODO implement
    static constexpr char LOAD_CHAR = 'e';
    static constexpr char UNLOAD_CHAR = 'd';
    static constexpr char MOVE_CHAR = 'm';
    static constexpr char RESET_CHAR = 'r'; // TODO implement
    static constexpr char QUIT_CHAR = 'q';
    static constexpr char MENU_CHAR = 'h'; // TODO nasty space at the beginning of display
    const char RIVER_CHAR = '=';
    const char BANK_CHAR = '-';
    const std::string ERROR_PREFIX = "### ";
    const std::string ERROR_ARG_MESSAGE = "Argument invalide";
    const std::string ERROR_CMD_INVALID = "Commande invalide";

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
    bool moveBoat();
    void askAndRunCommand();
    void displayError(const std::string& message) const;

    /**
     * Verifies all Constraints on all Containers.
     * @return a pointer to the Constraint that is not respect or nullptr if they're all ok.
     */
    Constraint* validateAllContainers();

    /**
     * Transfer Person from his current Container to another.
     * @param p
     * @param to
     */
    static void movePerson(Person* p, Container* from, Container* to);

    /**
     * Moves a Person p from a container to another and displays an error if a constraint is not respected
     * @param p
     * @param from
     * @param to
     * @return true if the action performed successfully.
     */
    bool movePersonSafely(Person* p, Container* from, Container* to);
};


#endif //POO2_03_RIVER_RIVIERE_HHP
