//
// Created by Thomas Gillot on 13/11/2016.
//

#ifndef PROJET_ZONES_H
#define PROJET_ZONES_H

#include <iostream>
#include <queue>
#include <semaphore.h>
#include "Map.h"
#include "Entity.h"


class Zones {

public:
    Zones(Vector2i tl, Vector2i br, std::queue<Entity*> present_entities);
    Vector2i tl, br;
    std::queue<Entity*> present_entities;

public:
    bool entity_position_inside(Vector2i entity_position);
    void afficher();

    int verify_New_Zone(Vector2i currentEntityPosition, std::vector<Zones> mZones);

    void down();
    void up();

private:
    sem_t mutex;
};


#endif //PROJET_ZONES_H
