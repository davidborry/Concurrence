//
// Created by David on 9/28/16.
//

#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H

#include <include/Map.h>

class Entity{

public:
    enum Type{
        Human,
        Wall
    };

public:

    Entity(Map map, Type type, int x, int y);

    void update();
    void move(Vector direction);
    Vector shortestDistanceTo(int x, int y);

private:

    Map* mMap;
    Type mType;
    int mX;
    int mY;
};

#endif //PROJET_ENTITY_H
