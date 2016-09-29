//
// Created by Thomas on 9/29/16.
//

#include <include/DataTable.h>
#include <include/Entity.h>

using namespace std;

vector<EntityData> initializeEntityDatas(){

    vector<EntityData> datas(Entity::TypeCount);

    datas[Entity::Human].height = 4;
    datas[Entity::Human].width = 4;
    datas[Entity::Human].solid = true;

    datas[Entity::Wall].width = 2;
    datas[Entity::Wall].height = 16;
    datas[Entity::Wall].solid = true;

    datas[Entity::HoleA].width = 2;
    datas[Entity::HoleA].height = 8;
    datas[Entity::HoleA].solid = false;

    datas[Entity::HoleB].width = 16;
    datas[Entity::HoleB].height = 16;
    datas[Entity::HoleB].solid = false;

    return datas;

}