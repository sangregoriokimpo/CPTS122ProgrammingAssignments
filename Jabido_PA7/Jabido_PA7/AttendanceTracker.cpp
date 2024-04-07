//
// Created by Gregory Jabido on 4/5/24.
//
#include "AttendanceTracker.h"
struct student {
    int record = 0;
    int id = 0;
    string firstName;
    string lastName;
    string name;
    string email;
    int units = 0;
    string program;
    string level;
};

/*************************************************************
* Function: importRecords(const string &fileName)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Imports records from a CSV file into the master list.
* Input parameters: fileName - the name of the CSV file to import
* Returns: void
* Preconditions: None
* Postconditions: Records are imported into the master list.
*************************************************************/

void AttendanceTracker::importRecords(const string& fileName) {
    //https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus
    //https://en.cppreference.com/w/cpp/regex/regex_iterator
    masterList.clear();
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "|Unable to open file" << fileName << std::endl;
        return;
    }

    std::regex pattern(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::sregex_token_iterator it(line.begin(), line.end(), pattern, -1);
        std::sregex_token_iterator end;

        student s;

        if (it != end) {
            s.record = std::stoi(*it); // First token is record
            ++it;
        }
        if (it != end) {
            s.id = std::stoi(*it); // Second token is ID
            ++it;
        }
        if (it != end) {
            s.name = *it; // Third token is name
            ++it;
        }
        if (it != end) {
            s.email = *it; // Fourth token is email
            ++it;
        }
        if (it != end) {
            std::string un = *it; // Fifth token is units
            if (un == "AU") {
                s.units = -1; // Handling withdrawn/failed units
            }
            else {
                s.units = std::stoi(un);
            }
            ++it;
        }
        if (it != end) {
            s.program = *it; // Sixth token is program
            ++it;
        }
        if (it != end) {
            s.level = *it; // Seventh token is level
            ++it;
        }

        s.name.erase(std::remove(s.name.begin(), s.name.end(), '\"'), s.name.end());
        //    Data(int record, int id, const string &name, const string &email, int units, const string &program,
        //         const string &level, int absences);
        Data data(s.record, s.id, s.name, s.email, s.units, s.program, s.level, 0);
        masterList.insert(data);
    }
    file.close();
}

/*************************************************************
* Function: searchByID(const int &id)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Searches for a student by ID in the master list.
* Input parameters: id - the ID to search for
* Returns: Node pointer to the found student, or nullptr if not found
* Preconditions: None
* Postconditions: None
*************************************************************/

Node<Data>* AttendanceTracker::searchByID(const int& id) {
    Node<Data>* pCurr = masterList.getPHead();
    while (pCurr != nullptr) {
        if (pCurr->getData().getId() == id) {
            return pCurr;
        }
        pCurr = pCurr->getPNext();
    }
    return nullptr;
}

/*************************************************************
* Function: searchByName(const string &name)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Searches for a student by name in the master list.
* Input parameters: name - the name to search for
* Returns: Node pointer to the found student, or nullptr if not found
* Preconditions: None
* Postconditions: None
*************************************************************/

Node<Data>* AttendanceTracker::searchByName(const string& name) {
    Node<Data>* pCurr = masterList.getPHead();
    while (pCurr != nullptr) {
        if (pCurr->getData().getName() == name) {
            return pCurr;
        }
        pCurr = pCurr->getPNext();
    }
    return nullptr;
}

/*************************************************************
* Function: displayRecords()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Displays all records stored in the master list.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void AttendanceTracker::displayRecords() {
    masterList.printList();
}

/*************************************************************
* Function: testInsert()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Inserts test data into the master list for testing purposes.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Test data is inserted into the master list.
*************************************************************/

void AttendanceTracker::testInsert() {
    Data testData1(1, 111, "name", "email", 1, "program", "level", 0);
    Data testData2(2, 222, "name", "email", 2, "program", "level", 0);
    Data testData3(3, 333, "name", "email", 3, "program", "level", 0);

    masterList.insert(testData1);
    masterList.insert(testData2);
    masterList.insert(testData3);
}

/*************************************************************
* Function: testAbsences()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Tests the functionality of marking absences for a dummy student.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Absences are marked and absence dates are displayed.
*************************************************************/

void AttendanceTracker::testAbsences() {
    Data ta(0, 000, "name", "email", 0, "program", "level", 0);
    ta.markAbsence();
    ta.markAbsence();
    ta.displayAbsenceDates();
}

/*************************************************************
* Function: markAbsences()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Marks absences for students based on user input.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Absences are marked for selected students.
*************************************************************/

void AttendanceTracker::markAbsences() {
    vector<int>absentees;
    displayRecords();
    cout << "|Enter record # of absentees: ";
    string line;
    getline(cin, line);
    std::stringstream ss(line);
    int num;
    while (ss >> num) {
        absentees.push_back(num);
    }
    Node<Data>* pCurr = masterList.getPHead();
    while (pCurr != nullptr) {
        if (find(absentees.begin(), absentees.end(), pCurr->getData().getRecord()) != absentees.end()) {
            cout << "|" << pCurr->getData().getName() << " has been marked absent" << endl;
            pCurr->getData().markAbsence();
        }
        pCurr = pCurr->getPNext();
    }
}

/*************************************************************
* Function: editAbsences()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Edits absences for a specific student based on user input.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Absences for the selected student are edited.
*************************************************************/

void AttendanceTracker::editAbsences() {
    string identifier;
    cout << "|Enter the ID number or name of the student whose absences you want to edit: ";
    getline(cin, identifier);

    Node<Data>* pSearch;

    if (isdigit(identifier[0])) {
        int id = std::stoi(identifier);
        pSearch = searchByID(id);
    }
    else {
        pSearch = searchByName(identifier);
    }
    if (pSearch == nullptr) {
        cout << "|Student not found" << endl;
        return;
    }
    string date;
    cout << "|Enter the date of absence you want to edit YYYY-MM-DD: ";
    getline(cin, date);
    pSearch->getData().editAbsences(date);
}

/*************************************************************
* Function: loadMasterList(const string &fileName)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Loads the master list from a CSV file.
* Input parameters: fileName - the name of the CSV file to load
* Returns: void
* Preconditions: None
* Postconditions: Master list is populated with data from the CSV file.
*************************************************************/

void AttendanceTracker::loadMasterList(const string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "|Unable to open file" << fileName << std::endl;
        return;
    }

    std::regex pattern(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::sregex_token_iterator it(line.begin(), line.end(), pattern, -1);
        std::sregex_token_iterator end;

        student s;

        if (it != end) {
            s.record = std::stoi(*it); // First token is record
            ++it;
        }
        if (it != end) {
            s.id = std::stoi(*it); // Second token is ID
            ++it;
        }
        if (it != end) {
            s.name = *it; // Third token is name
            ++it;
        }
        if (it != end) {
            s.email = *it; // Fourth token is email
            ++it;
        }
        if (it != end) {
            std::string un = *it; // Fifth token is units
            if (un == "AU") {
                s.units = -1; // Handling withdrawn/failed units
            }
            else {
                s.units = std::stoi(un);
            }
            ++it;
        }
        if (it != end) {
            s.program = *it; // Sixth token is program
            ++it;
        }
        if (it != end) {
            s.level = *it; // Seventh token is level
            ++it;
        }

        s.name.erase(std::remove(s.name.begin(), s.name.end(), '\"'), s.name.end());
        //    Data(int record, int id, const string &name, const string &email, int units, const string &program,
        //         const string &level, int absences);
        Data data(s.record, s.id, s.name, s.email, s.units, s.program, s.level, 0);
        masterList.insert(data);
    }
    file.close();
}

/*************************************************************
* Function: storeMasterList(const string &fileName)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Stores the master list to a CSV file.
* Input parameters: fileName - the name of the CSV file to store
* Returns: void
* Preconditions: None
* Postconditions: Master list is saved to the CSV file.
*************************************************************/

void AttendanceTracker::storeMasterList(const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "|Unable to open file" << fileName << std::endl;
        return;
    }
    //    Data(int record, int id, const string &name, const string &email, int units, const string &program,
    //         const string &level, int absences);
    file << ",ID,Name,Email,Units,Program,Level" << endl;
    Node <Data>* pCurr = masterList.getPHead();
    while (pCurr != nullptr) {
        Data d = pCurr->getData();
        string units;
        if (d.getUnits() == -1) {
            units = "AU";
        }
        else {
            units = std::to_string(d.getUnits());
        }
        file << d.getRecord() << "," << d.getId() << ",\"" << d.getName() << "\"," << d.getEmail()
            << "," << units << "," << d.getProgram() << "," << d.getLevel() << endl;
        pCurr = pCurr->getPNext();
    }
    file.close();
}

/*************************************************************
* Function: generateReportSubMenu()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Displays a submenu for generating reports.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Depending on user input, generates report for all students with their most recent absences
*                 or generates report for all students matching or exceeding a specific threshold.
*************************************************************/

void AttendanceTracker::generateReportSubMenu() {
    string choice;
    cout << "|1. Generate report for all students with their most recent absences" << endl;
    cout << "|2. Generate report for all students matching or exceeding a specific threshold." << endl;
    cout << "|Enter option: ";
    getline(cin, choice);
    switch (std::stoi(choice)) {
    case 1:
        generateReportAllStudents();
        break;

    case 2:
        generateReportThreshold();
        break;

    default:
        cout << "|Enter valid option" << endl;
    }
}

/*************************************************************
* Function: generateReportAllStudents()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Generates a report for all students with their most recent absences.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Report is generated and saved to "ReportAllStudents.txt".
*************************************************************/

void AttendanceTracker::generateReportAllStudents() {
    ofstream outfile("ReportAllStudents.txt");
    if (!outfile) {
        std::cerr << "|Unable to open file for writing" << endl;
        return;
    }
    Node<Data>* pCurr = masterList.getPHead();
    outfile << "|" << std::setw(10) << "Record" << " | "
        << std::setw(10) << "ID" << " | "
        << std::setw(20) << "Name" << " | "
        << std::setw(25) << "Email" << " | "
        << std::setw(5) << "Units" << " | "
        << std::setw(10) << "Program" << " | "
        << std::setw(5) << "Absences" << endl;
    while (pCurr != nullptr) {
        outfile << pCurr->getData();
        pCurr->getData().printRecentAbsenceToFile(outfile);
        pCurr = pCurr->getPNext();
    }
    outfile.close();
}

/*************************************************************
* Function: generateReportThreshold()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Generates a report for all students matching or exceeding a specific absence threshold.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: Report is generated and saved to "ReportThresholdStudents.txt".
*************************************************************/

void AttendanceTracker::generateReportThreshold() {
    string thresholdStr;
    int threshold;

    cout << "|Enter the threshold for absences: ";
    getline(cin, thresholdStr);
    try {
        threshold = stoi(thresholdStr);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "|Invalid input. Please enter a valid integer." << endl;
        return;
    }

    ofstream outfile("ReportThresholdStudents.txt");
    if (!outfile) {
        std::cerr << "|Unable to open file for writing" << endl;
        return;
    }
    Node<Data>* pCurr = masterList.getPHead();
    outfile << "|" << std::setw(10) << "Record" << " | "
        << std::setw(10) << "ID" << " | "
        << std::setw(20) << "Name" << " | "
        << std::setw(25) << "Email" << " | "
        << std::setw(5) << "Units" << " | "
        << std::setw(10) << "Program" << " | "
        << std::setw(5) << "Absences" << endl;
    while (pCurr != nullptr) {
        if (pCurr->getData().getAbsences() >= threshold) {
            outfile << pCurr->getData();
            pCurr->getData().printRecentAbsenceToFile(outfile);
        }
        pCurr = pCurr->getPNext();
    }
    outfile.close();
}

/*************************************************************
* Function: run()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Runs the attendance tracker application.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: The user interacts with the application until choosing to exit.
*************************************************************/

void AttendanceTracker::run() {
    bool exitflag = false;
    string option;
    int op;
    while (!exitflag) {
        displayMenu();
        cout << "|Enter option: ";
        getline(cin, option);
        op = std::stoi(option);
        switch (op) {
        case 1:// Option 1: Reads the classlist.csv course file and destroys and overwrites the master list.
            clearScreen();
            importRecords("classList.csv");
            displayRecords();
            break;
        case 2:// Option 2: Populates the master list with previous nodes from master.csv file
            clearScreen();
            loadMasterList("master.csv");
            displayRecords();
            break;
        case 3:// Option 3: Stores the contents of the master list's nodes to the master.csv file
            clearScreen();
            storeMasterList("master.csv");
            break;
        case 4:// Option 4: Marks absences for the current day and pushes data to the stack
            clearScreen();
            displayRecords();
            markAbsences();
            clearScreen();
            displayRecords();
            break;
        case 5:// BONUS: Option 5: Prompts for an ID or name of student to edit absences
            clearScreen();
            displayRecords();
            editAbsences();
            displayRecords();
            break;
        case 6:// Option 6: Leads to submenu for generating reports
            clearScreen();
            generateReportSubMenu();
            break;
        case 7:// Option 7: Exit the program.
            clearScreen();
            exitflag = true;
            break;

        default:// Default
            cout << "|Enter valid option" << endl;
            break;
        }
    }
}

/*************************************************************
* Function: displayMenu()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Displays the main menu of the attendance tracker application.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: The main menu is displayed for user interaction.
*************************************************************/

void AttendanceTracker::displayMenu() {
    cout << "|Attendance Tracker" << endl;
    cout << "|1. Import Records" << endl;
    cout << "|2. Load master list" << endl;
    cout << "|3. Store master list" << endl;
    cout << "|4. Mark absences" << endl;
    cout << "|5. Edit absences" << endl;
    cout << "|6. Generate reports" << endl;
    cout << "|7. Exit application" << endl;
}