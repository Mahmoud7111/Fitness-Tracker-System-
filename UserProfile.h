#pragma once
#include <string>
#include <vector>
#include "Utilities.h"
#include "Activity.h"
using namespace std;

class UserProfile {
public:
    string name;
    int age;
    double weight;
    double height;
    int personalId;

    FitnessGoals goals;

    vector<Activity> activities;
    vector<WorkoutPlan> workoutPlans;

    UserProfile();

    void createProfile(int id);
    void viewProfile();
    void updateProfile();
    void addActivity();
    void viewActivities();
    void setGoals();
    void createWorkoutPlan();
    void viewWorkoutPlans();
    void autoSave();
    bool autoLoad();
};