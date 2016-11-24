//
// Created by david on 12/11/16.
//

#include "../include/FullSyncEntity.h"

FullSyncEntity::FullSyncEntity(Map *map, Type type, int x, int y) :
        Entity(map,type,x,y)
{

}

bool FullSyncEntity::goLeft() {

    if(mPosition.x-1 < 0)
        return false;

    for(int i = 0; i < mHeight; i++) {

        mMap->acquire(mPosition.x -1, mPosition.y +i);
        mMap->acquire(mPosition.x +3, mPosition.y +i);

        if (mMap->isSolid(mPosition.x - 1, mPosition.y + i)){
            for(int j = 0; j <= i; j++) {
                mMap->release(mPosition.x - 1, mPosition.y + j);
                mMap->release(mPosition.x +mWidth-1, mPosition.y +j);
            }
            return false;
        }
    }

    mPosition.x--;

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x,mPosition.y+i,true);
        mMap->release(mPosition.x, mPosition.y +i);

        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,false);
        mMap->release(mPosition.x +mWidth, mPosition.y +i);

    }

    return true;
}

bool FullSyncEntity::goRight() {
    if(mPosition.x+mWidth >= mMap->getWidth())
        return false;

    for(int i = 0; i < mHeight; i++) {
        mMap->acquire(mPosition.x + mWidth, mPosition.y +i);
        mMap->acquire(mPosition.x -1, mPosition.y +i);

        if (mMap->isSolid(mPosition.x + mWidth, mPosition.y + i)) {

            for(int j = 0; j <= i; j++) {
                mMap->release(mPosition.x + mWidth, mPosition.y + j);
                mMap->release(mPosition.x -1, mPosition.y +j);

            }

            return false;
        }
    }

    for(int i = 0; i < mHeight; i++){
        mMap->setSolid(mPosition.x+mWidth,mPosition.y+i,true);
        mMap->release(mPosition.x + mWidth, mPosition.y +i);

        mMap->setSolid(mPosition.x,mPosition.y+i,false);
        mMap->release(mPosition.x,mPosition.y+i);

    }

    mPosition.x++;
    return true;
}

bool FullSyncEntity::goUp() {

    if(mPosition.y-1 < 0)
        return false;

    for(int i = 0; i < mWidth; i++) {
        mMap->acquire(mPosition.x + i, mPosition.y -1);
        mMap->acquire(mPosition.x +i, mPosition.y + mHeight -1);

        if (mMap->isSolid(mPosition.x + i, mPosition.y - 1)) {
            for(int j = 0; j <= i; j++) {
                mMap->release(mPosition.x + j, mPosition.y - 1);
                mMap->release(mPosition.x + j, mPosition.y + mHeight -1);
            }
            return false;
        }
    }

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y-1,true);
        mMap->release(mPosition.x + i, mPosition.y -1);

        mMap->setSolid(mPosition.x+i,mPosition.y-1+mHeight,false);
        mMap->release(mPosition.x +i, mPosition.y + mHeight -1);
    }

    mPosition.y--;
    return true;

}

bool FullSyncEntity::goDown() {
    if(mPosition.y+mHeight >= mMap->getHeight())
        return false;

    for(int i = 0; i < mWidth; i++) {

        mMap->acquire(mPosition.x + i, mPosition.y + mHeight);
        mMap->acquire(mPosition.x +i, mPosition.y);

        if (mMap->isSolid(mPosition.x + i, mPosition.y + mHeight)) {
            for(int j = 0; j <= i; j++) {
                mMap->release(mPosition.x + j, mPosition.y + mHeight);
                mMap->release(mPosition.x +j, mPosition.y);

            }

            return false;
        }
    }

    for(int i = 0; i < mWidth; i++){
        mMap->setSolid(mPosition.x+i,mPosition.y+mHeight,true);
        mMap->release(mPosition.x + i, mPosition.y + mHeight);

        mMap->setSolid(mPosition.x+i,mPosition.y,false);
        mMap->release(mPosition.x +i, mPosition.y);

    }

    mPosition.y++;
    return true;
}
