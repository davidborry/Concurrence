#include <iostream>
#include "include/options.h"
#include "include/STSim.h"
#include "include/MTSim2.h"
#include "include/MTSim1.h"
#include "include/Measures.h"



using namespace std;

Simulation* build(int p, int t, int e){
    Simulation::Scenario  scenario;
    switch(e){
        case 2:
            scenario = Simulation::E2;
            break;

        case 3:
            scenario = Simulation::E3;
            break;

        default:
            scenario = Simulation::E1;
            break;
    }

    if(t==1)
        return new MTSim1(p,scenario);
    else if(t==2)
        return new MTSim2(p,scenario);
    else
        return new STSim(p);

}


int main(int argc, char** argv) {

    Options my_options = get_options(argc,argv);

    int p = my_options->person_number;
    int t = my_options->threads_creation;
    int e = my_options ->project_step;
    bool m = my_options->execution_measure;

    cout <<"Loading scenario e" << e << endl;
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
        cout << "Simulation succesfully ended ! " << endl;
    }

    return 0;
}