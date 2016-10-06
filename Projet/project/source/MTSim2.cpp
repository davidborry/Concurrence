//
// Created by david on 05/10/16.
//

#include <unistd.h>
#include <iostream>
#include "include/MTSim2.h"

using namespace std;

Args::Args(World* w, Rectangle r) :
w(w),
r(r)
{

}

static void* updateRegion(void* p)
{
    auto args = static_cast<Args*>(p);

   // cout << args->w->getMap() << endl;

    Rectangle r = args->r;
    World* w = args->w;

    bool end = false;

    while(!end) {
        end = true;
        for (int i = 0; i < w->getActiveHumans().size(); i++) {
            Entity *entity = w->getActiveHumans()[i];

            if(!entity->isDestroyed()) {
                end = false;
                bool supTL = entity->getPosition().x >= r.tl.x && entity->getPosition().y >= r.tl.y;
                bool infBR = entity->getPosition().x < r.br.x && entity->getPosition().y < r.br.y;

                if (supTL && infBR) {
                    entity->update();
                }
            }


        }
      //  cout << args->w->getMap() << endl;
    }



    return NULL;
}

MTSim2::MTSim2() :
Simulation()
{
    int width = mWorld.getMap().getWidth();
    int height = mWorld.getMap().getHeight();


    mZones.push_back(Rectangle(Vector2i(0,0),Vector2i(width/4,height/4)));
    mZones.push_back(Rectangle(Vector2i(width/4,0), Vector2i(width,height/4)));
    mZones.push_back(Rectangle(Vector2i(0,height/4), Vector2i(width/4,height)));
    mZones.push_back(Rectangle(Vector2i(width/4,height/4),Vector2i(width,height)));
}

void MTSim2::run() {




    for(int i = 0; i < mZones.size(); i++) {
        pthread_t id;
        pthread_create(&id, NULL, updateRegion, new Args(&mWorld, mZones[i]));

        mThreads.push_back(id);
    }

    for(int i = 0; i < mThreads.size(); i++)
        pthread_join(mThreads[i],NULL);
}