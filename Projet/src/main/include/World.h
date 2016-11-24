//
// Created by David on 9/28/16.
//

#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "Entity.h"
#include <array>
#include <semaphore.h>

class World{

public:
    enum Sync{
        NoSync,
        RegionSync,
        FullSync
    };

public:
    World(int p = 1);

    void update();
    bool update(int zone);
    bool spawn(Entity::Type type, int x, int y, Sync sync);
    void spawn(Entity::Type, int n, Sync sync);
    void removeDestroyedEntities();
    void reset();

    Map* getMapAddress();
    Map getMap() const;
    std::vector<Entity*> getActiveHumans() const;
    void setTarget(Vector2i v);

private:
    Map mMap;
    Vector2i mTarget;

    int livingPeopleNumber;

    std::vector<Entity*> mActiveHumans;
};

#endif //PROJET_WORLD_H
