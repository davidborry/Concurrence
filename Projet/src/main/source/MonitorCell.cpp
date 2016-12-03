//
// Created by david on 03/12/16.
//

#include <iostream>
#include "../include/MonitorCell.h"

MonitorCell::MonitorCell() :
count(0)
{
    pthread_cond_init(&cond, NULL);

}

void MonitorCell::acquire() {
    pthread_mutex_lock(&mutexT);


    while(count >= 1)
        pthread_cond_wait(&cond,&mutexT);

    count++;
}

void MonitorCell::release() {

    count--;
    pthread_cond_broadcast(&cond);

    pthread_mutex_unlock(&mutexT);
}