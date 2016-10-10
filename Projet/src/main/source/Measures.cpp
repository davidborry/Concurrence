//
// Created by Thomas Gillot on 07/10/2016.
//

#include "../include/Measures.h"
#include <iostream>
#include <algorithm>

const int MEASURES_NUMBER = 3;

Measures :: Measures(Simulation* sim):
mSim(sim)
{

}

void Measures::run() {

    for(int i = 0; i < 5; i++)
        update();

    averageTime(mRealTimes,mAverageRealTime);
    averageTime(mUTimes, mAverageUTime);
    averageTime(mSTimes, mAverageSTime);

}

void Measures::averageTime(std::vector<double> &times, double& averageTime) {
    std::sort(times.begin(), times.end());

    for(int i = 1; i < times.size()-1; i++)
        averageTime+= times[i];

    averageTime = averageTime/MEASURES_NUMBER;
}

void Measures::update() {
    struct timeval t1, t2;
    gettimeofday(&t1,NULL);

    mSim->run();

    gettimeofday(&t2,NULL);

    //mAverageRealTime += (t2.tv_sec-t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
    mRealTimes.push_back((t2.tv_sec-t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0);

    getrusage(RUSAGE_SELF,&mRusage);
    updateSTime();
    updateUTime();

    mSim->reset();
}

/**
 * We display the result of the measures
 * @param result_name
 * @param time
 */

void Measures::print_result() {
    std::cout << "Average real time : " << mAverageRealTime << "s" << std::endl;
    std::cout << "Average user time : " << mAverageUTime << "s" << std::endl;
    std::cout << "Average system time : " << mAverageSTime << "s" << std::endl;
}

void Measures::updateUTime() {

    struct timeval time = mRusage.ru_utime;

    //mAverageUTime += (double)time.tv_sec + (double)time.tv_usec / 1000000.0;
    mUTimes.push_back((double)time.tv_sec + (double)time.tv_usec / 1000000.0);
}

void Measures::updateSTime() {

    struct timeval time = mRusage.ru_stime;

    //mAverageSTime += (double)time.tv_sec + (double)time.tv_usec / 1000000.0;
    mSTimes.push_back((double)time.tv_sec + (double)time.tv_usec / 1000000.0);
}
