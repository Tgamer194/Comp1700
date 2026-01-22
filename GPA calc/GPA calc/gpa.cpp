#include <iostream>
#include <string>
using namespace std;

int main() {
	int courses, courseCount, hours;
	double points, gpa, totalHours;
	string grade;
	cout << "Number of courses? ";
	cin >> courses;
	courseCount = 1;
	totalHours = 0;
	points = 0;

	while (courses <= 0) {
		cout << "Must be positive " << endl;
		cout << "Number of courses? ";
		cin >> courses;
		cout << endl;
	}

	while (courses > 0) {
		cout << "For course " << courseCount << ":" << endl;
		cout << "Hours? ";
		cin >> hours;
		cout << "Grade? ";
		cin >> grade;
		cout << endl;
		if (grade == "A" || grade == "a") {
			points = points + hours * 4;
		}
		else if (grade == "B" || grade == "b") {
			points = points + hours * 3;
		}
		else if (grade == "C" || grade == "c") {
			points = points + hours * 2;
		}
		else if (grade == "D" || grade == "d") {
			points = points + hours;
		}

		courses = courses - 1;
		courseCount = courseCount + 1;
		totalHours = totalHours + hours;
	}

	gpa = points / totalHours;
	cout << "Your GPA is " << gpa << endl;



	

	



}