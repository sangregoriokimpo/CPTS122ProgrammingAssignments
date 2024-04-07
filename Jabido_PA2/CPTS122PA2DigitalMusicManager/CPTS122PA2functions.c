#include "CPTS122PA2functions.h"

/*************************************************************
* Function: checkString                                     *
* Date Created: 1/27/23                                     *
* Date Last Modified: 1/27/23                                *
* Description: function to detect quotes at start of string *
* Input parameters: char *str to read                       *
* Returns: integer to be used as boolean                    *
* Preconditions: valid string input parameter               *
* Postconditions: quote detected at str[0]                  *
*************************************************************/

int checkString(const char* str) {//first iteration of checkString (GEN 1)
    if (str[0] == '"') {//check if there is a quote at beginning of string
        return 1;//return 1 if quote detected
    }
    return 0;//return 0 if quote not detected
}

/*************************************************************
* Function: getDuration                                     *
* Date Created: 1/30/23                                     *
* Date Last Modified: 1/30/23                                *
* Description: function to get duration                     *
* Input parameters: duration token string                   *
* Returns: Duration struct                                  *
* Preconditions: valid duration token                       *
* Postconditions: returns Duration struct                   *
*************************************************************/

Duration getDuration(char durationToken[50]) {//first iteration of getDuration(GEN 1)
    Duration duration;//initialize Duration struct
    sscanf(durationToken, "%d:%d", &duration.minutes, &duration.seconds);//set Duration to duration token
    return duration;//return duration
}

/*************************************************************
* Function: getRecord                                       *
* Date Created: 1/27/23                                     *
* Date Last Modified: 1/30/23                                *
* Description: function to get record                       *
* Input parameters: artistToken, albumTitleToken,           *
* songTitleToken, genreToken, durationToken,                *
* timesPlayedToken, ratingToken                             *
* Returns: Record                                           *
* Preconditions: must have valid tokens                     *
* Postconditions: must return valid record struct           *
*************************************************************/

Record getRecord(char artistToken[50], char albumTitleToken[50], char songTitleToken[50], char genreToken[50],//first iteration of getRecord function (GEN 1)
    char durationToken[50], char timesPlayedToken[50], char ratingToken[50]) {
    Record returnRecord;//initialize returnRecord struct
    strcpy(returnRecord.artist, artistToken);//set artist name
    strcpy(returnRecord.albumTitle, albumTitleToken);//set album title
    strcpy(returnRecord.songTitle, songTitleToken);//set song title
    strcpy(returnRecord.genre, genreToken);//set genre
    returnRecord.songLength = getDuration(durationToken);//set song length
    returnRecord.timesPlayed = atoi(timesPlayedToken);//set times played
    returnRecord.rating = atoi(ratingToken);//set rating

    return returnRecord;//return returnRecord

}

/*************************************************************
* Function: loadRecords                                     *
* Date Created: 1/30/23                                     *
* Date Last Modified: 1/30/23                                *
* Description: Function to read records from csv file        *
* Input parameters: FILE *inputStream, Node **pList         *
* Returns: void                                             *
* Preconditions: valid file input stream                     *
* Postconditions: valid linked list to insert nodes into    *
*************************************************************/

void loadRecords(FILE* inputStream, Node** pList) {//first iteration of loadRecords function (GEN 1)
    char inputLine[100];//input line
    Record inputRecord;//record to be inserted into the linked list

    //## INITIALIZE TOKENS ##
    char artistToken[50]; char albumTitleToken[50]; char songTitleToken[50]; char genreToken[50];
    char durationToken[50]; char timesPlayedToken[50]; char ratingToken[50];

    //## FILE IO ##
    if (inputStream != NULL) {
        while (fgets(inputLine, sizeof(inputLine), inputStream) != NULL) {
            if (checkString(inputLine)) {//file input if there are quotes in the artist name
                sscanf(inputLine, "\"%[^\"]\",%[^,],%[^,],%[^,],%[^,],%[^,],%s", artistToken, albumTitleToken,//format specifiers
                    songTitleToken, genreToken, durationToken, timesPlayedToken, ratingToken);
            }
            else {//file input if there are no quotes in the artist name
                sscanf(inputLine, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", artistToken, albumTitleToken, songTitleToken,//format specifiers
                    genreToken, durationToken, timesPlayedToken, ratingToken);
            }
            inputRecord = getRecord(artistToken, albumTitleToken, songTitleToken, genreToken, durationToken, timesPlayedToken, ratingToken);//set input record
            insert(pList, inputRecord);//insert record into linked list
        }
    }
}

/*************************************************************
* Function: insert                                          *
* Date Created: 1/27/23                                     *
* Date Last Modified: 1/28/23                                *
* Description: function to insert Record into linked list   *
* Input parameters: valid linked list and record struct     *
* Returns: void                                             *
* Preconditions: initialized linked list                    *
* Postconditions: node inserted into linked list            *
*************************************************************/

void insert(Node** pList, Record insertRecord) {
    Node* insertionNode = (Node*)malloc(sizeof(Node));//initialize node
    insertionNode->record = insertRecord;//set record of node to insertRecord
    insertionNode->pNext = (*pList);//set node to the top of the linked list
    insertionNode->pPrev = NULL;//set previous of node to NULL
    if ((*pList) != NULL) {//check if linked list is not empty
        (*pList)->pPrev = insertionNode;//set node to the top of the linked list
    }
    (*pList) = insertionNode;
}

int deleteRecord(Node** pList, char* delete) {
    Node* pCurr = *pList;
    Node* pNext = pCurr->pNext;
    int foundRecord = 0;
    int success = 0;
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.songTitle, delete) == 0) {
            foundRecord = 1;
            success = 1;
            pCurr->pPrev->pNext = pCurr->pNext;
            pNext->pPrev = pCurr->pPrev;
            free(pCurr);
            return success;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("NO RECORDS FOUND\n");
    }
    return success;
}

void editRecord(Node** pList) {
    char editArtist[50] = "";
    char editRecordSelection[50] = "";
    char inputEdit[50] = "";
    int found = 0;
    int artist = 0;
    int choice = 0;
    int editselected = 0;
    int edited = 0;
    int editType = 0;
    int editAction = 0;
    int userEdit = 0;
    printf("Which Artist's records do you want to edit?\n");
    do {
        scanf("%s", editArtist);
        found = displayArtistRecords(*pList, editArtist);
        if (found == 1) {
            artist = 1;
        }
    } while (!artist);
    printf("What Record do you want to edit?\n");
    do {
        scanf("%s", editRecordSelection);
        editselected = checkRecord(*pList, editRecordSelection);
        if (editselected) {
            edited = 1;
        }
    } while (!edited);
    displayEditMenu(editRecordSelection);
    editType = getEditAction();
    printf("Enter Edit\n");
    scanf("%s", inputEdit);
    //fgets(inputEdit,sizeof(inputEdit),stdin);
    editRecordContents(pList, editRecordSelection, inputEdit, editType);




}

int editRecordArtist(Node** pList, char* artist) {

}

int editRecordContents(Node** pList, char* songTitle, char* input, int editType) {
    Node* pCurr = *pList;
    int foundRecord = 0;
    int chosen = 0;
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.songTitle, songTitle) == 0) {
            foundRecord = 1;
            do {
                switch (editType) {
                case 1:
                    //edit artist
                    strcpy(pCurr->record.artist, input);
                    chosen = 1;
                    break;

                case 2:
                    //edit album title
                    strcpy(pCurr->record.albumTitle, input);
                    chosen = 1;
                    break;

                case 3:
                    //edit song title
                    strcpy(pCurr->record.songTitle, input);
                    chosen = 1;
                    break;

                case 4:
                    //edit genre
                    strcpy(pCurr->record.genre, input);
                    chosen = 1;
                    break;

                case 5:
                    //edit song length
                    pCurr->record.songLength = getDuration(input);
                    chosen = 1;
                    break;

                case 6:
                    //edit times played
                    pCurr->record.timesPlayed = atoi(input);
                    chosen = 1;
                    break;

                case 7:
                    //edit rating
                    pCurr->record.rating = atoi(input);
                    chosen = 1;
                    break;

                default:
                    //invalid option passed
                    printf("Invalid option passed\n");
                    break;
                }
            } while (!chosen);
            printf("%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
                pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);
            foundRecord = 1;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("NO RECORDS FOUND\n");
    }
    return foundRecord;
}

/*************************************************************
* Function: displayAllRecords                               *
* Date Created: 1/27/23                                     *
* Date Last Modified: 1/30/23                                *
* Description: function to display all records              *
* Input parameters: valid linked list                       *
* Returns: void                                             *
* Preconditions: must have linked list with nodes in it     *
* Postconditions: prints values of all nodes                *
*************************************************************/

void displayAllRecords(Node* pList) {
    Node* pCurr = pList;//set current pointer to the top of the linked list

    while (pCurr != NULL) {//display node data
        printf("%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
            pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);

        pCurr = pCurr->pNext;//index to next node
    }
}

int displayArtistRecords(Node* pList, char* artist) {
    Node* pCurr = pList;
    int foundRecord = 0;
    printf("Records by %s\n", artist);
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.artist, artist) == 0) {
            foundRecord = 1;
            printf("%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
                pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("NO RECORDS FOUND\n");
    }
    return foundRecord;
}

int checkRecord(Node* pList, char* record) {
    Node* pCurr = pList;
    int foundRecord = 0;
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.songTitle, record) == 0) {
            foundRecord = 1;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        foundRecord = 0;
        printf("NO RECORDS FOUND\n");
    }
    return foundRecord;
}

void displayEditMenu(char* songTitle) {
    printf("|Editing %s \n", songTitle);
    printf("|1. Edit Artist\n");
    printf("|2. Edit Album Title\n");
    printf("|3. Edit Song Title\n");
    printf("|4. Edit Genre\n");
    printf("|5. Edit Song Length\n");
    printf("|6. Edit Times Played\n");
    printf("|7. Edit Rating\n");

}

int getEditAction() {
    int choice = 0;
    int chosen = 0;
    do {
        printf("Enter Edit Action [1-7]\n");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 7) {
            chosen = 1;
        }
    } while (!chosen);
    return choice;
}