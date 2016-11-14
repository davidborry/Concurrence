//
// Created by David on 9/22/16.
//

#ifndef PROJET_CELL_H
#define PROJET_CELL_H

#include <ostream>
#include <semaphore.h>

/**
 * Simple map cell. Can be solid (occupied) or not.
 * Can also be synchronized with a mutex
 */

class Cell{

public:
    Cell();

    bool isSolid() const;
    void setSolid(bool solid);

    void print(std::ostream &flux) const;

    void acquire();
    void release();

private:
    sem_t mutex;
    bool mSolid = false;
};

std::ostream &operator<<(std::ostream& flux, Cell const& cell);

#endif //PROJET_CELL_H
