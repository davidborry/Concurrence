//
// Created by david on 05/10/16.
//

#include <iostream>
#include <unistd.h>
#include "include/Simulation.h"

using namespace std;

Simulation::Simulation() :
mWorld()
{
    mWorld.setTarget(Vector2i(0,64));

    mWorld.spawn(Entity::Wall,0,0);
    mWorld.spawn(Entity::Hole8,0,60);

    mWorld.spawn(Entity::Wall,128,0);
    mWorld.spawn(Entity::Hole16,128,56);

    mWorld.spawn(Entity::Human,256);



}

void Simulation::run() {

    //cout << mWorld.getActiveHumans().size() << endl;
    //cout << mWorld.getMap() << endl;

    while(mWorld.getActiveHumans().size() > 0) {
        mWorld.update();
        mWorld.removeDestroyedEntities();
       // cout << mWorld.getActiveHumans().size() << endl;

    }



}