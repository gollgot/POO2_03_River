#include <iostream>

#include "Container.hpp"
#include "Boat.hpp"
#include "Controller.hpp"

using namespace std;

int main() {


    Controller c;
    c.showMenu();
    c.display();

    c.nextTurn();

    c.display();

    /*
    Bank leftBank("Left Bank");
    Bank rightBank("Right Bank");

    Boat boat("Boat", leftBank);

    cout << "The boat named : " << boat.getName() <<  " is on the bank : " << boat.getBank().getName() << endl;

    boat.setBank(rightBank);
    cout << "The boat is moving..." << endl;

    cout << "The boat named : " << boat.getName() <<  " is on the bank : " << boat.getBank().getName() << endl;
    */

    return 0;
}