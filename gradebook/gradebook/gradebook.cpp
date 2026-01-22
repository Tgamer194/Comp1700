#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void calcFinals(vector<vector<double>>& grades) {
	for (int i = 0; i < grades.size(); ++i) {
		double sum = 0.0;
		for (int j = 0; j < grades[i].size(); ++j) {
			sum += grades[i][j];
		}
		double average = sum / grades[i].size();
		grades[i].push_back(average);
	}
}

void averages(vector<string>& students, vector<vector<double>>& grades) {

	vector<double> averages;
	int numStudents = grades.size();
	int numAssignments = grades[0].size();

	for (int j = 0; j < numAssignments; ++j) {
		double sum = 0.0;
		for (int i = 0; i < grades.size(); ++i) {
			sum += grades[i][j];
		}
		double avg = sum / grades.size();
		averages.push_back(avg);
	}
	grades.push_back(averages);
	students.push_back("Average");
}

void outputGrades(vector<string>&names, vector<string>& assignments, vector<vector<double>>& grades) {
	ofstream fout("gradebook.csv");
	fout << "Name";
	for (int i = 0; i < assignments.size(); ++i) {
		fout << "," << assignments[i];
	}
	fout << endl;

	int finalCol = assignments.size() - 1;

	for (int i = 0; i < names.size(); ++i) {
		fout << names[i];
		bool isAverageRow = (names[i] == "Average");
		for (int j = 0; j < assignments.size(); ++j) {
			fout << ",";
			if (isAverageRow || j == finalCol) {
				ostringstream sout;
				sout << fixed << setprecision(2) << grades[i][j];
				fout << sout.str();
			}
			else {
				fout << grades[i][j];
			}
			
		}
		fout << endl;
	}
}

int lookUp(vector<string>& names, const string name) {
	for (int i = 0; i < names.size(); ++i) {
		if (names[i] == name) {
			return i;
		}
	}

	names.push_back(name);
	return names.size() - 1;
}

void input(vector<string>& names, vector<string>& assignments, vector<vector<double>>& grades) {
	int namesNum, assignmentsNum;
	cin >> namesNum >> assignmentsNum;

	grades.resize(namesNum, vector<double>(assignmentsNum));

	for (int i = 0; i < assignmentsNum; ++i) {
		string currentAssignment;
		getline(cin, currentAssignment);
		while (currentAssignment == "") {
			getline(cin, currentAssignment);
		}

		assignments.push_back(currentAssignment);
		for (int j = 0; j < namesNum; ++j) {
			string currentLine;
			getline(cin, currentLine);
			size_t colonPos = currentLine.find(':');
			string name = currentLine.substr(0, colonPos);
			double grade = stod(currentLine.substr(colonPos + 1));

			int studentSpot = lookUp(names, name);

			grades[studentSpot][i] = grade;

		}
	}
	assignments.push_back("Final Grade");
}


int main() {
	vector<string> names;
	vector<string> assignments;
	vector<vector<double>> grades;

	input(names, assignments, grades);
	calcFinals(grades);
	averages(names, grades);
	outputGrades(names, assignments, grades);



}