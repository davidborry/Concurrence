//
// Created by Thomas on 9/29/16.
//

#ifndef PROJET_DATATABLE_H
#define PROJET_DATATABLE_H


#include <vector>

struct EntityData{
    int width;
    int height;
    bool solid;
};

std::vector<EntityData> initializeEntityDatas();

#endif //PROJET_DATATABLE_H
