#include "UserProfile.h"
#include <iostream>
#include <fstream>
using namespace std;

UserProfile::UserProfile() : name(""), age(0), weight(0.0), height(0.0), personalId(0) {
    activities.reserve(50);
    workoutPlans.reserve(10);
}

void UserProfile::createProfile(int id) {
    personalId = id;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, name);
    age = static_cast<int>(getPositiveInput("Enter Age: "));
    weight = getPositiveInput("Enter your Weight (kg): ");
    height = getPositiveInput("Enter your Height (cm): ");
    cout << "Profile created successfully! Your Personal ID is: " << personalId << "\n";
    autoSave();
}

void UserProfile::viewProfile() {
    cout << "\n--- User Profile ---\n";
    cout << "Your Name is : " << name << "\n";
    cout << "Your Age is : " << age << "\n";
    cout << "Your Weight is : " << weight << " kg\n";
    cout << "Your Height is : " << height << " cm\n";
    cout << "\n--- Fitness Goals ---\n";
    cout << "Target Weight: " << goals.targetWeight << " kg\n";
    cout << "Target Longest Distance: " << goals.targetLongestDistance << " km\n";
    cout << "Target Duration: " << goals.targetDuration << " minutes\n";
}

void UserProfile::updateProfile() {
    weight = getPositiveInput("Update Weight (kg): ");
    height = getPositiveInput("Update Height (cm): ");
    cout << "Profile updated successfully!\n";
    autoSave();
}

//-------------------------------------------------------

void UserProfile::addActivity() {
    if (activities.size() >= 50) {
        cout << "Maximum activity limit reached.\n";
        return;
    }
    cout << "Select Activity Type:\n1. Cardio\n2. Weightlifting\nChoice: ";
    int typeChoice;
    cin >> typeChoice;
    Activity newActivity;
    if (typeChoice == 1) {
        newActivity.type = "Cardio";
        cout << "Enter Cardio Name (e.g., Running, Cycling): ";
        cin.ignore();
        getline(cin, newActivity.name);
        newActivity.inputCardioActivity();
    }
    else if (typeChoice == 2) {
        newActivity.type = "Weightlifting";
        newActivity.inputWeightliftingActivity();
    }
    else {
        cout << "Invalid choice.\n";
        return;
    }
    activities.push_back(newActivity);
    cout << "Activity added successfully!\n";
    autoSave();
}

void UserProfile::viewActivities() {
    if (activities.empty()) {
        cout << "\nNo activities logged yet.\n";
        return;
    }

    cout << "\n=== Activity History ===\n";
    cout << "Total Activities Logged: " << activities.size() << "\n\n";

    for (size_t i = 0; i < activities.size(); ++i) {
        cout << "--- Activity " << (i + 1) << " ---\n";
        cout << "Type: " << activities[i].type << "\n";
        cout << "Name: " << activities[i].name << "\n";

        if (activities[i].type == "Cardio") {
            cout << "Duration: " << activities[i].duration << " minutes\n";
            cout << "Distance: " << activities[i].distance << " km\n";
            cout << "Calories Burned: " << activities[i].caloriesBurned << "\n";
        }
        else if (activities[i].type == "Weightlifting") {
            cout << "Weight Lifted: " << activities[i].weight << " kg\n";
            cout << "Reps: " << activities[i].reps << "\n";
        }
        cout << "\n";
    }
}

//------------------------------------

void UserProfile::setGoals() {
    goals.targetWeight = getPositiveInput("Set Target Weight (Kg): ");
    goals.targetLongestDistance = getPositiveInput("Set Target Longest Distance (Km): ");
    goals.targetDuration = static_cast<int>(getPositiveInput("Set Target Duration (Weeks): "));
    cout << "Goals set successfully!\n";
    autoSave();
}

//-----------------------------------------------

void UserProfile::createWorkoutPlan() {
    if (workoutPlans.size() >= 10) {
        cout << "Maximum workout plan limit reached.\n";
        return;
    }

    WorkoutPlan newPlan;

    cout << "Enter Workout Plan Name: ";
    cin.ignore();
    cin.getline(newPlan.planName, 100);

    cout << "Enter Plan Description: ";
    cin.getline(newPlan.description, 500);

    newPlan.daysPerWeek = static_cast<int>(getPositiveInput("Enter Days per Week: "));
    if (newPlan.daysPerWeek > 7) {
        cout << "Days per week cannot exceed 7. Setting to 7.\n";
        newPlan.daysPerWeek = 7;
    }

    cout << "How many exercises in this plan? (Max 10): ";
    cin >> newPlan.exerciseCount;
    if (newPlan.exerciseCount > 10) {
        cout << "Exercise count cannot exceed 10. Setting to 10.\n";
        newPlan.exerciseCount = 10;
    }

    cin.ignore(); // Clear the newline left in buffer
    for (int i = 0; i < newPlan.exerciseCount; ++i) {
        cout << "\n--- Exercise " << (i + 1) << " ---\n";
        cout << "Enter Exercise Name: ";
        cin.getline(newPlan.exercises[i].exerciseName, 100);

        newPlan.exercises[i].sets = static_cast<int>(getPositiveInput("Enter Number of Sets: "));
        newPlan.exercises[i].repsPerSet = static_cast<int>(getPositiveInput("Enter Reps per Set: "));

        ////// Clear the newline left by getPositiveInput() before next iteration
        if (i < newPlan.exerciseCount - 1) {
            cin.ignore();
        }
    }

    workoutPlans.push_back(newPlan);
    cout << "\nWorkout plan created successfully!\n";
    autoSave();
}

void UserProfile::viewWorkoutPlans() {
    if (workoutPlans.empty()) {
        cout << "\nNo workout plans available.\n";
        return;
    }

    cout << "\n=== Your Workout Plans ===\n";
    for (size_t i = 0; i < workoutPlans.size(); ++i) {
        cout << "\n--- Plan " << (i + 1) << " ---\n";
        cout << "Name: " << workoutPlans[i].planName << "\n";
        cout << "Description: " << workoutPlans[i].description << "\n";
        cout << "Days per Week: " << workoutPlans[i].daysPerWeek << "\n";
        cout << "\nExercises:\n";
        for (int j = 0; j < workoutPlans[i].exerciseCount; ++j) {
            cout << "  " << (j + 1) << ". " << workoutPlans[i].exercises[j].exerciseName << "\n";
            cout << "     Sets: " << workoutPlans[i].exercises[j].sets
                << " x " << workoutPlans[i].exercises[j].repsPerSet << " reps\n";
        }
    }
}

void UserProfile::autoSave() {
    string filename = "user_" + to_string(personalId) + ".dat";
    ofstream file(filename, ios::binary);
    if (!file) {
        return;
    }

    file.write(reinterpret_cast<const char*>(&personalId), sizeof(personalId));

    size_t nameLength = name.length();
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(name.c_str(), nameLength);

    file.write(reinterpret_cast<const char*>(&age), sizeof(age));
    file.write(reinterpret_cast<const char*>(&weight), sizeof(weight));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));

    file.write(reinterpret_cast<const char*>(&goals), sizeof(goals));

    size_t activityCount = activities.size();
    file.write(reinterpret_cast<const char*>(&activityCount), sizeof(activityCount));
    for (size_t i = 0; i < activityCount; ++i)
    {
        const Activity& activity = activities[i];

        size_t typeLength = activity.type.length();
        file.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
        file.write(activity.type.c_str(), typeLength);

        size_t actNameLength = activity.name.length();
        file.write(reinterpret_cast<const char*>(&actNameLength), sizeof(actNameLength));
        file.write(activity.name.c_str(), actNameLength);

        file.write(reinterpret_cast<const char*>(&activity.duration), sizeof(activity.duration));
        file.write(reinterpret_cast<const char*>(&activity.distance), sizeof(activity.distance));
        file.write(reinterpret_cast<const char*>(&activity.caloriesBurned), sizeof(activity.caloriesBurned));
        file.write(reinterpret_cast<const char*>(&activity.weight), sizeof(activity.weight));
        file.write(reinterpret_cast<const char*>(&activity.reps), sizeof(activity.reps));
    }

    size_t planCount = workoutPlans.size();
    file.write(reinterpret_cast<const char*>(&planCount), sizeof(planCount));
    for (size_t i = 0; i < planCount; ++i) {
        file.write(reinterpret_cast<const char*>(&workoutPlans[i]), sizeof(WorkoutPlan));
    }

    file.close();
}

bool UserProfile::autoLoad() {
    string filename = "user_" + to_string(personalId) + ".dat";
    ifstream file(filename, ios::binary);
    if (!file)
    {
        return false;
    }

    file.read(reinterpret_cast<char*>(&personalId), sizeof(personalId));

    size_t nameLength;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    name.resize(nameLength);
    file.read(&name[0], nameLength);

    file.read(reinterpret_cast<char*>(&age), sizeof(age));
    file.read(reinterpret_cast<char*>(&weight), sizeof(weight));
    file.read(reinterpret_cast<char*>(&height), sizeof(height));

    file.read(reinterpret_cast<char*>(&goals), sizeof(goals));

    size_t activityCount;
    file.read(reinterpret_cast<char*>(&activityCount), sizeof(activityCount));
    activities.resize(activityCount);
    for (size_t i = 0; i < activityCount; ++i)
    {
        Activity& activity = activities[i];

        size_t typeLength;
        file.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
        activity.type.resize(typeLength);
        file.read(&activity.type[0], typeLength);

        size_t actNameLength;
        file.read(reinterpret_cast<char*>(&actNameLength), sizeof(actNameLength));
        activity.name.resize(actNameLength);
        file.read(&activity.name[0], actNameLength);

        file.read(reinterpret_cast<char*>(&activity.duration), sizeof(activity.duration));
        file.read(reinterpret_cast<char*>(&activity.distance), sizeof(activity.distance));
        file.read(reinterpret_cast<char*>(&activity.caloriesBurned), sizeof(activity.caloriesBurned));
        file.read(reinterpret_cast<char*>(&activity.weight), sizeof(activity.weight));
        file.read(reinterpret_cast<char*>(&activity.reps), sizeof(activity.reps));
    }

    size_t planCount;
    file.read(reinterpret_cast<char*>(&planCount), sizeof(planCount));
    workoutPlans.resize(planCount);
    for (size_t i = 0; i < planCount; ++i) {
        file.read(reinterpret_cast<char*>(&workoutPlans[i]), sizeof(WorkoutPlan));
    }

    file.close();
    return true;
}