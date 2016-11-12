//
// Created by david on 12/11/16.
//

#ifndef PROJET_FULLSYNCENTITY_H
#define PROJET_FULLSYNCENTITY_H

#include "Entity.h"

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
