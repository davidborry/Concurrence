//
// Created by david on 05/10/16.
//

#ifndef PROJET_MTSIM2_H
#define PROJET_MTSIM2_H

#include "Simulation.h"

struct Zones{
    Zones(Vector2i tl, Vector2i br, std::vector<Entity*> present_entities);
    Vector2i tl, br;
    std::vector<Entity*> present_entities;

    bool entity_position_inside(Vector2i entity_position);
    void afficher();

};

struct Args{
    Args(World* w, Zones r);

    World* w;
    Zones r;
};




class MTSim1 : public Simulation{

public:
    MTSim1(int n = 4);

    void run();

private:
    std::vector<Zones> mZones;
    std::vector<pthread_t> mThreads;
    void initZones();
};

#endif //PROJET_MTSIM2_H
