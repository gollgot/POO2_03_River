//
// Created by loic on 4/9/20.
//

#include "Container.h"

using namespace std;

Container::Container(string name): name(name) {}

string Container::getName() const {
    return name;
}

/**
 * Need an empty implementation to works with pur virtual destructor
 */
Container::~Container(){}