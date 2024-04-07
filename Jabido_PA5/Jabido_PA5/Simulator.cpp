//
// Created by Gregory Jabido on 3/8/24.
//

#include "Simulator.h"

/*************************************************************
* Function: getTotalTime()
* Date Created: 3/8/24
* Date Last Modified: 3/10/24
* Description: Returns the total time elapsed in the simulation.
* Input parameters: None
* Returns: Integer representing the total time elapsed.
* Preconditions: The Simulator object must be properly initialized.
* Postconditions: None
*************************************************************/

int Simulator::getTotalTime() const {
    return totalTime;
}

/*************************************************************
* Function: setTotalTime(int totalTime)
* Date Created: 3/8/24
* Date Last Modified: 3/10/24
* Description: Sets the total time elapsed in the simulation.
* Input parameters:
    - totalTime: Integer representing the total time to set.
* Returns: Void
* Preconditions: None
* Postconditions: The total time of the Simulator object is updated.
*************************************************************/

void Simulator::setTotalTime(int totalTime) {
    Simulator::totalTime = totalTime;
}

/*************************************************************
* Function: ~Simulator()
* Date Created: 3/8/24
* Date Last Modified: 3/10/24
* Description: Destructor for the Simulator class.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: N/A
*************************************************************/

Simulator::~Simulator() {
    //Destructor
}

/*************************************************************
* Function: runSimulation(int duration)
* Date Created: 3/8/24
* Date Last Modified: 3/10/24
* Description: Runs a simulation of customer
* queues for a specified duration.
* Input parameters:
    - duration: Integer representing the duration of the simulation.
* Returns: Void
* Preconditions: None
* Postconditions: The simulation is executed for the
* specified duration.
*************************************************************/

void Simulator::runSimulation(int duration) {
    int expressLaneArrivalTime = generateRandomNumber(1, 5);
    int normalLaneArrivalTime = generateRandomNumber(3, 8);
    int timeElapsed = 0;
    int customerNumberExpressLane = 1;
    int customerNumberNormalLane = 1;

    for (; timeElapsed < duration; timeElapsed++) {
        if (timeElapsed % expressLaneArrivalTime == 0) {
            Data* pDataExpressLane = new Data(customerNumberExpressLane);
            //cout << pDataExpressLane->getCustomerNumber() << endl;
            //cout << pDataExpressLane->getServiceTime() << endl;
            //cout << pDataExpressLane->getTotalTime() << endl;
            QueueNode* expressLaneNode = new QueueNode(pDataExpressLane);
            expressLaneNode->addRandomGroceryItems();
            expressLaneNode->getPData()->setTotalTime(expressLaneArrivalTime + expressLaneNode->getServiceTime());
            expressQueue.enqueue(expressLaneNode);
            customerNumberExpressLane++;
            expressLaneArrivalTime = generateRandomNumber(1, 5);
        }
        if (timeElapsed % normalLaneArrivalTime == 0) {
            Data* pDataNormalLane = new Data(customerNumberNormalLane);
            //cout << pDataNormalLane->getCustomerNumber() << endl;
            //cout << pDataNormalLane->getServiceTime() << endl;
            //cout << pDataNormalLane->getTotalTime() << endl;
            QueueNode* normalLaneNode = new QueueNode(pDataNormalLane);
            normalLaneNode->addRandomGroceryItems();
            normalLaneNode->getPData()->setTotalTime(normalLaneArrivalTime + normalLaneNode->getServiceTime());
            normalQueue.enqueue(normalLaneNode);
            customerNumberNormalLane++;
            normalLaneArrivalTime = generateRandomNumber(3, 8);
        }

        expressQueue.process(timeElapsed);
        normalQueue.process(timeElapsed);
        if (timeElapsed % 10 == 0) {
            cout << "|Express Line" << endl;
            expressQueue.printQueue();
            cout << "|Normal Line" << endl;
            normalQueue.printQueue();
        }
    }
}

/*************************************************************
* Function: generateRandomNumber(int min, int max)
* Date Created: 3/8/24
* Date Last Modified: 3/10/24
* Description: Generates a random integer between min and max (inclusive).
* Input parameters:
    - min: Integer representing the minimum value of the range.
    - max: Integer representing the maximum value of the range.
* Returns: Integer
* Preconditions: None
* Postconditions: A random number is generated.
*************************************************************/

int Simulator::generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
