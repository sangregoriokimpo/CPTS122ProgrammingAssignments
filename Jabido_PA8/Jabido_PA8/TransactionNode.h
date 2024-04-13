//
// Created by Gregory Jabido on 4/10/24.
//

#ifndef JABIDO_PA8_TRANSACTIONNODE_H
#define JABIDO_PA8_TRANSACTIONNODE_H

#include "Node.h"

class TransactionNode : public Node {
private:
    int mUnits;

public:
    TransactionNode(const string& mData, int mUnits);

    ~TransactionNode() override;

    int getMUnits() const;

    void setMUnits(int mUnits);

    /*************************************************************
    * Function: printData() const override
    * Date Created: 04/10/2024
    * Date Last Modified: 04/12/2024
    * Description: Prints the data associated with the TransactionNode.
    * Input parameters: None
    * Returns: None
    * Preconditions: None
    * Postconditions: The data associated with the TransactionNode is printed to the console.
    *************************************************************/

    void printData() const override {
        cout << "|Product: " << mData << ", Units: " << mUnits << endl;
    };
};


#endif //JABIDO_PA8_TRANSACTIONNODE_H

