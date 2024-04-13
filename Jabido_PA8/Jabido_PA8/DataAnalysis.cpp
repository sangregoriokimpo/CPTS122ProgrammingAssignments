//
// Created by Gregory Jabido on 4/11/24.
//

#include "DataAnalysis.h"



/*************************************************************
* Function: DataAnalysis::insertData()
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Inserts data from a CSV stream into respective trees based on transaction type.
* Input parameters: None
* Returns: None
* Preconditions: CSV stream (mCsvStream) is open and contains data.
* Postconditions: Data is inserted into appropriate trees (mTreeSold or mTreePurchased).
*************************************************************/

void DataAnalysis::insertData() {
    string line;
    getline(mCsvStream, line);//ignore header
    while (getline(mCsvStream, line)) {

        std::istringstream ss(line);
        string unitStr, typeStr, transactionStr;
        getline(ss, unitStr, ',');
        getline(ss, typeStr, ',');
        getline(ss, transactionStr, ',');
        transactionStr.erase(std::remove_if(transactionStr.begin(), transactionStr.end(), ::isspace), transactionStr.end());

        //cout << "Units: " << endl;
        //cout << unitStr << endl;
        //cout << "Type: " << endl;
        //cout << typeStr << endl;
        //cout << "Transaction: " << endl;
        //cout << transactionStr << endl;
        //cout << "|Line: " << endl;
        //cout << line << endl;
        int units = stoi(unitStr);
        if (transactionStr == "Sold") {
            mTreeSold.insert(typeStr, units);
        }
        else if (transactionStr == "Purchased") {
            mTreePurchased.insert(typeStr, units);
        }
    }
    mCsvStream.close();
}

/*************************************************************
* Function: DataAnalysis::openFile(const string &filename)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Opens a CSV file for reading.
* Input parameters:
    - filename: A string containing the name of the CSV file to open.
* Returns: None
* Preconditions: None
* Postconditions: If successful, mCsvStream is opened with the specified file.
*                If unsuccessful, an error message is printed and the program exits.
*************************************************************/

void DataAnalysis::openFile(const string& filename) {
    mCsvStream.open(filename);
    if (!mCsvStream.is_open()) {
        std::cerr << "|Error opening file: " << filename << endl;
        exit(1);
    }
}

/*************************************************************
* Function: DataAnalysis::displayTrends() const
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Displays trends by printing the most and least sold/purchased products.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: Trends are printed to the console.
*************************************************************/

void DataAnalysis::displayTrends() const {
    cout << "|Trends " << endl;
    cout << "|Most sold product: " << endl;
    mTreeSold.getLargest()->printData();
    cout << "|Least sold product: " << endl;
    mTreeSold.getSmallest()->printData();
    cout << "|Most purchased product: " << endl;
    mTreePurchased.getLargest()->printData();
    cout << "|Least purchased product: " << endl;
    mTreePurchased.getSmallest()->printData();
}

/*************************************************************
* Function: DataAnalysis::runAnalysis(const string &filename)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Runs the analysis on the specified CSV file.
* Input parameters:
    - filename: A string containing the name of the CSV file to analyze.
* Returns: None
* Preconditions: None
* Postconditions: The analysis is performed and results are displayed.
*************************************************************/

void DataAnalysis::runAnalysis(const string& filename) {
    openFile(filename);
    insertData();

    cout << "|Sold Products:" << endl;
    mTreeSold.inOrderTraversal();
    cout << endl << "|Purchased Products:" << endl;
    mTreePurchased.inOrderTraversal();
    displayTrends();
}

/*************************************************************
* Function: DataAnalysis::runAnalysis(const string &filename)
* Date Created: 04/10/2024
* Date Last Modified: 04/12/2024
* Description: Runs the analysis on the specified CSV file.
* Input parameters:
    - filename: A string containing the name of the CSV file to analyze.
* Returns: None
* Preconditions: None
* Postconditions: The analysis is performed and results are displayed.
*************************************************************/

void DataAnalysis::testBST() {
    mTreePurchased.insert("Test1", 1);
    mTreePurchased.insert("Test2", 2);
    mTreePurchased.insert("Test3", 3);
    mTreePurchased.insert("Test4", 4);
    mTreePurchased.insert("Test5", 5);
    mTreePurchased.insert("Test6", 6);
    mTreePurchased.insert("Test7", 7);
    mTreePurchased.insert("Test8", 8);
    mTreePurchased.insert("Test9", 9);
    mTreePurchased.insert("Test10", 10);

    mTreeSold.insert("Test1", 1);
    mTreeSold.insert("Test2", 2);
    mTreeSold.insert("Test3", 3);
    mTreeSold.insert("Test4", 4);
    mTreeSold.insert("Test5", 5);
    mTreeSold.insert("Test6", 6);
    mTreeSold.insert("Test7", 7);
    mTreeSold.insert("Test8", 8);
    mTreeSold.insert("Test9", 9);
    mTreeSold.insert("Test10", 10);
    cout << "|Tree sold: " << endl;
    mTreeSold.inOrderTraversal();
    cout << "|Tree Purchased: " << endl;
    mTreePurchased.inOrderTraversal();

}
