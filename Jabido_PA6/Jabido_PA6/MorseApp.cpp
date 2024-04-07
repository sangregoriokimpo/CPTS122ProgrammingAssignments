//
// Created by Gregory Jabido on 3/20/24.
//

#include <sstream>
#include "MorseApp.h"

/*************************************************************
* Function: run_system ()
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

/*************************************************************
* Function: insertMorseTable()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Reads Morse code mappings from a file and
* inserts them into a binary search tree.
* Input parameters: filePath - the path to the file
* containing Morse code mappings
* Returns: None.
* Preconditions: None.
* Postconditions: The Morse code mappings are
* inserted into the binary search tree.
*************************************************************/

void MorseApp::insertMorseTable(const string filePath) {
    std::ifstream FILE(filePath);
    if (!FILE.is_open()) {
        std::cerr << "|Unable to open file: " << filePath << endl;
    }
    string line;
    while (getline(FILE, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream ss(line);
        string token;
        if (getline(ss, token, '|')) {
            char key = token[0];
            if (getline(ss, token)) {
                bst.insert(key, token);
            }
        }
    }
    FILE.close();
}

/*************************************************************
* Function: translate()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Reads text from a file, translates it using
* Morse code mappings stored in a binary search tree, and
* prints the translations.
* Input parameters: filePath - the path to the file
* containing text to be translated
* Returns: None.
* Preconditions: None.
* Postconditions: The translations of the text are printed.
*************************************************************/

void MorseApp::translate(const string& filePath) {
    std::ifstream FILE(filePath);
    if (!FILE.is_open()) {
        std::cerr << "|Unable to open file: " << filePath << endl;
    }
    string line;
    string translation;
    while (getline(FILE, line)) {
        translation = bst.convert(line);
        cout << translation << endl;
    }
    FILE.close();
}

/*************************************************************
* Function: printBST()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Initiates the printing of the binary
* search tree containing Morse code mappings.
* Input parameters: None.
* Returns: None.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

void MorseApp::printBST() {
    bst.printBST();
}

/*************************************************************
* Function: printInOrder()
* Date Created: 3/23/24
* Date Last Modified: 3/24/24
* Description: Initiates the printing of the Morse code
* mappings stored in the binary search tree in sorted order.
* Input parameters: None.
* Returns: None.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

void MorseApp::printInOrder() {
    bst.printBSTinOrder();
}

/*************************************************************
* Function: runApplication()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Runs the Morse code translation application.
* Input parameters: None.
* Returns: None.
* Preconditions: None.
* Postconditions: The application is executed until the
* user chooses to exit.
*************************************************************/

void MorseApp::runApplication() {
    clearScreen();
    int choice;
    bool exitFlag = false;
    insertMorseTable("mt.txt");
    while (!exitFlag) {
        printMenu();
        exitFlag = getChoice();
    }
}

/*************************************************************
* Function: printMenu()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Prints the menu options for the
* Morse code application.
* Input parameters: None.
* Returns: None.
* Preconditions: None.
* Postconditions: None.
*************************************************************/

void MorseApp::printMenu() {
    cout << "|Morse Code Application " << endl;
    cout << "|1. Translate Convert.txt " << endl;
    cout << "|2. Translate custom text " << endl;
    cout << "|3. Display BST " << endl;
    cout << "|4. In order traverse BST" << endl;
    cout << "|5. Exit " << endl;
    cout << endl;
}

/*************************************************************
* Function: getChoice()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Gets the user's choice from the menu and
* executes the corresponding functionality.
* Input parameters: None.
* Returns: A boolean indicating whether the user chose
* to exit the application.
* Preconditions: None.
* Postconditions: The user's choice is processed and
* the corresponding functionality is executed.
*************************************************************/

bool MorseApp::getChoice() {
    int choice;
    string text;
    bool exitFlag = false;

    cout << "|Enter Choice: ";
    cin >> choice;
    cin.ignore();
    switch (choice) {
    case 1:
        clearScreen();
        translate("Convert.txt");
        break;

    case 2:
        clearScreen();
        cout << "|Enter text: ";
        getline(cin, text);
        translateText(text);
        break;

    case 3:
        clearScreen();
        bst.printBST();
        break;

    case 4:
        clearScreen();
        bst.printBSTinOrder();
        break;

    case 5:
        clearScreen();
        exitFlag = true;
        break;

    default:
        clearScreen();
        cout << "|Enter valid option" << endl;
        break;
    }

    return exitFlag;
}

/*************************************************************
* Function: translateText()
* Date Created: 3/23/24
* Date Last Modified: 3/23/24
* Description: Translates custom text using Morse code
* mappings stored in the binary search tree.
* Input parameters: text - the text to be translated
* Returns: None.
* Preconditions: None.
* Postconditions: The translation of the text is printed.
*************************************************************/

void MorseApp::translateText(const string& text) {
    string txt;
    txt = bst.convert(text);
    cout << "|Translate text " << endl;
    cout << txt << endl;
}
