#include <iostream>

#include "Container.hpp"
#include "Boat.hpp"
#include "Controller.hpp"

using namespace std;

int main() {

    Controller c;
    c.showMenu();
    c.display();
    c.beginGame();

    return 0;
}