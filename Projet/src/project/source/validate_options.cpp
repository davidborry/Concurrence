//
// Created by Thomas Gillot on 30/09/2016.
//

#include <iostream>
#include "../include/validate_options.h"

using namespace std;

bool validate_person(int user_number) {
    if(user_number<0 || user_number > 9){
        cout << "Invalide argument for -p"<<endl;
        print_help();
        exit(-1);
    }
    return true;
}

bool validate_threads(int user_number) {
    if(user_number<0 || user_number > 2){
        cout << "Invalide argument for -t"<<endl;
        print_help();
        exit(-1);
    }
    return true;
}


void print_help(){
    cout << "HELP : " << endl;
    cout << "-p [0123456789] : person's number (2^p)" << endl;
    cout << "-t [012] :  thread creation" << endl;
    cout << "-m no arguments : execution measures " << endl;
}
