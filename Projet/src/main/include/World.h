//
// Created by David on 9/28/16.
//

#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include "Entity.h"
#include <array>
#import <semaphore.h>

/**
 * World class. Can spawn entities and set a target for them
 */
class World{

public:
    enum Sync{
        E1,
        E2,
        E3
    };

public:
    World(int p = 1);

    void update();
    bool update(int zone);
    bool spawn(Entity::Type type, int x, int y, Sync sync);
    void spawn(Entity::Type, int n, Sync sync);
    void removeDestroyedEntities();
    void reset();

    int getLivingPeopleNumber() const;

    void down();
    void up();
    void decrementLivingPeople();

    Map getMap() const;
    std::vector<Entity*> getActiveHumans() const;
    void setTarget(Vector2i v);

private:
    Map mMap;
    Vector2i mTarget;
    sem_t mutex;

    int livingPeopleNumber;

    std::vector<Entity*> mActiveHumans;
};

#endif //PROJET_WORLD_H
