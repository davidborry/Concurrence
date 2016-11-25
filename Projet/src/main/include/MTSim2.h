//
// Created by david on 05/10/16.
//

/**
 * T2 scenario. Each human entity has an associated thread
 */

#ifndef PROJET_MTSIM1_H
#define PROJET_MTSIM1_H

#include "STSim.h"

class MTSim2 : public Simulation{
public:
    MTSim2(int n = 4, Scenario scenario = E1);
    void run();

private:
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM1_H
