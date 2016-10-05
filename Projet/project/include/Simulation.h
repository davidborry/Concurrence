//
// Created by david on 05/10/16.
//

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

#include "World.h"

class Simulation{

public:
    Simulation();

    void run();

protected:
    World mWorld;
};

#endif //PROJET_SIMULATION_H
