//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM2_H
#define PROJET_MTSIM2_H

#include <iostream>
#include <vector>
#include "Simulation.h"
#include "Zones.h"


struct Args{
    Args(World* w, std::vector<Zones> mZones, int i );
    World* w;

    std::vector<Zones> mZones;
    int i;
};




class MTSim1 : public Simulation{

public:
    MTSim1(int n = 4, int e = 1);

    void run();

private:
    std::vector<Zones> mZones;
    std::vector<pthread_t> mThreads;
    void initZones();
};

#endif //PROJET_MTSIM2_H
