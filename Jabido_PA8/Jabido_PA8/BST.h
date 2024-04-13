#pragma once
//
// Created by Gregory Jabido on 4/10/24.
//

#ifndef JABIDO_PA8_BST_H
#define JABIDO_PA8_BST_H

#include "PA8Header.h"
#include "Node.h"
#include "TransactionNode.h"


class BST {
private:
    Node* mpRoot;

    void insertUtil(Node*& node, const string& data, int units);

    void destroyTree(Node*& node);

    void inOrderTraversalUtil(Node* node) const;

    TransactionNode* findSmallestUtil(Node* node) const;

    TransactionNode* findLargestUtil(Node* node) const;

    void displayBSTUtil(Node* node, int space);


public:
    //explicit BST(Node *mpRoot);

    virtual ~BST();

    BST() { mpRoot = nullptr; }

    void insert(const string& data, int units) { insertUtil(mpRoot, data, units); }

    void inOrderTraversal() const { inOrderTraversalUtil(mpRoot); }

    TransactionNode* getSmallest() const { return findSmallestUtil(mpRoot); }

    TransactionNode* getLargest() const { return findLargestUtil(mpRoot); }

    void displayBST();



};


#endif //JABIDO_PA8_BST_H
