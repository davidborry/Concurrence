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

/**
 * Measure class, used to calculate real and CPU time in the simulation
 */
class Measures {

public:
    Measures(Simulation* sim, int e = 2);

    //Launches the simulation 5 times and calculates the mean of the 3 intermediary times
    void run();

    void averageTime(std::vector<double>& times, double& averageTime);

    //Calculate current simulation and reset it
    void update();
    void updateUTime();
    void updateSTime();

    void print_result();


private:
    int e;

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
