#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream fin(fileName);
	double increment;
	cin >> increment;
	int howMany;
	fin >> howMany;
	vector<double> numbers;
	for (int i = 0; i < howMany; i++) {
		double addToVector;
		fin >> addToVector;
		numbers.push_back(addToVector);		
	}
	for (int i = 0; i < numbers.size(); i++) {
		numbers[i] += increment;
	}
	fin.close();
	ofstream fout(fileName);
	fout << howMany << "\n";
	for (int i = 0; i < numbers.size(); i++) {
		fout << numbers[i] << "\n";
	}
	fout.close();
	cout << "Wrote \"" << fileName << "\"\n";
}