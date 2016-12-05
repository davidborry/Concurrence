//
// Created by david on 12/11/16.
//

#ifndef PROJET_FULLSYNCENTITY_H
#define PROJET_FULLSYNCENTITY_H

#include "Entity.h"

/**
 * Used in scenario T2 and E2.
 * This synchronized entity will block every cell it
 * tries to occupy while moving.
 */

class FullSyncEntity : public Entity{

public:
    FullSyncEntity(Map* map, Type type, int x, int y);

private:
    bool goLeft();
    bool goRight();
    bool goUp();
    bool goDown();

};

#endif //PROJET_FULLSYNCENTITY_H
