//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM2_H
#define PROJET_MTSIM2_H

#include "Simulation.h"

struct Args{
    Args(World* w, Rectangle r);

    World* w;
    Rectangle r;
};

class MTSim1 : public Simulation{

public:
    MTSim1(int n = 4);
    void run();

private:
    std::vector<Rectangle> mZones;
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM2_H
