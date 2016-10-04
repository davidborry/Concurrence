//
// Created by David on 9/28/16.
//

#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H

#include <array>
#include <queue>
#include "Map.h"
#include "DataTable.h"

typedef std::priority_queue<Vector2i,std::vector<Vector2i>,std::greater<Vector2i>> Paths;

class Entity{

public:

    enum Type{
        Human,
        Wall,
        HoleA,
        HoleB,
        TypeCount
    };

    enum Corner{
        TL,
        TR,
        BL,
        BR,
        CornerCount
    };

public:
    static std::vector<EntityData> Table;


public:

    Entity(Map* map, Type type, int x, int y);

    void update();
    bool move(Vector2i direction);
    Paths shortestDistanceToTarget();
    void setTarget(Vector2i target);
    void destroy();

    Vector2i getTarget() const;
    std::array<Vector2i,4> corners() const;

private:
    bool goLeft();
    bool goRight();
    bool goUp();
    bool goDown();

private:

    Map* mMap;
    Type mType;
    Vector2i mPosition;
    int mWidth;
    int mHeight;
    bool mSolid;
    bool mIsDestroyed;
    Vector2i* mTarget;
};

#endif //PROJET_ENTITY_H
