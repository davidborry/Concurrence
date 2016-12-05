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
 * Entity class.
 * Can be a human or a wall.
 * If given a target, an entity can process the shortest distance to reach
 * it and use it to move. The entity is destroyed when it reaches its target,
 * but it can respawn.
 */

typedef std::priority_queue<Vector2i,std::vector<Vector2i>,std::greater<Vector2i>> Paths;

class Entity{

public:

    static int cnt;

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

    //move while not destroyed
    void update();
    bool move(Vector2i direction);
    Paths shortestDistanceToTarget();
    void setTarget(Vector2i target);
    //used when targed is reached
    void destroy();
    bool isDestroyed() const;
    void respawn();

    Vector2i getTarget() const;
    Vector2i getPosition() const;
    std::array<Vector2i,4> corners() const;

    Map* getMap() const;

    //Set region limits. Used in t1 sim
    int getL() const;
    int getR() const;
    void setL(int l2);
    void setR(int r2);

    void acquire();
    void release();

private:
    virtual bool goLeft();
    virtual bool goRight();
    virtual bool goUp();
    virtual bool goDown();

protected:

    //private mutex, used to replace pthread_join
    sem_t sem;
    Map* mMap;
    Type mType;
    Vector2i mSpawn;
    Vector2i mPosition;
    int mWidth;
    int mHeight;
    bool mSolid;
    bool mIsDestroyed;
    Vector2i* mTarget;

    //region limits
    int l,r;
};

#endif //PROJET_ENTITY_H
