//
// Created by loic on 4/19/20.
//

#include "FamilyMember.hpp"
#include "Container.hpp"
#include <list>

using namespace std;

FamilyMember::FamilyMember(const std::string &name, bool canDrive) : Person(name, canDrive) {}


bool FamilyMember::isRuleRespected(const Container& c) const {
    /*
    for(list<Person*>::iterator it = c.begin(); it < c.end(); ++it){

    }
    */
}
