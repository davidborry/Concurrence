//
// Created by david on 05/10/16.
//

#include <iostream>
#include <unistd.h>
#include <cmath>
#include "../include/Simulation.h"

using namespace std;

Simulation::Simulation(int n, int e) : mWorld(pow(2,n))
{

    this->e = e;
    cout << "Initializing..." << endl;



    mWorld.setTarget(Vector2i(0,62));

    mWorld.spawn(Entity::Wall,0,0, World::E1);
    mWorld.spawn(Entity::Hole8,0,60, World::E1);

    mWorld.spawn(Entity::Wall,128,0, World::E1);
    mWorld.spawn(Entity::Hole16,128,56,World::E1);

    switch (e){
        case 1:
            mWorld.spawn(Entity::Human,pow(2,n),World::E1);
            break;
        case 2:
            mWorld.spawn(Entity::Human,pow(2,n),World::E2);
            break;
        case 3:
            mWorld.spawn(Entity::Human,pow(2,n),World::E2);
            break;
        default:
            mWorld.spawn(Entity::Human,pow(2,n),World::E1);
            break;
    }
}



void Simulation::run() {

    while(mWorld.update(0)) {

    }

}


void Simulation::reset() {
    mWorld.reset();
}