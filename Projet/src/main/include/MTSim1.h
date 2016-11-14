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

/**
 * Multi thread simulation 1 (t2)
 * Every zone of the full map is associated to a thread
 * must be fully synchronized to fill associated queue and change zone of current entity
 */


class MTSim1 : public Simulation{

public:
    MTSim1(int n = 4, int e = 1);
    //Lanuch simulation associated to the e value
    void run();

private:
    // vector of zone
    std::vector<Zones> mZones;
    std::vector<pthread_t> mThreads;
    void initZones();
};

#endif //PROJET_MTSIM2_H
