//
// Created by Gregory Jabido on 1/23/24.
//
#include "CPTS122redonefunctions.h"

void initializeFitBitData(FitbitData input)//initialize fitbit data (didnt use)
{
    strcpy(input.patient, "EMPTY");//set patient ID to empty
    strcpy(input.minute, "0:00:00");//set minute
    input.calories = -1.0;//set calories to NA value
    input.distance = -1.0;//set distance to NA value
    input.floors = -1;//set floors to NA value
    input.heartRate = -1;//set heart rate to NA value
    input.steps = -1;//set steps to NA value
    input.sleepLevel = -1;//set sleep level value to NA value
}

int checkForDuplicateMinute(FitbitData fitBitUserData[1440], FitbitData input, int fitbitIndex)//check for duplicate minute
{
    for (int i = 0; i < fitbitIndex; i++) {
        if (strcmp(fitBitUserData[i].minute, input.minute) == 0) {
            return 1;//return 1 if duplicate found
        }
    }
    return 0;//return 0 if no duplicate found
}

int checkForIncorrectPatientID(FitbitData fitBitUserData[1440], FitbitData input, int fitbitIndex) {//check for incorrect patient ID
    for (int i = 0; i < fitbitIndex; i++) {
        if (strcmp("12cx7", input.patient) != 0) {
            return 1;//return 1 if duplicate found
        }
    }
    return 0;//return 0 if duplicate not found
}

char* mystringtokenizeA1(char* str, char delimiter) {//first improvement of mystrtok (gen 2)
    static char* state = NULL;

    if (str == NULL) {//check if token is NULL
        str = state;
        if (str == NULL)
            return NULL;//if token is NULL, return NULL
    }
    for (size_t i = 0; str[i] != '\0'; i++) {//index through token
        if (str[i] == delimiter) {//we found the delimiter
            str[i] = '\0';//cut the string
            state = str + i + 1;//set state to the remaining part of the string
            return str;//return token
        }
    }
    state = NULL;
    return str;//return token
}

int checkInputInteger(char* str) {//check if input token is NULL and return an integer
    char tempInteger[20];//temp string
    strcpy(tempInteger, str);//copy string to temp string
    if (tempInteger[0] == '\0') {//check if the temp string is NULL
        return -1;//if NULL return -1 (NA value)
    }
    return (int)strtol(tempInteger, &str, 10);//convert string to integer and return it
}

double checkInputDouble(char* str) {//check if input token is NULL and return a double
    char tempDouble[20];//temp string
    strcpy(tempDouble, str);//copy string to temp string
    if (tempDouble[0] == '\0') {//check if the temp string is NULL
        return -1.0;//if NULL return -1.0 (NA value)
    }
    return (double)strtod(tempDouble, &str);//convert string to double and return it
}

double getAverage(FitbitData fitBitUserData[1440]) {//get average heart rate
    double average = 0.0;
    int total = 0;
    int validHeartRate = 0;
    double totalDouble = 0.0;
    int countinvalidcells = 0;
    for (int i = 0; i < 1440; i++) {//index through data
        if (fitBitUserData[i].heartRate != -1) {
            total = total + (int)fitBitUserData[i].heartRate;//cast unsigned int to int
            validHeartRate++;
        }
        else {
            countinvalidcells++;
        }
    }

    totalDouble = (double)total;//cast total to double
    average = totalDouble / (double)validHeartRate;//calculate average
    return average;//return average
}

double getTotalCalories(FitbitData fitBitUserData[1440]) {//get total calories
    double total = 0.0;
    for (int i = 0; i < 1440; i++) {//index through data
        if (fitBitUserData[i].calories != -1) {//check if NA value
            total = total + fitBitUserData[i].calories;//add the calories up
        }
    }
    return total;
}

void getSleepRangeA1(FitbitData fitBitUserData[1440], int fitbitIndex, int* startTimeIndex, int* endTimeIndex) {//first improvement of my sleep range function (gen 2)
    //William Fralia helped me with this
    int longestRangeStart = -1;
    int longestRangeEnd = -1;
    int currentRangeStart = -1;
    int currentRangeEnd = -1;
    int sleep = 0;
    for (int i = 0; i < fitbitIndex; i++) {//iterate through fitbituserdata
        if (fitBitUserData[i].sleepLevel > 1) {//if asleep
            if (!sleep) {//check if currently not asleep
                currentRangeStart = i;//set current start index
                sleep = 1;//set sleep to 1 (true)
            }
            currentRangeEnd = i;//set current end index
        }
        else {
            sleep = 0;//set sleep to 0 (not sleeping)
            currentRangeStart = -1;
            currentRangeEnd = -1;
        }

        if ((currentRangeEnd - currentRangeStart) > (longestRangeEnd - longestRangeStart)) {//calculate longest sleep range
            longestRangeStart = currentRangeStart;
            longestRangeEnd = currentRangeEnd;
        }
    }
    *startTimeIndex = longestRangeStart;
    *endTimeIndex = longestRangeEnd;
    //printf("start time index: %d\n",*startTimeIndex);
    //printf("end time index: %d\n",*endTimeIndex);
}


