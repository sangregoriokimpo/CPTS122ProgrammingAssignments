#pragma once
//
// Created by Gregory Jabido on 3/5/24.
//

#ifndef JABIDO_PA5_QUEUENODE_H
#define JABIDO_PA5_QUEUENODE_H
#include "PA5Header.h"
#include "Data.h"
#include "GroceryItem.h"


class QueueNode {
public:

    // ## Constructors
    QueueNode(Data* pData, QueueNode* pNext);
    QueueNode(Data* pData, const GroceryItem& groceryItem);
    QueueNode(Data* pData);
    QueueNode(Data* pData, QueueNode* pNext, const GroceryItem& groceryItem);

    // ## Grocery Functions
    void addGroceryItem(const string& itemName);
    void addRandomGroceryItems();
    void printGroceryItems() const;
    int getServiceTime() const;

    // ## Constructor
    QueueNode(Data* pData, const string& groceryItem);

    // ## Copy Constructor
    QueueNode(const QueueNode& other);

    // ## pData functions
    Data* getPData() const;
    void setPData(Data* pData);

    // ## pNext functions
    QueueNode* getPNext() const;
    void setPNext(QueueNode* pNext);

    // ## Destructor
    virtual ~QueueNode();

private:
    Data* pData;
    QueueNode* pNext;
    GroceryItem* groceryItem;
public:
    void setGroceryItem(GroceryItem* groceryItem);

public:
    GroceryItem* getGroceryItem() const;
};


#endif //JABIDO_PA5_QUEUENODE_H
