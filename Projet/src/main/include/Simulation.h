//
// Created by david on 05/10/16.
//

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

#include "World.h"

/**
 * Basic iterative simulation (t0)
 * Works like a game loop and updates every entity
 * at each iteration
 */
class Simulation{

public:
    Simulation(int n = 4, int e = 1);

    virtual void run();
    void reset();

protected:
    int e;
    World mWorld;
};

#endif //PROJET_SIMULATION_H
