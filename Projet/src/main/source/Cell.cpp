//
// Created by David on 9/27/16.
//

#include <iostream>
#include "../include/Cell.h"

using namespace std;

Cell::Cell(){
    sem_init(&mutex,0,1);
}

bool Cell::isSolid() const {
    return mSolid;
}

void Cell::setSolid(bool solid) {
    mSolid = solid;
}

void Cell::acquire() {
    sem_wait(&mutex);
}

void Cell::release() {

    sem_post(&mutex);
}

void Cell::print(ostream &flux) const{
    if(mSolid)
        flux << "X";

    else
        flux << ".";
}

ostream &operator<<(ostream &flux, Cell const& cell){
    cell.print(flux);
    return flux;
}