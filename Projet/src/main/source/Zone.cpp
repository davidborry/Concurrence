//
// Created by david on 13/11/16.
//

#include <zconf.h>
#include <algorithm>
#include <functional>
#include "../include/Zone.h"

Zone::Zone(int l, int r, int w, int h) :
l(l),
r(r),
w(w),
h(h),
prev(nullptr),
next(nullptr)
{
    sem_init(&mutex,0,1);

}

void Zone::add(Entity *entity) {
    acquire();
    mActiveHumans.push_back(entity);
    release();
}

void Zone::update() {
    bool end = false;

    while(!end){
        end = true;

        acquire();
        for(int i = 0; i < mActiveHumans.size(); i++){
            if(!mActiveHumans[i]->isDestroyed()){
                end = false;
                mActiveHumans[i]->update();
            }
        }

        clearList();

        release();

        usleep(10000);
    }
}


void Zone::clearList() {
    auto listBegin = std::remove_if(mActiveHumans.begin(), mActiveHumans.end(),
                                    [this] (Entity* e)
                                    {
                                        if(e->getPosition().x < l) {
                                            if(prev != nullptr)
                                                prev->add(e);
                                            return true;
                                        }

                                        if(e->getPosition().x >= r){
                                            if(next != nullptr)
                                                next->add(e);
                                            return true;
                                        }

                                        return false;
                                    });

    mActiveHumans.erase(listBegin,mActiveHumans.end());
}
void Zone::setNext(Zone *n) {
    next = n;
}

void Zone::setPrev(Zone *p) {
    prev = p;
}

void Zone::acquire() {
    sem_wait(&mutex);
}

void Zone::release() {
    sem_post(&mutex);
}