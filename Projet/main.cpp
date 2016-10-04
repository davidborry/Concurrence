#include <iostream>
#include "include/Entity.h"
#include <unistd.h>
#include "include/World.h"
#include "include/Save_Map.h"


using namespace std;

int main(int argc, char** argv) {

    Map m(64,16);

    Entity h(&m,Entity::Human,32,0);
    Entity h2(&m,Entity::Human,50,12);

    Entity w(&m,Entity::Wall,30,0);
    Entity wo(&m,Entity::HoleA,30,4);

    h.setTarget(Vector2i(0,6));
    h2.setTarget(Vector2i(0,6));

    /**
    World world;
    world.setTarget(Vector2i(32,8));
    world.spawn(Entity::Human,0,0);
    world.spawn(Entity::Human,60,0);
    world.spawn(Entity::Human,0,12);
    world.spawn(Entity::Human,60,12);

    while(true) {
        cout << world.getMap() << endl;
        world.update();
        /**h.update();
        h2.update();**/

        //usleep(200000);
    }



    return 0;
}