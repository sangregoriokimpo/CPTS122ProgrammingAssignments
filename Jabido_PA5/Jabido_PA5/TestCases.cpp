//
// Created by Gregory Jabido on 3/6/24.
//

#include "TestCases.h"

/*************************************************************
* Function: testEnqueueEmptyQueue()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Test function to enqueue a node into an empty queue.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: A node is enqueued into the empty queue,
* and the contents of the queue are printed.
*************************************************************/

void TestCases::testEnqueueEmptyQueue() {
    Queue tq;
    Data* c1 = new Data(1);
    QueueNode* tc1 = new QueueNode(c1);
    tc1->addRandomGroceryItems();
    tq.enqueue(tc1);
    cout << "|test enqueue on empty queue" << endl;
    tq.printQueue();
    if (!tq.isEmpty()) {
        cout << "|it worked" << endl;
    }
}

/*************************************************************
* Function: testEnqueue()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Test function to enqueue two nodes into a queue.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: Two nodes are enqueued into the queue,
* and the contents of the queue are printed.
*************************************************************/

void TestCases::testEnqueue() {
    Queue tq;
    Data* c1 = new Data(1);
    QueueNode* tc1 = new QueueNode(c1);
    tc1->addRandomGroceryItems();
    Data* c2 = new Data(2);
    QueueNode* tc2 = new QueueNode(c2);
    tc2->addRandomGroceryItems();
    tq.enqueue(tc1);
    tq.enqueue(tc2);
    cout << "|test enqueue with two nodes" << endl;
    tq.printQueue();
    if (!tq.isEmpty()) {
        cout << "|it worked" << endl;
    }
}

/*************************************************************
* Function: testDequeueOneNode()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Test function to dequeue one node from a queue.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: One node is dequeued from the queue.
*************************************************************/

void TestCases::testDequeueOneNode() {
    Queue tq;
    Data* c1 = new Data(1);
    QueueNode* tc1 = new QueueNode(c1);
    tc1->addRandomGroceryItems();
    tq.enqueue(tc1);
    cout << "|test dequeue with one node" << endl;
    tq.dequeue();
    tq.printQueue();
    if (tq.isEmpty()) {
        cout << "|it worked" << endl;
    }
}

/*************************************************************
* Function: testDequeueTwoNode()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Test function to dequeue two nodes from a queue.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: Two nodes are dequeued from the queue,
* and the contents of the queue are printed.
*************************************************************/

void TestCases::testDequeueTwoNode() {
    Queue tq;
    Data* c1 = new Data(1);
    QueueNode* tc1 = new QueueNode(c1);
    tc1->addRandomGroceryItems();
    Data* c2 = new Data(2);
    QueueNode* tc2 = new QueueNode(c2);
    tc2->addRandomGroceryItems();
    tq.enqueue(tc1);
    tq.enqueue(tc2);
    tq.dequeue();
    cout << "|test dequeue with two nodes" << endl;
    tq.printQueue();
    if (!tq.isEmpty()) {
        cout << "|it worked, there should be only one node" << endl;
    }
}

/*************************************************************
* Function: runTests()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Runs a menu-driven interface to execute various test cases.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: Test cases are executed based on user input
* until the exit option is chosen.
*************************************************************/

void TestCases::runTests() {
    bool exitFlag = false;
    int choice = 0;
    while (!exitFlag) {
        cout << "|Menu" << endl;
        cout << "|1. Test enqueue with empty queue" << endl;
        cout << "|2. Test enqueue with two nodes" << endl;
        cout << "|3. Test dequeue with one node" << endl;
        cout << "|4. Test dequeue with two nodes" << endl;
        cout << "|5. Run simulation" << endl;
        cout << "|6. Exit" << endl;
        cout << "|Enter Choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case 1:
            clearScreen();
            testEnqueueEmptyQueue();
            break;

        case 2:
            clearScreen();
            testEnqueue();
            break;

        case 3:
            clearScreen();
            testDequeueOneNode();
            break;

        case 4:
            clearScreen();
            testDequeueTwoNode();
            break;

        case 5:
            clearScreen();
            testSimulator();
            break;

        case 6:
            clearScreen();
            exitFlag = true;
            break;

        default:
            cout << "|Enter valid option" << endl;
            break;

        }

    }

}

/*************************************************************
* Function: testSimulator()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Executes a simulation using the Simulator
* class for a specified duration. In this case, 1440 minutes.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: A simulation is executed for
* the specified duration.
*************************************************************/

void TestCases::testSimulator() {
    Simulator s;
    s.runSimulation(1440);
}
