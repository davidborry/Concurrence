//
// Created by David on 9/28/16.
//
#include <iostream>
#include <cmath>
#include "../include/Map.h"


using namespace std;

Vector2i::Vector2i(int x, int y) :
        x(x),
        y(y) {

}

double Vector2i::length() const {
    return sqrt(x * x + y * y);
}

Map::Map(int width, int height) :
        mWidth(width),
        mHeight(height) {
    mCells.resize(mHeight);

    for (int i = 0; i < mHeight; i++)
        mCells[i].resize(mWidth);
}


bool Map::isSolid(int x, int y) const {
    return mCells[y][x].isSolid();
}

void Map::setSolid(int x, int y, bool solid) {
    mCells[y][x].setSolid(solid);
}

void Map::setSolid(int x, int y, int width, int height, bool solid) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            mCells[y + i][x + j].setSolid(solid);
}

void Map::acquire(int x, int y) {
    mCells[y][x].acquire();
}

void Map::release(int x, int y) {
    mCells[y][x].release();
}

void Map::print(ostream &flux) const {
    for (int i = 0; i < mHeight; i++) {
        for (int j = 0; j < mWidth; j++)
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

ostream &operator<<(ostream &flux, Map const &map) {
    map.print(flux);
    return flux;
}

bool operator==(Vector2i const &a, Vector2i const &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(Vector2i const &a, Vector2i const &b) {
    return !(a == b);
}

bool operator<(Vector2i const &a, Vector2i const &b) {
    return a.length() < b.length();
}

bool operator<=(Vector2i const &a, Vector2i const &b) {
    return a.length() <= b.length();
}

bool operator>(Vector2i const &a, Vector2i const &b) {
    return !(a <= b);
}

bool operator>=(Vector2i const &a, Vector2i const &b) {
    return !(a < b);
}

Vector2i operator+(Vector2i const &a, Vector2i const &b) {
    return Vector2i(a.x + b.x, a.y + b.y);
}

Vector2i operator-(Vector2i &a, Vector2i const &b) {
    return Vector2i(a.x - b.x, a.y - b.y);
}

Vector2i operator*(Vector2i &a, float const &i) {
    return Vector2i(a.x * i, a.y * i);
}

Vector2i operator*(float const &i, Vector2i &a) {
    return a * i;
}

Vector2i operator/(Vector2i &a, float const &i) {
    return a * (1 / i);
}

ostream &operator<<(ostream &flux, Vector2i const &v) {
    flux << v.x << ":" << v.y;

    return flux;
}