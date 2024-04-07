//
// Created by Gregory Jabido on 4/5/24.
//

#include "Data.h"

/*************************************************************
* Function: int Data::getRecord() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the record of the data.
* Input parameters: None
* Returns: int
* Preconditions: None
* Postconditions: None
*************************************************************/

int Data::getRecord() const {
    return record;
}

/*************************************************************
* Function: void Data::setRecord(int record)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the record of the data.
* Input parameters:
*     - record: int
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setRecord(int record) {
    Data::record = record;
}

/*************************************************************
* Function: int Data::getId() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the ID of the data.
* Input parameters: None
* Returns: int
* Preconditions: None
* Postconditions: None
*************************************************************/

int Data::getId() const {
    return id;
}

/*************************************************************
* Function: void Data::setId(int id)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the ID of the data.
* Input parameters:
*     - id: int
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setId(int id) {
    Data::id = id;
}

/*************************************************************
* Function: const string &Data::getName() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the name of the data.
* Input parameters: None
* Returns: const string &
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& Data::getName() const {
    return name;
}

/*************************************************************
* Function: void Data::setName(const string &name)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the name of the data.
* Input parameters:
*     - name: const string &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setName(const string& name) {
    Data::name = name;
}

/*************************************************************
* Function: const string &Data::getEmail() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the email of the data.
* Input parameters: None
* Returns: const string &
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& Data::getEmail() const {
    return email;
}

/*************************************************************
* Function: void Data::setEmail(const string &email)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the email of the data.
* Input parameters:
*     - email: const string &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setEmail(const string& email) {
    Data::email = email;
}

/*************************************************************
* Function: int Data::getUnits() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the units of the data.
* Input parameters: None
* Returns: int
* Preconditions: None
* Postconditions: None
*************************************************************/

int Data::getUnits() const {
    return units;
}

/*************************************************************
* Function: void Data::setUnits(int units)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the units of the data.
* Input parameters:
*     - units: int
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setUnits(int units) {
    Data::units = units;
}

/*************************************************************
* Function: const string &Data::getProgram() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the program of the data.
* Input parameters: None
* Returns: const string &
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& Data::getProgram() const {
    return program;
}

/*************************************************************
* Function: void Data::setProgram(const string &program)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the program of the data.
* Input parameters:
*     - program: const string &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setProgram(const string& program) {
    Data::program = program;
}

/*************************************************************
* Function: const string &Data::getLevel() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the level of the data.
* Input parameters: None
* Returns: const string &
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& Data::getLevel() const {
    return level;
}

/*************************************************************
* Function: void Data::setLevel(const string &level)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the level of the data.
* Input parameters:
*     - level: const string &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setLevel(const string& level) {
    Data::level = level;
}

/*************************************************************
* Function: int Data::getAbsences() const
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Returns the absences of the data.
* Input parameters: None
* Returns: int
* Preconditions: None
* Postconditions: None
*************************************************************/

int Data::getAbsences() const {
    return absences;
}

/*************************************************************
* Function: void Data::setAbsences(int absences)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Sets the absences of the data.
* Input parameters:
*     - absences: int
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::setAbsences(int absences) {
    Data::absences = absences;
}

/*************************************************************
* Function: Data::Data(int record, int id, const string &name, const string &email, int units, const string &program,
*           const string &level, int absences)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Constructor for the Data class.
* Input parameters:
*     - record: int
*     - id: int
*     - name: const string &
*     - email: const string &
*     - units: int
*     - program: const string &
*     - level: const string &
*     - absences: int
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

Data::Data(int record, int id, const string& name, const string& email, int units, const string& program,
    const string& level, int absences) : record(record), id(id), name(name), email(email), units(units),
    program(program), level(level), absences(absences) {}

/*************************************************************
* Function: Data::~Data()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Destructor for the Data class.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

Data::~Data() {

}

/*************************************************************
* Function: Data::Data()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Default constructor for the Data class.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

Data::Data() {
    record = 0;
    name = "";
    email = "";
    program = "";
    level = "";
    absences = 0;
}

/*************************************************************
* Function: void Data::markAbsence()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Marks an absence for the current date and updates the absence count.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::markAbsence() {
    time_t now = time(0);
    tm* date = localtime(&now);
    std::stringstream ss;
    ss << date->tm_year + 1900 << '-' << date->tm_mon + 1 << '-' << date->tm_mday;
    string currentDate = ss.str();
    absenceDates.push(currentDate);
    absences++;
}

/*************************************************************
* Function: ostream &operator<<(ostream &os, const Data &data)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Overloaded stream insertion operator to display Data object.
* Input parameters:
*     - os: ostream &
*     - data: const Data &
* Returns: ostream &
* Preconditions: None
* Postconditions: None
*************************************************************/

ostream& operator<<(ostream& os, const Data& data) {
    //os << data.getRecord() << "/" << data.getId() << "/" << data.getName() << "/" << data.getEmail() << "/" << data.getUnits() << "/" << data.getProgram() << "/" << data.getAbsences() << endl;
    os << "|" << std::setw(10) << data.getRecord() << " | "
        << std::setw(10) << data.getId() << " | "
        << std::setw(20) << data.getName() << " | "
        << std::setw(25) << data.getEmail() << " | "
        << std::setw(5) << data.getUnits() << " | "
        << std::setw(10) << data.getProgram() << " | "
        << std::setw(5) << data.getAbsences() << endl;
    return os;
}

/*************************************************************
* Function: void Data::displayAbsenceDates()
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Displays the absence dates for the Data object.
* Input parameters: None
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::displayAbsenceDates() {
    absenceDates.display();
}

/*************************************************************
* Function: void Data::editAbsences(const string& absenceDate)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Edits the absences by removing a specific absence date.
* Input parameters:
*     - absenceDate: const string &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::editAbsences(const string& absenceDate) {
    for (auto i = absenceDates.getStack().begin(); i != absenceDates.getStack().end(); ++i) {
        if (*i == absenceDate) {
            absenceDates.getStack().erase(i);
            --absences;
            cout << "|" << absenceDate << " has been removed." << endl;
            return;
        }
    }
    cout << "|No absence found for: " << absenceDate << endl;
}

/*************************************************************
* Function: void Data::printRecentAbsenceToFile(ofstream &outfile)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Prints the most recent absence date to a file.
* Input parameters:
*     - outfile: ofstream &
* Returns: void
* Preconditions: None
* Postconditions: None
*************************************************************/

void Data::printRecentAbsenceToFile(ofstream& outfile) {
    //absenceDates.printRecentAbsenceDateToFile(outfile);
    if (!absenceDates.isEmpty()) {
        outfile << "|" << absenceDates.peek() << endl;
    }
}

/*************************************************************
* Function: ofstream &operator<<(ofstream &outfile, const Data &data)
* Date Created: 04/05/2024
* Date Last Modified: 04/07/2024
* Description: Overloaded stream insertion operator to write Data object to a file.
* Input parameters:
*     - outfile: ofstream &
*     - data: const Data &
* Returns: ofstream &
* Preconditions: None
* Postconditions: None
*************************************************************/

ofstream& operator<<(ofstream& outfile, const Data& data) {
    string units;
    if (data.getUnits() == -1) {
        units = "AU";
    }
    else {
        units = std::to_string(data.getUnits());
    }
    outfile << "|" << std::setw(10) << data.getRecord() << " | "
        << std::setw(10) << data.getId() << " | "
        << std::setw(20) << data.getName() << " | "
        << std::setw(25) << data.getEmail() << " | "
        << std::setw(5) << units << " | "
        << std::setw(10) << data.getProgram() << " | "
        << std::setw(5) << data.getAbsences() << endl;
    return outfile;
}