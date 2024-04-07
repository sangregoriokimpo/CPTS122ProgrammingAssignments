#include "functions.h"
#include "testCases.h"

int main() {
    srand((unsigned int)time(NULL));
    char inputLine[100];//input line
    int testInsertCase = 0;
    int testDeleteCase = 0;
    int testShuffleCase = 0;
    Node* pList = NULL;//initialize linked list
    FILE* inputStream = fopen("musicPlayList.csv", "r+");
    char playerChoice[50];
    int choice = 0;
    //    printf("|Digital Music Manager\n");
    //    printf("|1. Load\n");
    //    printf("|2. Store\n");
    //    printf("|3. Display\n");
    //    printf("|4. Insert\n");
    //    printf("|5. Delete\n");
    //    printf("|6. Edit\n");
    //    printf("|7. Sort\n");
    //    printf("|8. Rate\n");
    //    printf("|9. Play\n");
    //    printf("|10. Shuffle\n");
    //    printf("|11. Test Cases\n);
    //    printf("|11. Exit\n");
    do {
        //clearScreen();
        displayMenu();
        printf("|Enter option\n");
        fgets(playerChoice, sizeof(playerChoice), stdin);
        playerChoice[strcspn(playerChoice, "\n")] = '\0';
        choice = atoi(playerChoice);
        switch (choice) {
        case 1://load music
            loadRecords(inputStream, &pList);
            break;

        case 2://store records
            storeRecords("musicPlayList.csv", pList);
            break;

        case 3:
            displayRecordsPrompt(&pList);
            break;

        case 4://insert record
            createRecord(&pList);
            break;

        case 5://delete record
            deleteRecordPrompt(&pList);
            break;

        case 6://edit record
            editRecordPrompt(&pList);
            break;

        case 7://sort records
            sortRecordPrompt(&pList);
            break;

        case 8://rate records
            rateRecordPrompt(&pList);
            break;

        case 9://play records
            playRecordPrompt(&pList);
            break;

        case 10://shuffle records
            shuffleRecords(&pList);
            break;

        case 11://test cases
            testInsertCase = testInsert();
            testDeleteCase = testDelete();
            testShuffleCase = testShuffle();
            printf("Test Insert: %d\n", testInsertCase);
            printf("Test Delete: %d\n", testDeleteCase);
            printf("Test Shuffle: %d\n", testShuffleCase);
            break;

        case 12://exit digital music manager
            exitDigitalMusicManager(inputStream, pList);
            break;

        default:
            printf("|Invalid Selection\n");
            break;
        }
    } while (choice != 12);

    fclose(inputStream);
    return 0;
}


//    TRIAL 1 - test functions
//    srand((unsigned int)time(NULL));
//    char inputLine[100];//input line
//    Node *pList = NULL;//initialize linked list
//    FILE *inputStream = fopen("../musicPlayList.csv","r+");
//
//    loadRecords(inputStream,&pList);
//    displayAllRecords(pList);
//    printf("SORT RECORDS ALPHABETICALLY BY ARTIST IN ASCENDING ORDER\n");
//    sortRecordsAlphabeticallyByArtist(pList,1);
//    printf("SORT RECORDS ALPHABETICALLY BY ARTIST IN DESCENDING ORDER\n");
//    sortRecordsAlphabeticallyByArtist(pList,0);
//    printf("SORT RECORDS ALPHABETICALLY BY ALBUM TITLE IN ASCENDING ORDER\n");
//    sortRecordsAlphabeticallyByAlbumTitle(pList,1);
//    printf("SORT RECORDS ALPHABETICALLY BY ALBUM TITLE IN DESCENDING ORDER\n");
//    sortRecordsAlphabeticallyByAlbumTitle(pList,0);
//    printf("SORT RECORDS BY RATING IN ASCENDING ORDER\n");
//    sortRecordsByRating(pList,1);
//    printf("SORT RECORDS BY RATING IN DESCENDING ORDER\n");
//    sortRecordsByRating(pList,0);
//    printf("SORT RECORDS BY TIMES PLAYED IN ASCENDING ORDER\n");
//    sortRecordsByTimesPlayed(pList,1);
//    printf("SORT RECORDS BY TIMES PLAYED IN DESCENDING ORDER\n");
//    sortRecordsByTimesPlayed(pList,0);
//    printf("SHUFFLE RECORDS\n");
//    int n = rand() % 10;
//    printf("%d\n",n);
//    shuffleRecords(pList);
//
//    fclose(inputStream);
