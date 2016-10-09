//
// Created by David on 9/27/16.
//

#include "../include/Cell.h"

using namespace std;

bool Cell::isSolid() const {
    return mSolid;
}

void Cell::setSolid(bool solid) {
    mSolid = solid;
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