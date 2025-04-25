#include <vector>
#include <string>
#include <iomanip>
#include<iostream>
using namespace std;

string getLetterFromPoint(double point) {
    if (point >= 4.00) return "A";
    else if (point >= 3.30) return "B";
    else if (point >= 2.70) return "C";
    else if (point >= 2.20) return "D";
    else return "F";
}
double getGradeFromPoints(int numsubjects) {
    double totalpoints = 0.0;
    double highpoints = 0.0;
    double lowpoints = 1000.0;
    for (int subject = 1; subject <= numsubjects; subject++) {
        int mark;
        
        cout << "enter mark for subject #" + to_string(subject) << endl;
        cin >> mark;
        string grade;
        double point = 0.0;
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
        cout << "grade: " << grade << endl;
        if (point > highpoints)
            highpoints = point;
        if (point < lowpoints)
            lowpoints = point;
        totalpoints += point;
    }
    cout << "Highest grade: " << getLetterFromPoint(highpoints) << endl;
    cout << "Lowest grade: " << getLetterFromPoint(lowpoints) << endl;
 
    return totalpoints;
}
string getGeneralGrade(double gpa) {
    string GeneralGrade;
    if (gpa < 0.0 || gpa > 4.0)
        GeneralGrade = "Invalid GPA.";
    else if (gpa >= 3.7) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = "Excellent";
    }
    else if (gpa >= 3.3) {
        cout << "GPA = " << gpa  << endl;
        GeneralGrade = "General Grade: Very Good";
    }
    else if (gpa >= 2.7) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = " General Grade: Good";
    }
    else if (gpa >= 2.0) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = " General Grade: Fair";
    }
    else if (gpa >= 1.0) {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = " \nGeneral Grade: Poor";
    }
    else {
        cout << "GPA = " << gpa << endl;
        GeneralGrade = " \nGeneral Grade: Very Poor";
    }
    return GeneralGrade;
    }

int main() {
	int totalstudents, numsubjects;
    double totalpoints;

	string name;
	cout << "Enter the number of total students" << endl;
	cin >> totalstudents;
    double totalgpa=0.0;
	vector <string> names{};
	vector <double> gpas{};
    double gpa;
    
    cout << fixed << setprecision(2);
	for (int student = 1; student <= totalstudents; student++) {
		cout << "Enter name of student #"<<student<< ": " << endl;
		cin >> name;
		names.push_back(name);
        cout << "enter number of student subjects for "<<name<<": " << endl;
		cin >> numsubjects;
        totalpoints = 0.0;
        totalpoints= getGradeFromPoints(numsubjects);
        gpa = totalpoints / numsubjects;
        gpas.push_back(gpa);
        totalgpa += gpa;
        getGeneralGrade(gpa);
	}
    double highestgpa = 0.00;
    double lowestgpa = 4.00;
    int index = 0;
    string higheststudent;
    while (index < gpas.size()) {
        if (gpas[index] > highestgpa) {
            highestgpa = gpas[index];
            higheststudent = names[index];
            index++;
        }
        else
            index++;
    }
    index = 0;
    string loweststudent;
    while (index < gpas.size()) {
        if (gpas[index] < lowestgpa) {
            lowestgpa = gpas[index];
            loweststudent = names[index];
            index++;
        }
        else
            index++;
    }
    cout << "Average GPA for students is " << totalgpa / totalstudents<<endl;
    cout << "highest GPA = " <<highestgpa<< " for " << higheststudent << endl;
    cout << "lowest GPA = " <<lowestgpa << " for " << loweststudent << endl;
    return 0;
}
