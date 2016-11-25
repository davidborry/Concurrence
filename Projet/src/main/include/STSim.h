//
// Created by david on 05/10/16.
//

#ifndef PROJET_STSIM_H
#define PROJET_STSIM_H

#include "World.h"
#include "Simulation.h"
/**
 * T0 scenario.
 */
class STSim : public Simulation{

public:
    STSim(int n = 4);

    virtual void run();

};

#endif //PROJET_STSIM_H
