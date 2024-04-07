#pragma once
//
// Created by Gregory Jabido on 3/6/24.
//

#ifndef JABIDO_PA5_TESTCASES_H
#define JABIDO_PA5_TESTCASES_H

#include "PA5Header.h"
#include "QueueNode.h"
#include "Queue.h"
#include "Data.h"
#include "GroceryItem.h"
#include "Simulator.h"


class TestCases {
public:
    // ## Run tests function
    void runTests();
    /*
    - One test case that executes your enqueue() operation on an empty queue
    - One test case that executes your enqueue() operation with one node in the queue
    - One test case that executes your dequeue() operation on a queue with one node
    - One test case that executes your dequeue() operation on a queue with two nodes
    - One test case that runs your simulation for 24 hours
     */
     // ## Various test cases
    void testEnqueueEmptyQueue();
    void testEnqueue();
    void testDequeueOneNode();
    void testDequeueTwoNode();
    void testSimulator();
private:
};


#endif //JABIDO_PA5_TESTCASES_H

