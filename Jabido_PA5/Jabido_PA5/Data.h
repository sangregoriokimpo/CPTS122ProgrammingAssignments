#pragma once
//
// Created by Gregory Jabido on 3/5/24.
//

#ifndef JABIDO_PA5_DATA_H
#define JABIDO_PA5_DATA_H
#include "PA5Header.h"


class Data {
public:
    // ## Constructors
    Data(int customerNumber, int serviceTime);
    Data(int customerNumber);
    Data();

    // ## Setters and Getters
    int getCustomerNumber() const;
    void setCustomerNumber(int customerNumber);
    int getServiceTime() const;
    void setServiceTime(int serviceTime);
    int getTotalTime() const;
    void setTotalTime(int totalTime);

    // ## ServiceTime functions
    void decrementServiceTime();

private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};


#endif //JABIDO_PA5_DATA_H

