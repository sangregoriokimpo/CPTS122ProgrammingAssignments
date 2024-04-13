//
// Created by Gregory Jabido on 4/10/24.
//

#include "BST.h"

//BST::BST(Node *mpRoot) : mpRoot(mpRoot) {}

/*************************************************************
* Function: BST::~BST()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Destructor for the Binary Search Tree (BST).
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The BST is destroyed, and memory is deallocated.
*************************************************************/

BST::~BST() {
    destroyTree(mpRoot);
}

/*************************************************************
* Function: BST::inOrderTraversalUtil(Node* node) const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Utility function for in-order traversal of the BST.
* Input parameters:
    - node: A pointer to the current node being traversed.
* Returns: None
* Preconditions: None
* Postconditions: The contents of the BST are printed in sorted order.
*************************************************************/

void BST::inOrderTraversalUtil(Node* node) const {
    if (node) {
        inOrderTraversalUtil(node->getMpLeft());
        ((TransactionNode*)node)->printData();
        inOrderTraversalUtil(node->getMpRight());
    }
}

/*************************************************************
* Function: BST::findSmallestUtil(Node* node) const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Utility function to find the smallest node in the BST.
* Input parameters:
    - node: A pointer to the current node being considered.
* Returns:
    - A pointer to the smallest TransactionNode in the BST.
* Preconditions: None
* Postconditions: None
*************************************************************/

TransactionNode* BST::findSmallestUtil(Node* node) const {
    if (!node->getMpLeft()) {
        return dynamic_cast<TransactionNode*>(node);
    }
    return findSmallestUtil(node->getMpLeft());
}

/*************************************************************
* Function: BST::findLargestUtil(Node* node) const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Utility function to find the largest node in the BST.
* Input parameters:
    - node: A pointer to the current node being considered.
* Returns:
    - A pointer to the largest TransactionNode in the BST.
* Preconditions: None
* Postconditions: None
*************************************************************/

TransactionNode* BST::findLargestUtil(Node* node) const {
    if (!node->getMpRight()) {
        return dynamic_cast<TransactionNode*>(node);
    }
    return findLargestUtil(node->getMpRight());
}

/*************************************************************
* Function: BST::destroyTree(Node* &node)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Recursively destroys the BST starting from the given node.
* Input parameters:
    - node: A reference to a pointer to the root node of the subtree to destroy.
* Returns: None
* Preconditions: None
* Postconditions: The subtree rooted at the given node is destroyed, and memory is deallocated.
*************************************************************/

void BST::destroyTree(Node*& node) {
    if (node) {
        destroyTree(node->getMpLeft());
        destroyTree(node->getMpRight());
        delete node;
    }
}

/*************************************************************
* Function: BST::insertUtil(Node *&node, const string &data, int units)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Utility function to insert a new node into the BST.
* Input parameters:
    - node: A reference to a pointer to the root node of the subtree to insert into.
    - data: A string containing the data to be stored in the new node.
    - units: An integer representing the number of units associated with the data.
* Returns: None
* Preconditions: None
* Postconditions: If the data is not a duplicate, a new TransactionNode containing the data and units is inserted into the BST.
*                 If the data is a duplicate, a message is printed indicating a duplicate insertion.
*************************************************************/

void BST::insertUtil(Node*& node, const string& data, int units) {
    if (node == nullptr) {
        //cout << "|Creating new node with data: " << data << ", units: " << units << endl;
        node = new TransactionNode(data, units);
    }
    else if (units < dynamic_cast<TransactionNode*>(node)->getMUnits()) {
        //cout << "|Inserting left of node with data: " << dynamic_cast<TransactionNode*>(node)->getMData() << ", units: " << ((TransactionNode*)(node))->getMUnits() << endl;
        insertUtil(node->getMpLeft(), data, units);
    }
    else if (units > dynamic_cast<TransactionNode*>(node)->getMUnits()) {
        //cout << "|Inserting right of node with data: " << dynamic_cast<TransactionNode*>(node)->getMData() << ", units: " << ((TransactionNode*)(node))->getMUnits() << endl;
        insertUtil(node->getMpRight(), data, units);
    }
    else {
        cout << "|Duplicate insertion" << endl;
    }
}

/*************************************************************
* Function: BST::displayBST()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Displays the contents of the Binary Search Tree (BST).
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The contents of the BST are printed to the console.
*************************************************************/

void BST::displayBST() {
    displayBSTUtil(this->mpRoot, 0);
}

/*************************************************************
* Function: BST::displayBSTUtil(Node *node, int space)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Utility function to recursively display the contents of the BST.
* Input parameters:
    - node: A pointer to the current node being considered.
    - space: An integer representing the amount of space for indentation.
* Returns: None
* Preconditions: None
* Postconditions: The contents of the BST are printed to the console with proper indentation.
*************************************************************/

void BST::displayBSTUtil(Node* node, int space) {
    if (node == nullptr) {
        return;
    }
    space += 10;
    displayBSTUtil(node->getMpRight(), space);
    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << node->getMData() << "|" << dynamic_cast<TransactionNode*>(node)->getMUnits() << endl;
    displayBSTUtil(node->getMpRight(), space);
}
