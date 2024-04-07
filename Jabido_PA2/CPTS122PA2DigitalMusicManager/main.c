#include "CPTS122PA2functions.h"

int main() {
    char inputLine[100];//input line
    Node* pList = NULL;//initialize linked list
    FILE* inputStream = fopen("musicPlayList.csv", "r");
    int successfulDelete = 0;

    loadRecords(inputStream, &pList);
    displayAllRecords(pList);
    //printf("DELETING The Motto\n");
    successfulDelete = deleteRecord(&pList, "The Motto");
    printf("successful delete: %d\n", successfulDelete);
    displayAllRecords(pList);
    editRecord(&pList);
    printf("## DISPLAY LINKED LIST ##\n");
    displayAllRecords(pList);
    displayArtistRecords(pList, "Swift, Taylor");

    fclose(inputStream);
    return 0;
}

// ## TRIAL 1 - TEST TOKENIZATION GEN 1 ##
//    char testSentence[] = "\"Taylor, Swift\",42,17";
//    char testSentence2[]="Drake,69,69";
//    char testsscanf[]="test sscanf test";
//    char sscanftest1[20];char sscanftest2[20];char sscanftest3[20];
//    //printf("%s\n", strtok(testSentence,"\""));
//    if(checkString(testSentence)){
//        printf("%s\n", strtok(testSentence,"\""));
//    }
//    printf("%s\n", strtok(testSentence2,"\""));
//    sscanf(testsscanf,"%s %s %s",sscanftest1,sscanftest2,sscanftest3);
//    printf("%s %s %s",sscanftest1,sscanftest2,sscanftest3);

//## TRIAL 2 - TOKENIZATION GEN 2 ##
//    char inputLine[100];//input line
//    Node *pList = NULL;//initialize linked list
//    FILE *inputStream = fopen("../musicPlayList.csv","r");
//    Record testArr[100];Record inputRecord;Duration inputDuration;int inputTimesPlayed=0;int inputRating=0;
//
//    char artistToken[20]; char albumTitleToken[20]; char songTitleToken[20]; char genreToken[20];
//    char durationToken[20];char timesPlayedToken[20];char ratingToken[20];
//
//    if(inputStream != NULL){
//        while(fgets(inputLine,sizeof(inputLine),inputStream) != NULL){
//            if(checkString(inputLine)){
//                sscanf(inputLine,"\"%[^\"]\" %s %s %s %s %s %s",artistToken,albumTitleToken,
//                       songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//            }else{
//                sscanf(inputLine,"%s %s %s %s %s %s %s",artistToken,albumTitleToken,songTitleToken,
//                       genreToken,durationToken,timesPlayedToken,ratingToken);
//            }
//            printf("%s %s %s %s %s %s %s\n",artistToken,albumTitleToken,songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//        }
//    }

// ## TRIAL 3 - TOKENIZATION GEN 3 ##
//    char inputLine[100];//input line
//    Node *pList = NULL;//initialize linked list
//    FILE *inputStream = fopen("../musicPlayList.csv","r");
//    Record recordArr[100];Record inputRecord;Duration inputDuration;int inputTimesPlayed=0;int inputRating=0;
//    int inputIndex=0;
//
//    char artistToken[50]; char albumTitleToken[50]; char songTitleToken[50]; char genreToken[50];
//    char durationToken[50];char timesPlayedToken[50];char ratingToken[50];
//
//    if(inputStream != NULL){
//        while(fgets(inputLine,sizeof(inputLine),inputStream) != NULL){
//            if(checkString(inputLine)){
//                sscanf(inputLine,"\"%[^\"]\",%[^,],%[^,],%[^,],%[^,],%[^,],%s",artistToken,albumTitleToken,
//                       songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//            }else{
//                sscanf(inputLine,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",artistToken,albumTitleToken,songTitleToken,
//                       genreToken,durationToken,timesPlayedToken,ratingToken);
//            }
//            inputRecord = getRecord(artistToken,albumTitleToken,songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//            recordArr[inputIndex] =inputRecord;
//            inputIndex++;
//        }
//    }
//    for(int i = 0; i < inputIndex;i++){
//        printf("%s|%s|%s|%s|%d:%d|%d|%d\n",recordArr[i].artist,recordArr[i].albumTitle,recordArr[i].songTitle,
//               recordArr[i].genre,recordArr[i].songLength.minutes,recordArr[i].songLength.seconds,recordArr[i].timesPlayed,recordArr[i].rating);
//        insert(&pList,recordArr[i]);
//    }
//    printf("## DISPLAY LINKED LIST ##\n");
//    display(pList);
//    fclose(inputStream);

// ## TRIAL 4 - TEST LINKED LIST FUNCTIONS ##
//    char inputLine[100];//input line
//    Node *pList = NULL;//initialize linked list
//    FILE *inputStream = fopen("../musicPlayList.csv","r");
//    Record recordArr[100];Record inputRecord;Duration inputDuration;int inputTimesPlayed=0;int inputRating=0;
//    int inputIndex=0;
//
//    char artistToken[50]; char albumTitleToken[50]; char songTitleToken[50]; char genreToken[50];
//    char durationToken[50];char timesPlayedToken[50];char ratingToken[50];
//
//    if(inputStream != NULL){
//        while(fgets(inputLine,sizeof(inputLine),inputStream) != NULL){
//            if(checkString(inputLine)){
//                sscanf(inputLine,"\"%[^\"]\",%[^,],%[^,],%[^,],%[^,],%[^,],%s",artistToken,albumTitleToken,
//                       songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//            }else{
//                sscanf(inputLine,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",artistToken,albumTitleToken,songTitleToken,
//                       genreToken,durationToken,timesPlayedToken,ratingToken);
//            }
//            inputRecord = getRecord(artistToken,albumTitleToken,songTitleToken,genreToken,durationToken,timesPlayedToken,ratingToken);
//            recordArr[inputIndex] =inputRecord;
//            inputIndex++;
//        }
//    }
//    for(int i = 0; i < inputIndex;i++){
//        printf("%s|%s|%s|%s|%d:%d|%d|%d\n",recordArr[i].artist,recordArr[i].albumTitle,recordArr[i].songTitle,
//               recordArr[i].genre,recordArr[i].songLength.minutes,recordArr[i].songLength.seconds,recordArr[i].timesPlayed,recordArr[i].rating);
//        insert(&pList,recordArr[i]);
//    }
//    printf("## DISPLAY LINKED LIST ##\n");
//    displayAllRecords(pList);
//    displayArtistRecords(pList,"Swift, Taylor");

// ##TRIAL 5 - TEST DELETE FUNCTION ##
//    char inputLine[100];//input line
//    Node *pList = NULL;//initialize linked list
//    FILE *inputStream = fopen("../musicPlayList.csv","r");
//    int successfulDelete=0;
//
//    loadRecords(inputStream,&pList);
//    displayAllRecords(pList);
//    printf("DELETING The Motto\n");
//    successfulDelete = deleteRecord(&pList,"The Motto");
//    printf("successful delete: %d\n",successfulDelete);
//    displayAllRecords(pList);
//    editRecord(&pList);
//    printf("## DISPLAY LINKED LIST ##\n");
//    displayAllRecords(pList);
//    displayArtistRecords(pList,"Swift, Taylor");
//
//    fclose(inputStream);



//char *artistToken; char *albumTitleToken; char *songTitleToken; char *genreToken;
//char *durationToken;char *timesPlayedToken;char *ratingToken;