//
// Created by david on 05/10/16.
//

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

#include "World.h"

class Simulation{

public:
    Simulation(int n = 4);

    virtual void run();
    void reset();

protected:
    World mWorld;
};

#endif //PROJET_SIMULATION_H
