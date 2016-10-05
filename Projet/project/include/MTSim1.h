//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM1_H
#define PROJET_MTSIM1_H

#include "Simulation.h"

class MTSim1 : public Simulation{
public:
    void run();

private:
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM1_H
