#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	cin.ignore();
	ofstream fout(fileName);
	string line;

	while (getline(cin, line)) {
		fout << line << "\n";
	}
	cout << "Wrote \"" << fileName << "\"\n";

}