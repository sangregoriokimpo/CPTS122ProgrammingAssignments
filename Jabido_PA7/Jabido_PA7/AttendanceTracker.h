#pragma once
//
// Created by Gregory Jabido on 4/5/24.
//

#ifndef JABIDO_PA7_ATTENDANCETRACKER_H
#define JABIDO_PA7_ATTENDANCETRACKER_H

#include "PA7Header.h"
#include "List.h"
#include "Data.h"
#include "Node.h"
#include "Stack.h"


class AttendanceTracker {
private:
    List <Data> masterList;
public:
    Node<Data>* searchByID(int const& id);

    Node<Data>* searchByName(string const& name);

    void displayRecords();

    void importRecords(const string& fileName);// Option 1: Reads the classlist.csv course file and destroys and overwrites the master list.


    // Option 2: Populates the master list with previous nodes from master.csv file
    void loadMasterList(const string& fileName);

    // Option 3: Stores the contents of the master list's nodes to the master.csv file
    void storeMasterList(const string& fileName);

    // Option 4: Marks absences for the current day and pushes data to the stack
    void markAbsences();

    // BONUS: Option 5: Prompts for an ID or name of student to edit absences
    void editAbsences();

    // Option 6: Leads to submenu for generating reports
    void generateReportSubMenu();

    // Submenu Option 1: Generates report for all students with their most recent absence
    void generateReportAllStudents();

    // Submenu Option 2: Generates report for students with absences matching or exceeding a threshold
    void generateReportThreshold();

    void testInsert();

    void testAbsences();

    void run();

    void displayMenu();


};


#endif //JABIDO_PA7_ATTENDANCETRACKER_H
