//
// Created by David on 9/29/16.
//

#include "../include/Entity.h"
#include "../include/DataTable.h"
#include <iostream>

using namespace std;

vector<EntityData> Entity::Table = initializeEntityDatas();

Entity::Entity(Map* map, Type type, int x, int y) :
mMap(map),
mType(type),
mPosition(x,y),
mWidth(Table[mType].width),
mHeight(Table[mType].height),
mSolid(Table[mType].solid),
mTarget(nullptr),
mIsDestroyed(false)
{
    mMap->setSolid(mPosition.x,mPosition.y,mWidth,mHeight,mSolid);

    if(mTarget == nullptr)
        cout << "null" << endl;
}

void Entity::update() {
    if(!mIsDestroyed && mTarget != nullptr) {
        if(shortestDistanceToTarget() != Vector2i(0,0)) {
            if (!move(shortestDistanceToTarget()))
                for (int i = TL; i < CornerCount; i++)
                    if (move(*mTarget - corners()[i]))
                        return;
        }

        else
            destroy();
    }

}

bool Entity::move(Vector2i direction) {

    Vector2i po = mPosition;

    if(direction.x < 0)
       goLeft();

    if(direction.x > 0)
         goRight();

    if(direction.y < 0)
         goUp();

    if(direction.y > 0)
         goDown();

    return po!=mPosition;

}

void Entity::setTarget(Vector2i target) {
    mTarget = new Vector2i(target);
}

Vector2i Entity::shortestDistanceToTarget() {
    Vector2i dist = *mTarget - mPosition;

    for(int i = 1; i < CornerCount; i++)
        if((*mTarget - corners()[i]) < dist)
            dist = *mTarget - corners()[i];

    return dist;
}

Vector2i Entity::getTarget() const {
    return *mTarget;
}

bool Entity::goLeft() {
    if(mPosition.x-1 < 0)
        return false;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mPosition.x - 1,mPosition.y+i))
            return false;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x-1,mPosition.y+i,true);
        mMap->setSolid(mPosition.x-1+mWidth,mPosition.y+i,false);
    }

    mPosition.x--;
    return true;
}

bool Entity::goRight() {
    if(mPosition.x+mWidth >= mMap->getWidth())
        return false;

    for(int i = 0; i < mHeight; i++)
        if (mMap->isSolid(mPosition.x + mWidth, mPosition.y + i))
            return false;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,true);
        mMap->setSolid(mPosition.x,mPosition.y+i,false);
    }

    mPosition.x++;
    return true;
}

bool Entity::goUp() {

    if(mPosition.y-1 < 0)
        return false;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mPosition.x+i,mPosition.y-1))
            return false;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y-1,true);
        mMap->setSolid(mPosition.x+i,mPosition.y-1+mHeight,false);
    }

    mPosition.y--;
    return true;

}

bool Entity::goDown() {
    if(mPosition.y+mHeight >= mMap->getHeight())
        return false;

    for(int i = 0; i < mWidth; i++)
        if(mMap->isSolid(mPosition.x+i,mPosition.y+mHeight))
            return false;

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y+mHeight,true);
        mMap->setSolid(mPosition.x+i,mPosition.y,false);
    }

    mPosition.y++;
    return true;
}

std::array<Vector2i,4> Entity::corners() const{
    std::array<Vector2i,4> c = {
            mPosition,
            mPosition + Vector2i(mWidth-1,0),
            mPosition + Vector2i(0,mHeight-1),
            mPosition + Vector2i(mWidth-1,mHeight-1)
    };

    return c;
}

void Entity::destroy() {
    mMap->setSolid(mPosition.x,mPosition.y,mWidth,mHeight,false);
    mIsDestroyed = true;
}

