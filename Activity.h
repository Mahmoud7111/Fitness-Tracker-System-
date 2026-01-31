#pragma once

#include <string>
using namespace std;

class Activity {
public:
    string type;
    string name;
    int duration;
    double distance;
    double caloriesBurned;
    double weight;
    int reps;

    Activity();

    void inputCardioActivity();
    void inputWeightliftingActivity();
};

