//
// Created by david on 24/11/16.
//

#ifndef PROJET_REGIONSYNCENTITY_H
#define PROJET_REGIONSYNCENTITY_H

#include "Entity.h"

/**
 * This synchronized entity acquires the cells it
 * tries to occupy when changing zone.
 * l and r attributes are used in the different
 * go functions
 */

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
