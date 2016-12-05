//
// Created by david on 13/11/16.
//

#ifndef PROJET_ZONE_H
#define PROJET_ZONE_H

#include <vector>
#include "Entity.h"

/**
 * Synchronized zone class used int t1 sim
 */

class Zone{

public:
    Zone(int l, int r, int w, int h, int totalEntities);

    void add(Entity* entity);
    void update();

    void setNext(Zone* n);
    void setPrev(Zone* p);

    void acquire();
    void release();

    void acquireList();
    void releaseList();

    void clearList();

private:
    //number of the entities present in all the zones
    int mTotalEntities;
    bool end;

    //2 mutexes : one for the entity list and one that replaces pthread_join
    sem_t mutex, sem;

    //dimensions and boundaries
    int l,r,w,h;
    Zone *prev, *next;
    std::vector<Entity*> mActiveHumans;
};
#endif //PROJET_ZONE_H
