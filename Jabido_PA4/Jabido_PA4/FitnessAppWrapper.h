//
// Created by Gregory Jabido on 2/23/24.
//
#pragma once
#ifndef JABIDO_PA4_FITNESSAPPWRAPPER_H
#define JABIDO_PA4_FITNESSAPPWRAPPER_H
#include "PA4Header.h"
#include "DietPlan.h"
#include "ExercisePlan.h"


class FitnessAppWrapper {
private:
    DietPlan weeklyDietPlans[7];
    ExercisePlan weeklyExercisePlans[7];
    std::fstream dietFileStream;
    std::fstream exerciseFileStream;

    //void loadDailyPlan(std::ifstream& fileStream, DietPlan& plan);
    //void loadDailyPlan(std::ifstream& fileStream, ExercisePlan& plan);

    // ## LOAD FUNCTIONS


    template<typename T>
    void loadDailyPlan(std::fstream& fileStream, T& plan);
    void loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[]);
    void loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[]);

    // ## DISPLAY FUNCTIONS
    void displayDailyPlan(const DietPlan& plan);
    void displayDailyPlan(const ExercisePlan& plan);
    void displayWeeklyPlan(DietPlan weeklyPlan[]);
    void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

    // ## STORE FUNCTIONS
    template<typename T>
    void storeDailyPlan(std::fstream& fileStream, const T& plan);
    void storeWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[]);
    void storeWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[]);

    // ## MENU FUNCTIONS
    void displayMenu();

    // ## SEARCH FUNCTIONS
    template<typename T>
    void changeGoal(T* weeklyPlan, const std::string& name, int index);
    template<typename T>
    int foundPlan(T* weeklyPlan, const std::string& name);
    template<typename T>
    void editPlan(T* weeklyPlan);

public:
    // ## CONSTRUCTOR
    FitnessAppWrapper();

    // ## DESTRUCTOR
    ~FitnessAppWrapper();

    // RUN FUNCTIONS
    void runFitnessApp();
};


#endif //JABIDO_PA4_FITNESSAPPWRAPPER_H
