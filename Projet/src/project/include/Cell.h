//
// Created by David on 9/22/16.
//

#ifndef PROJET_CELL_H
#define PROJET_CELL_H

#include <ostream>

class Cell{

public:
    bool isSolid() const;
    void setSolid(bool solid);

    void print(std::ostream &flux) const;

private:
    bool mSolid = false;
};

std::ostream &operator<<(std::ostream& flux, Cell const& cell);

#endif //PROJET_CELL_H
