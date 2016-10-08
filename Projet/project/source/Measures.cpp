//
// Created by Thomas Gillot on 07/10/2016.
//

#include "../include/Measures.h"
#include <iostream>

const int MEASURES_NUMBER = 3;


Measures :: Measures(){
    /**
     * We initialize all the total times. The times are the total of all measures after 5 exection to do the average
     * (The times are durations : (end - start))
     */
    total_CPU_consumption = 0;
    total_Response_Time = 0;
};

/**
 * We add this duration (end - start) to the total CPU consumption
 * @param start
 * @param end
 */
void Measures::addCPUConsumption(std::clock_t start, std::clock_t end){
    double duration = (end - start) / (double) CLOCKS_PER_SEC;
    total_CPU_consumption += duration;
}

/**
 * We add this duration (end - start) to the total CPU consumption
 * @param start
 * @param end
 */

void Measures::addResponseTime(std::time_t start, std::time_t end) {
    double duration = difftime(end,start);
    total_Response_Time += duration;
}

/**
 * After all the try we can calculate the average of the CPU consumption in seconds
 */
void Measures::calculateTotalCPUConsumption() {
    double average = (double) (total_CPU_consumption / MEASURES_NUMBER);
    print_result("CPU Consumption", average);
    return;
}

/**
 * After all the try we can calculate the average of the response time in seconds
 */
void Measures::calculateTotalResponseTime() {
    double average = (double) (total_Response_Time / MEASURES_NUMBER);
    print_result("Response Time", average);
    return;
}



/**
 * We display the result of the measures
 * @param result_name
 * @param time
 */

void Measures::print_result(std::string result_name, double time) {
    std::cout << result_name << ": " << time << "seconds" << std::endl;
    return;
}


