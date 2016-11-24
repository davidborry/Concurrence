//
// Created by david on 14/11/16.
//

#include "../include/Simulation.h"

#include <iostream>
using namespace std;

Simulation::Simulation() {
    mWorld.setTarget(Vector2i(0,62));

    mWorld.spawn(Entity::Wall,0,0, World::NoSync);
    mWorld.spawn(Entity::Hole8,0,60, World::NoSync);

    mWorld.spawn(Entity::Wall,128,0, World::NoSync);
    mWorld.spawn(Entity::Hole16,128,56,World::NoSync);
}

void Simulation::reset() {
    //cout << "Reset" << endl;
    mWorld.reset();
}