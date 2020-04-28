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
    std::list<Person*> _people;
    std::list<Constraint*> _constraints;
    Bank _leftBank;
    Bank _rightBank;
    Boat _boat;
    int _turn;
    bool _isFinish = false;

    const int WIDTH = 58;
    const int MENU_WIDTH = 8;
    const char DISPLAY_CHAR = 'p';
    const char LOAD_CHAR = 'e';
    const char UNLOAD_CHAR = 'd';
    const char MOVE_CHAR = 'm';
    const char RESET_CHAR = 'r';
    const char QUIT_CHAR = 'q';
    const char MENU_CHAR = 'h';
    const char RIVER_CHAR = '=';
    const char BANK_CHAR = '-';
    const std::string ERROR_PREFIX = "### ";
    const std::string ERROR_ARG_MESSAGE = "Argument invalide";
    const std::string ERROR_CMD_INVALID = "Commande invalide";
    const std::string ERROR_NOT_DRIVER = "Aucun conducteur, impossible de deplacer le bateau";

public:

    /**
     * Empty constructor
     */
    Controller();

    /**
     * Destructor, delete all Person and Constraint create dynamically
     */
    ~Controller();

    /**
     * Display the menu
     */
    void showMenu() const;

    /**
     * Display the current game state
     */
    void display() const;

    /**
     * Pass to the next turn and display the game state
     */
    void nextTurn();

    /**
     * Begin the game loop
     */
    void beginGame();

private:

    /**
     * Create all Constraint that will be used in the game
     */
    void createConstraints();

    /**
     * Display the left Bank
     */
    void displayLeftBank() const;

    /**
     * Display the right Bank
     */
    void displayRightBank() const;

    /**
     * Display the Boat
     */
    void displayBoat() const;

    /**
     * Move the Boat if there is a driver inside it
     */
    void moveBoat();

    /**
     * Ask to the player to type a command and execute it
     */
    void askAndRunCommand();

    /**
     * Display an error message
     * @param message The error message to display
     */
    void displayError(const std::string& message) const;

    /**
     * Verifies all Constraints on all Containers.
     * @return a pointer to the Constraint that is not respect or nullptr if they're all ok.
     */
    Constraint* validateAllContainers();

    /**
     * Transfer Person from his current Container to another. No specific check applied
     * @param p The Person we want to move
     * @param from The starting Container
     * @param to The destination Container
     */
    void movePerson(Person* p, Container* from, Container* to) const;

    /**
     * Moves a Person p from a container to another and displays an error if a constraint is not respected
     * @param p The Person we want to move
     * @param from The starting Container
     * @param to The destination Container
     */
    void movePersonSafely(Person* p, Container* from, Container* to);

    /**
     * Put all people of the Container in the initial Container (_leftBank).
     * @param c The Container we want to reset
     */
    void reset(Container* c);

    /**
     * Resets the game properly.
     */
    void resetGame();
};


#endif //POO2_03_RIVER_RIVIERE_HHP
