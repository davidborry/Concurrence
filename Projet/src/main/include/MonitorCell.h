//
// Created by david on 03/12/16.
//

#ifndef PROJET_MONITORCELL_H
#define PROJET_MONITORCELL_H

#include "Cell.h"

/**
 * Works like Cell, but can be synchronized with a monitor
 * instead of a mutex.
 * Condition variable is bound to a counter that theoricaly
 * can be only 1 (taken) or 0 (free)
 */

class MonitorCell : public Cell{
public:
    MonitorCell();

    virtual void acquire();
    virtual void release();

private:
    pthread_mutex_t mutexT;
    pthread_cond_t cond;
    int count;
};
#endif //PROJET_MONITORCELL_H
