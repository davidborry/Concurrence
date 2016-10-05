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

class MTSim2 : public Simulation{

public:
    MTSim2();
    void run();

private:
    std::vector<Rectangle> mZones;
    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM2_H
