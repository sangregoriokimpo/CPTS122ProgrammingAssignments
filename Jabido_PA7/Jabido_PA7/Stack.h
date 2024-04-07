#pragma once
//
// Created by Gregory Jabido on 4/5/24.
//

#ifndef JABIDO_PA7_STACK_H
#define JABIDO_PA7_STACK_H

#include "PA7Header.h"

template<typename T>
class Stack {
private:
    vector<T> stack;

    int size;

public:
    Stack() {}

    virtual ~Stack() {

    }

    bool isEmpty();

    void push(const T& item);

    T pop();

    T peek();

    /*************************************************************
    * Function: getSize()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Returns the size of the stack.
    * Input parameters: None
    * Returns: Integer representing the size of the stack.
    * Preconditions: None
    * Postconditions: None
    *************************************************************/

    int getSize() const {
        return stack.size();
    }

    void display();

    void printRecentAbsenceDateToFile(ofstream& outfile);

    /*************************************************************
    * Function: getStack()
    * Date Created: 04/05/2024
    * Date Last Modified: 04/07/2024
    * Description: Returns a reference to the stack.
    * Input parameters: None
    * Returns: Reference to the stack vector.
    * Preconditions: None
    * Postconditions: None
    *************************************************************/

    vector<T>& getStack() {
        return stack;
    }


};

/*************************************************************
* Function: printRecentAbsenceDateToFile()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Prints the most recent absence date to a file.
* Input parameters:
    - outfile: Reference to the ofstream object to write to.
* Returns: None
* Preconditions: None
* Postconditions: The most recent absence date is written to the file.
*************************************************************/

template<typename T>
void Stack<T>::printRecentAbsenceDateToFile(ofstream& outfile) {
    if (!stack.empty()) {
        outfile << "|" << stack.back() << endl;
    }
    //outfile << stack.back() << endl;
}


/*************************************************************
* Function: display()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Displays the contents of the stack.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

template<typename T>
void Stack<T>::display() {
    if (isEmpty()) {
        throw std::out_of_range("|Stack is empty");
    }
    else {
        cout << "|Absence Dates: " << endl;
        for (const auto& item : stack) {
            cout << "|" << item << endl;
        }
    }

}

/*************************************************************
* Function: peek()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the top element of the stack without removing it.
* Input parameters: None
* Returns: The top element of the stack.
* Preconditions: None
* Postconditions: None
*************************************************************/

template<typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("|Stack is empty");
    }
    return stack.back();
}

/*************************************************************
* Function: pop()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Removes and returns the top element of the stack.
* Input parameters: None
* Returns: The top element of the stack.
* Preconditions: The stack is not empty.
* Postconditions: The top element of the stack is removed.
*************************************************************/

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("|Stack is empty");
    }
    T top = stack.back();
    stack.pop_back();
    return top;
}

/*************************************************************
* Function: push()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Pushes an item onto the top of the stack.
* Input parameters:
    - item: The item to be pushed onto the stack.
* Returns: None
* Preconditions: None
* Postconditions: The item is added to the top of the stack.
*************************************************************/

template<typename T>
void Stack<T>::push(const T& item) {
    stack.push_back(item);
}

/*************************************************************
* Function: isEmpty()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Checks if the stack is empty.
* Input parameters: None
* Returns: True if the stack is empty, false otherwise.
* Preconditions: None
* Postconditions: None
*************************************************************/

template<typename T>
bool Stack<T>::isEmpty() {
    return stack.empty();
}


#endif //JABIDO_PA7_STACK_H


