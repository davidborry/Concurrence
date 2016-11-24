//
// Created by david on 24/11/16.
//

#ifndef PROJET_REGIONSYNCENTITY_H
#define PROJET_REGIONSYNCENTITY_H

#include "Entity.h"

class RegionSyncEntity : public Entity{
public:
    RegionSyncEntity(Map* map, Type type, int x, int y);

public:
    bool goLeft();
    bool goRight();
    bool goUp();
    bool goDown();
};

#endif //PROJET_REGIONSYNCENTITY_H
