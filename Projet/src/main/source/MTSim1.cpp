//
// Created by david on 05/10/16.
//


#include <vector>
#include <queue>
#include <unistd.h>
#include <iostream>
#include "../include/MTSim1.h"
using namespace std;

Args::Args(World *w, Zones r) :
        w(w),
        r(r) {

}

Zones::Zones(Vector2i tl, Vector2i br, queue<Entity*> present_entities) :
        tl(tl),
        br(br),
        present_entities(present_entities)
{}

bool Zones::entity_position_inside(Vector2i entity_position) {
    if((entity_position.x >= tl.x && entity_position.y >= tl.y) && (entity_position.x <= br.x && entity_position.y <= br.y))
        return true;
    return false;
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

static void *updateRegion(void *p) {
    auto args = static_cast<Args *>(p);

    // cout << args->w->getMap() << endl;

    Zones r = args->r;
    World *w = args->w;

    bool end = false;

    while (!end) {
        end = true;
        for (int i = 0; i < w->getActiveHumans().size(); i++) {
            Entity *entity = w->getActiveHumans()[i];

            if (!entity->isDestroyed()) {
                end = false;
                bool supTL = entity->getPosition().x >= r.tl.x && entity->getPosition().y >= r.tl.y;
                bool infBR = entity->getPosition().x < r.br.x && entity->getPosition().y < r.br.y;

                if (supTL && infBR) {
                    entity->update();
                }
            }


        }
        //  cout << args->w->getMap() << endl;
    }


    return NULL;
}

MTSim1::MTSim1(int n) :
        Simulation(n) {

    initZones();

}

void MTSim1::initZones() {

    int width = mWorld.getMap().getWidth();
    int height = mWorld.getMap().getHeight();

    queue<Entity*> vector_zone_1;
    queue<Entity*> vector_zone_2;
    queue<Entity*> vector_zone_3;
    queue<Entity*> vector_zone_4;

    mZones.push_back(Zones(Vector2i(0, 0), Vector2i(width / 2, height / 2), vector_zone_1));
    mZones.push_back(Zones(Vector2i(width / 2, 0), Vector2i(width, height / 2),vector_zone_2));
    mZones.push_back(Zones(Vector2i(0, height / 2), Vector2i(width / 2, height),vector_zone_3));
    mZones.push_back(Zones(Vector2i(width / 2, height / 2), Vector2i(width, height),vector_zone_4));


    for(int i = 0 ; i<mWorld.getActiveHumans().size() ; i++){
        Entity *current_entity = mWorld.getActiveHumans()[i];
        if(current_entity != nullptr){
            Vector2i entity_position = current_entity->getPosition();
            if(mZones[0].entity_position_inside(entity_position))
                mZones[0].present_entities.push(current_entity);
            else if(mZones[1].entity_position_inside(entity_position))
                mZones[1].present_entities.push(current_entity);
            else if(mZones[2].entity_position_inside(entity_position))
                mZones[2].present_entities.push(current_entity);
            else if(mZones[3].entity_position_inside(entity_position))
                mZones[3].present_entities.push(current_entity);
        }
    }

    mZones[0].afficher();
    mZones[1].afficher();
    mZones[2].afficher();
    mZones[3].afficher();

}

void MTSim1::run() {

    for (int i = 0; i < mZones.size(); i++) {
        pthread_t id;
        pthread_create(&id, NULL, updateRegion, new Args(&mWorld, mZones[i]));

        mThreads.push_back(id);
    }

    for (int i = 0; i < mThreads.size(); i++)
        pthread_join(mThreads[i], NULL);

    mThreads.clear();


}