# 🏋️ Fitness Tracker System

A comprehensive C++ console-based fitness tracking application that helps users manage their fitness journey through profile management, activity tracking, goal setting, and personalized workout planning.

## 📋 Table of Contents
- [Features](-#features)
- [Project Structure](-#project-structure)
- [Getting Started](-#getting-started)
- [Usage](-#usage)
- [Technical Details](-#technical-details)
- [Future Enhancements](-#future-enhancements)

## ✨ Features

### 🔐 User Management
- **Profile Creation**: Create personalized user profiles with unique IDs
- **Sign In System**: Secure sign-in using personal ID
- **Auto-Save/Load**: Automatic data persistence using binary file storage
- **Multi-User Support**: Supports up to 100 user profiles

### 🏃 Activity Tracking
- **Cardio Activities**: Track running, cycling, and other cardio exercises
  - Duration monitoring (minutes)
  - Distance tracking (kilometers)
  - Automatic calorie calculation
- **Weightlifting Activities**: Log strength training exercises
  - Exercise name tracking
  - Weight lifted (kg)
  - Repetitions achieved
- **Activity History**: View complete activity log with detailed statistics
- **Maximum 50 activities** per user profile

### 🎯 Goal Setting
- Set target weight goals
- Define target distance objectives
- Track duration targets
- Monitor progress towards fitness goals

### 📅 Workout Planning
- **Custom Workout Plans**: Create personalized workout routines
  - Plan name and description
  - Days per week scheduling (max 7)
  - Up to 10 exercises per plan
- **Exercise Management**: 
  - Exercise names
  - Sets configuration
  - Reps per set
- **Plan Viewing**: Review all created workout plans with detailed breakdowns
- **Maximum 10 workout plans** per user

### 💾 Data Persistence
- Automatic saving on profile creation and updates
- Binary file storage format (`user_[ID].dat`)
- Profile data including activities and workout plans
- Seamless data loading on sign-in

## 📁 Project Structure

```
Fitness-Tracker-System/
├── FitnessMain.cpp       # Main application entry point with menu system
├── UserProfile.h         # UserProfile class declaration
├── UserProfile.cpp       # UserProfile class implementation
├── Activity.h            # Activity class declaration
├── Activity.cpp          # Activity class implementation
├── Utilities.h           # Helper structures and function declarations
├── Utilities.cpp         # Utility function implementations
└── README.md             # Project documentation
```

### Core Components

#### `UserProfile` Class
Manages user data and functionality:
- Personal information (name, age, weight, height, ID)
- Fitness goals management
- Activity tracking
- Workout plan creation
- Data persistence (save/load)

#### `Activity` Class
Handles exercise tracking:
- Cardio activity input with calorie calculation
- Weightlifting activity logging
- Activity type differentiation

#### `Utilities`
Global helper functions and structures:
- Input validation (`getPositiveInput`)
- `FitnessGoals` structure
- `Exercise` structure
- `WorkoutPlan` structure

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++11 support or later
- Standard Template Library (STL)

### Compilation

```bash
g++ -std=c++11 FitnessMain.cpp UserProfile.cpp Activity.cpp Utilities.cpp -o FitnessTracker
```

### Running the Application

```bash
./FitnessTracker
```

## 💻 Usage

### Main Menu
```
1. Create Profile    - Register a new user
2. Sign In          - Access existing profile
3. Exit             - Close application
```

### Profile Menu
Once signed in, users can:
```
1. View Profile          - Display user information and goals
2. Update Profile        - Modify personal details
3. Add Activity          - Log new exercise
4. View Activities       - Review activity history
5. Set Goals            - Define fitness objectives
6. Create Workout Plan  - Design custom workout routine
7. View Workout Plans   - Review existing plans
8. Sign Out             - Save and exit profile
```

### Example Workflow

1. **Create Profile**
   ```
   Enter your Name: John Doe
   Enter Age: 25
   Enter your Weight (kg): 75
   Enter your Height (cm): 180
   ```

2. **Add Cardio Activity**
   ```
   Select Activity Type: 1 (Cardio)
   Enter Cardio Name: Running
   Enter Duration (minutes): 30
   Enter Distance (kilometers): 5
   ```

3. **Create Workout Plan**
   ```
   Enter Workout Plan Name: Morning Routine
   Enter Plan Description: Full body workout
   Enter Days per Week: 5
   How many exercises: 3
   ```

## 🔧 Technical Details

### Data Storage
- **Format**: Binary files (`user_[ID].dat`)
- **Location**: Current working directory
- **Content**: Complete user profile including activities and workout plans

### Calorie Calculation
Cardio calories burned formula:
```cpp
calories = (distance * 50) + (duration / 60.0) * 100
```

### Limits
- **Maximum Users**: 100 profiles
- **Activities per User**: 50
- **Workout Plans per User**: 10
- **Exercises per Plan**: 10
- **Days per Week**: 7

### Memory Management
- Vector pre-allocation for optimization
- Efficient binary file I/O
- Automatic memory cleanup

## 🎨 Code Highlights

### Simple Object-Oriented Design
- Clean class separation (UserProfile, Activity)
- Encapsulation of functionality
- Modular structure for easy maintenance

### Input Validation
- Positive number validation for all numeric inputs
- Range checking for days per week and exercise counts
- Robust error handling

### User Experience
- Clear menu navigation
- Informative feedback messages
- Automatic data persistence

## 🔮 Future Enhancements

Potential improvements for the system:
- [ ] BMI calculation and health metrics
- [ ] Progress tracking with charts/graphs
- [ ] Nutrition logging
- [ ] Database integration (SQLite/MySQL)
- [ ] GUI implementation
- [ ] Mobile app version
- [ ] Social features (friend challenges)
- [ ] Advanced calorie calculation (based on intensity)
- [ ] Workout reminders and scheduling
- [ ] Export data to CSV/JSON
- [ ] Multi-language support
- [ ] Password protection for profiles

## 📝 License

This project is available for educational and personal use.

## 👤 Author

**Mahmoud7111**

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page or submit pull requests.

---

**Note**: This is a console-based application designed for educational purposes and personal fitness tracking. For production use, consider adding more robust error handling, security features, and data validation.
