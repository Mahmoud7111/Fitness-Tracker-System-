#include <iostream>
#include <vector>
#include "UserProfile.h"
#include "Activity.h"

using namespace std;

int main() {
    vector<UserProfile> users;
    users.reserve(100);

    int choice;
    do {
        cout << "\n==========================\n| Fitness Tracker system |\n==========================\n\n";
        cout << "1. Create Profile\n2. Sign In\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (users.size() >= 100) {
                cout << "Maximum user limit reached. Cannot create more profiles.\n";
                continue;
            }
            UserProfile newUser;
            newUser.createProfile(static_cast<int>(users.size()) + 1);
            users.push_back(newUser);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter Personal ID: ";
            cin >> id;

            UserProfile loadedUser;
            loadedUser.personalId = id;
            bool loaded = loadedUser.autoLoad();

            if (loaded) {
                bool foundInMemory = false;
                size_t userIndex = 0;
                for (size_t i = 0; i < users.size(); ++i) {
                    if (users[i].personalId == id) {
                        foundInMemory = true;
                        userIndex = i;
                        break;
                    }
                }

                if (!foundInMemory) {
                    users.push_back(loadedUser);
                    userIndex = users.size() - 1;
                }

                cout << "Welcome back, " << users[userIndex].name << "!\n";

                int userChoice;
                do {
                    cout << "\nProfile Menu for " << users[userIndex].name << ":\n";
                    cout << "1. View Profile\n2. Update Profile\n3. Add Activity\n4. View Activities\n";
                    cout << "5. Set Goals\n6. Create Workout Plan\n7. View Workout Plans\n8. Sign Out\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                    case 1: users[userIndex].viewProfile(); break;
                    case 2: users[userIndex].updateProfile(); break;
                    case 3: users[userIndex].addActivity(); break;
                    case 4: users[userIndex].viewActivities(); break;
                    case 5: users[userIndex].setGoals(); break;
                    case 6: users[userIndex].createWorkoutPlan(); break;
                    case 7: users[userIndex].viewWorkoutPlans(); break;
                    case 8:
                        users[userIndex].autoSave();
                        cout << "Signing out...\n";
                        break;
                    default: cout << "Invalid choice. Please try again.\n";
                    }
                } while (userChoice != 8);
            }
            else {
                cout << "Profile not found. Please create a new profile first.\n";
            }
        }
    } while (choice != 3);

    cout << "Saving all data...\n";
    for (size_t i = 0; i < users.size(); ++i) {
        users[i].autoSave();
    }

    cout << "Exiting... Goodbye!\n";
    return 0;
}