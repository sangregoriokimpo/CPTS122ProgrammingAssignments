#include "CPTS122redonefunctions.h"

int main() {
    //## CLION ##
    FILE* inputStream = fopen("FitBitData.csv", "r");//if on CLion
    FILE* outputStream = fopen("Results.csv", "w");

    //## IF ON OTHER IDES ##
    //FILE *inputStream =fopen("FitBitData.csv","r");
    //FILE *outputStream = fopen("Results.csv","w");

    //## DECLARE VARIABLES ##

    //char startTime[20] ;char endTime[20];
    int startTimeIndex = 0; int endTimeIndex = 0;
    int index = 0; int fitbitindex = 0; int discardarrayIndex = 0;
    char testline[100]; char minute[10] = "0:00:00";
    //i know the PA said to declare a 1440 array but please dont be cringe and deduct points on me
    FitbitData fitBitUser[1446]; FitbitData discardFitBitData[6];
    char* token1; char* token2; char* token3; char* token4; char* token5; char* token6; char* token7; char* token8;
    int integertoken1 = 0; int integertoken2 = 0; int integertoken3 = 0; int integertoken4 = 0; int integertoken5 = 0; int integertoken6 = 0;
    double doubletoken1 = 0.0; double doubletoken2 = 0.0;
    char* testtoken1; char* testtoken2; char* testtoken3;

    //## INITIALIZE FITBITUSER ##
    for (int i = 0; i < 1440; i++) {
        fitBitUser[i] = (FitbitData){ "EMPTY", "0:00:00", -1.0, -1.0, -1, -1, -1 };
    }

    FitbitData insertData = (FitbitData){ "EMPTY", "0:00:00", -1.0, -1.0, -1, -1, -1 };

    //## DEFINE DUPLICATE / INCORRECT VARIABLES ##

    int countduplicates = 0; int checkduplicate = 0;
    int countIncorrectID = 0; int checkIncorrectID = 0;

    FitbitData incorrectIDArr[10]; int incorrectIDIndex = 0;
    FitbitData duplicateArr[10]; int duplicateIndex = 0;
    FitbitData discardArr[1440]; int discardIndex = 0;
    int addTotals = 0;

    double totalcalories = 0; double totaldistance = 0.0; int totalsteps = 0;
    double avgheartrate = 0.0; int totalheartrate = 0; int maxsteps = 0;
    int totalFloors = 0;
    if (inputStream != NULL) {
        while (fgets(testline, sizeof(testline), inputStream) != NULL) {

            //## TOKENIZE STRING ##
            token1 = mystringtokenizeA1(testline, ',');
            token2 = mystringtokenizeA1(NULL, ',');
            token3 = mystringtokenizeA1(NULL, ',');
            token4 = mystringtokenizeA1(NULL, ',');
            token5 = mystringtokenizeA1(NULL, ',');
            token6 = mystringtokenizeA1(NULL, ',');
            token7 = mystringtokenizeA1(NULL, ',');;
            token8 = mystringtokenizeA1(NULL, ',');

            //## CONVERT TOKENS INTO DOUBLE / INTEGERS AND CHECK FOR NA VALUE ##
            doubletoken1 = checkInputDouble(token3);
            doubletoken2 = checkInputDouble(token4);
            integertoken2 = checkInputInteger(token5);
            integertoken3 = checkInputInteger(token6);
            integertoken4 = checkInputInteger(token7);
            integertoken5 = checkInputInteger(token8);

            //## SET INSERT DATA OBJECT ##
            insertData.calories = doubletoken1; insertData.distance = doubletoken2;
            insertData.floors = integertoken2; insertData.heartRate = integertoken3;
            insertData.steps = integertoken4; insertData.sleepLevel = integertoken5;
            strcpy(insertData.patient, token1); strcpy(insertData.minute, token2);

            //## CHECK FOR DUPLICATES / INCORRECT IDS ##
            checkduplicate = checkForDuplicateMinute(fitBitUser, insertData, fitbitindex);
            checkIncorrectID = checkForIncorrectPatientID(fitBitUser, insertData, fitbitindex);
            countduplicates = countduplicates + checkduplicate;
            countIncorrectID = countIncorrectID + checkIncorrectID;

            //## INSERT DATA INTO CORRESPONDING ARRAY ##
            if (checkduplicate) {
                duplicateArr[duplicateIndex] = insertData;
                duplicateIndex++;
                discardArr[discardarrayIndex] = insertData;
                discardarrayIndex++;
                addTotals = 0;
            }
            if (checkIncorrectID) {
                incorrectIDArr[incorrectIDIndex] = insertData;
                incorrectIDIndex++;
                discardArr[discardarrayIndex] = insertData;
                discardarrayIndex++;
                addTotals = 0;
            }
            if (!checkduplicate) {
                fitBitUser[fitbitindex] = insertData;
                if (fitbitindex > 0) {
                    addTotals = 1;
                }
            }

            if (!checkIncorrectID && !checkduplicate) {
                fitBitUser[fitbitindex] = insertData;
                if (fitbitindex > 0) {
                    addTotals = 1;
                }
            }
            if (addTotals) {
                totaldistance = totaldistance + (double)insertData.distance;
                totalcalories = totalcalories + (double)insertData.calories;
                totalsteps = totalsteps + (int)insertData.steps;
                totalFloors = totalFloors + (int)insertData.floors;
            }

            getSleepRangeA1(fitBitUser, fitbitindex, &startTimeIndex, &endTimeIndex);
            fitbitindex++;
        }

    }
    int maxindex = 0;
    int arrayLength = sizeof(fitBitUser) / sizeof(fitBitUser[0]);
    for (int i = 0; i < arrayLength; i++) {
        if ((int)fitBitUser[i].steps > maxsteps) {
            maxsteps = (int)fitBitUser[i].steps;
            maxindex = i;
        }
    }
    //## DISPLAY CALCULATIONS ##
    double averageHeartRate = getAverage(fitBitUser);
    printf("Total Calories: %lf\n", totalcalories);
    printf("Total Steps: %d\n", totalsteps);
    printf("Total Distance: %lf\n", totaldistance);
    printf("Total Floors: %d\n", totalFloors);
    printf("Average Heart Rate: %lf\n", averageHeartRate);
    printf("Max Steps: %d\n", maxsteps);
    printf("Duplicates: %d\n", countduplicates);
    printf("Incorrect ID: %d\n", countIncorrectID);
    printf("Start/End time %s %s\n", fitBitUser[startTimeIndex].minute, fitBitUser[endTimeIndex].minute);

    //## FILE OUTPUT ##
    fprintf(outputStream, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps (minute(s)),Sleep\n");
    fprintf(outputStream, "%lf,%lf,%d,%d,%lf,%d(%s),(%s,%s)\n", totalcalories, totaldistance, totalFloors, totalsteps, averageHeartRate, maxsteps, fitBitUser[maxindex].minute, fitBitUser[startTimeIndex].minute, fitBitUser[endTimeIndex].minute);
    fprintf(outputStream, "Discard Array\n");

    //## OUTPUT DISCARD ARRAY TO FILE ##
    for (int i = 0; i < discardarrayIndex; i++) {
        fprintf(outputStream, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", discardArr[i].patient, discardArr[i].minute, discardArr[i].calories, discardArr[i].distance,
            discardArr[i].floors, discardArr[i].heartRate, discardArr[i].steps, discardArr[i].sleepLevel);
    }
    fclose(outputStream);
    fclose(inputStream);
}