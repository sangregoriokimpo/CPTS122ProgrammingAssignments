#pragma once
//
// Created by Gregory Jabido on 4/5/24.
//

#ifndef JABIDO_PA7_NODE_H
#define JABIDO_PA7_NODE_H

#include "PA7Header.h"

template<typename T>
class Node {
private:
    T data;
    Node* pNext;

public:

    /*************************************************************
    * Function: Node(const T& data)
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Constructor for the Node class. Initializes the node with the given data and nullptr for the next pointer.
    * Input parameters:
    *     - const T& data: The data to be stored in the node.
    * Returns: N/A
    * Preconditions: None
    * Postconditions: The node is initialized with the given data and nullptr for the next pointer.
    *************************************************************/

    explicit Node(const T& data) : data(data), pNext(nullptr) {}

    /*************************************************************
    * Function: ~Node()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Destructor for the Node class.
    * Input parameters: None
    * Returns: N/A
    * Preconditions: None
    * Postconditions: Memory allocated to the node is deallocated.
    *************************************************************/

    virtual ~Node() {
        //Destructor
    }

    /*************************************************************
    * Function: getData()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Getter function for retrieving the data stored in the node.
    * Input parameters: None
    * Returns:
    *     - T&: Reference to the data stored in the node.
    * Preconditions: None
    * Postconditions: None
    *************************************************************/

    T& getData() {
        return data;
    }

    /*************************************************************
    * Function: setData(const T& data)
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Setter function for setting the data stored in the node.
    * Input parameters:
    *     - const T& data: The data to be set in the node.
    * Returns: N/A
    * Preconditions: None
    * Postconditions: The data stored in the node is updated with the given data.
    *************************************************************/

    void setData(const T& data) {
        Node::data = data;
    }

    /*************************************************************
    * Function: getPNext()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Getter function for retrieving the pointer to the next node.
    * Input parameters: None
    * Returns:
    *     - Node*: Pointer to the next node.
    * Preconditions: None
    * Postconditions: None
    *************************************************************/

    Node* getPNext() const {
        return pNext;
    }

    /*************************************************************
    * Function: setPNext(Node *pNext)
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Setter function for setting the pointer to the next node.
    * Input parameters:
    *     - Node *pNext: Pointer to the next node.
    * Returns: N/A
    * Preconditions: None
    * Postconditions: The pointer to the next node is updated with the given pointer.
    *************************************************************/

    void setPNext(Node* pNext) {
        Node::pNext = pNext;
    }


};


#endif //JABIDO_PA7_NODE_H

