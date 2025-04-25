#include <vector>
#include <string>
#include <iomanip>
#include<iostream>
using namespace std;

// Converts GPA points into a letter grade
string getLetterFromPoint(double point) {
    if (point >= 4.00) return "A";
    else if (point >= 3.30) return "B";
    else if (point >= 2.70) return "C";
    else if (point >= 2.20) return "D";
    else return "F";
}

// Handles input of subject marks, calculates GPA points, and shows highest/lowest grades
double getGradeFromPoints(int numsubjects) {
    double totalpoints = 0.0;
    double highpoints = 0.0;
    double lowpoints = 1000.0;

    // Loop over each subject
    for (int subject = 1; subject <= numsubjects; subject++) {
        int mark;
        cout << "enter mark for subject #" + to_string(subject) << endl;
        cin >> mark;

        string grade;
        double point = 0.0;

        // Determine letter grade and GPA point based on mark
        if (mark >= 85) {
            grade = "A";
            point = 4.00;
        }
        else if (mark >= 75) {
            grade = "B";
            point = 3.30;
        }
        else if (mark >= 65) {
            grade = "C";
            point = 2.70;
        }
        else if (mark >= 50) {
            grade = "D";
            point = 2.20;
        }
        else {
            grade = "F";
            point = 0.00;
        }

        // Output the grade
        cout << "grade: " << grade << endl;

        // Track highest and lowest points
        if (point > highpoints)
            highpoints = point;
        if (point < lowpoints)
            lowpoints = point;

        totalpoints += point;
    }

    // Output the highest and lowest grades
    cout << "Highest grade: " << getLetterFromPoint(highpoints) << endl;
    cout << "Lowest grade: " << getLetterFromPoint(lowpoints) << endl;

    return totalpoints;
}

// Returns a general grade (like Excellent, Very Good, etc.) based on the GPA
string getGeneralGrade(double gpa) {
    string GeneralGrade;

    if (gpa < 0.0 || gpa > 4.0)
        GeneralGrade = "Invalid GPA.";
    else if (gpa >= 3.7) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "Excellent";
    }
    else if (gpa >= 3.3) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "General Grade: Very Good";
    }
    else if (gpa >= 2.7) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "General Grade: Good";
    }
    else if (gpa >= 2.0) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "General Grade: Fair";
    }
    else if (gpa >= 1.0) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "General Grade: Poor";
    }
    else {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "General Grade: Very Poor";
    }

    return GeneralGrade;
}

int main() {
    int totalstudents, numsubjects;
    double totalpoints;
    double totalgpa = 0.0;
    double gpa;

    vector<string> names{};     // List of student names
    vector<double> gpas{};      // List of student GPAs
    string name;

    cout << "Enter the number of total students" << endl;
    cin >> totalstudents;

    cout << fixed << setprecision(2); // Format output to 2 decimal places

    // Loop through each student
    for (int student = 1; student <= totalstudents; student++) {
        cout << "Enter name of student #" << student << ": " << endl;
        cin >> name;
        names.push_back(name);

        cout << "enter number of student subjects for " << name << ": " << endl;
        cin >> numsubjects;

        totalpoints = getGradeFromPoints(numsubjects);
        gpa = totalpoints / numsubjects;

        gpas.push_back(gpa);
        totalgpa += gpa;

        // Show general grade based on GPA
        getGeneralGrade(gpa);
    }

    // Determine student with highest and lowest GPA
    double highestgpa = 0.00;
    double lowestgpa = 4.00;
    string higheststudent;
    string loweststudent;

    for (int i = 0; i < gpas.size(); ++i) {
        if (gpas[i] > highestgpa) {
            highestgpa = gpas[i];
            higheststudent = names[i];
        }
        if (gpas[i] < lowestgpa) {
            lowestgpa = gpas[i];
            loweststudent = names[i];
        }
    }

    // Display final statistics
    cout << "Average GPA for students is " << totalgpa / totalstudents << endl;
    cout << "highest GPA = " << highestgpa << " for " << higheststudent << endl;
    cout << "lowest GPA = " << lowestgpa << " for " << loweststudent << endl;

    return 0;
}
