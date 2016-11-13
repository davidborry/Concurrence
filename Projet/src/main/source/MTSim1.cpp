//
// Created by david on 05/10/16.
//


#include <vector>
#include <queue>
#include <iostream>
#include "../include/MTSim1.h"


using namespace std;

Args::Args(World *w, vector<Zones> mZones, int i) :
        w(w),
        mZones(mZones),
        i(i) {
}


static void *updateRegion(void *p) {
    auto args = static_cast<Args *>(p);

    int zoneId = args->i;
    Zones r = args->mZones[zoneId];
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
    }

    return NULL;

}

static void *updateRegionE2(void *p) {
    auto args = static_cast<Args *>(p);

    vector<Zones> mZones = args->mZones;
    Zones current_zone = mZones[args->i];
    World *worldSync = args->w;


    //worldSync->down();
    int livingPeople = worldSync->getLivingPeopleNumber();
    //worldSync->up();


    while (livingPeople != 0) {

        current_zone.down();
        //worldSync->down();

        bool isEmpty = current_zone.present_entities.empty();


        if (!isEmpty) {
            Entity *current_entity = current_zone.present_entities.front();

            if (current_entity != nullptr) {
                if (!current_entity->isDestroyed()) {
                    current_entity->update();

                    if (!current_zone.entity_position_inside(current_entity->getPosition())) {
                        int newZoneId = current_zone.verify_New_Zone(current_entity->getPosition(), mZones);
                        Zones newZone = mZones[newZoneId];

                        current_zone.present_entities.pop();

                        newZone.addNewSyncEntity(current_entity);

                    } else {

                        current_zone.present_entities.pop();
                        current_zone.present_entities.push(current_entity);
                    }
                } else {
                    worldSync->decrementLivingPeople();
                }

            }
        }

        livingPeople = worldSync->getLivingPeopleNumber();

        current_zone.up();
        //worldSync->up();

    }

    return NULL;
}

MTSim1::MTSim1(int n, int e) :
        Simulation(n,e) {

    initZones();

}

void MTSim1::initZones() {

    int width = mWorld.getMap().getWidth();
    int height = mWorld.getMap().getHeight();

    queue<Entity *> queue_zone_1;
    queue<Entity *> queue_zone_2;
    queue<Entity *> queue_zone_3;
    queue<Entity *> queue_zone_4;

    mZones.push_back(Zones(Vector2i(0, 0), Vector2i(width / 2, height / 2), queue_zone_1));
    mZones.push_back(Zones(Vector2i(width / 2, 0), Vector2i(width, height / 2), queue_zone_2));
    mZones.push_back(Zones(Vector2i(0, height / 2), Vector2i(width / 2, height), queue_zone_3));
    mZones.push_back(Zones(Vector2i(width / 2, height / 2), Vector2i(width, height), queue_zone_4));


    for (int i = 0; i < mWorld.getActiveHumans().size(); i++) {
        Entity *current_entity = mWorld.getActiveHumans()[i];
        if (current_entity != nullptr) {
            Vector2i entity_position = current_entity->getPosition();
            if (mZones[0].entity_position_inside(entity_position))
                mZones[0].present_entities.push(current_entity);
            else if (mZones[1].entity_position_inside(entity_position))
                mZones[1].present_entities.push(current_entity);
            else if (mZones[2].entity_position_inside(entity_position))
                mZones[2].present_entities.push(current_entity);
            else if (mZones[3].entity_position_inside(entity_position))
                mZones[3].present_entities.push(current_entity);
        }
    }
}

void MTSim1::run() {
    for (int i = 0; i < mZones.size(); i++) {
        pthread_t id;
        switch (this->e) {
            case 1:
                pthread_create(&id, NULL, updateRegion, new Args(&mWorld, mZones, i));
                break;
            case 2:
                pthread_create(&id, NULL, updateRegionE2, new Args(&mWorld, mZones, i));
                break;
            case 3:
                pthread_create(&id, NULL, updateRegionE2, new Args(&mWorld, mZones, i));
                break;
            default:
                pthread_create(&id, NULL, updateRegion, new Args(&mWorld, mZones, i));
                break;

        }
        mThreads.push_back(id);
    }
    for (int i = 0; i < mThreads.size(); i++)
        pthread_join(mThreads[i], NULL);

    mThreads.clear();

}