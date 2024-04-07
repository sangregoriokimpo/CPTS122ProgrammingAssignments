#pragma once
//
// Created by Gregory Jabido on 3/8/24.
//

#ifndef JABIDO_PA5_SIMULATOR_H
#define JABIDO_PA5_SIMULATOR_H
#include "Queue.h"
#include "QueueNode.h"
#include "Data.h"


class Simulator {
private:
    Queue expressQueue;
    Queue normalQueue;
    int totalTime;
public:

    // ## Constructor
    Simulator() : totalTime(0) {}

    // ## Destructor
    ~Simulator();


    // ## Random number generator
    int generateRandomNumber(int min, int max);

    // ## TotalTime setters & getters
    int getTotalTime() const;

    void setTotalTime(int totalTime);

    // ## Run simulation function
    void runSimulation(int duration);

};


#endif //JABIDO_PA5_SIMULATOR_H

