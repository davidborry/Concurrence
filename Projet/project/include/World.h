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

    void update();
    void update(int zone);
    bool spawn(Entity::Type type, int x, int y);

    Map getMap() const;
    void setTarget(Vector2i v);


private:
    Map mMap;
    Vector2i mTarget;

    std::array<std::vector<Entity*>,4> mActiveHumans;
};

#endif //PROJET_WORLD_H
