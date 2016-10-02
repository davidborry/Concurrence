//
// Created by David on 9/29/16.
//

#include "../include/Entity.h"
#include "../include/DataTable.h"
#include <iostream>

using namespace std;

namespace {
    const std::vector<EntityData> Table = initializeEntityDatas();
}

Entity::Entity(Map* map, Type type, int x, int y) :
mMap(map),
mType(type),
mPosition(x,y),
mWidth(Table[mType].width),
mHeight(Table[mType].height),
mSolid(Table[mType].solid),
mTarget(nullptr)
{
    mMap->setSolid(mPosition.x,mPosition.y,mWidth,mHeight,mSolid);

    if(mTarget == nullptr)
        cout << "null" << endl;
}

void Entity::move(Vector2i direction) {

    if(direction.x < 0)
        goLeft();

    if(direction.x > 0)
        goRight();

    if(direction.y < 0)
        goUp();

    if(direction.y > 0)
        goDown();
}

void Entity::setTarget(Vector2i target) {
    mTarget = &target;
}

Vector2i Entity::shortestDistanceToTarget() {
    return *mTarget-mPosition;
}

void Entity::goLeft() {
    if(mPosition.x-1 < 0)
        return;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mPosition.x - 1,mPosition.y+i))
            return;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x-1,mPosition.y+i,true);
        mMap->setSolid(mPosition.x-1+mWidth,mPosition.y+i,false);
    }

    mPosition.x--;
}

void Entity::goRight() {
    if(mPosition.x+mWidth >= mMap->getWidth())
        return;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mPosition.x + mWidth, mPosition.y + i))
            return;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,true);
        mMap->setSolid(mPosition.x,mPosition.y+i,false);
    }

    mPosition.x++;
}

void Entity::goUp() {

    if(mPosition.y-1 < 0)
        return;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mPosition.x+i,mPosition.y-1))
            return;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y-1,true);
        mMap->setSolid(mPosition.x+i,mPosition.y-1+mHeight,false);
    }

    mPosition.y--;

}

void Entity::goDown() {
    if(mPosition.y+mHeight >= mMap->getHeight())
        return;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mPosition.x+i,mPosition.y+mHeight))
            return;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y+mHeight,true);
        mMap->setSolid(mPosition.x+i,mPosition.y,false);
    }

    mPosition.y++;
}