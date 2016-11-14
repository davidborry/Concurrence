//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM1_H
#define PROJET_MTSIM1_H

#include "Simulation.h"

/**
 * Multi thread simulation 2 (t2)
 * Every human entity has its associated thread and
 * must be fully synchronized in order to avoid collisions
 */
class MTSim2 : public Simulation{
public:
    MTSim2(int n = 4, int e = 1);
    void run();

private:
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM1_H
