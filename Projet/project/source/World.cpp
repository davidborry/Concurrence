//
// Created by david on 03/10/16.
//

#include <thread>
#include <algorithm>
#include "include/World.h"




World::World():
mMap(64,16),
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
            if(mMap.isSolid(x+i,y+j))
                return false;
    Entity* e = new Entity(&mMap,type,x,y);

    mActiveHumans.push_back(e);
    e->setTarget(mTarget);

    return true;
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