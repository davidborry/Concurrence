//
// Created by epu on 9/22/16.
//

#ifndef PROJET_MAP_H
#define PROJET_MAP_H

#include <vector>
#include "Cell.h"

struct Vector2i{
    Vector2i(int x, int y);
    double length() const;

    int x;
    int y;

};

class Map{
public:
    Map(int width, int height);

    bool isSolid(int x, int y) const;
    void setSolid(int x, int y, bool solid);
    void setSolid(int x, int y, int width, int height, bool solid);

    void print(std::ostream &flux) const;

    int getWidth() const;
    int getHeight() const;

private:
    int mWidth;
    int mHeight;
    std::vector<std::vector<Cell> > mCells;
};

std::ostream &operator<<(std::ostream &flux, Map const& map);

bool operator==(Vector2i const& a, Vector2i const& b);
bool operator!=(Vector2i const& a, Vector2i const& b);
bool operator<(Vector2i const& a, Vector2i const& b);
bool operator<=(Vector2i const& a, Vector2i const& b);
bool operator>(Vector2i const& a, Vector2i const& b);
bool operator>=(Vector2i const& a, Vector2i const& b);
Vector2i operator+(Vector2i const& a, Vector2i const& b);
Vector2i operator-(Vector2i& a, Vector2i const& b);
Vector2i operator*(Vector2i& a, float const& i);
Vector2i operator*(float const& i, Vector2i& a);
Vector2i operator/(Vector2i& a, float const& i);

std::ostream &operator<<(std::ostream &flux, Vector2i const& v);


#endif //PROJET_MAP_H
