//
// Created by loic on 4/9/20.
//

#ifndef POO2_03_RIVER_CONTAINER_H
#define POO2_03_RIVER_CONTAINER_H

#include <string>
#include <vector>


class Container {

private:
    std::string name;

public:

    Container(std::string name);

    std::string getName() const;

    /**
     * Pur virtual destructor, to have a real abstract Container class
     */
    virtual ~Container() = 0;

};


#endif //POO2_03_RIVER_CONTAINER_H
