#pragma once
//
// Created by Gregory Jabido on 3/17/24.
//
#include "PA6Header.h"
#ifndef JABIDO_PA6_BSTNODE_H
#define JABIDO_PA6_BSTNODE_H

/*************************************************************
* Function: run_system ()
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

template <typename KeyType, typename ValueType>
class BSTNode {
private:
    KeyType key;
    ValueType value;
    BSTNode<KeyType, ValueType>* pLeft;
    BSTNode<KeyType, ValueType>* pRight;
public:


    /*************************************************************
    * Function: BSTNode()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Constructor for a binary search tree node.
    * Input parameters: k - the key of the node, v - the value
    * of the node
    * Returns: None.
    * Preconditions: None.
    * Postconditions: A new binary search tree node is created
    * with the given key, value, left and right pointers.
    *************************************************************/

    BSTNode(KeyType k, ValueType v) : key(k), value(v), pLeft(nullptr), pRight(nullptr) {}

    /*************************************************************
    * Function: getKey()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Retrieves the key of the binary search tree node.
    * Input parameters: None.
    * Returns: The key of the node.
    * Preconditions: None.
    * Postconditions: None.
    *************************************************************/

    KeyType getKey() const {
        return key;
    }

    /*************************************************************
    * Function: setKey()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Sets the key of the binary search tree node.
    * Input parameters: key - the key to be set
    * Returns: None.
    * Preconditions: None.
    * Postconditions: The key of the node is updated
    * to the provided value.
    *************************************************************/

    void setKey(KeyType key) {
        BSTNode::key = key;
    }

    /*************************************************************
    * Function: getValue()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Retrieves the value of the binary
    * search tree node.
    * Input parameters: None.
    * Returns: The value of the node.
    * Preconditions: None.
    * Postconditions: None.
    *************************************************************/

    ValueType getValue() const {
        return value;
    }

    /*************************************************************
    * Function: setValue()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Sets the value of the binary
    * search tree node.
    * Input parameters: value - the value to be set
    * Returns: None.
    * Preconditions: None.
    * Postconditions: The value of the node is updated to
    * the provided value.
    *************************************************************/

    void setValue(ValueType value) {
        BSTNode::value = value;
    }

    /*************************************************************
    * Function: getPLeft()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Retrieves a pointer to the left child of
    * the binary search tree node.
    * Input parameters: None.
    * Returns: A pointer to the left child node.
    * Preconditions: None.
    * Postconditions: None.
    *************************************************************/

    BSTNode<KeyType, ValueType>* getPLeft() const {
        return pLeft;
    }

    /*************************************************************
    * Function: setPLeft()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Sets the left child pointer of the binary
    * search tree node.
    * Input parameters: pLeft - a pointer to the node to be
    * set as the left child
    * Returns: None.
    * Preconditions: None.
    * Postconditions: The left child pointer of the node is
    * updated to the provided pointer.
    *************************************************************/

    void setPLeft(BSTNode<KeyType, ValueType>* pLeft) {
        BSTNode::pLeft = pLeft;
    }

    /*************************************************************
    * Function: getPRight()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Retrieves a pointer to the right
    * child of the binary search tree node.
    * Input parameters: None.
    * Returns: A pointer to the right child node.
    * Preconditions: None.
    * Postconditions: None.
    *************************************************************/

    BSTNode<KeyType, ValueType>* getPRight() const {
        return pRight;
    }

    /*************************************************************
    * Function: setPRight()
    * Date Created: 3/17/24
    * Date Last Modified: 3/17/24
    * Description: Sets the right child pointer of the
    * binary search tree node.
    * Input parameters: pRight - a pointer to the node to
    * be set as the right child
    * Returns: None.
    * Preconditions: None.
    * Postconditions: The right child pointer of the node is
    * updated to the provided pointer.
    *************************************************************/

    void setPRight(BSTNode<KeyType, ValueType>* pRight) {
        BSTNode::pRight = pRight;
    }

};


#endif //JABIDO_PA6_BSTNODE_H


