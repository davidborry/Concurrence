#include <iostream>
#include <include/Measures.h>
#include "include/options.h"
#include "include/Simulation.h"
#include "include/MTSim2.h"
#include "include/MTSim1.h"
#include "include/Entity.h"



using namespace std;

Simulation* build(int p, int t,int e){
    if(t==1)
        return new MTSim1(p,e);
    else if(t==2)
        return new MTSim2(p,e);
    else
        return new Simulation(p,e);
}


int main(int argc, char** argv) {

    Options my_options = get_options(argc,argv);

    int p = my_options->person_number;
    int t = my_options->threads_creation;
    int e = my_options ->project_step;
    bool m = my_options->execution_measure;

    Simulation* sim = build(p,t,e);


    if(m){

        Measures measures(sim);
        cout << "Starting simulation with :" << endl;
        cout << "   -p: " << p << endl;
        cout << "   -e: " << e << endl;
        cout << "   -t: " << t << endl;
        cout << "   -m: " << true << endl;

        measures.run();
        measures.print_result();
    }

    else {
        cout << "Starting simulation with :" << endl;
        cout << "   -p: " << p << endl;
        cout << "   -e: " << e << endl;
        cout << "   -t: " << t << endl;
        cout << "   -m: " << false << endl;


        sim->run();

        cout << "Simulation succesfully ended ! " << endl;
    }

    return 0;
}