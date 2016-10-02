//
// Created by David on 9/28/16.
//

#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H

#include "Map.h"

class Entity{

public:

    enum Type{
        Human,
        Wall,
        HoleA,
        HoleB,
        TypeCount
    };

public:

    Entity(Map* map, Type type, int x, int y);

    void update();
    void move(Vector direction);
    Vector shortestDistanceToTarget();
    void setTarget(Vector target);

    Vector getTarget() const;

private:
    void goLeft();
    void goRight();
    void goUp();
    void goDown();

private:

    Map* mMap;
    Type mType;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    bool mSolid;
    Vector* mTarget;
};

#endif //PROJET_ENTITY_H