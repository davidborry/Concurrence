//
// Created by david on 13/11/16.
//

#include <zconf.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include "../include/Zone.h"

Zone::Zone(int l, int r, int w, int h) :
l(l),
r(r),
w(w),
h(h),
prev(nullptr),
next(nullptr),
end(false)
{
    sem_init(&mutex,0,1);
}

void Zone::add(Entity *entity) {
    mActiveHumans.push_back(entity);
}

void Zone::update() {

    while(true){

        end = true;

       // acquire();
        for(int i = 0; i < mActiveHumans.size(); i++){

            if(!mActiveHumans[i]->isDestroyed()){
                end = false;
                mActiveHumans[i]->update();
            }
        }

        //release();


        clearList();



    }
}


void Zone::clearList() {
    acquire();
    auto listBegin = std::remove_if(mActiveHumans.begin(), mActiveHumans.end(),
                                    [this] (Entity* e)
                                    {
                                       // std::cout << e->getPosition().x << " : " << l << std::endl;
                                        if(e->isDestroyed() || e->getPosition().x < l) {

                                            if(prev != nullptr) {
                                                prev->acquire();
                                                prev->add(e);
                                                prev->release();
                                            }
                                            return true;
                                        }



                                        return false;
                                    });

    mActiveHumans.erase(listBegin,mActiveHumans.end());
    release();
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