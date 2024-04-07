#pragma once
//
// Created by Gregory Jabido on 1/23/24.
//

#ifndef CPTS122REDONE_CPTS122REDONEFUNCTIONS_H
#define CPTS122REDONE_CPTS122REDONEFUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum sleep
{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;





void initializeFitBitData(FitbitData input);//INITIALIZE FITBITDATA STRUCT (DIDNT USE)

int checkForDuplicateMinute(FitbitData fitBitUserData[1440], FitbitData input, int fitbitIndex);//CHECK FOR DUPLICATE MINUTES

int checkForIncorrectPatientID(FitbitData fitBitUserData[1440], FitbitData input, int fitbitIndex);//CHECK FOR INCORRECT PATIENT IDS

char* mystringtokenizeA1(char* str, char delimiter);//FIRST IMPROVEMENT OF MYSTRINGTOKENIZE

int checkInputInteger(char* str);//CHECK INPUT INTEGER FOR NULL

double checkInputDouble(char* str);//CHECK INPUT DOUBLE FOR NULL

double getAverage(FitbitData fitBitUserData[1440]);//GET AVERAGE HEART RATE

double getTotalCalories(FitbitData fitBitUserData[1440]);//GET TOTAL CALORIES

void getSleepRangeA1(FitbitData fitBitUserData[1440], int fitbitIndex, int* startTimeIndex, int* endTimeIndex);//GET SLEEP RANGE


#endif //CPTS122REDONE_CPTS122REDONEFUNCTIONS_H



