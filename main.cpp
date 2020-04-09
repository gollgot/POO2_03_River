#include <iostream>
#include "Container.h"
#include "Boat.h"

using namespace std;

int main() {

    Bank leftBank("Left Bank");
    Bank rightBank("Right Bank");

    Boat boat("Boat", leftBank);

    cout << "The boat named : " << boat.getName() <<  " is on the bank : " << boat.getBank().getName() << endl;

    boat.setBank(rightBank);
    cout << "The boat is moving..." << endl;

    cout << "The boat named : " << boat.getName() <<  " is on the bank : " << boat.getBank().getName() << endl;


    return 0;
}