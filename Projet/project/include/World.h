//
// Created by David on 9/28/16.
//

#ifndef PROJET_WORLD_H
#define PROJET_WORLD_H

#include <include/Entity.h>
#include <array>

class World{

public:
    World();

    void run();
    void update();

    void spawn(Entity::Type type, int x, int y);


private:
    Map mMap;

    std::array<std::vector<Entity*>,4> mActiveHumans;
};

#endif //PROJET_WORLD_H
