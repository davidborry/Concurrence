#include <iostream>
#include <include/Map.h>


using namespace std;

int main() {
    cout << "Hello, World!" << std::endl;

    Map m(20,10);

    m.setSolid(18,5,true);
    m.setSolid(2,7,true);
    m.setSolid(4,8,true);
    m.setSolid(19,9,true);


    cout << m;

    return 0;
}