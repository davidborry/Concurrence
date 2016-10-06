//
// Created by Thomas Gillot on 03/10/2016.
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
    void removeDestroyedEntities();

    Map getMap() const;
    std::vector<Entity*> getActiveHumans() const;
    void setTarget(Vector2i v);


private:
    Map mMap;
    Vector2i mTarget;

    std::vector<Entity*> mActiveHumans;
};

#endif //PROJET_WORLD_H
