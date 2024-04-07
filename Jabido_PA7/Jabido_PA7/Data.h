#pragma once
//
// Created by Gregory Jabido on 4/5/24.
//

#ifndef JABIDO_PA7_DATA_H
#define JABIDO_PA7_DATA_H

#include "PA7Header.h"
#include "Stack.h"
#include <vector>

class Data {
private:
    int record;
    int id;
    string name;
    string email;
    int units;
    string program;
    string level;
    int absences;
    Stack<string> absenceDates;


public:
    Data(int record, int id, const string& name, const string& email, int units, const string& program,
        const string& level, int absences);

    Data();

    virtual ~Data();

    int getAbsences() const;

    void setAbsences(int absences);

    int getRecord() const;

    void setRecord(int record);

    int getId() const;

    void setId(int id);

    const string& getName() const;

    void setName(const string& name);

    const string& getEmail() const;

    void setEmail(const string& email);

    int getUnits() const;

    void setUnits(int units);

    const string& getProgram() const;

    void setProgram(const string& program);

    const string& getLevel() const;

    void setLevel(const string& level);

    void markAbsence();

    void displayAbsenceDates();

    void editAbsences(const string& absenceDate);

    void printRecentAbsenceToFile(ofstream& outfile);

    //friend std::ostream& operator<<(std::ostream& os, const DietPlan& plan);
    friend ostream& operator<<(ostream& os, const Data& data);

    friend ofstream& operator<<(ofstream& outfile, const Data& data);
};


#endif //JABIDO_PA7_DATA_H

