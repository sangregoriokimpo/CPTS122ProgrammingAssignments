#pragma once
//
// Created by Gregory Jabido on 3/17/24.
//
#include <optional>
#include "PA6Header.h"
#include "BSTNode.h"
#ifndef JABIDO_PA6_BST_H
#define JABIDO_PA6_BST_H

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
class BST {
private:
    BSTNode<KeyType, ValueType>* pRoot;

    void destroyBST(BSTNode<KeyType, ValueType>* bstNode);

    void printBSTHelper(BSTNode<KeyType, ValueType>* pRoot, int space);

    void printBSTinOrderHelper(BSTNode<KeyType, ValueType>* bstNode);

public:
    // Constructor
    BST() : pRoot(nullptr) {}


    // Destructor
    ~BST() {
        destroyBST(pRoot);
    }

    void insert(KeyType key, ValueType value);

    ValueType search(KeyType key);

    void printBST();

    void printBSTinOrder();

    string convert(const string& str);
};

/*************************************************************
* Function: convert()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Converts each character in the input string
* to its corresponding value in a binary search tree and
* returns the result as a string.
* Input parameters: str - the input string to be
* converted
* Returns: A string containing the conversion of each
* character in the input string.
* Preconditions: The binary search tree (BST) must be
* initialized and populated with key-value pairs.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
string BST<KeyType, ValueType>::convert(const string& str) {
    string conversion;
    for (int i = 0; i < str.length(); i++) {
        conversion += search(toupper(str[i]));
        conversion += " ";
    }
    return conversion;
}

/*************************************************************
* Function: search()
* Date Created: 3/17/24
* Date Last Modified: 3/23/24
* Description: Searches for the value associated with the
* given key in the binary search tree.
* Input parameters: key - the key to search for
* Returns: The value associated with the given key if found,
* otherwise returns "NULL" if the key is not found or three
* spaces if the key is a space character.
* Preconditions: The binary search tree (BST) must be
* initialized and populated with key-value pairs.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
ValueType BST<KeyType, ValueType>::search(KeyType key) {
    BSTNode<KeyType, ValueType>* pCurr = pRoot;
    while (pCurr != nullptr) {
        if (key < pCurr->getKey()) {
            pCurr = pCurr->getPLeft();
        }
        else if (key > pCurr->getKey()) {
            pCurr = pCurr->getPRight();
        }
        else if (key == pCurr->getKey()) {
            return pCurr->getValue();
        }
    }
    if (key == ' ') {
        ValueType space = "   ";
        return space;
    }
    ValueType nul = "NULL";
    return nul;
}

/*************************************************************
* Function: insert()
* Date Created: 3/17/24
* Date Last Modified: 3/23/24
* Description: Inserts a new key-value pair into the
* binary search tree.
* Input parameters: key - the key to be inserted,
* value - the corresponding value to be inserted
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: The binary search tree will contain
* the newly inserted key-value pair.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::insert(KeyType key, ValueType value) {
    if (pRoot == nullptr)
    {
        pRoot = new BSTNode<KeyType, ValueType>(key, value);
        return;
    }

    auto pCurr = pRoot;
    for (;;)
    {
        auto current_key = pCurr->getKey();
        if (key < current_key)
        {
            auto p = pCurr->getPLeft();
            if (p)
            {
                pCurr = p;
                continue;
            }
            pCurr->setPLeft(new BSTNode<KeyType, ValueType>(key, value));
            break;
        }
        else if (key > current_key)
        {
            auto p = pCurr->getPRight();
            if (p)
            {
                pCurr = p;
                continue;
            }
            pCurr->setPRight(new BSTNode<KeyType, ValueType>(key, value));
            break;
        }
        else // (key == current_key)
        {
            std::cerr << "|Duplicate Value \n\n";
            break;
        }
    }
    /*//insertNode(this->pRoot,key,value);
    if (pRoot == nullptr)
    {
        pRoot = new BSTNode<KeyType, ValueType>(key, value);
        return;
    }
    auto pCurr{ pRoot };
    for (;;)
    {
        auto current_key{ pCurr->getKey() };
        if (key < current_key)
        {
            if (auto p{ pCurr->getPLeft() }; p)
            {
                pCurr = p;
                continue;
            }
            pCurr->setPLeft(new BSTNode<KeyType, ValueType>(key, value));
            break;
        }
        else if (key > current_key)
        {
            if (auto p{ pCurr->getPRight() }; p)
            {
                pCurr = p;
                continue;
            }
            pCurr->setPRight(new BSTNode<KeyType, ValueType>(key, value));
            break;
        }
        else  // (key == current_key)
        {
            std::cerr << "|Duplicate Value \n\n";
            break;
        }
    }*/
}

/*************************************************************
* Function: printBSTinOrderHelper()
* Date Created: 3/17/24
* Date Last Modified: 3/23/24
* Description: Prints the keys and values of the binary
* search tree in sorted order.
* Input parameters: bstNode - a pointer to the
* current node being processed
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::printBSTinOrderHelper(BSTNode<KeyType, ValueType>* bstNode) {
    if (bstNode == nullptr) {
        return;
    }
    else {
        printBSTinOrderHelper(bstNode->getPLeft());
        cout << bstNode->getKey() << " " << bstNode->getValue() << endl;
        printBSTinOrderHelper(bstNode->getPRight());
    }

}

/*************************************************************
* Function: printBSTinOrder()
* Date Created: 3/18/24
* Date Last Modified: 3/23/24
* Description: Initiates the printing of the keys and
* values of the binary search tree in sorted order.
* Input parameters: None.
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::printBSTinOrder() {
    printBSTinOrderHelper(this->pRoot);
}

/*************************************************************
* Function: printBST()
* Date Created: 3/18/24
* Date Last Modified: 3/23/24
* Description: Initiates the printing of the binary
* search tree.
* Input parameters: None.
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::printBST() {
    printBSTHelper(pRoot, 0);
}

/*************************************************************
* Function: printBSTHelper()
* Date Created: 3/18/24
* Date Last Modified: 3/23/24
* Description: Recursively prints the binary search tree
* structure with keys and values.
* Input parameters: pRoot - a pointer to the root node of
* the subtree to be printed, space - the amount of space
* to be used for indentation
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: None.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::printBSTHelper(BSTNode<KeyType, ValueType>* pRoot, int space) {
    if (pRoot == nullptr) {
        return;
    }
    space += 10;
    printBSTHelper(pRoot->getPRight(), space);
    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << pRoot->getKey() << "|" << pRoot->getValue() << endl;
    printBSTHelper(pRoot->getPLeft(), space);
}

/*************************************************************
* Function: destroyBST()
* Date Created: 3/17/24
* Date Last Modified: 3/23/24
* Description: Recursively destroys the binary search
* tree by deallocating memory for each node.
* Input parameters: bstNode - a pointer to the root
* node of the subtree to be destroyed
* Returns: None.
* Preconditions: The binary search tree (BST) may or
* may not be initialized.
* Postconditions: The memory allocated for each node in
* the binary search tree will be deallocated.
*************************************************************/

template<typename KeyType, typename ValueType>
void BST<KeyType, ValueType>::destroyBST(BSTNode<KeyType, ValueType>* bstNode) {
    if (bstNode != nullptr) {
        destroyBST(bstNode->getPLeft());
        destroyBST(bstNode->getPRight());
        delete bstNode;
    }
}

#endif //JABIDO_PA6_BST_H
