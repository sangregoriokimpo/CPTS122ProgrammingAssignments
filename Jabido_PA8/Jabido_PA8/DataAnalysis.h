#pragma once
//
// Created by Gregory Jabido on 4/11/24.
//

#ifndef JABIDO_PA8_DATAANALYSIS_H
#define JABIDO_PA8_DATAANALYSIS_H

#include "PA8Header.h"
#include "BST.h"
#include "TransactionNode.h"
#include "Node.h"

class DataAnalysis {
private:
    BST mTreeSold;
    BST mTreePurchased;

    ifstream mCsvStream;

    void insertData();

    void openFile(const string& filename);

    void displayTrends() const;


public:
    void runAnalysis(const string& filename);

    void testBST();

    DataAnalysis() { ; }
    ~DataAnalysis() { ; }

};


#endif //JABIDO_PA8_DATAANALYSIS_H

