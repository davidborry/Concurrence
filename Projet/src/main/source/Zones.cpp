//
// Created by Thomas Gillot on 13/11/2016.
//

#include <iostream>
#include "../include/Map.h"
#include "../include/Entity.h"
#include "../include/Zones.h"

using namespace std;


Zones:: Zones(Vector2i tl , Vector2i br, std::queue<Entity *> present_entities) {
    sem_init(&mutex,0,1);

    this->tl = tl;
    this->br = br;
    this->present_entities = present_entities;

}

void Zones::down() {
    sem_wait(&mutex);
}

void Zones::up() {
    sem_post(&mutex);
}

bool Zones::entity_position_inside(Vector2i entity_position) {
    if((entity_position.x >= tl.x && entity_position.y >= tl.y) && (entity_position.x <= br.x && entity_position.y <= br.y))
        return true;
    return false;
}

int Zones::verify_New_Zone(Vector2i currentEntityPosition, vector<Zones> mZones) {
    for(int i = 0; i< mZones.size() ; i++){
        if(mZones[i].entity_position_inside(currentEntityPosition))
            return i;
    }
    return 0; // Never accessed
}

void Zones::afficher()  {
    cout << "Zone position: " << tl << "," << br << endl;
    cout << "Present entities"<<endl;
    while(!present_entities.empty()){
        Entity *current_entity = present_entities.front();
        present_entities.pop();
        if(current_entity != nullptr) {
            cout << current_entity->getPosition() << endl;
        }
    }
}
