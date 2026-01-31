#include "Utilities.h"
#include <iostream>
using namespace std;

double getPositiveInput(const string& prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (value <= 0) cout << "Invalid input. Please enter a positive number.\n";
    } while (value <= 0);
    return value;
}

FitnessGoals::FitnessGoals() : targetWeight(0.0), targetLongestDistance(0.0), targetDuration(0) {}

Exercise::Exercise() : sets(0), repsPerSet(0) {
    exerciseName[0] = '\0';
}

WorkoutPlan::WorkoutPlan() : daysPerWeek(0), exerciseCount(0) {
    planName[0] = '\0';
    description[0] = '\0';
}