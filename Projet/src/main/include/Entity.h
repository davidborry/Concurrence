//
// Created by David on 9/28/16.
//

#ifndef PROJET_ENTITY_H
#define PROJET_ENTITY_H

#include <array>
#include <queue>
#include "Map.h"
#include "DataTable.h"

/**
 * Entity class. Can be a wall or a person, and it's represented
 * by a rectangle of cells on the map
 */

typedef std::priority_queue<Vector2i,std::vector<Vector2i>,std::greater<Vector2i>> Paths;

class Entity{

public:

    enum Type{
        Human,
        Wall,
        Hole8,
        Hole16,
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

    //move algorithm
    void update();
    bool move(Vector2i direction);

    //Stores the shortest distances from the borders to the target
    //in a priority queue
    Paths shortestDistanceToTarget();
    void setTarget(Vector2i target);

    //Destroy when target is reached
    void destroy();
    bool isDestroyed() const;
    void respawn();

    Vector2i getTarget() const;
    Vector2i getPosition() const;
    std::array<Vector2i,4> corners() const;

    Map* getMap() const;

    //1 step move functions. Can be redefined in synchronized
    //subclasses
private:
    virtual bool goLeft();
    virtual bool goRight();
    virtual bool goUp();
    virtual bool goDown();

protected:

    Map* mMap;
    Type mType;
    Vector2i mSpawn;
    Vector2i mPosition;
    int mWidth;
    int mHeight;
    bool mSolid;
    bool mIsDestroyed;
    Vector2i* mTarget;
};

#endif //PROJET_ENTITY_H
