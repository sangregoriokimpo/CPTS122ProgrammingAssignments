//
// Created by Gregory Jabido on 3/5/24.
//

#include "GroceryItem.h"

/*************************************************************
* Function: getItemName() const
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Returns the name of the grocery item.
* Input parameters: None
* Returns: Reference to a constant string
*          representing the name of the grocery item.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& GroceryItem::getItemName() const {
    return itemName;
}

/*************************************************************
* Function: setItemName(const string &itemName)
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Sets the name of the grocery item.
* Input parameters:
*   - itemName: Reference to a constant string representing
*   the name of the grocery item to set.
* Returns: Void
* Preconditions: None
* Postconditions: The name of the grocery item is updated.
*************************************************************/

void GroceryItem::setItemName(const string& itemName) {
    this->pNext = nullptr;
    this->itemName = itemName;
}

/*************************************************************
* Function: getPNext() const
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Returns a pointer to the next GroceryItem
*              in the linked list.
* Input parameters: None
* Returns: Pointer to the next GroceryItem.
* Preconditions: None
* Postconditions: None
*************************************************************/

GroceryItem* GroceryItem::getPNext() const {
    return pNext;
}

/*************************************************************
* Function: setPNext(GroceryItem *pNext)
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Sets the pointer to the next GroceryItem in
* the linked list.
* Input parameters:
*   - pNext: Pointer to the next GroceryItem to set.
* Returns: Void
* Preconditions: None
* Postconditions: The pointer to the next GroceryItem
* is updated.
*************************************************************/

void GroceryItem::setPNext(GroceryItem* pNext) {
    this->pNext = pNext;
}

/*************************************************************
* Function: GroceryItem(GroceryItem *pNext, const string &itemName)
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Constructor for the GroceryItem class.
* Initializes pNext pointer and itemName.
* Input parameters:
*   - pNext: Pointer to the next GroceryItem in the linked list.
*   - itemName: Reference to a constant string representing
*               the name of the grocery item.
* Returns: N/A
* Preconditions: None
* Postconditions: The GroceryItem object is properly
* initialized with pNext and itemName set.
*************************************************************/

GroceryItem::GroceryItem(GroceryItem* pNext, const string& itemName) : pNext(pNext), itemName(itemName) {}

/*************************************************************
* Function: GroceryItem()
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Default constructor for the GroceryItem class.
*              Initializes pNext pointer to nullptr.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: The GroceryItem object is properly
* initialized with pNext set to nullptr.
*************************************************************/

GroceryItem::GroceryItem() {
    this->setPNext(nullptr);
    this->itemName = "";
}

/*************************************************************
* Function: GroceryItem(const string &itemName)
* Date Created: 3/6/24
* Date Last Modified: 3/10/24
* Description: Constructor for the GroceryItem class.
* Initializes itemName and pNext pointer.
* Input parameters:
*   - itemName: Reference to a constant string representing
*     the name of the grocery item.
* Returns: N/A
* Preconditions: None
* Postconditions: The GroceryItem object is properly
* initialized with itemName and pNext set.
*************************************************************/

GroceryItem::GroceryItem(const string& itemName) : itemName(itemName), pNext(nullptr) {}


