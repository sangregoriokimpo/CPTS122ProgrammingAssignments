#pragma once
//
// Created by Gregory Jabido on 3/5/24.
//

#ifndef JABIDO_PA5_GROCERYITEM_H
#define JABIDO_PA5_GROCERYITEM_H
#include "PA5Header.h"


class GroceryItem {
public:
    GroceryItem(GroceryItem* pNext, const string& itemName);

    GroceryItem(const string& itemName);

    GroceryItem();

    const string& getItemName() const;

    void setItemName(const string& itemName);

    GroceryItem* getPNext() const;

    void setPNext(GroceryItem* pNext);

private:
    GroceryItem* pNext;
    string itemName;
};


#endif //JABIDO_PA5_GROCERYITEM_H
