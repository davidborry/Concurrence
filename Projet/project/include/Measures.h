//
// Created by Thomas Gillot on 07/10/2016.
//

#ifndef PROJET_MEASURE_H
#define PROJET_MEASURE_H

#include <iostream>
#include <ctime>

class Measures {

public:
    Measures();

    void addCPUConsumption(std::clock_t start, std::clock_t end);
    void addResponseTime(std::time_t start, std::time_t end);

    void calculateTotalCPUConsumption();
    void calculateTotalResponseTime();
    void print_result(std::string result_name, double time);



private:
    double total_CPU_consumption; //Total with all the 5 try
    double total_Response_Time; //Total with all the 5 try

};
#endif //PROJET_MEASURE_H
