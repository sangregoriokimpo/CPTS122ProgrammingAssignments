//
// Created by Gregory Jabido on 3/5/24.
//

#include "Queue.h"

/*************************************************************
* Function: Queue()
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Default constructor for the Queue class.
* Initializes pHead and pTail pointers to nullptr.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: The Queue object is properly
* initialized with pHead and pTail set to nullptr.
*************************************************************/

Queue::Queue() : pHead(nullptr), pTail(nullptr) {}

/*************************************************************
* Function: ~Queue()
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Destructor for the Queue class.
* Dequeues all nodes until the queue is empty.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: All nodes in the queue are dequeued,
* and memory is properly deallocated.
*************************************************************/

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

/*************************************************************
* Function: enqueue(Data *data, const string& groceryItem)
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Enqueues a new node with the
* provided data and grocery item into the queue.
* Input parameters:
*   - data: Pointer to the Data object to be
*     stored in the queue node.
*   - groceryItem: Reference to the string representing
*     the grocery item associated with the data.
* Returns: Void
* Preconditions: None
* Postconditions: A new node containing the provided
* data and grocery item is added to the end of the queue.
*************************************************************/

void Queue::enqueue(Data* data, const string& groceryItem) {
    bool success;
    success = false;
    QueueNode* enqueueNode = new QueueNode(data, groceryItem);
    if (isEmpty()) {
        pHead = enqueueNode;
        pTail = enqueueNode;
    }
    else {
        pTail->setPNext(enqueueNode);
        pTail = enqueueNode;
    }
}

/*************************************************************
* Function: dequeue()
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Dequeues the front node from the queue.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: The front node is removed from the queue,
* and memory is deallocated if necessary.
*************************************************************/

void Queue::dequeue() {
    if (!isEmpty()) {
        QueueNode* pTemp = pHead;
        pHead = pHead->getPNext();
        delete pTemp;
        if (isEmpty()) {
            pTail = nullptr;
        }
    }
}

/*************************************************************
* Function: printQueue()
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Prints the contents of the queue, including
* customer number, service time, and grocery list for each node.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: The contents of the queue are printed.
*************************************************************/

void Queue::printQueue() {
    QueueNode* pCurr = pHead;
    while (pCurr != nullptr) {
        cout << "|Customer " << pCurr->getPData()->getCustomerNumber() << endl;
        cout << "|Service Time " << pCurr->getPData()->getServiceTime() << endl;
        cout << "|Grocery List" << endl;
        pCurr->printGroceryItems();
        pCurr = pCurr->getPNext();
    }
}
/*************************************************************
* Function: isEmpty()
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Checks if the queue is empty.
* Input parameters: None
* Returns:
*   - bool: True if the queue is empty, false otherwise.
* Preconditions: None
* Postconditions: None
*************************************************************/

bool Queue::isEmpty() {
    return pHead == nullptr;
}

/*************************************************************
* Function: enqueue(Data *data)
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Enqueues a new node with the provided
* data into the queue.
* Input parameters:
*   - data: Pointer to the Data object to be stored
*   in the queue node.
* Returns: Void
* Preconditions: None
* Postconditions: A new node containing the provided data is
* added to the end of the queue.
*************************************************************/

void Queue::enqueue(Data* data) {
    QueueNode* enqueueNode = new QueueNode(data);
    if (isEmpty()) {
        pHead = enqueueNode;
        pTail = enqueueNode;
    }
    else {
        pTail->setPNext(enqueueNode);
        pTail = enqueueNode;
    }
}

/*************************************************************
* Function: enqueue(QueueNode *queueNode)
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Enqueues the provided queue node into the queue.
* Input parameters:
*   - queueNode: Pointer to the QueueNode object to be enqueued.
* Returns: Void
* Preconditions: None
* Postconditions: The provided queue node is added to the end of the queue.
*************************************************************/

void Queue::enqueue(QueueNode* queueNode) {
    if (isEmpty()) {
        pHead = queueNode;
        pTail = queueNode;
    }
    else {
        pTail->setPNext(queueNode);
        pTail = queueNode;
    }
}

/*************************************************************
* Function: process(int currentTime)
* Date Created: 3/5/24
* Date Last Modified: 3/11/24
* Description: Processes the queue by decrementing service
* times of customers and checking them out if their service time reaches zero.
* Input parameters:
    - currentTime: Integer representing the current simulation time.
* Returns: Void
* Preconditions: None
* Postconditions: Customers with zero service time are
* checked out from the queue.
*************************************************************/

void Queue::process(int currentTime) {
    if (isEmpty()) {
        return;
    }
    else {
        QueueNode* pCurr = pHead;
        QueueNode* pNext;
        while (pCurr != nullptr) {
            pNext = pCurr->getPNext(); 
            pCurr->getPData()->decrementServiceTime();
            if (pCurr->getPData()->getServiceTime() == 0) {
                cout << "|Customer " << pCurr->getPData()->getCustomerNumber() << " checked out at " << currentTime << " minutes" << endl;
                dequeue(); 
            }
            pCurr = pNext; 
        }
    }
    //if (isEmpty()) {
    //    return;
    //}
    //else {
    //    QueueNode* pCurr = pHead;
    //    while (pCurr != nullptr) {
    //        //cout << pCurr->getGroceryItem()->getItemName() << " " << pCurr->getPData()->getCustomerNumber() << " " << pCurr->getPData()->getServiceTime() << " " << pCurr->getPData()->getTotalTime() << " " << endl;
    //        if (pCurr != nullptr && pCurr->getServiceTime() > 0 && pCurr->getGroceryItem() != nullptr) {
    //            pCurr->getPData()->decrementServiceTime();
    //            //pCurr->getPData()->decrementServiceTime();
    //            if (pCurr->getPData()->getServiceTime() == 0) {
    //                cout << "Customer " << pCurr->getPData()->getCustomerNumber() << " checked out at " << currentTime << " minutes" << endl;
    //                dequeue();
    //            }
    //            pCurr = pCurr->getPNext();
    //        }
    //        
    //    }
    //}
}