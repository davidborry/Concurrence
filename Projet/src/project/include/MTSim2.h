//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM1_H
#define PROJET_MTSIM1_H

#include "Simulation.h"

class MTSim2 : public Simulation{
public:
    MTSim2(int n = 4);
    void run();

private:
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM1_H
