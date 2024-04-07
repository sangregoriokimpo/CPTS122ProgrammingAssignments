#include "functions.h"

/*************************************************************
* Function: run_system ()
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

/*************************************************************
* Function: checkString()
* Date Created: 1/27/24
* Date Last Modified: 1/27/24
* Description: Checks if the input string starts with a
*              double quote.
* Input parameters: str - Pointer to a null-terminated
*                        string.
* Returns: 1 if the string starts with a double quote,
*          otherwise returns 0.
* Preconditions: The input string must be a valid C string.
* Postconditions: None.
*************************************************************/

int checkString(const char* str) {//first iteration of checkString (GEN 1)
    if (str[0] == '"') {//check if there is a quote at beginning of string
        return 1;//return 1 if quote detected
    }
    return 0;//return 0 if quote not detected
}

/*************************************************************
* Function: getDuration()
* Date Created: 1/30/24
* Date Last Modified: 1/30/24
* Description: Parses a duration token in the format
*              "minutes:seconds" and returns a Duration
*              struct.
* Input parameters: durationToken - A character array
*                        containing the duration token.
* Returns: A Duration struct representing the parsed
*          duration.
* Preconditions: The input durationToken must be a valid
*                string representing a duration in the
*                format "minutes:seconds".
* Postconditions: None.
*************************************************************/

Duration getDuration(char durationToken[50]) {//first iteration of getDuration(GEN 1)
    Duration duration;//initialize Duration struct
    sscanf(durationToken, "%d:%d", &duration.minutes, &duration.seconds);//set Duration to duration token
    return duration;//return duration
}

/*************************************************************
* Function: getRecord()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Constructs a Record struct from the provided
*              tokens representing artist, album title,
*              song title, genre, duration, times played,
*              and rating.
* Input parameters: artistToken - A character array
*                        containing the artist's name.
*                    albumTitleToken - A character array
*                        containing the album title.
*                    songTitleToken - A character array
*                        containing the song title.
*                    genreToken - A character array
*                        containing the genre.
*                    durationToken - A character array
*                        containing the duration token.
*                    timesPlayedToken - A character array
*                        containing the number of times
*                        played.
*                    ratingToken - A character array
*                        containing the rating.
* Returns: A Record struct constructed from the provided
*          tokens.
* Preconditions: The input tokens must be valid strings
*                representing their respective data fields.
* Postconditions: None.
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
* Function: createRecord()
* Date Created: 1/27/24
* Date Last Modified: 1/27/24
* Description: Prompts the user to input details of a new
*              record and creates a Record struct
*              accordingly.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: A new Record struct is created and added
*                 to the linked list pointed to by pList.
*************************************************************/

void createRecord(Node** pList) {
    //fgets(editArtist,sizeof(editArtist),stdin);
    //editArtist[strcspn(editArtist, "\n")] = '\0';
    int success = 0;
    char artistInsert[50];
    char albumTitleInsert[50];
    char songTitleInsert[50];
    char genreInsert[50];
    char durationInsert[50];
    char timesPlayedInsert[50];
    char ratingInsert[50];
    Record record;

    printf("|Artist Name:\n");
    fgets(artistInsert, sizeof(artistInsert), stdin);
    artistInsert[strcspn(artistInsert, "\n")] = '\0';

    printf("|Album Title:\n");
    fgets(albumTitleInsert, sizeof(albumTitleInsert), stdin);
    albumTitleInsert[strcspn(albumTitleInsert, "\n")] = '\0';

    printf("|Song Title:\n");
    fgets(songTitleInsert, sizeof(songTitleInsert), stdin);
    songTitleInsert[strcspn(songTitleInsert, "\n")] = '\0';

    printf("|Genre:\n");
    fgets(genreInsert, sizeof(genreInsert), stdin);
    genreInsert[strcspn(genreInsert, "\n")] = '\0';

    printf("|Song Length [Minutes:Seconds]:\n");
    fgets(durationInsert, sizeof(durationInsert), stdin);
    durationInsert[strcspn(durationInsert, "\n")] = '\0';

    printf("|Times Played:\n");
    fgets(timesPlayedInsert, sizeof(timesPlayedInsert), stdin);
    timesPlayedInsert[strcspn(timesPlayedInsert, "\n")] = '\0';

    printf("|Rating [1-5]:\n");
    fgets(ratingInsert, sizeof(ratingInsert), stdin);
    ratingInsert[strcspn(ratingInsert, "\n")] = '\0';

    record = getRecord(artistInsert, albumTitleInsert, songTitleInsert,
        genreInsert, durationInsert, timesPlayedInsert,
        ratingInsert);

    insert(pList, record);

}

/*************************************************************
* Function: loadRecords()
* Date Created: 1/30/24
* Date Last Modified: 1/30/24
* Description: Reads records from a file stream and inserts
*              them into a linked list.
* Input parameters: inputStream - Pointer to a FILE stream
*                                 from which records are
*                                 read.
*                   pList - Pointer to a pointer to the
*                           beginning of a linked list of
*                           records.
* Returns: None.
* Preconditions: The inputStream must be opened and
*                pointing to a valid file containing records.
* Postconditions: Records from the file are inserted into
*                 the linked list pointed to by pList.
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
* Function: storeRecords()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Stores records from a linked list into a file
*              stream.
* Input parameters: outputStream - Pointer to a character
*                                   array containing the
*                                   filename to write the
*                                   records to.
*                   pList - Pointer to the beginning of a
*                           linked list of records.
* Returns: 1 if records are successfully stored, 0 otherwise.
* Preconditions: The outputStream must point to a valid
*                character array representing a filename,
*                and pList must point to a valid linked list
*                of records.
* Postconditions: Records from the linked list are written
*                 to the file specified by outputStream.
*************************************************************/

int storeRecords(char* outputStream, Node* pList) {
    FILE* output = fopen(outputStream, "w+");
    Node* pCurr = pList;
    int success = 0;
    //go to the end of the list
    while (pCurr->pNext != NULL) {
        pCurr = pCurr->pNext;
    }
    //print list from last to first
    while (pCurr != NULL) {
        fprintf(output, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", pCurr->record.artist, pCurr->record.albumTitle,
            pCurr->record.songTitle, pCurr->record.genre, pCurr->record.songLength.minutes,
            pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);
        pCurr = pCurr->pPrev; //move backwards in the list
        success = 1;
    }
    fclose(output);
    return success;
}

/*************************************************************
* Function: insert()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Inserts a new record into a linked list.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   insertRecord - The record to be inserted.
* Returns: None.
* Preconditions: The rating and timesPlayed fields of
*                insertRecord must be within valid ranges
*                (0-5 for rating, non-negative for
*                timesPlayed).
* Postconditions: If insertRecord is valid, it is inserted
*                 at the beginning of the linked list
*                 pointed to by pList.
*************************************************************/

void insert(Node** pList, Record insertRecord) {
    if (insertRecord.rating < 0 || insertRecord.timesPlayed < 0 || insertRecord.rating > 5) {//validation check
        printf("|Invalid record\n");
        return;
    }
    Node* insertionNode = (Node*)malloc(sizeof(Node));//initialize node
    insertionNode->record = insertRecord;//set record of node to insertRecord
    insertionNode->pNext = (*pList);//set node to the top of the linked list
    insertionNode->pPrev = NULL;//set previous of node to NULL
    if ((*pList) != NULL) {//check if linked list is not empty
        (*pList)->pPrev = insertionNode;//set node to the top of the linked list
    }
    (*pList) = insertionNode;
}

/*************************************************************
* Function: deleteRecord()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Deletes a record from a linked list based
*              on the song title.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   delete - Pointer to a character array
*                            containing the song title of
*                            the record to be deleted.
* Returns: 1 if the record is successfully deleted, 0
*          otherwise.
* Preconditions: None.
* Postconditions: If a record with the specified song title
*                 is found in the linked list pointed to by
*                 pList, it is deleted. Otherwise, no
*                 changes are made.
*************************************************************/

int deleteRecord(Node** pList, char* delete) {
    Node* pCurr = *pList;
    int foundRecord = 0;
    int success = 0;

    if (pCurr != NULL && strcmp(pCurr->record.songTitle, delete) == 0) {//first case scenario
        *pList = pCurr->pNext;
        if (pCurr->pNext != NULL) {
            pCurr->pNext->pPrev = NULL;
        }
        free(pCurr);
        success = 1;
        return success;
    }

    while (pCurr != NULL) {//traverse through
        if (strcmp(pCurr->record.songTitle, delete) == 0) {
            foundRecord = 1;
            success = 1;
            if (pCurr->pPrev != NULL) {
                pCurr->pPrev->pNext = pCurr->pNext;
            }
            if (pCurr->pNext != NULL) {
                pCurr->pNext->pPrev = pCurr->pPrev;
            }

            free(pCurr);
            break;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("NO RECORDS FOUND\n");
    }
    return success;

}

/*************************************************************
* Function: editRecord()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Allows the user to edit the contents of a
*              record in the linked list.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The specified record in the linked list
*                 pointed to by pList is edited according
*                 to user input.
*************************************************************/

void editRecord(Node** pList) {
    char editArtist[50] = "";
    char editRecordSelection[50] = "";
    char inputEdit[50] = "";
    int found = 0;
    int artist = 0;
    int editSelected = 0;
    int edited = 0;
    int editType = 0;

    char editTypes[][100] = { "Artist","Album Title","Song Title","Genre","Song Length","Times played","Rating" };
    printf("|Which Artist's records do you want to edit?\n");
    do {
        fgets(editArtist, sizeof(editArtist), stdin);
        //str[strcspn(str, "\n")] = '\0';
        editArtist[strcspn(editArtist, "\n")] = '\0';
        //scanf("%s",editArtist);
        found = displayArtistRecords(*pList, editArtist);
        if (found == 1) {
            artist = 1;
        }
    } while (!artist);
    //displayArtistRecords(*pList,editArtist);
    printf("What Record do you want to edit?\n");
    do {
        fgets(editRecordSelection, sizeof(editRecordSelection), stdin);
        editRecordSelection[strcspn(editRecordSelection, "\n")] = '\0';
        //scanf("%s",editRecordSelection);
        editSelected = checkRecord(*pList, editRecordSelection);
        if (editSelected) {
            edited = 1;
        }
    } while (!edited);
    displayEditMenu(editRecordSelection);
    editType = getEditAction();
    printf("|Enter %s edit\n", editTypes[editType - 1]);
    //scanf("%s",inputEdit);
    fgets(inputEdit, sizeof(inputEdit), stdin);
    inputEdit[strcspn(inputEdit, "\n")] = '\0';
    editRecordContents(pList, editRecordSelection, inputEdit, editType);
}

/*************************************************************
* Function: editRecordContents()
* Date Created: 1/27/24
* Date Last Modified: 2/9/24
* Description: Edits the contents of a record in the linked
*              list based on the specified song title and
*              edit type.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   songTitle - Pointer to a character array
*                              containing the song title of
*                              the record to be edited.
*                   input - Pointer to a character array
*                           containing the new content for
*                           the specified field.
*                   editType - An integer representing the
*                              type of field to be edited.
* Returns: 1 if the record is found and edited, 0 otherwise.
* Preconditions: None.
* Postconditions: If a record with the specified song title
*                 is found in the linked list pointed to by
*                 pList, its content is updated according
*                 to the specified field and input.
*************************************************************/

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
            printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
                pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);
            foundRecord = 1;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("|No records found\n");
    }
    return foundRecord;
}

/*************************************************************
* Function: rateRecord()
* Date Created: 1/28/24
* Date Last Modified: 2/13/24
* Description: Allows the user to rate a record in the
*              linked list.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The specified record in the linked list
*                 pointed to by pList is rated by the user.
*************************************************************/

void rateRecord(Node** pList) {
    char recordToRate[50];
    char recordRating[50];
    int insertRating = 0;
    Node* pCurr = *pList;
    int found = 0;
    printf("|Enter record to rate:\n");
    fgets(recordToRate, sizeof(recordToRate), stdin);
    recordToRate[strcspn(recordToRate, "\n")] = '\0';
    found = checkRecord(*pList, recordToRate);
    if (found) {

        while (!(insertRating >= 1 && insertRating <= 5)) {
            printf("|Enter rating [1-5]:\n");
            fgets(recordRating, sizeof(recordRating), stdin);
            recordRating[strcspn(recordRating, "\n")] = '\0';
            insertRating = atoi(recordRating);
        }

        while (pCurr != NULL) {
            if (strcmp(pCurr->record.songTitle, recordToRate) == 0) {
                pCurr->record.rating = atoi(recordRating);
                break;
            }
            pCurr = pCurr->pNext;
        }
    }
}

/*************************************************************
* Function: playSpecificRecord()
* Date Created: 1/28/24
* Date Last Modified: 2/13/24
* Description: Plays a specific record from the linked list
*              based on the specified song title.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The specified record in the linked list
*                 pointed to by pList is played.
*************************************************************/

void playSpecificRecord(Node** pList) {
    char recordToPlay[50];
    int found = 0;
    Node* pCurr = *pList;
    printf("|Record to play:\n");
    fgets(recordToPlay, sizeof(recordToPlay), stdin);
    recordToPlay[strcspn(recordToPlay, "\n")] = '\0';
    found = checkRecord(*pList, recordToPlay);
    if (found) {
        while (pCurr != NULL) {
            if (strcmp(pCurr->record.songTitle, recordToPlay) == 0) {
                playRecord(pCurr->record);
            }
        }
    }

}

/*************************************************************
* Function: playRecord()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Simulates playing a record by displaying its
*              details on the screen.
* Input parameters: record - The record to be played.
* Returns: None.
* Preconditions: None.
* Postconditions: The details of the specified record are
*                 displayed on the screen.
*************************************************************/

void playRecord(Record record) {
    clearScreen();
    printf("|Playing Record\n");
    printf("|Artist: %s\n", record.artist);
    printf("|Album Title: %s\n", record.albumTitle);
    printf("|Song Title: %s\n", record.songTitle);
    printf("|Genre %s\n", record.genre);
    printf("|Duration: %d:%d\n", record.songLength.minutes, record.songLength.seconds);
    printf("|Times Played: %d\n", record.timesPlayed);
    printf("|Rating: %d\n", record.rating);
    printf("|Imagine music playing\n");
    Sleep(2000);
}

/*************************************************************
* Function: displayMenu()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays the main menu of the Digital Music
*              Manager program.
* Input parameters: None.
* Returns: None.
* Preconditions: None.
* Postconditions: The main menu is displayed on the screen.
*************************************************************/

void displayMenu() {
    printf("|Digital Music Manager\n");
    printf("|1. Load\n");
    printf("|2. Store\n");
    printf("|3. Display\n");
    printf("|4. Insert\n");
    printf("|5. Delete\n");
    printf("|6. Edit\n");
    printf("|7. Sort\n");
    printf("|8. Rate\n");
    printf("|9. Play\n");
    printf("|10. Shuffle\n");
    printf("|11. Test Cases\n");
    printf("|12. Exit\n");
}

/*************************************************************
* Function: displayRecordsPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to choose
*              whether to display all records or records
*              by a specific artist.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The user's choice is processed, and the
*                 corresponding records are displayed on
*                 the screen.
*************************************************************/

void displayRecordsPrompt(Node** pList) {
    int choice = 0;
    int chosen = 0;
    int found = 0;
    char artist[50];
    char userInput[50];
    clearScreen();
    do {
        printf("|1. Display all records\n");
        printf("|2. Display Artist's records\n");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';
        choice = atoi(userInput);
        switch (choice) {
        case 1:
            displayAllRecords(*pList);
            chosen = 1;
            break;

        case 2:
            while (!found) {
                printf("|Enter Artist:\n");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = '\0';
                found = checkArtist(*pList, artist);
            }
            if (found) {
                displayArtistRecords(*pList, artist);
            }
            break;

        default:
            printf("|Invalid Selection\n");
            break;


        }
    } while (chosen != 1);
}

/*************************************************************
* Function: deleteRecordPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to choose a
*              record to delete and deletes it from the
*              linked list if found.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: If a record with the specified title is
*                 found in the linked list pointed to by
*                 pList, it is deleted. Otherwise, no
*                 changes are made.
*************************************************************/

void deleteRecordPrompt(Node** pList) {
    char deleteRecordChoice[50];
    clearScreen();
    displayAllRecords(*pList);
    printf("|Enter record to delete\n");
    fgets(deleteRecordChoice, sizeof(deleteRecordChoice), stdin);
    deleteRecordChoice[strcspn(deleteRecordChoice, "\n")] = '\0';
    int found = checkRecord(*pList, deleteRecordChoice);
    if (found) {
        deleteRecord(pList, deleteRecordChoice);
    }
}

/*************************************************************
* Function: editRecordPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to choose a
*              record to edit and initiates the editing
*              process.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The user is prompted to choose a record
*                 to edit, and the editing process is
*                 initiated.
*************************************************************/

void editRecordPrompt(Node** pList) {
    char editRecordChoice[50];
    clearScreen();
    displayAllRecords(*pList);
    editRecord(pList);
}

/*************************************************************
* Function: sortRecordPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to choose a
*              sorting criteria and order, then sorts the
*              records in the linked list accordingly.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are sorted according to the
*                 user's choice of criteria and order.
*************************************************************/

void sortRecordPrompt(Node** pList) {
    char userInput[50];
    char userOrder[50];
    int sort = 0;
    int order = 0;
    int valid = 0;
    clearScreen();
    do {
        printf("|Sort Record\n");
        printf("|1. Sort records alphabetically by Artist\n");
        printf("|2. Sort records alphabetically by Album Title\n");
        printf("|3. Sort records by rating\n");
        printf("|4. Sort records by times played\n");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';
        sort = atoi(userInput);
        printf("|Ascending [1] or Descending [0] order? [1/0]");
        fgets(userOrder, sizeof(userOrder), stdin);
        userOrder[strcspn(userOrder, "\n")] = '\0';
        order = atoi(userOrder);
        switch (sort) {
        case 1:
            sortRecordsAlphabeticallyByArtist(pList, order);
            valid = 1;
            break;

        case 2:
            sortRecordsAlphabeticallyByAlbumTitle(pList, order);
            valid = 1;
            break;

        case 3:
            sortRecordsByRating(pList, order);
            valid = 1;
            break;

        case 4:
            sortRecordsByTimesPlayed(pList, order);
            valid = 1;
            break;

        default:
            printf("|Enter valid option\n");
            break;
        }
    } while (valid != 1);
    //deleteRecordChoice[strcspn(deleteRecordChoice,"\n")] = '\0';
}

/*************************************************************
* Function: rateRecordPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to rate a
*              record and rates it in the linked list
*              accordingly.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The user is prompted to rate a record,
*                 and its rating is updated in the linked
*                 list pointed to by pList.
*************************************************************/

void rateRecordPrompt(Node** pList) {
    clearScreen();
    displayAllRecords(*pList);
    rateRecord(pList);
}

/*************************************************************
* Function: playRecordPrompt()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Displays a prompt for the user to choose a
*              record to play and plays it in the linked
*              list accordingly.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The user is prompted to choose a record
*                 to play, and it is played in the linked
*                 list pointed to by pList.
*************************************************************/

void playRecordPrompt(Node** pList) {
    char recordToPlay[50];
    int exit = 0;
    int found = 0;
    Node* pHead = *pList;
    Node* pCurr = *pList;
    clearScreen();
    printf("|Records: \n");
    displayAllRecords(*pList);
    while (!found) {
        printf("|Enter Record to play: \n");
        fgets(recordToPlay, sizeof(recordToPlay), stdin);
        recordToPlay[strcspn(recordToPlay, "\n")] = '\0';
        found = checkRecord(*pList, recordToPlay);
    }
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.songTitle, recordToPlay) == 0) {
            playRecord(pCurr->record);
            break;
        }
        pCurr = pCurr->pNext;
    }
    while (pCurr != NULL) {
        playRecord(pCurr->record);
        pCurr = pCurr->pNext;
    }
}

/*************************************************************
* Function: countRecords()
* Date Created: 2/9/24
* Date Last Modified: 2/9/24
* Description: Counts the number of records in a linked
*              list.
* Input parameters: pList - Pointer to the beginning of a
*                            linked list of records.
* Returns: The number of records in the linked list.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

int countRecords(Node* pList) {
    int count = 0;
    Node* pCurr = pList;
    while (pCurr != NULL) {
        count++;
        pCurr = pCurr->pNext;
    }
    return count;
}

/*************************************************************
* Function: clearLinkedList()
* Date Created: 2/13/24
* Date Last Modified: 2/13/24
* Description: Frees the memory occupied by all nodes in a
*              linked list and sets the list to NULL.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: All memory allocated for nodes in the
*                 linked list pointed to by pList is freed,
*                 and pList is set to NULL.
*************************************************************/

void clearLinkedList(Node** pList) {
    Node* pCurr = *pList;
    Node* pNext;
    while (pCurr != NULL) {
        pNext = pCurr->pNext;
        free(pCurr);
        pCurr = pNext;
    }
}

/*************************************************************
* Function: setLinkedList()
* Date Created: 2/13/24
* Date Last Modified: 2/13/24
* Description: Sets the records in a linked list to the
*              contents of an array of records.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   recordArr - Array of records to set in
*                               the linked list.
*                   size - The size of the recordArr array.
* Returns: None.
* Preconditions: The size parameter must be greater than
*                zero or non-negative, and recordArr must
*                contain at least size records.
* Postconditions: The records in the linked list pointed to
*                 by pList are set to the contents of
*                 recordArr.
*************************************************************/

void setLinkedList(Node** pList, Record recordArr[], int size) {
    if (size == 0 || size < 0) {
        return;
    }
    Node* pCurr = *pList;
    int index = 0;
    while (pCurr != NULL) {
        pCurr->record = recordArr[index];
        index++;
        pCurr = pCurr->pNext;
    }
}

/*************************************************************
* Function: sortRecordsAlphabeticallyByArtist()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Sorts the records in the linked list
*              alphabetically by artist name in either
*              ascending or descending order.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   order - An integer representing the
*                           sorting order. 1 for ascending
*                           and 0 for descending.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are sorted alphabetically by
*                 artist name according to the specified
*                 order.
*************************************************************/

void sortRecordsAlphabeticallyByArtist(Node** pList, int order) {
    int recordAmount = countRecords(*pList);
    Record* recordArr = malloc(sizeof(Record) * recordAmount);
    Node* pCurr = *pList;
    int index = 0;
    while (pCurr != NULL) {
        recordArr[index] = pCurr->record;
        index++;
        pCurr = pCurr->pNext;
    }
    if (order == 1) {//SORT ALPHABETICALLY IN ASCENDING ORDER
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (strcmp(recordArr[i].artist, recordArr[j].artist) > 0) {
                    Record tempRecord;
                    tempRecord = recordArr[i];
                    recordArr[i] = recordArr[j];
                    recordArr[j] = tempRecord;
                }
            }
        }
    }
    if (order == 0) {//SORT ALPHABETICALLY IN DESCENDING ORDER
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (strcmp(recordArr[i].artist, recordArr[j].artist) < 0) {
                    Record tempRecord;
                    tempRecord = recordArr[i];
                    recordArr[i] = recordArr[j];
                    recordArr[j] = tempRecord;
                }
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", recordArr[i].artist, recordArr[i].albumTitle,
            recordArr[i].songTitle, recordArr[i].genre,
            recordArr[i].songLength.minutes, recordArr[i].songLength.seconds,
            recordArr[i].timesPlayed, recordArr[i].rating);
    }
    setLinkedList(pList, recordArr, recordAmount);//set linked List to sorted array
    free(recordArr);
}

/*************************************************************
* Function: sortRecordsAlphabeticallyByAlbumTitle()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Sorts the records in the linked list
*              alphabetically by album title in either
*              ascending or descending order.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   order - An integer representing the
*                           sorting order. 1 for ascending
*                           and 0 for descending.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are sorted alphabetically by
*                 album title according to the specified
*                 order.
*************************************************************/

void sortRecordsAlphabeticallyByAlbumTitle(Node** pList, int order) {
    int recordAmount = countRecords(*pList);
    Record* recordArr = malloc(sizeof(Record) * recordAmount);
    Node* pCurr = *pList;
    int index = 0;
    Record tempRecord;
    while (pCurr != NULL) {
        recordArr[index] = pCurr->record;
        index++;
        pCurr = pCurr->pNext;
    }
    if (order == 1) {//SORT ALPHABETICALLY IN ASCENDING ORDER
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (strcmp(recordArr[i].albumTitle, recordArr[j].albumTitle) > 0) {
                    tempRecord = recordArr[i];
                    recordArr[i] = recordArr[j];
                    recordArr[j] = tempRecord;
                }
            }
        }
    }
    if (order == 0) {//SORT ALPHABETICALLY IN DESCENDING ORDER
        for (int i = 0; i < index - 1; i++) {
            for (int j = i + 1; j < index; j++) {
                if (strcmp(recordArr[i].albumTitle, recordArr[j].albumTitle) < 0) {
                    tempRecord = recordArr[i];
                    recordArr[i] = recordArr[j];
                    recordArr[j] = tempRecord;
                }
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", recordArr[i].artist, recordArr[i].albumTitle,
            recordArr[i].songTitle, recordArr[i].genre,
            recordArr[i].songLength.minutes, recordArr[i].songLength.seconds,
            recordArr[i].timesPlayed, recordArr[i].rating);
    }
    setLinkedList(pList, recordArr, recordAmount);//set linked list to sorted array
    free(recordArr);
}

/*************************************************************
* Function: sortRecordsByRating()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Sorts the records in the linked list
*              by rating in either ascending or descending
*              order.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   order - An integer representing the
*                           sorting order. 1 for ascending
*                           and 0 for descending.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are sorted by rating according
*                 to the specified order.
*************************************************************/

void sortRecordsByRating(Node** pList, int order) {
    int recordAmount = countRecords(*pList);
    Node* pCurr = *pList;
    Record* recordArr = malloc(sizeof(Record) * recordAmount);
    int index = 0;
    Record tempRecord;
    while (pCurr != NULL) {
        recordArr[index] = pCurr->record;
        index++;
        pCurr = pCurr->pNext;
    }

    if (order == 1) {//SORT IN ASCENDING ORDER
        for (int i = 0; i < recordAmount - 1; i++) {
            for (int j = 0; j < recordAmount - i - 1; j++) {
                if (recordArr[j].rating > recordArr[j + 1].rating) {
                    tempRecord = recordArr[j];
                    recordArr[j] = recordArr[j + 1];
                    recordArr[j + 1] = tempRecord;
                }
            }
        }
    }
    if (order == 0) {//SORT IN DESCENDING ORDER
        for (int i = 0; i < recordAmount - 1; i++) {
            for (int j = 0; j < recordAmount - i - 1; j++) {
                if (recordArr[j].rating < recordArr[j + 1].rating) {
                    tempRecord = recordArr[j];
                    recordArr[j] = recordArr[j + 1];
                    recordArr[j + 1] = tempRecord;
                }
            }
        }
    }
    for (int i = 0; i < index; i++) {
        printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", recordArr[i].artist, recordArr[i].albumTitle,
            recordArr[i].songTitle, recordArr[i].genre,
            recordArr[i].songLength.minutes, recordArr[i].songLength.seconds,
            recordArr[i].timesPlayed, recordArr[i].rating);
    }
    setLinkedList(pList, recordArr, recordAmount);//set linked list to sorted array
    free(recordArr);
}

/*************************************************************
* Function: sortRecordsByTimesPlayed()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Sorts the records in the linked list
*              by times played in either ascending or
*              descending order.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
*                   order - An integer representing the
*                           sorting order. 1 for ascending
*                           and 0 for descending.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are sorted by times played
*                 according to the specified order.
*************************************************************/

void sortRecordsByTimesPlayed(Node** pList, int order) {
    int recordAmount = countRecords(*pList);
    Node* pCurr = *pList;
    Record* recordArr = malloc(sizeof(Record) * recordAmount);
    int index = 0;
    Record tempRecord;
    while (pCurr != NULL) {
        recordArr[index] = pCurr->record;
        index++;
        pCurr = pCurr->pNext;
    }

    if (order == 1) {//SORT IN ASCENDING ORDER
        for (int i = 0; i < recordAmount - 1; i++) {
            for (int j = 0; j < recordAmount - i - 1; j++) {
                if (recordArr[j].timesPlayed > recordArr[j + 1].timesPlayed) {
                    tempRecord = recordArr[j];
                    recordArr[j] = recordArr[j + 1];
                    recordArr[j + 1] = tempRecord;
                }
            }
        }
    }
    if (order == 0) {//SORT IN DESCENDING ORDER
        for (int i = 0; i < recordAmount - 1; i++) {
            for (int j = 0; j < recordAmount - i - 1; j++) {
                if (recordArr[j].timesPlayed < recordArr[j + 1].timesPlayed) {
                    tempRecord = recordArr[j];
                    recordArr[j] = recordArr[j + 1];
                    recordArr[j + 1] = tempRecord;
                }
            }
        }
    }
    for (int i = 0; i < index; i++) {
        printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", recordArr[i].artist, recordArr[i].albumTitle,
            recordArr[i].songTitle, recordArr[i].genre,
            recordArr[i].songLength.minutes, recordArr[i].songLength.seconds,
            recordArr[i].timesPlayed, recordArr[i].rating);
    }
    setLinkedList(pList, recordArr, recordAmount);//set linked list to sorted array
    free(recordArr);
}

/*************************************************************
* Function: shuffleRecords()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Shuffles the records in the linked list and
*              plays them in the shuffled order.
* Input parameters: pList - Pointer to a pointer to the
*                            beginning of a linked list of
*                            records.
* Returns: None.
* Preconditions: None.
* Postconditions: The records in the linked list pointed to
*                 by pList are shuffled and played in the
*                 shuffled order.
*************************************************************/

void shuffleRecords(Node** pList) {
    int recordAmount = countRecords(*pList);
    Node* pCurr = *pList;
 
    int *assignedPositions = malloc(sizeof(Record) * recordAmount);
    Record* recordArr = malloc(sizeof(Record) * recordAmount);
    int index = 0;
    Record tempRecord;

    //initialize assigned positions
    for (int i = 0; i < recordAmount; i++) {
        assignedPositions[i] = 0;
    }


    while (pCurr != NULL) {
        recordArr[index] = pCurr->record;
        index++;
        pCurr = pCurr->pNext;
    }
    for (int i = 0; i < recordAmount; i++) {
        int newPosition;
        do {
            newPosition = rand() % recordAmount + 1;
        } while (assignedPositions[newPosition - 1] == 1);
        recordArr[i].position = newPosition;
        assignedPositions[newPosition - 1] = 1;

    }
    for (int i = 0; i < recordAmount - 1; i++) {
        for (int j = 0; j < recordAmount - i - 1; j++) {
            if (recordArr[j].position > recordArr[j + 1].position) {
                tempRecord = recordArr[j];
                recordArr[j] = recordArr[j + 1];
                recordArr[j + 1] = tempRecord;
            }
        }
    }
    setLinkedList(pList, recordArr, recordAmount);

    printf("|Shuffle records\n");
    for (int i = 0; i < index; i++) {
        playRecord(recordArr[i]);
    }
    free(recordArr);
}

/*************************************************************
* Function: displayAllRecords()
* Date Created: 1/28/24
* Date Last Modified: 2/13/24
* Description: Displays all records in the linked list.
* Input parameters: pList - Pointer to the beginning of a
*                            linked list of records.
* Returns: None.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

void displayAllRecords(Node* pList) {
    Node* pCurr = pList;//set current pointer to the top of the linked list

    while (pCurr != NULL) {//display node data
        printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
            pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);

        pCurr = pCurr->pNext;//index to next node
    }
}

/*************************************************************
* Function: displayArtistRecords()
* Date Created: 1/27/24
* Date Last Modified: 2/13/24
* Description: Displays all records by a specific artist.
* Input parameters: pList - Pointer to the beginning of a
*                            linked list of records.
*                   artist - Name of the artist to display
* Returns: 1 if records by the specified artist are found,
*          0 otherwise.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

int displayArtistRecords(Node* pList, char* artist) {
    Node* pCurr = pList;
    int foundRecord = 0;
    printf("Records by %s\n", artist);
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.artist, artist) == 0) {
            foundRecord = 1;
            printf("|%s|%s|%s|%s|%d:%d|%d|%d\n", pCurr->record.artist, pCurr->record.albumTitle, pCurr->record.songTitle, pCurr->record.genre,
                pCurr->record.songLength.minutes, pCurr->record.songLength.seconds, pCurr->record.timesPlayed, pCurr->record.rating);
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        printf("NO RECORDS FOUND\n");
    }
    return foundRecord;
}

/***************************************************************
* Function: checkRecord()
* Date Created: 1/27/24
* Date Last Modified: 1/27/24
* Description: Checks if a record with a specified song title
*              exists in the linked list.
* Input parameters: pList - Pointer to the beginning of a
*                            linked list of records.
*                   record - Song title to check.
* Returns: 1 if a record with the specified song title exists,
*          0 otherwise.
* Preconditions: None.
* Postconditions: None.
***************************************************************/

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
        printf("|No records found\n");
    }
    return foundRecord;
}

/***************************************************************
* Function: checkArtist()
* Date Created: 2/13/24
* Date Last Modified: 2/13/24
* Description: Checks if any records by a specified artist
*              exist in the linked list.
* Input parameters: pList - Pointer to the beginning of a
*                            linked list of records.
*                   artist - Artist name to check.
* Returns: 1 if any records by the specified artist exist,
*          0 otherwise.
* Preconditions: None.
* Postconditions: None.
***************************************************************/

int checkArtist(Node* pList, char* artist) {
    Node* pCurr = pList;
    int foundRecord = 0;
    while (pCurr != NULL) {
        if (strcmp(pCurr->record.artist, artist) == 0) {
            foundRecord = 1;
        }
        pCurr = pCurr->pNext;
    }
    if (!foundRecord) {
        foundRecord = 0;
        printf("|No records found\n");
    }
    return foundRecord;
}

/***************************************************************
* Function: displayEditMenu()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Displays a menu for editing different attributes
*              of a song based on its title.
* Input parameters: songTitle - The title of the song to edit.
* Returns: None.
* Preconditions: None.
* Postconditions: None.
***************************************************************/

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

/***************************************************************
* Function: getEditAction()
* Date Created: 2/11/24
* Date Last Modified: 2/13/24
* Description: Prompts the user to enter an action for editing
*              a song attribute and returns the chosen action.
* Input parameters: None.
* Returns: The chosen edit action as an integer.
* Preconditions: None.
* Postconditions: None.
***************************************************************/

int getEditAction() {
    int choice = 0;
    char choiceStr[10];
    int chosen = 0;
    do {
        printf("|Enter Edit Action [1-7]\n");
        fgets(choiceStr, sizeof(choiceStr), stdin);
        choiceStr[strcspn(choiceStr, "\n")] = '\0';
        choice = atoi(choiceStr);
        //scanf("%d",&choice);
        if (choice >= 1 && choice <= 7) {
            chosen = 1;
        }
    } while (!chosen);
    return choice;
}

/*************************************************************
* Function: clearScreen()
* Date Created: 2/9/24
* Date Last Modified: 2/9/24
* Description: This function clears the screen based on the
*              operating system.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: The screen is cleared.
*************************************************************/

void clearScreen() {//clear screen
#ifdef _WIN32
    // For Windows
    system("cls");
#elif __APPLE__
    // For macOS
    system("clear");
#else
    // ANSI escape codes to clear the screen
    printf("\033[H\033[J");
#endif
}

/*************************************************************
* Function: exitDigitalMusicManager()
* Date Created: 2/9/24
* Date Last Modified: 2/13/24
* Description: Exits the digital music manager program,
*             storing records and closing the input stream.
* Input parameters:
*     - inputStream: Pointer to the input stream file.
*     - pList: Pointer to the linked list storing music records.
* Returns: Void
* Preconditions: None
* Postconditions: Records are stored, input stream is closed,
*                 and program exits.
*************************************************************/

void exitDigitalMusicManager(FILE* inputStream, Node* pList) {
    //storeRecords(inputStream,pList);
    storeRecords("musicPlayList.csv", pList);
    fclose(inputStream);
    exit(0);
}
