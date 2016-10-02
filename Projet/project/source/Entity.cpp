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
mX(x),
mY(y),
mWidth(Table[mType].width),
mHeight(Table[mType].height),
mSolid(Table[mType].solid),
mTarget(nullptr)
{
    mMap->setSolid(mX,mY,mWidth,mHeight,mSolid);
    mTarget = new Vector(0,0);

    if(mTarget == nullptr)
        cout << "null" << endl;
}

void Entity::move(Vector direction) {

    if(direction.x < 0)
        goLeft();

    if(direction.x > 0)
        goRight();

    if(direction.y < 0)
        goUp();

    if(direction.y > 0)
        goDown();
}

void Entity::goLeft() {
    if(mX-1 < 0)
        return;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mX - 1,mY+i))
            return;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mX-1,mY+i,true);
        mMap->setSolid(mX-1+mWidth,mY+i,false);
    }

    mX--;
}

void Entity::goRight() {
    if(mX+mWidth >= mMap->getWidth())
        return;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mX + mWidth, mY + i))
            return;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mX+mWidth,mY+i,true);
        mMap->setSolid(mX,mY+i,false);
    }

    mX++;
}

void Entity::goUp() {

    if(mY-1 < 0)
        return;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mX+i,mY-1))
            return;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mX+i,mY-1,true);
        mMap->setSolid(mX+i,mY-1+mHeight,false);
    }

    mY--;

}

void Entity::goDown() {
    if(mY+mHeight >= mMap->getHeight())
        return;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mX+i,mY+mHeight))
            return;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mX+i,mY+mHeight,true);
        mMap->setSolid(mX+i,mY,false);
    }

    mY++;
}