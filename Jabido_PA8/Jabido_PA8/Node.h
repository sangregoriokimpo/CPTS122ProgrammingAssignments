#pragma once
//
// Created by Gregory Jabido on 4/10/24.
//

#ifndef JABIDO_PA8_NODE_H
#define JABIDO_PA8_NODE_H

#include "PA8Header.h"

class Node {
protected:
    string mData;
    Node* mpLeft;
    Node* mpRight;
public:
    const string& getMData() const;

    void setMData(const string& mData);

    Node*& getMpLeft();

    void setMpLeft(Node* mpLeft);

    Node*& getMpRight();

    void setMpRight(Node* mpRight);

    explicit Node(const string& mData);

    virtual ~Node();

    virtual void printData() const = 0;



};


#endif //JABIDO_PA8_NODE_H
