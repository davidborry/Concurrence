//
// Created by epu on 9/22/16.
//

#ifndef PROJET_MAP_H
#define PROJET_MAP_H

#include <vector>
#include "Cell.h"

struct Vector{
    Vector(int x, int y);

    int x;
    int y;
};

class Map{
public:
    Map(int width, int height);

    bool isSolid(int x, int y) const;
    void setSolid(int x, int y, bool solid);

    void print(std::ostream &flux) const;

private:
    int mWidth;
    int mHeight;
    std::vector<std::vector<Cell>> mCells;
};

std::ostream &operator<<(std::ostream &flux, Map const& map);

#endif //PROJET_MAP_H
