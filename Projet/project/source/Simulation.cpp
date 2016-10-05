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
    mWorld.setTarget(Vector2i(32,8));

    mWorld.spawn(Entity::Human,0,0);
    mWorld.spawn(Entity::Human,60,0);
    mWorld.spawn(Entity::Human,0,12);
    mWorld.spawn(Entity::Human,60,12);


}

void Simulation::run() {
    while(mWorld.getActiveHumans().size() > 0) {
        cout << mWorld.getMap() << endl;
        mWorld.update();
        mWorld.removeDestroyedEntities();
        usleep(100000);
    }
}