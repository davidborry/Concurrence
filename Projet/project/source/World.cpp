//
// Created by david on 03/10/16.
//

#include <thread>
#include "include/World.h"

World::World():
mMap(64,16),
mTarget(0,0)
{

}

void World::update() {
    for(int i = 0; i < 4; i++)
        update(i);
}

void World::update(int zone){
    for(int i = 0; i < mActiveHumans[zone].size(); i++){
        //std::thread t(&Entity::update,mActiveHumans[zone][i]);
        //t.join();
        mActiveHumans[zone][i]->update();

    }
}

bool World::spawn(Entity::Type type, int x, int y) {
    for(int i = 0; i < Entity::Table[type].width ;i++)
        for(int j = 0; j < Entity::Table[type].height; j++)
            if(mMap.isSolid(x+i,y+j))
                return false;
    Entity* e = new Entity(&mMap,type,x,y);

    mActiveHumans[0].push_back(e);
    e->setTarget(mTarget);

    return true;
}

Map World::getMap() const {
    return mMap;
}

void World::setTarget(Vector2i v){
    mTarget = v;
}