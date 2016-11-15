//
// Created by david on 13/11/16.
//

#ifndef PROJET_ZONE_H
#define PROJET_ZONE_H

#include <vector>
#include "Entity.h"

class Zone{

public:
    Zone(int l, int r, int w, int h);

    void add(Entity* entity);
    void update();

    void setNext(Zone* n);
    void setPrev(Zone* p);

    void clearList();

    void acquire();
    void release();

private:
    sem_t mutex;
    int l,r,w,h;
    bool end;
    Zone *prev, *next;
    std::vector<Entity*> mActiveHumans;
};
#endif //PROJET_ZONE_H
