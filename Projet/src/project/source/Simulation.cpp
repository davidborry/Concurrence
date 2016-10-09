//
// Created by david on 05/10/16.
//

#include <iostream>
#include <unistd.h>
#include <cmath>
#include "../include/Simulation.h"

using namespace std;

Simulation::Simulation(int n) :
mWorld()
{

    cout << "Initializing..." << endl;
    mWorld.setTarget(Vector2i(0,62));

    mWorld.spawn(Entity::Wall,0,0);
    mWorld.spawn(Entity::Hole8,0,60);

    mWorld.spawn(Entity::Wall,128,0);
    mWorld.spawn(Entity::Hole16,128,56);

    mWorld.spawn(Entity::Human,pow(2,n));



}

void Simulation::run() {

    //cout << mWorld.getMap() << endl;

    while(mWorld.update(0)) {

       // cout << mWorld.getActiveHumans().size() << endl;

    }



}

void Simulation::reset() {
    mWorld.reset();
}