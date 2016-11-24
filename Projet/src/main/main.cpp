#include <iostream>
#include "include/options.h"
#include "include/STSim.h"
#include "include/MTSim2.h"
#include "include/MTSim1.h"
#include "include/Measures.h"



using namespace std;

Simulation* build(int p, int t, int e){
    World::Sync sync;
    switch(e){
        case 2:
            sync = World::RegionSync;
            break;

        case 3:
            sync = World::FullSync;
            break;

        default:
            sync = World::NoSync;
            break;
    }

    if(t==1)
        return new MTSim1(p,sync);
    else if(t==2)
        return new MTSim2(p,sync);
    else {
        STSim* s = new STSim(p,sync);
        cout << "Loading scenario T0..." << endl;
        return s;
    }
}


int main(int argc, char** argv) {

    Options my_options = get_options(argc,argv);

    int p = my_options->person_number;
    int t = my_options->threads_creation;
    int e = my_options ->project_step;
    bool m = my_options->execution_measure;

    cout << e << endl;
    Simulation* sim = build(p,t,e);


    if(m){

        Measures measures(sim);
        cout << "Starting measures..." << endl << endl;

        measures.run();
        measures.print_result();
    }

    else {
        cout << "Starting simulation..." << endl;
        sim->run();
        cout << "STSim succesfully ended ! " << endl;
    }

    return 0;
}