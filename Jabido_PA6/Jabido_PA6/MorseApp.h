#pragma once
//
// Created by Gregory Jabido on 3/20/24.
//

#ifndef JABIDO_PA6_MORSEAPP_H
#define JABIDO_PA6_MORSEAPP_H
#include "PA6Header.h"
#include "BST.h"
#include "BSTNode.h"
#include <fstream>


class MorseApp {
private:
    BST<char, string> bst;
public:
    void insertMorseTable(const string filePath);

    void translate(const string& filePath);

    void translateText(const string& text);

    void printBST();

    void printInOrder();

    void runApplication();

    void printMenu();

    bool getChoice();
};


#endif //JABIDO_PA6_MORSEAPP_H

