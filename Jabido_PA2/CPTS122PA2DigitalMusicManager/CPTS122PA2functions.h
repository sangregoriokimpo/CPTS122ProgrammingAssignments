#pragma once
#ifndef CPTS122PA2FUNCTIONS_H
#define CPTS122PA2FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
//(1) load - done
//(2) store
//(3) display - done
//(4) insert - done
//(5) delete - done
//(6) edit - done (almost)
//(7) sort
//(8) rate
//(9) play
//(10) shuffle
//(11) exit
typedef struct duration {
    int seconds;
    int minutes;
}Duration;
typedef struct record {
    char artist[50];
    char albumTitle[50];
    char songTitle[50];
    char genre[50];
    Duration songLength;
    int timesPlayed;
    int rating;
}Record;
typedef struct node {
    struct node* pPrev;
    struct node* pNext;
    Record record;
}Node;

//## FILE IO FUNCTIONS
int checkString(const char* str);
Duration getDuration(char durationToken[50]);
Record getRecord(char artistToken[50], char albumTitleToken[50], char songTitleToken[50], char genreToken[50],
    char durationToken[50], char timesPlayedToken[50], char ratingToken[50]);
//## RECORD FUNCTIONS
void loadRecords(FILE* inputStream, Node** pList);
void store(Node* pList);
void insert(Node** pList, Record insertRecord);
int deleteRecord(Node** pList, char* delete);
void editRecord(Node** pList);
int editRecordArtist(Node** pList, char* artist);
//WIP
int editRecordContents(Node** pList, char* songTitle, char* input, int editType);
void editRecordAlbumTitle(Node** pList, char* artist, char* albumTitle);
void editRecordSongTitle(Node** pList, char* artist, char* songTitle);
void editRecordGenre(Node** pList, char* artist);


//## DISPLAY FUNCTIONS ##
void display(Node* pList);
void displayAllRecords(Node* pList);
int displayArtistRecords(Node* pList, char* artist);
int checkRecord(Node* pList, char* record);
void displayEditMenu(char* songTitle);
int getEditAction();


#endif CPTS122PA2FUNCTIONS_H
