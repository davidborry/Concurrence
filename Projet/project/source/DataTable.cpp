//
// Created by Thomas on 9/29/16.
//

#include "../include/DataTable.h"
#include "../include/Entity.h"

using namespace std;

vector<EntityData> initializeEntityDatas(){

    vector<EntityData> datas(Entity::TypeCount);

    datas[Entity::Human].height = 4;
    datas[Entity::Human].width = 4;
    datas[Entity::Human].solid = true;

    datas[Entity::Wall].width = 16;
    datas[Entity::Wall].height = 128;
    datas[Entity::Wall].solid = true;

    datas[Entity::Hole8].width = 16;
    datas[Entity::Hole8].height = 8;
    datas[Entity::Hole8].solid = false;

    datas[Entity::Hole16].width = 16;
    datas[Entity::Hole16].height = 16;
    datas[Entity::Hole16].solid = false;

    return datas;

}