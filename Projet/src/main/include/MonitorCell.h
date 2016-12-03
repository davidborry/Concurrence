//
// Created by david on 03/12/16.
//

#ifndef PROJET_MONITORCELL_H
#define PROJET_MONITORCELL_H

#include "Cell.h"

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
