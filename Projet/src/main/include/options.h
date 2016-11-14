//
// Created by Thomas Gillot on 29/09/2016.
//
# include <iostream>
# include <getopt.h>

#ifndef PROJECT_OPTIONS_H
#define PROJECT_OPTIONS_H

typedef struct options *Options;

/**
 * Represent the options of the sumulation
 */

struct options {
    int person_number;
    int threads_creation;
    int project_step;
    bool execution_measure;
};


struct options* get_options(int argc,char **argv);


void destruct_options(Options options);

//Only for tests

void print_options(Options options);

#endif //PROJECT_OPTIONS_H
