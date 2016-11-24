//
// Created by david on 14/11/16.
//

#ifndef PROJET_SIMULATION_H
#define PROJET_SIMULATION_H

#include "World.h"

class Simulation{
public:
    Simulation();

public:
    virtual void run() = 0;
    void reset();

protected:
    World mWorld;
};

#endif //PROJET_SIMULATION_H
