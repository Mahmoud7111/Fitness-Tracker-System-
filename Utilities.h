#pragma once
#include <string>
using namespace std;

// Global Helper Function
double getPositiveInput(const string& prompt);

// Fitness Goals Structure
struct FitnessGoals {
    double targetWeight;
    double targetLongestDistance;
    int targetDuration;

    FitnessGoals();
};

// Exercise Structure
struct Exercise {
    char exerciseName[100];
    int sets;
    int repsPerSet;

    Exercise();
};

// Workout Plan Structure
struct WorkoutPlan {
    char planName[100];
    char description[500];
    int daysPerWeek;
    Exercise exercises[10];
    int exerciseCount;

    WorkoutPlan();
};

