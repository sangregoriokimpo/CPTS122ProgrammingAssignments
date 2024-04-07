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

#pragma once

#include "FitnessAppWrapper.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/*************************************************************
* Function: loadDailyPlan(std::fstream &fileStream, T& plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Loads a daily plan from a file stream.
* Input parameters:
*     - fileStream: Reference to an input file stream.
*     - plan: Reference to a plan object to store the
*     loaded plan.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided plan object is updated
* with the loaded plan.
*************************************************************/

template<typename T>
void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, T& plan) {
    fileStream >> plan;
}

/*************************************************************
* Function: loadWeeklyPlan(std::fstream &fileStream, DietPlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Loads a weekly diet plan from a file stream.
* Input parameters:
*     - fileStream: Reference to an input file stream.
*     - weeklyPlan: Pointer to an array of DietPlan objects
*     representing the weekly plan.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided array of DietPlan objects
* is updated with the loaded weekly plan.
*************************************************************/

void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, DietPlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        //loadDailyPlan(fileStream,weeklyPlan[i]);
        fileStream >> weeklyPlan[i];
    }
}

/*************************************************************
* Function: loadWeeklyPlan(std::fstream &fileStream, ExercisePlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Loads a weekly exercise plan from a file stream.
* Input parameters:
*     - fileStream: Reference to an input file stream.
*     - weeklyPlan: Pointer to an array of ExercisePlan
*     objects representing the weekly plan.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided array of ExercisePlan
* objects is updated with the loaded weekly plan.
*************************************************************/

void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, ExercisePlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        loadDailyPlan(fileStream, weeklyPlan[i]);
    }
}

/*************************************************************
* Function: displayDailyPlan(const DietPlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Displays a daily diet plan.
* Input parameters:
*     - plan: Constant reference to a DietPlan object
*     representing the plan to be displayed.
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::displayDailyPlan(const DietPlan& plan) {
    cout << plan << endl;
}

/*************************************************************
* Function: displayDailyPlan(const ExercisePlan &plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Displays a daily exercise plan.
* Input parameters:
*     - plan: Constant reference to an ExercisePlan object
*     representing the plan to be displayed.
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan& plan) {
    cout << plan << endl;
}

/*************************************************************
* Function: displayWeeklyPlan(DietPlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/26/24
* Description: Displays a weekly diet plan.
* Input parameters:
*     - weeklyPlan: Pointer to an array of DietPlan objects
*     representing the weekly plan.
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::displayWeeklyPlan(DietPlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        //cout << weeklyPlan[i] << endl;
        displayDailyPlan(weeklyPlan[i]);
    }
}

/*************************************************************
* Function: displayWeeklyPlan(ExercisePlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/26/24
* Description: Displays a weekly exercise plan.
* Input parameters:
*     - weeklyPlan: Pointer to an array of ExercisePlan
*     objects representing the weekly plan.
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        //cout << weeklyPlan[i] << endl;
        displayDailyPlan(weeklyPlan[i]);
    }
}

/*************************************************************
* Function: storeDailyPlan(std::fstream &fileStream, const T& plan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Stores a daily plan to a file stream.
* Input parameters:
*     - fileStream: Reference to an output file stream.
*     - plan: Constant reference to a plan object
*     to be stored.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided plan object is stored
* in the file stream.
*************************************************************/

template<typename T>
void FitnessAppWrapper::storeDailyPlan(std::fstream& fileStream, const T& plan) {
    fileStream << plan;
}

/*************************************************************
* Function: storeWeeklyPlan(std::fstream &fileStream, DietPlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Stores a weekly diet plan to a file stream.
* Input parameters:
*     - fileStream: Reference to an output file stream.
*     - weeklyPlan: Pointer to an array of DietPlan
*     objects representing the weekly plan.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided array of DietPlan objects
* is stored in the file stream.
*************************************************************/

void FitnessAppWrapper::storeWeeklyPlan(std::fstream& fileStream, DietPlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        storeDailyPlan(fileStream, weeklyPlan[i]);
    }
}

/*************************************************************
* Function: storeWeeklyPlan(std::fstream &fileStream, ExercisePlan *weeklyPlan)
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Stores a weekly exercise plan to a file stream.
* Input parameters:
*     - fileStream: Reference to an output file stream.
*     - weeklyPlan: Pointer to an array of ExercisePlan
*     objects representing the weekly plan.
* Returns: None
* Preconditions: The file stream must be opened and valid.
* Postconditions: The provided array of ExercisePlan
* objects is stored in the file stream.
*************************************************************/

void FitnessAppWrapper::storeWeeklyPlan(std::fstream& fileStream, ExercisePlan* weeklyPlan) {
    for (int i = 0; i < 7; i++) {
        storeDailyPlan(fileStream, weeklyPlan[i]);
    }
}

/*************************************************************
* Function: displayMenu()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Displays the main menu of the fitness
* application.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::displayMenu() {
    cout << "|Fitness Application \n";
    cout << "|1. Load weekly diet plan from file. \n";
    cout << "|2. Load weekly exercise plan from file. \n";
    cout << "|3. Store weekly diet plan to file. \n";
    cout << "|4. Store weekly exercise plan to file. \n";
    cout << "|5. Display weekly diet plan to screen. \n";
    cout << "|6. Display weekly exercise plan to screen. \n";
    cout << "|7. Edit daily diet plan. \n";
    cout << "|8. Edit daily exercise plan. \n";
    cout << "|9. Exit. \n";
}

/*************************************************************
* Function: FitnessAppWrapper()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Default constructor for FitnessAppWrapper class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

FitnessAppWrapper::FitnessAppWrapper() {
    // Default Constructor
}

/*************************************************************
* Function: ~FitnessAppWrapper()
* Date Created: 2/23/24
* Date Last Modified: 2/23/24
* Description: Destructor for FitnessAppWrapper class.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

FitnessAppWrapper::~FitnessAppWrapper() {
    //Destructor
}

/*************************************************************
* Function: runFitnessApp()
* Date Created: 2/23/24
* Date Last Modified: 2/24/24
* Description: Runs the fitness application.
* Input parameters: None
* Returns: None
* Preconditions: None
* Postconditions: None
*************************************************************/

void FitnessAppWrapper::runFitnessApp() {
    int choice = 0;
    bool exitFlag = false;
    dietFileStream.open("DietPlans.txt");
    exerciseFileStream.open("ExercisePlans.txt");
    string searchName;
    do {
        displayMenu();
        cout << "|Enter Choice: ";
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        dietFileStream.clear();
        dietFileStream.seekg(0, std::ios::beg);
        exerciseFileStream.clear();
        exerciseFileStream.seekg(0, std::ios::beg);
        switch (choice) {
        case 1://Load weekly diet plan from file.
            clearScreen();
            loadWeeklyPlan(dietFileStream, weeklyDietPlans);
            break;

        case 2://Load weekly exercise plan from file.
            clearScreen();
            loadWeeklyPlan(exerciseFileStream, weeklyExercisePlans);
            break;

        case 3://Store weekly diet plan to file.
            storeWeeklyPlan(dietFileStream, weeklyDietPlans);
            break;

        case 4://Store weekly exercise plan to file.
            storeWeeklyPlan(exerciseFileStream, weeklyExercisePlans);
            break;

        case 5://Display weekly diet plan to screen.
            clearScreen();
            displayWeeklyPlan(weeklyDietPlans);
            break;

        case 6://Display weekly exercise plan to screen.
            clearScreen();
            displayWeeklyPlan(weeklyExercisePlans);
            break;

        case 7://Edit daily diet plan.
            clearScreen();
            displayWeeklyPlan(weeklyDietPlans);
            editPlan(weeklyDietPlans);
            break;

        case 8://Edit daily exercise plan.
            clearScreen();
            displayWeeklyPlan(weeklyExercisePlans);
            editPlan(weeklyExercisePlans);
            break;

        case 9://Exit program, and store the most recent files.
            storeWeeklyPlan(dietFileStream, weeklyDietPlans);
            storeWeeklyPlan(dietFileStream, weeklyExercisePlans);
            exitFlag = true;
            break;

        default://Default case.
            cout << "|Enter Valid Option \n";
            break;
        }

    } while (!exitFlag);
}

/*************************************************************
* Function: editPlan<T>(T *weeklyPlan)
* Date Created: 2/24/24
* Date Last Modified: 2/24/24
* Description: Edits a plan in the weekly plan.
* Input parameters:
*   - weeklyPlan: Pointer to the array of plans to be edited.
* Returns: None
* Preconditions: None
* Postconditions: The specified plan is edited if found.
*************************************************************/

template<typename T>
void FitnessAppWrapper::editPlan(T* weeklyPlan) {
    string planName;
    int index = 0;
    cout << "|Enter plan name to edit\n";
    std::getline(std::cin, planName);
    index = foundPlan(weeklyPlan, planName);
    changeGoal(weeklyPlan, planName, index);
}

/*************************************************************
* Function: changeGoal<T>(T *weeklyPlan, const std::string& name, int index)
* Date Created: 2/24/24
* Date Last Modified: 2/24/24
* Description: Changes the goal of a plan in the weekly plan.
* Input parameters:
*   - weeklyPlan: Pointer to the array of plans.
*   - name: Const reference to the name of the plan to be edited.
*   - index: Index of the plan to be edited.
* Returns: None
* Preconditions: None
* Postconditions: If the plan is found, its goal is edited.
*************************************************************/

template<typename T>
void FitnessAppWrapper::changeGoal(T* weeklyPlan, const std::string& name, int index) {
    if (index < 0) {
        cout << "|Plan not found \n";
    }
    else {
        weeklyPlan[index].editGoal();
    }
}

/*************************************************************
* Function: foundPlan<T>(T *weeklyPlan, const std::string& name)
* Date Created: 2/24/24
* Date Last Modified: 2/24/24
* Description: Finds the index of a plan in the weekly plan
* array based on its name.
* Input parameters:
*   - weeklyPlan: Pointer to the array of plans to search.
*   - name: Const reference to the name of the plan to find.
* Returns: Index of the plan if found, otherwise -1.
* Preconditions: None
* Postconditions: None
*************************************************************/

template<typename T>
int FitnessAppWrapper::foundPlan(T* weeklyPlan, const std::string& name) {
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (weeklyPlan[i].getPlanName() == name) {
            index = i;
            break;
        }
    }
    return index;
}


/*void FitnessAppWrapper::loadDailyPlan(std::ifstream &fileStream, DietPlan &plan) {
    fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(std::ifstream &fileStream, ExercisePlan &plan) {
    fileStream >> plan;
}*/

/*
 template<typename T>
void FitnessAppWrapper::storeDailyPlan(std::fstream &fileStream, const T& plan) {
    fileStream << plan;
}*/

/*template <typename T>
T add(T a, T b){
    return a + b;
}*/

/*~List{
    ListNode* current = startNode;
    ListNode* next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
}*/

