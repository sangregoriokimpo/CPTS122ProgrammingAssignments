//
// Created by Gregory Jabido on 4/10/24.
//

#include "TransactionNode.h"

/*************************************************************
* Function: TransactionNode::TransactionNode(const string &mData, int mUnits)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Constructor for the TransactionNode class.
* Input parameters:
    - mData: A constant reference to a string containing the data for the node.
    - mUnits: An integer representing the units associated with the data.
* Returns: None
* Preconditions: None
* Postconditions: A new TransactionNode object is created with the specified data and units.
*************************************************************/

TransactionNode::TransactionNode(const string& mData, int mUnits) : Node(mData), mUnits(mUnits) {}

/*************************************************************
* Function: TransactionNode::~TransactionNode()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Destructor for the TransactionNode class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

TransactionNode::~TransactionNode() {

}

/*************************************************************
* Function: TransactionNode::getMUnits() const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Getter function to retrieve the number of units associated with the TransactionNode.
* Input parameters: None
* Returns: An integer representing the number of units.
* Preconditions: None
* Postconditions: None
*************************************************************/

int TransactionNode::getMUnits() const {
    return mUnits;
}

/*************************************************************
* Function: TransactionNode::setMUnits(int mUnits)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Setter function to set the number of units associated with the TransactionNode.
* Input parameters:
    - mUnits: An integer representing the number of units to set.
* Returns: None
* Preconditions: None
* Postconditions: The number of units associated with the TransactionNode is updated.
*************************************************************/

void TransactionNode::setMUnits(int mUnits) {
    TransactionNode::mUnits = mUnits;
}
