//
// Created by david on 13/11/16.
//

#ifndef PROJET_ZONE_H
#define PROJET_ZONE_H

#include <vector>
#include "Entity.h"

class Zone{

public:
    Zone(int l, int r, int w, int h, int totalEntities);

    void add(Entity* entity);
    void update();

    void setNext(Zone* n);
    void setPrev(Zone* p);

    void acquire();
    void release();

    void clearList();

private:
    int mTotalEntities;
    bool end;
    sem_t mutex;
    int l,r,w,h;
    Zone *prev, *next;
    std::vector<Entity*> mActiveHumans;
};
#endif //PROJET_ZONE_H
