#include "PA8Header.h"
#include "BST.h"
#include "Node.h"
#include "TransactionNode.h"
#include "DataAnalysis.h"

/*************************************************************
* Function: testBST()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Function to test the Binary Search Tree (BST) class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The BST is created, nodes are inserted, and
* various operations such as traversal, finding smallest/largest nodes are performed and printed.
*************************************************************/

void testBST() {
    // Create a BST object
    BST bst;

    // Insert some nodes into the BST
    bst.insert("Apple", 10);
    bst.insert("Banana", 5);
    bst.insert("Orange", 8);
    bst.insert("Grapes", 12);

    // Print the nodes in the BST using in-order traversal
    cout << "In-order traversal of the BST:" << endl;
    bst.inOrderTraversal();
    cout << endl;

    // Find and print the smallest node in the BST
    TransactionNode* smallest = bst.getSmallest();
    if (smallest) {
        cout << "Smallest node in the BST: " << smallest->getMData() << " - " << smallest->getMUnits() << " units" << endl;
    }
    else {
        cout << "BST is empty!" << endl;
    }

    // Find and print the largest node in the BST
    TransactionNode* largest = bst.getLargest();
    if (largest) {
        cout << "Largest node in the BST: " << largest->getMData() << " - " << largest->getMUnits() << " units" << endl;
    }
    else {
        cout << "BST is empty!" << endl;
    }

}




int main() {
    //testBST();
    DataAnalysis da;
    //da.testBST();
    da.runAnalysis("data.csv");




    return 0;

}