//
// Created by Gregory Jabido on 3/5/24.
//

#include "QueueNode.h"

/*************************************************************
* Function: getPData() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns a pointer to the Data object
* stored in the QueueNode.
* Input parameters: None
* Returns: Pointer to the Data object.
* Preconditions: None
* Postconditions: None
*************************************************************/

Data* QueueNode::getPData() const {
    return pData;
}

/*************************************************************
* Function: setPData(Data *pData)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the pointer to the Data object stored
* in the QueueNode.
* Input parameters:
*   - pData: Pointer to the Data object to set.
* Returns: Void
* Preconditions: None
* Postconditions: The pointer to the Data object is updated.
*************************************************************/

void QueueNode::setPData(Data* pData) {
    this->pData = pData;
}

/*************************************************************
* Function: getPNext() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns a pointer to the next QueueNode in
* the linked list.
* Input parameters: None
* Returns: Pointer to the next QueueNode.
* Preconditions: None
* Postconditions: None
*************************************************************/

QueueNode* QueueNode::getPNext() const {
    return pNext;
}

/*************************************************************
* Function: setPNext(QueueNode *pNext)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the pointer to the next QueueNode in
* the linked list.
* Input parameters:
    - pNext: Pointer to the next QueueNode to set.
* Returns: Void
* Preconditions: None
* Postconditions: The pointer to the next QueueNode is
* updated.
*************************************************************/

void QueueNode::setPNext(QueueNode* pNext) {
    this->pNext = pNext;
}

/*************************************************************
* Function: QueueNode(Data *pData, QueueNode *pNext)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the QueueNode class.
* Initializes pData, pNext, and groceryItem.
* Input parameters:
    - pData: Pointer to the Data object to be stored in the QueueNode.
    - pNext: Pointer to the next QueueNode in the linked list.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly initialized
* with pData, pNext, and groceryItem set to nullptr.
*************************************************************/

QueueNode::QueueNode(Data* pData, QueueNode* pNext) : pData(pData), pNext(pNext), groceryItem(nullptr) {}

/*************************************************************
* Function: ~QueueNode()
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Destructor for the QueueNode class.
* Input parameters: None
* Returns: N/A
* Preconditions: None
* Postconditions: Memory allocated for the grocery item is deallocated.
*************************************************************/

QueueNode::~QueueNode() {
    delete groceryItem;
}

/*************************************************************
* Function: QueueNode(Data *pData, QueueNode *pNext, const GroceryItem& groceryItem)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the QueueNode class.
* Initializes pData, pNext, and groceryItem.
* Input parameters:
*   - pData: Pointer to the Data object to be stored in the
*   QueueNode.
*   - pNext: Pointer to the next QueueNode in the linked list.
*   - groceryItem: Reference to a constant GroceryItem object
*   representing the grocery item to be stored.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly initialized
* with pData, pNext, and groceryItem set.
*************************************************************/

QueueNode::QueueNode(Data* pData, QueueNode* pNext, const GroceryItem& groceryItem) : pData(pData), pNext(pNext) {
    this->groceryItem = new GroceryItem(groceryItem);
}

/*************************************************************
* Function: QueueNode(const QueueNode &other)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Copy constructor for the QueueNode class.
* Input parameters:
*   - other: Reference to a constant QueueNode
*   object to be copied.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly
* initialized as a copy of the provided QueueNode object.
*************************************************************/

QueueNode::QueueNode(const QueueNode& other) : pData(other.pData), pNext(other.pNext) {
    this->groceryItem = new GroceryItem(*(other.groceryItem));
}

/*************************************************************
* Function: QueueNode(Data *pData, const GroceryItem& groceryItem)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the QueueNode class.
* Initializes pData, pNext, and groceryItem.
* Input parameters:
*   - pData: Pointer to the Data object to be stored
*   in the QueueNode.
*   - groceryItem: Reference to a constant GroceryItem
*   object representing the grocery item to be stored.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly
* initialized with pData, pNext, and groceryItem set.
*************************************************************/

QueueNode::QueueNode(Data* pData, const GroceryItem& groceryItem) : pData(pData), pNext(nullptr) {
    this->groceryItem = new GroceryItem(groceryItem);
}

/*************************************************************
* Function: QueueNode(Data *pData, const string &groceryItem)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the QueueNode class.
* Initializes pData, pNext, and groceryItem.
* Input parameters:
*   - pData: Pointer to the Data object to be stored in the
*   QueueNode.
*   - groceryItem: Reference to a constant string
*   representing the name of the grocery item.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly initialized
* with pData, pNext, and groceryItem set.
*************************************************************/

QueueNode::QueueNode(Data* pData, const string& groceryItem) : pData(pData), pNext(nullptr) {
    this->groceryItem = new GroceryItem(groceryItem);
}

/*************************************************************
* Function: QueueNode(Data *pData)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Constructor for the QueueNode class. Initializes
* pData, pNext, and groceryItem.
* Input parameters:
    - pData: Pointer to the Data object to be stored in the QueueNode.
* Returns: N/A
* Preconditions: None
* Postconditions: The QueueNode object is properly initialized
* with pData, pNext, and groceryItem set.
*************************************************************/

QueueNode::QueueNode(Data* pData) : pData(pData), pNext(nullptr), groceryItem(nullptr) {}

/*************************************************************
* Function: getGroceryItem() const
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Returns a pointer to the grocery item of the QueueNode.
* Input parameters: None
* Returns: Pointer to the GroceryItem object.
* Preconditions: None
* Postconditions: None
*************************************************************/

GroceryItem* QueueNode::getGroceryItem() const {
    return groceryItem;
}

/*************************************************************
* Function: setGroceryItem(GroceryItem *groceryItem)
* Date Created: 3/5/24
* Date Last Modified: 3/5/24
* Description: Sets the grocery item of the QueueNode.
* Input parameters:
    - groceryItem: Pointer to the GroceryItem object to set.
* Returns: Void
* Preconditions: None
* Postconditions: The grocery item of the QueueNode is updated.
*************************************************************/

void QueueNode::setGroceryItem(GroceryItem* groceryItem) {
    QueueNode::groceryItem = groceryItem;
}

/*************************************************************
* Function: addGroceryItem(const string &itemName)
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Adds a grocery item to the QueueNode.
* Input parameters:
*   - itemName: Reference to a constant string representing
*   the name of the grocery item to add.
* Returns: Void
* Preconditions: None
* Postconditions: The grocery item is added to the QueueNode,
* and the service time of the associated Data object is updated.
*************************************************************/

void QueueNode::addGroceryItem(const string& itemName) {
    auto* newItem = new GroceryItem(itemName);
    if (groceryItem == nullptr) {
        groceryItem = newItem;
    }
    else {
        GroceryItem* pCurr = groceryItem;
        while (pCurr->getPNext() != nullptr) {
            pCurr = pCurr->getPNext();
        }
        pCurr->setPNext(newItem);
    }
    this->pData->setServiceTime(getServiceTime());
}

/*************************************************************
* Function: printGroceryItems() const
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Prints the grocery items in the QueueNode.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: None
*************************************************************/

void QueueNode::printGroceryItems() const {
    GroceryItem* pCurr = groceryItem;
    int index = 1;
    while (pCurr != nullptr) {
        cout << "|" << index << ": " << pCurr->getItemName() << endl;
        pCurr = pCurr->getPNext();
        index++;
    }
}

/*************************************************************
* Function: getServiceTime() const
* Date Created: 3/5/24
* Date Last Modified: 3/10/24
* Description: Calculates and returns the
* service time of the QueueNode.
* Input parameters: None
* Returns: Integer representing the service time.
* Preconditions: None
* Postconditions: None
*************************************************************/

int QueueNode::getServiceTime() const {
    int serviceTime = 0;
    //cout << groceryItem->getItemName() << endl;
    GroceryItem* pCurr = groceryItem;
    
    while (pCurr != nullptr) {
        serviceTime++;
        pCurr = pCurr->getPNext();
    }
    return serviceTime;

  
}

/*************************************************************
* Function: addRandomGroceryItems()
* Date Created: 3/9/24
* Date Last Modified: 3/10/24
* Description: Adds a random number of random
* grocery items to the QueueNode.
* Input parameters: None
* Returns: Void
* Preconditions: None
* Postconditions: Random grocery items are added to
* the QueueNode.
*************************************************************/

void QueueNode::addRandomGroceryItems() {
    array<string, 100> groceryItemNames = {
            "Apples", "Bananas", "Oranges", "Milk", "Eggs", "Bread", "Butter", "Cheese", "Yogurt", "Cereal",
            "Spinach", "Tomatoes", "Potatoes", "Carrots", "Broccoli", "Onions", "Garlic", "Lettuce", "Cucumber", "Bell Peppers",
            "Chicken", "Beef", "Pork", "Salmon", "Tuna", "Shrimp", "Turkey", "Bacon", "Sausages", "Ham",
            "Rice", "Pasta", "Quinoa", "Oats", "Couscous", "Barley", "Beans", "Lentils", "Chickpeas", "Black Beans",
            "Ketchup", "Mustard", "Mayonnaise", "Soy Sauce", "Vinegar", "Olive Oil", "Vegetable Oil", "Honey", "Maple Syrup",
            "Flour", "Sugar", "Salt", "Pepper", "Baking Powder", "Baking Soda", "Vanilla Extract", "Cinnamon", "Nutmeg",
            "Coffee", "Tea", "Hot Chocolate", "Orange Juice", "Apple Juice", "Grape Juice", "Lemonade", "Soda", "Water",
            "Chips", "Popcorn", "Crackers", "Pretzels", "Cookies", "Chocolate", "Ice Cream", "Frozen Vegetables", "Frozen Fruits", "Frozen Pizza",
            "Toilet Paper", "Paper Towels", "Dish Soap", "Laundry Detergent", "Hand Soap", "Trash Bags", "Aluminum Foil", "Plastic Wrap", "Ziploc Bags",
            "Toothpaste", "Shampoo", "Conditioner", "Body Wash", "Razors", "Shaving Cream", "Deodorant", "Feminine Hygiene Products", "Tissues"
    };
    int amountItems = rand() % 10 + 1;//Change this number to however you want (10 - 10000 grocery items)
    for (int i = 0; i < amountItems; i++) {
        int index = rand() % 100;
        while (groceryItemNames[index] == "") {//Error catching for empty strings (idk why C++ does that)
            index = rand() % 100;
        }
        string itemName = groceryItemNames[index];
        addGroceryItem(itemName);
    }
}

