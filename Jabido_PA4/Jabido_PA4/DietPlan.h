#pragma once
//
// Created by Gregory Jabido on 2/23/24.
//

#ifndef JABIDO_PA4_DIETPLAN_H
#define JABIDO_PA4_DIETPLAN_H
#include "PA4Header.h"

class DietPlan {
private:
    int goalCalories;
    string planName;
    string date;
public:
    // ## SETTERS AND GETTERS
    int getGoalCalories() const;
    void setGoalCalories(int goalCalories);
    const string& getPlanName() const;
    void setPlanName(const string& planName);
    const string& getDate() const;
    void setDate(const string& date);

    // ## CONSTRUCTORS
    DietPlan();
    DietPlan(int calories, const std::string& name, const std::string& date);
    DietPlan(const DietPlan& other);

    // ## DESTRUCTOR
    ~DietPlan();

    // ## OTHER FUNCTIONS
    void editGoal();
    friend std::ostream& operator<<(std::ostream& os, const DietPlan& plan);
    friend std::istream& operator>>(std::istream& is, DietPlan& plan);
    friend std::fstream& operator<<(std::fstream& fileStream, const DietPlan& plan);

};


#endif //JABIDO_PA4_DIETPLAN_H


