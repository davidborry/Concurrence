#include <iostream>
#include <include/Measures.h>
#include "include/options.h"
#include "include/Simulation.h"
#include "include/MTSim2.h"
#include "include/MTSim1.h"
#include "include/Entity.h"



using namespace std;

Simulation* build(int p, int t){
    if(t==1)
        return new MTSim1(p);
    else if(t==2)
        return new MTSim2(p);
    else
        return new Simulation(p);
}


int main(int argc, char** argv) {

    Options my_options = get_options(argc,argv);

    int p = my_options->person_number;
    int t = my_options->threads_creation;
    int e = my_options ->project_step;
    bool m = my_options->execution_measure;

    Simulation* sim = build(p,t);


    if(m){

        Measures measures(sim);
        cout << "Starting measures..." << endl << endl;

        measures.run();
        measures.print_result();
    }

    else {
        cout << "Starting simulation..." << endl;

        if(e == 2)
            sim->runE2();
        else
            sim->run();

        cout << "Simulation succesfully ended ! " << endl;
    }

    return 0;
}