#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
//#include <unistd.h>
#include <assert.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif // _WIN32


/*************************************************************
* Function: run_system ()                                   *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description:                                              *
* Input parameters:                                         *
* Returns:                                                  *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/

//(1) load - done
//(2) store - done
//(3) display - done
//(4) insert - done
//(5) delete - done
//(6) edit - done
//(7) sort - done
//(8) rate - done
//(9) play - done
//(10) shuffle - done
//(11) exit - done

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
    int position;
}Record;
typedef struct node {
    struct node* pPrev;
    struct node* pNext;
    Record record;
}Node;

//## FILE IO FUNCTIONS ##


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
int checkString(const char* str);

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
Duration getDuration(char durationToken[50]);

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
Record getRecord(char artistToken[50], char albumTitleToken[50], char songTitleToken[50], char genreToken[50],
    char durationToken[50], char timesPlayedToken[50], char ratingToken[50]);

//## RECORD FUNCTIONS ##

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
void createRecord(Node** pList);

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
void loadRecords(FILE* inputStream, Node** pList);

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
int storeRecords(char* outputStream, Node* pList);

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
void insert(Node** pList, Record insertRecord);

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
int deleteRecord(Node** pList, char* delete);

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
void editRecord(Node** pList);

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
int editRecordContents(Node** pList, char* songTitle, char* input, int editType);

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
void rateRecord(Node** pList);

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
void playSpecificRecord(Node** pList);

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
void playRecord(Record record);


//## MENU FUNCTIONS ##

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
void displayMenu();

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
void displayRecordsPrompt(Node** pList);

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
void deleteRecordPrompt(Node** pList);

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
void editRecordPrompt(Node** pList);

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
void sortRecordPrompt(Node** pList);

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
void rateRecordPrompt(Node** pList);

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
void playRecordPrompt(Node** pList);


//## LINKEDLIST FUNCTIONS ##

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
int countRecords(Node* pList);

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
void clearLinkedList(Node** pList);

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
void setLinkedList(Node** pList, Record recordArr[], int size);


//## SORT FUNCTIONS ##

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
void sortRecordsAlphabeticallyByArtist(Node** pList, int order);

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
void sortRecordsAlphabeticallyByAlbumTitle(Node** pList, int order);

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
void sortRecordsByRating(Node** pList, int order);

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
void sortRecordsByTimesPlayed(Node** pList, int order);


//## SHUFFLE FUNCTIONS ##

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
void shuffleRecords(Node** pList);



//## DISPLAY FUNCTIONS ##

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
void displayAllRecords(Node* pList);

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
int displayArtistRecords(Node* pList, char* artist);

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
int checkRecord(Node* pList, char* record);

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
int checkArtist(Node* pList, char* artist);

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
void displayEditMenu(char* songTitle);

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
int getEditAction();

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
void clearScreen();


//## EXIT FUNCTIONS ##

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
void exitDigitalMusicManager(FILE* inputStream, Node* pList);


#endif FUNCTIONS_H