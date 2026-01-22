#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string fileName;
	cin >> fileName;
	ifstream fin(fileName);
	string line;
	int lineCount = 0;
	int wordCount = 0;
	while (getline(fin, line)) {
		lineCount++;
		istringstream sin(line);
		while (sin >> line) {
			wordCount++;
		}
	}
	cout << wordCount << " words\n" << lineCount << " lines";
}