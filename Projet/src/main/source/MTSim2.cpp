//
// Created by david on 05/10/16.
//

#include <iostream>
#include <unistd.h>
#include "../include/MTSim2.h"

using namespace std;

static void* updateEntity(void* p)
{
    auto entity = static_cast<Entity*>(p);

    while(!entity->isDestroyed()){

        entity->update();


    }

    return NULL;
}

MTSim2::MTSim2(int n) : Simulation(n)
{

}

void MTSim2::run() {

    for(int i = 0; i < mWorld.getActiveHumans().size(); i++){

            //updateEntity(mWorld.getActiveHumans()[i]);
            pthread_t id;
            pthread_create(&id,NULL,updateEntity,mWorld.getActiveHumans()[i]);

            mThreads.push_back(id);

        }

    for(int i = 0; i < mThreads.size(); i++) {

        pthread_join(mThreads[i], NULL);
    }

    mThreads.clear();


}
