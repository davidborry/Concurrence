//
// Created by david on 05/10/16.
//

#include <iostream>
#include <unistd.h>
#include <cmath>
#include "include/STSim.h"

using namespace std;

STSim::STSim(int n) :
Simulation()
{
    cout << "Initializing T0 simulation" << endl;
    mWorld.spawn(Entity::Human,pow(2,n),World::NoSync);

}

void STSim::run() {

    //cout << mWorld.getMap() << endl;

    while(mWorld.update(0)) {

       // cout << mWorld.getActiveHumans().size() << endl;

    }



}
