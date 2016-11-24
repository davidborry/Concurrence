//
// Created by david on 13/11/16.
//

#include <iostream>
#include "../include/RegionSyncEntity.h"

RegionSyncEntity::RegionSyncEntity(Map *map, Type type, int x, int y) :
Entity(map,type,x,y)
{

}

bool RegionSyncEntity::goLeft() {

    if(mPosition.x-1 < 0)
        return false;

    for(int i = 0; i < mHeight; i++) {

        if(mPosition.x -1 < l)
            mMap->acquire(mPosition.x -1, mPosition.y +i);

        if (mMap->isSolid(mPosition.x - 1, mPosition.y + i)){
            for(int j = 0; j <= i; j++) {
                if(mPosition.x -1 < l)
                    mMap->release(mPosition.x - 1, mPosition.y + j);
            }
            return false;
        }
    }

    mPosition.x--;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x,mPosition.y+i,true);
        if(mPosition.x < l)
            mMap->release(mPosition.x, mPosition.y +i);
        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,false);

    }

    return true;
}

bool RegionSyncEntity::goRight() {
    if(mPosition.x+mWidth >= mMap->getWidth())
        return false;

    for(int i = 0; i < mHeight; i++) {

        if(mPosition.x + mWidth > r)
            mMap->acquire(mPosition.x + mWidth, mPosition.y +i);

        if (mMap->isSolid(mPosition.x + mWidth, mPosition.y + i)) {

            for(int j = 0; j <= i; j++)
                if(mPosition.x + mWidth > r)
                    mMap->release(mPosition.x + mWidth, mPosition.y +j);

            return false;
        }
    }

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,true);
        mMap->setSolid(mPosition.x,mPosition.y+i,false);

        if(mPosition.x + mWidth > r)
            mMap->release(mPosition.x + mWidth, mPosition.y +i);

    }

    mPosition.x++;
    return true;
}

bool RegionSyncEntity::goUp() {

    if(mPosition.y-1 < 0)
        return false;

    for(int i = 0; i < mWidth; i++) {

        if(mPosition.x+i < l || mPosition.x +i > r)
            mMap->acquire(mPosition.x + i, mPosition.y -1);

        if (mMap->isSolid(mPosition.x + i, mPosition.y - 1)) {
            for(int j = 0; j <= i; j++) {
                if(mPosition.x+j < l || mPosition.x +j > r)
                    mMap->release(mPosition.x + j, mPosition.y - 1);
            }
            return false;
        }
    }

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y-1,true);
        mMap->setSolid(mPosition.x+i,mPosition.y-1+mHeight,false);

        if(mPosition.x+i < l || mPosition.x +i > r)
            mMap->release(mPosition.x + i, mPosition.y -1);

    }

    //cout << "Release up" << endl;


    mPosition.y--;
    return true;

}

bool RegionSyncEntity::goDown() {
    if(mPosition.y+mHeight >= mMap->getHeight())
        return false;

    for(int i = 0; i < mWidth; i++) {

        if(mPosition.x+i < l || mPosition.x +i > r)
             mMap->acquire(mPosition.x + i, mPosition.y + mHeight);

        if (mMap->isSolid(mPosition.x + i, mPosition.y + mHeight)) {
            for(int j = 0; j <= i; j++) {
                if(mPosition.x+j < l || mPosition.x +j > r)
                    mMap->release(mPosition.x + j, mPosition.y + mHeight);
            }

            return false;
        }
    }

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y+mHeight,true);

        if(mPosition.x+i < l || mPosition.x +i > r)
            mMap->release(mPosition.x + i, mPosition.y + mHeight);

        mMap->setSolid(mPosition.x+i,mPosition.y,false);
    }

    mPosition.y++;
    return true;
}

