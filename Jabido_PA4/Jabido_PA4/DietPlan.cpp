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

#include "DietPlan.h"
/*************************************************************
* Function: getGoalCalories()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the goal calories for the diet plan.
* Input parameters: None
* Returns: Integer value representing the goal calories.
* Preconditions: None
* Postconditions: None
*************************************************************/

int DietPlan::getGoalCalories() const {
    return goalCalories;
}

/*************************************************************
* Function: setGoalCalories(int goalCalories)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the goal calories for the diet plan.
* Input parameters:
*     - goalCalories: An integer representing the goal
*     calories to be set.
* Returns: None
* Preconditions: None
* Postconditions: The goal calories for the diet plan are updated.
*************************************************************/

void DietPlan::setGoalCalories(int goalCalories) {
    DietPlan::goalCalories = goalCalories;
}

/*************************************************************
* Function: getPlanName()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the name of the diet plan.
* Input parameters: None
* Returns: Constant reference to a string representing the
* name of the diet plan.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& DietPlan::getPlanName() const {
    return planName;
}

/*************************************************************
* Function: setPlanName(const string &planName)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the name of the diet plan.
* Input parameters:
*     - planName: A constant reference to a string representing
*     the name of the diet plan.
* Returns: None
* Preconditions: None
* Postconditions: The name of the diet plan is updated.
*************************************************************/

void DietPlan::setPlanName(const string& planName) {
    DietPlan::planName = planName;
}

/*************************************************************
* Function: getDate()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Returns the date of the diet plan.
* Input parameters: None
* Returns: Constant reference to a string representing
* the date of the diet plan.
* Preconditions: None
* Postconditions: None
*************************************************************/

const string& DietPlan::getDate() const {
    return date;
}
/*************************************************************
* Function: setDate(const string &date)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Sets the date of the diet plan.
* Input parameters:
*     - date: A constant reference to a string representing
*     the date of the diet plan.
* Returns: None
* Preconditions: None
* Postconditions: The date of the diet plan is updated.
*************************************************************/

void DietPlan::setDate(const string& date) {
    DietPlan::date = date;
}
/*************************************************************
* Function: DietPlan()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Default constructor for DietPlan class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: A DietPlan object is created with default values.
*************************************************************/

DietPlan::DietPlan() {
    this->goalCalories = 0;
    this->planName = "";
    this->date = "";
}

/*************************************************************
* Function: DietPlan(int calories, const std::string name, const std::string date)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Parameterized constructor for DietPlan class.
* Input parameters:
*     - calories: An integer representing the goal calories
*     for the diet plan.
*     - name: A constant reference to a string representing
*     the name of the diet plan.
*     - date: A constant reference to a string representing
*     the date of the diet plan.
* Returns: None
* Preconditions: None
* Postconditions: A DietPlan object is created with specified
* values for goal calories, name, and date.
*************************************************************/

DietPlan::DietPlan(int calories, const std::string& name, const std::string& date) {
    this->goalCalories = calories;
    this->planName = name;
    this->date = date;
}

/*************************************************************
* Function: DietPlan(const DietPlan &other)
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Copy constructor for DietPlan class.
* Input parameters:
*     - other: A constant reference to another
*     DietPlan object to be copied.
* Returns: None
* Preconditions: None
* Postconditions: A new DietPlan object is created with
* the same values as the provided DietPlan object.
*************************************************************/

DietPlan::DietPlan(const DietPlan& other) {
    this->goalCalories = other.goalCalories;
    this->planName = other.planName;
    this->date = other.date;
}

/*************************************************************
* Function: ~DietPlan()
* Date Created: 2/23/24
* Date Last Modified:
* Description: Destructor for DietPlan class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

DietPlan::~DietPlan() {
    //Destructor
}

/*************************************************************
* Function: editGoal()
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Allows the user to edit the goal calories
* for the diet plan.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: The goal calories for the diet plan
* may be updated based on user input.
*************************************************************/

void DietPlan::editGoal() {
    int newCalorieGoal = 0;
    clearScreen();
    std::cout << "|Enter Calories: ";
    std::cin >> newCalorieGoal;
    this->setGoalCalories(newCalorieGoal);
}

/*************************************************************
* Function: operator<<(std::ostream &os, const DietPlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Overloaded stream insertion operator for DietPlan class.
* Input parameters:
*     - os: Reference to an output stream.
*     - plan: Constant reference to a DietPlan object to be output.
* Returns: Reference to the output stream after outputting
* the DietPlan object.
* Preconditions: None
* Postconditions: The DietPlan object is output to the
* provided output stream.
*************************************************************/

std::ostream& operator<<(std::ostream& os, const DietPlan& plan) {
    os << "|Diet Plan: " << plan.getPlanName() << "\n";
    os << "|Date: " << plan.getDate() << "\n";
    os << "|Goal: " << plan.getGoalCalories() << " Calories \n";
    return os;
}

/*************************************************************
* Function: operator>>(std::istream &is, DietPlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Overloaded stream extraction operator
* for DietPlan class.
* Input parameters:
*     - is: Reference to an input stream.
*     - plan: Reference to a DietPlan object to store
*     the extracted data.
* Returns: Reference to the input stream after extracting
* data into the DietPlan object.
* Preconditions: None
* Postconditions: Data from the input stream is extracted
* into the provided DietPlan object.
*************************************************************/

std::istream& operator>>(std::istream& is, DietPlan& plan) {
    string name;
    int calories;
    string date;

    std::getline(is, name);
    is >> calories;

    std::getline(is >> std::ws, date);
    is.ignore();

    plan.setPlanName(name);
    plan.setGoalCalories(calories);
    plan.setDate(date);

    return is;
}

/*************************************************************
* Function: operator<< (std::fstream &fileStream, const DietPlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/25/24
* Description: Overloaded insertion operator to write DietPlan
* object to a file stream.
* Input parameters:
*   - fileStream: Reference to the file stream where the
*   DietPlan object will be written.
*   - plan: Const reference to the DietPlan object to be written.
* Returns: Reference to the file stream after writing the
* DietPlan object.
* Preconditions: The file stream must be open and valid.
* Postconditions: The DietPlan object is written to
* the file stream.
*************************************************************/

std::fstream& operator<<(std::fstream& fileStream, const DietPlan& plan) {
    fileStream << plan.getPlanName() << endl;
    fileStream << plan.getGoalCalories() << endl;
    fileStream << plan.getDate() << endl;
    fileStream << endl;
    return fileStream;
}

/*
 *
    fileStream << plan.getPlanName() << "\n";
    fileStream << plan.getGoalCalories() << "\n";
    fileStream << plan.getDate() << "\n";
    fileStream << "\n";
    return fileStream;

*/

