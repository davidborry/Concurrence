//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM2_H
#define PROJET_MTSIM2_H

#include "STSim.h"
#include "Zone.h"

struct Args{
    Args(World* w, Rectangle r);

    World* w;
    Rectangle r;
};

/**
 * t1 simulation. The map is divided in four
 * zones, each one of them is managed by a
 * different thread
 */
class MTSim1 : public Simulation{

public:
    MTSim1(int n = 4, Scenario scenario = E1);
    void initZones();
    void run();
    void reset();

private:
    std::vector<Rectangle> mRect;
    std::vector<Zone> mZones;

    std::vector<pthread_t> mThreads;
};

#endif //PROJET_MTSIM2_H
