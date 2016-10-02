#include <iostream>
#include "include/Entity.h"
#include <unistd.h>


using namespace std;

int main(int argc, char** argv) {

    Map m(64,16);

    Entity h(&m,Entity::Human,0,0);
    Entity w(&m,Entity::Wall,30,0);

    while(true) {
        h.move({1, 1});

        cout << m << endl;

        usleep(500000);
    }

    return 0;
}