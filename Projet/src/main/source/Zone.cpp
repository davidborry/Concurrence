//
// Created by david on 13/11/16.
//

#include <zconf.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include "../include/Zone.h"

Zone::Zone(int l, int r, int w, int h, int totalEntities) :
l(l),
r(r),
w(w),
h(h),
prev(nullptr),
next(nullptr),
end(false),
mTotalEntities(totalEntities)
{
    sem_init(&sem,0,0);
    sem_init(&mutex,0,1);

}

void Zone::add(Entity *entity) {
    entity->setL(l);
    entity->setR(r);

    mActiveHumans.push_back(entity);
}

void Zone::update() {

    while(Entity::cnt < mTotalEntities){

        end = true;

        for(int i = 0; i < mActiveHumans.size(); i++){

            if(!mActiveHumans[i]->isDestroyed()){
                end = false;
                mActiveHumans[i]->update();
            }
        }

        //Remove entities outside boundaries. Destroy them or add them to
        //neighbour zone
        clearList();

    }

    release();
}


void Zone::clearList() {
    acquireList();
    auto listBegin = std::remove_if(mActiveHumans.begin(), mActiveHumans.end(),
                                    [this] (Entity* e)
                                    {
                                        if(e->isDestroyed() || e->getPosition().x < l) {
                                            if(prev != nullptr) {
                                                prev->acquireList();
                                                prev->add(e);
                                                prev->releaseList();
                                            }
                                            return true;
                                        }

                                        return false;
                                    });

    mActiveHumans.erase(listBegin,mActiveHumans.end());
    releaseList();
}
void Zone::setNext(Zone *n) {
    next = n;
}

void Zone::setPrev(Zone *p) {
    prev = p;
}

void Zone::acquire() {
    sem_wait(&sem);
}

void Zone::release() {
    sem_post(&sem);
}

void Zone::acquireList() {
    sem_wait(&mutex);
}

void Zone::releaseList() {
    sem_post(&mutex);
}