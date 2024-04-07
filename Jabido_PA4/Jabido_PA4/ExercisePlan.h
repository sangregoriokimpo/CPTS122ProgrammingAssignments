#pragma once
//
// Created by Gregory Jabido on 2/23/24.
//

#ifndef JABIDO_PA4_EXERCISEPLAN_H
#define JABIDO_PA4_EXERCISEPLAN_H
#include "PA4Header.h"


class ExercisePlan {
private:
    int goalSteps;
    std::string planName;
    std::string date;
public:
    // ## SETTERS AND GETTERS
    int getGoalSteps() const;
    void setGoalSteps(int goalSteps);
    const string& getPlanName() const;
    void setPlanName(const string& planName);
    const string& getDate() const;
    void setDate(const string& date);

    // ## CONSTRUCTORS
    ExercisePlan();
    ExercisePlan(int steps, const std::string& name, const std::string& date);
    ExercisePlan(const ExercisePlan& other);

    // ## DESTRUCTOR
    ~ExercisePlan();

    // ## OTHER FUNCTIONS
    void editGoal();
    friend std::ostream& operator<<(std::ostream& os, const ExercisePlan& plan);
    friend std::istream& operator>>(std::istream& is, ExercisePlan& plan);
    friend std::fstream& operator<<(std::fstream& fileStream, const ExercisePlan& plan);
};


#endif //JABIDO_PA4_EXERCISEPLAN_H

