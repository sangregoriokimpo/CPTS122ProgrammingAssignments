#pragma once
//
// Created by Gregory Jabido on 2/23/24.
//

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

#include "ExercisePlan.h"
/*************************************************************
* Function: getGoalSteps()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the goal steps for the exercise plan.
* Input parameters: None
* Returns: Integer value representing the goal steps.
* Preconditions: None
* Postconditions: None
*************************************************************/

int ExercisePlan::getGoalSteps() const {
    return goalSteps;
}

/*************************************************************
* Function: setGoalSteps()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the goal steps for the exercise plan.
* Input parameters:
*     - goalSteps: An integer representing the goal steps to be set.
* Returns: None
* Preconditions: None
* Postconditions: The goal steps for the exercise plan are updated.
*************************************************************/

void ExercisePlan::setGoalSteps(int goalSteps) {
    ExercisePlan::goalSteps = goalSteps;
}

/*************************************************************
* Function: getPlanName()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the name of the exercise plan.
* Input parameters: None
* Returns: Constant reference to a string representing
* the name of the exercise plan.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& ExercisePlan::getPlanName() const {
    return planName;
}

/*************************************************************
* Function: setPlanName()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the name of the exercise plan.
* Input parameters:
*     - planName: A constant reference to a string representing
*     the name of the exercise plan.
* Returns: None
* Preconditions: None
* Postconditions: The name of the exercise plan is updated.
*************************************************************/

void ExercisePlan::setPlanName(const string& planName) {
    ExercisePlan::planName = planName;
}

/*************************************************************
* Function: getDate()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the date of the exercise plan.
* Input parameters: None
* Returns: Constant reference to a string representing
* the date of the exercise plan.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& ExercisePlan::getDate() const {
    return date;
}

/*************************************************************
* Function: setDate()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the date of the exercise plan.
* Input parameters:
*     - date: A constant reference to a string representing
*     the date of the exercise plan.
* Returns: None
* Preconditions: None
* Postconditions: The date of the exercise plan is updated.
*************************************************************/

void ExercisePlan::setDate(const string& date) {
    ExercisePlan::date = date;
}

/*************************************************************
* Function: ExercisePlan()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Default constructor for ExercisePlan class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: An ExercisePlan object is created with
* default values.
*************************************************************/

ExercisePlan::ExercisePlan() {
    this->goalSteps = 0;
    this->planName = "";
    this->date = "";
}

/*************************************************************
* Function: ExercisePlan(int steps, const string &name, const string &date)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Parameterized constructor for ExercisePlan class.
* Input parameters:
*     - steps: An integer representing the goal steps for
*     the exercise plan.
*     - name: A constant reference to a string representing
*     the name of the exercise plan.
*     - date: A constant reference to a string representing
*     the date of the exercise plan.
* Returns: None
* Preconditions: None
* Postconditions: An ExercisePlan object is created with
* specified values for goal steps, name, and date.
*************************************************************/

ExercisePlan::ExercisePlan(int steps, const string& name, const string& date) {
    this->goalSteps = steps;
    this->planName = name;
    this->date = date;
}
/*************************************************************
* Function: ExercisePlan(const ExercisePlan &other)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Copy constructor for ExercisePlan class.
* Input parameters:
*     - other: A constant reference to another
*     ExercisePlan object to be copied.
* Returns: None
* Preconditions: None
* Postconditions: A new ExercisePlan object is created with
* the same values as the provided ExercisePlan object.
*************************************************************/

ExercisePlan::ExercisePlan(const ExercisePlan& other) {
    this->goalSteps = other.goalSteps;
    this->planName = other.planName;
    this->date = other.date;
}

/*************************************************************
* Function: ~ExercisePlan()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Destructor for ExercisePlan class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

ExercisePlan::~ExercisePlan() {
    //Destructor
}
/*************************************************************
* Function: operator<<(std::ostream &os, const ExercisePlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Overloaded stream insertion operator
* for ExercisePlan class.
* Input parameters:
*     - os: Reference to an output stream.
*     - plan: Constant reference to an ExercisePlan
*     object to be output.
* Returns: Reference to the output stream after outputting
* the ExercisePlan object.
* Preconditions: None
* Postconditions: The ExercisePlan object is output to
* the provided output stream.
*************************************************************/

std::ostream& operator<<(std::ostream& os, const ExercisePlan& plan) {
    os << "|Exercise Plan: " << plan.getPlanName() << "\n";
    os << "|Date: " << plan.getDate() << "\n";
    os << "|Goal: " << plan.getGoalSteps() << " Steps\n";

    /*os << plan.getPlanName() << "\n";
    os << plan.getDate() << "\n";
    os << plan.getGoalSteps() << "\n";*/
    return os;
}

/*************************************************************
* Function: operator>>(std::istream &is, ExercisePlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Overloaded stream extraction operator
* for ExercisePlan class.
* Input parameters:
*     - is: Reference to an input stream.
*     - plan: Reference to an ExercisePlan object
*     to store the extracted data.
* Returns: Reference to the input stream after extracting
* data into the ExercisePlan object.
* Preconditions: None
* Postconditions: Data from the input stream is extracted
* into the provided ExercisePlan object.
*************************************************************/

std::istream& operator>>(std::istream& is, ExercisePlan& plan) {
    string name;
    int steps;
    string date;

    getline(is, name);
    is >> steps;

    getline(is >> std::ws, date);
    is.ignore();

    plan.setPlanName(name);
    plan.setGoalSteps(steps);
    plan.setDate(date);

    return is;
}

/*************************************************************
* Function: editGoal()
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Allows the user to edit the goal steps for
* the exercise plan.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The goal steps for the exercise plan may
* be updated based on user input.
*************************************************************/

void ExercisePlan::editGoal() {
    int newStepGoal = 0;
    clearScreen();
    cout << "|Enter Steps: ";
    cin >> newStepGoal;
    this->setGoalSteps(newStepGoal);
}

/*************************************************************
* Function: operator<< (std::fstream &fileStream, const ExercisePlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/25/24
* Description: Overloaded insertion operator to write
* ExercisePlan object to a file stream.
* Input parameters:
*   - fileStream: Reference to the file stream where the
*   ExercisePlan object will be written.
*   - plan: Const reference to the ExercisePlan
*   object to be written.
* Returns: Reference to the file stream after writing
* the ExercisePlan object.
* Preconditions: The file stream must be open and valid.
* Postconditions: The ExercisePlan object is written
* to the file stream.
*************************************************************/

std::fstream& operator<<(std::fstream& fileStream, const ExercisePlan& plan) {
    fileStream << plan.getPlanName() << endl;
    fileStream << plan.getGoalSteps() << endl;
    fileStream << plan.getDate() << endl;
    fileStream << endl;
    return fileStream;
}

