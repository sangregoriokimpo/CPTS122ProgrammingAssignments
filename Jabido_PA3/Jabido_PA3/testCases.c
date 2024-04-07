#include "testCases.h"

int testInsert(void) {
    Node* pTestList = NULL;
    Record insertRecord = (Record){ "Perry, Katy","Witness","Chained to the Rhythm","pop",{36,4},-1,6 };
    insert(&pTestList, insertRecord);
    assert(pTestList == NULL);//check if linked list is empty because the record shouldn't have been inserted
    return 1;//test successful
}

int testDelete(void) {
    Node* pTestList = NULL;
    Record insertRecord1 = (Record){ "Perry, Katy","Witness","Chained to the Rhythm","pop",{36,4},3,5 };
    deleteRecord(&pTestList, "Chained to the Rhythm");
    assert(pTestList == NULL);
    return 1;//test successful
}

int testShuffle(void) {
    Node* pTestList = NULL;
    Record insertRecord1 = (Record){ "Perry, Katy","Witness","Chained to the Rhythm","pop",{36,4},3,5 };
    Record insertRecord2 = { "Swift, Taylor", "1989", "Shake It Off", "pop", {3, 39}, 100, 5 };
    Record insertRecord3 = { "Sheeran, Ed", "Divide", "Shape of You", "pop", {3, 54}, 75, 4 };
    insert(&pTestList, insertRecord1);
    insert(&pTestList, insertRecord2);
    insert(&pTestList, insertRecord3);
    shuffleRecords(&pTestList);
    assert(pTestList != NULL);
    return 1;//test successful
}