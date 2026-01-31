#include "Activity.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

Activity::Activity() : type(""), name(""), duration(0), distance(0.0), caloriesBurned(0.0), weight(0.0), reps(0) {}

void Activity::inputCardioActivity()
{
    duration = static_cast<int>(getPositiveInput("Enter Duration (minutes): "));
    distance = getPositiveInput("Enter Distance (kilometers): ");
    caloriesBurned = (distance * 50 + (duration / 60.0) * 100);
    cout << "Calories Burned: " << caloriesBurned << "\n";
}

void Activity::inputWeightliftingActivity()
{
    cout << "Enter Exercise Name (e.g., Bench Press, Deadlift): ";
    cin.ignore();
    getline(cin, name);
    weight = getPositiveInput("Enter Weight Lifted (kg): ");
    reps = static_cast<int>(getPositiveInput("Enter Reps Achieved: "));
    cout << "Exercise logged successfully!\n";
}