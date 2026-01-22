#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream fin(fileName);
	double displayNum;
	
	while (true) {
		if (fin >> displayNum) {
			cout << displayNum << endl;
		}
		else if (fin.eof()) {
			break;
		}
		else {
			fin.clear();
			string clear;
			fin >> clear;
		}
	}
}