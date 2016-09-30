//
// Created by David on 9/28/16.
//

#include "../include/Map.h"

using namespace std;

Vector::Vector(int x, int y) :
x(x),
y(y)
{

}

Map::Map(int width, int height) :
mWidth(width),
mHeight(height)
{
    mCells.resize(mHeight);

    for(int i = 0; i < mHeight; i++)
        mCells[i].resize(mWidth);
}

bool Map::isSolid(int x, int y) const {
    return mCells[y][x].isSolid();
}

void Map::setSolid(int x, int y, bool solid) {
    mCells[y][x].setSolid(solid);
}

void Map::setSolid(int x, int y, int width, int height, bool solid) {
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            mCells[y+i][x+j].setSolid(solid);
}

void Map::print(ostream &flux) const {
    for(int i = 0; i < mHeight; i++){
        for(int j = 0; j < mWidth; j++)
            flux << mCells[i][j];
        flux << endl;
    }
}

int Map::getWidth() const {
    return mWidth;
}

int Map::getHeight() const {
    return mHeight;
}

ostream &operator<<(ostream &flux, Map const& map){
    map.print(flux);
    return flux;
}