#pragma once
//
// Created by Gregory Jabido on 3/5/24.
//

#ifndef JABIDO_PA5_QUEUE_H
#define JABIDO_PA5_QUEUE_H
#include "PA5Header.h"
#include "QueueNode.h"
#include "Data.h"


class Queue {
public:
    // ## Constructor
    Queue();

    // ## Destructor
    ~Queue();

    // ## Queue functions
    void enqueue(Data* data, const string& groceryItem);
    void enqueue(Data* data);
    void enqueue(QueueNode* queueNode);
    void process(int currentTime);
    void dequeue();
    void printQueue();
    bool isEmpty();
private:
    QueueNode* pHead;
    QueueNode* pTail;
};


#endif //JABIDO_PA5_QUEUE_H

