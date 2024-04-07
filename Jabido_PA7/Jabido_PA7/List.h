#pragma once
//
// Created by Gregory Jabido on 4/5/24.
//

#ifndef JABIDO_PA7_LIST_H
#define JABIDO_PA7_LIST_H

#include "Node.h"

template<typename T>
class List {
private:
    Node<T>* pHead;
public:
    Node<T>* getPHead() const {
        return pHead;
    }

    void setPHead(Node<T>* pHead) {
        List::pHead = pHead;
    }

public:

    /*************************************************************
    * Function: List()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Default constructor for the List class. Initializes pHead to nullptr.
    * Input parameters: None
    * Returns: N/A
    * Preconditions: None
    * Postconditions: pHead is initialized to nullptr.
    *************************************************************/

    List() :pHead(nullptr) {}

    /*************************************************************
    * Function: virtual ~List()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Destructor for the List class. Deallocates memory for all nodes in the list.
    * Input parameters: None
    * Returns: void
    * Preconditions: None
    * Postconditions: Memory allocated for all nodes in the list is deallocated.
    *************************************************************/

    virtual ~List() {
        //Destructor
        Node<T>* pCurr = pHead;
        while (pCurr != nullptr) {
            Node<T>* next = pCurr->getPNext();
            delete pCurr;
            pCurr = next;
        }
    }

    void insert(const T& data);

    void printList();

    void clear();

};

/*************************************************************
* Function: template<typename T> void List<T>::clear()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Clears the list by deallocating memory for all nodes.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: The list is empty.
*************************************************************/

template<typename T>
void List<T>::clear() {
    Node<T>* pCurr = pHead;
    while (pCurr != nullptr) {
        Node<T>* pNext = pCurr->getPNext();
        delete pCurr;
        pCurr = pNext;
    }
    pHead = nullptr;
}

/*************************************************************
* Function: template<typename T> void List<T>::printList()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Prints the contents of the list.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

template<typename T>
void List<T>::printList() {
    Node<T>* pCurr = pHead;
    cout << "|" << std::setw(10) << "Record" << " | "
        << std::setw(10) << "ID" << " | "
        << std::setw(20) << "Name" << " | "
        << std::setw(25) << "Email" << " | "
        << std::setw(5) << "Units" << " | "
        << std::setw(10) << "Program" << " | "
        << std::setw(5) << "Absences" << endl;
    while (pCurr != nullptr) {
        cout << pCurr->getData();
        pCurr = pCurr->getPNext();
    }
}

/*************************************************************
* Function: template<typename T> void List<T>::insert(const T &data)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Inserts a new node with the given data at the beginning of the list.
* Input parameters:
*     - data: const T &
* Returns: void
* Preconditions: None
* Postconditions: The list contains the new node with the given data at the beginning.
*************************************************************/

template<typename T>
void List<T>::insert(const T& data) {
    Node<T>* pNode = new Node<T>(data);
    pNode->setPNext(pHead);
    pHead = pNode;
}


#endif //JABIDO_PA7_LIST_H

