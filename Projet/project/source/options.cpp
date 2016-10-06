//
// Created by Thomas Gillot on 29/09/2016.
//
# include <iostream>
# include <getopt.h>



# include "../include/options.h"
# include "../include/validate_options.h"

using namespace std;

struct options* get_options(int argc,char **argv){

    if(argc == 1){
        cout << "Arguments required" << endl;
        print_help();
        exit(-1);
    }

    /**
     * Initialize to default values
     */

    struct options *options = (struct options*)malloc(sizeof(struct options));

    struct option long_options [] ={
            {"p",       required_argument,  0,  'a'},
            {"t",       required_argument,  0,  'b'},
            {"m",       no_argument,        0,  '@'}
    };


    if(options == NULL) {
        cout << "MALLOC ERROR" << endl;
        exit(-1);
    }

    options -> person_number = 0;
    options -> threads_creation = 0;
    options -> execution_measure = false;


    int c = 0;
    int option_id = 0;

    while((c = getopt_long_only(argc, argv, "",long_options, &option_id)) != -1){
        switch (c){
            case 'a':
                if(validate_person(atoi(optarg)))
                    options -> person_number = atoi(optarg);
                break;
            case 'b':
                if(validate_threads(atoi(optarg)))
                    options ->threads_creation = atoi(optarg);
                break;
            case '@':
                options -> execution_measure = true;
                break;
            default:
                cout << "Unknown option !" << endl;
                destruct_options(options);
                print_help();
                exit(-1);
        }
    }
    return options;
}

void destruct_options(Options options) {
    free(options);
}

/**
 * Only for tests
 */
void print_options(Options options) {
    cout << "-p: " << options -> person_number << endl;
    cout << "-t: " << options -> threads_creation << endl;
    cout << "-m: " << options -> execution_measure << endl;
}