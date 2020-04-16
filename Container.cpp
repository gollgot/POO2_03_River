//
// Created by loic on 4/9/20.
//

#include "Container.hpp"

using namespace std;

Container::Container(const string& name): _name(name) {}

string Container::getName() const {
    return _name;
}

/**
 * Need an empty implementation to works with pur virtual destructor
 */
Container::~Container(){}