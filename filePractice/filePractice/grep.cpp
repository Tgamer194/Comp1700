#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream fin(fileName);
	if (!fin) {
		cout << "Could not open file.\n";
		return 1;
	}
	string find;
	cin >> find;
	string line;
	while (getline(fin, line)) {
		if (line == "quit") {
			break;
		}
		if (line.find(find) != string::npos) {
			cout << line << endl;
		}
	}
	
}