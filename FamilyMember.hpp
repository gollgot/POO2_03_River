//
// Created by loic on 4/19/20.
//

#ifndef POO2_03_RIVER_FAMILYMEMBER_HPP
#define POO2_03_RIVER_FAMILYMEMBER_HPP


#include "Person.hpp"
#include "Container.hpp"

class FamilyMember : public Person{

private:

public:
    FamilyMember(const std::string& name, bool canDrive);

    bool isRuleRespected(const Container& c) const override;

};


#endif //POO2_03_RIVER_FAMILYMEMBER_HPP
