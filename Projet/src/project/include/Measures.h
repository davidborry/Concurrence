//
// Created by Thomas Gillot on 07/10/2016.
//

#ifndef PROJET_MEASURE_H
#define PROJET_MEASURE_H

#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <sys/resource.h>
#include "Simulation.h"

class Measures {

public:
    Measures(Simulation* sim);

    void run();

    void averageTime(std::vector<double>& times, double& averageTime);
    void update();
    void updateUTime();
    void updateSTime();

    void print_result();


private:

    std::vector<double> mRealTimes;
    std::vector<double> mUTimes;
    std::vector<double> mSTimes;

    Simulation* mSim;

    struct rusage mRusage;
    double mAverageRealTime;
    double mAverageUTime;
    double mAverageSTime;

};
#endif //PROJET_MEASURE_H
