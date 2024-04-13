//
// Created by Gregory Jabido on 4/10/24.
//

#include "Node.h"

/*************************************************************
* Function: Node::Node(const string &mData)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Constructor for the Node class.
* Input parameters:
    - mData: A constant reference to a string containing the data for the node.
* Returns: None
* Preconditions: None
* Postconditions: A new Node object is created with the specified data and null left and right pointers.
*************************************************************/

Node::Node(const string& mData) : mData(mData) {
    this->mpLeft = nullptr;
    this->mpRight = nullptr;
}

/*************************************************************
* Function: Node::~Node()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Destructor for the Node class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

Node::~Node() {

}

/*************************************************************
* Function: Node::getMData() const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Getter function to retrieve the data associated with the Node.
* Input parameters: None
* Returns: A constant reference to a string containing the data.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& Node::getMData() const {
    return mData;
}

/*************************************************************
* Function: Node::setMData(const string &mData)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Setter function to set the data associated with the Node.
* Input parameters:
    - mData: A constant reference to a string containing the data to set.
* Returns: None
* Preconditions: None
* Postconditions: The data associated with the Node is updated.
*************************************************************/

void Node::setMData(const string& mData) {
    Node::mData = mData;
}


/*************************************************************
* Function: Node::setMpLeft(Node *mpLeft)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Setter function to set the left child pointer of the Node.
* Input parameters:
    - mpLeft: A pointer to the Node that will be the left child.
* Returns: None
* Preconditions: None
* Postconditions: The left child pointer of the Node is updated.
*************************************************************/

void Node::setMpLeft(Node* mpLeft) {
    Node::mpLeft = mpLeft;
}


/*************************************************************
* Function: Node::setMpRight(Node *mpRight)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Setter function to set the right child pointer of the Node.
* Input parameters:
    - mpRight: A pointer to the Node that will be the right child.
* Returns: None
* Preconditions: None
* Postconditions: The right child pointer of the Node is updated.
*************************************************************/

void Node::setMpRight(Node* mpRight) {
    Node::mpRight = mpRight;
}

/*************************************************************
* Function: Node::getMpLeft()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Getter function to retrieve a reference to the left child pointer of the Node.
* Input parameters: None
* Returns: A reference to a pointer to the left child Node.
* Preconditions: None
* Postconditions: None
*************************************************************/

Node*& Node::getMpLeft() {
    return mpLeft;
}

/*************************************************************
* Function: Node::getMpRight()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Getter function to retrieve a reference to the right child pointer of the Node.
* Input parameters: None
* Returns: A reference to a pointer to the right child Node.
* Preconditions: None
* Postconditions: None
*************************************************************/

Node*& Node::getMpRight() {
    return mpRight;
}
