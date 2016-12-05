//
// Created by david on 14/11/16.
//

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

#include "World.h"

/**
 * Simulation class.
 * Can be run and reset for measures
 */
class Simulation{

public:
    enum Scenario{
        E1,
        E2,
        E3
    };

public:
    Simulation(Scenario scenario = E1);

public:
    virtual void run() = 0;
    virtual void reset();

protected:
    World mWorld;
};

#endif //PROJET_SIMULATION_H
