//
// Created by david on 03/10/16.
//

#include <thread>
#include <algorithm>
#include <iostream>
#include "../include/World.h"




World::World():
mMap(512,128),
mTarget(0,0)
{

}

void World::update() {

        update(0);
}

void World::update(int zone){
    for(int i = 0; i < mActiveHumans.size(); i++){
        /*pthread_t id;
        pthread_create(&id,NULL,Entity::staticFunction,mActiveHumans[zone][i]);
        pthread_join(id,NULL);*/

        mActiveHumans[i]->update();

    }
}

bool World::spawn(Entity::Type type, int x, int y) {


    for(int i = 0; i < Entity::Table[type].width ;i++)
        for(int j = 0; j < Entity::Table[type].height; j++)
            if(mMap.isSolid(x+i,y+j) && Entity::Table[type].solid)
                return false;
    Entity* e = new Entity(&mMap,type,x,y);

    if(type == Entity::Human) {
        mActiveHumans.push_back(e);
        e->setTarget(mTarget);
    }

    return true;
}

void World::spawn(Entity::Type type, int n) {
    int i = 0;

    std::cout << mMap.getWidth() << " - " << mMap.getHeight() << std::endl;
    srand (time(NULL));
    while(i<n){



        int x = rand()%(mMap.getWidth()-2*Entity::Table[type].width) + Entity::Table[type].width;
        int y = rand()%(mMap.getHeight()-2*Entity::Table[type].height) + Entity::Table[type].height;


        if(spawn(type,x,y))
            i++;
    }
}

void World::removeDestroyedEntities() {
    auto listBegin = std::remove_if(mActiveHumans.begin(), mActiveHumans.end(),
                                           std::mem_fn(&Entity::isDestroyed));

    mActiveHumans.erase(listBegin,mActiveHumans.end());
}

Map World::getMap() const {
    return mMap;
}

std::vector<Entity*> World::getActiveHumans() const {
    return mActiveHumans;
}

void World::setTarget(Vector2i v){
    mTarget = v;
}