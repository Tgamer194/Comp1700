#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string fileName;
	string text;
	cin >> fileName;
	cin.ignore();
	ofstream fout(fileName);
	while (getline(cin, text) && text != "quit") {
		fout << text << endl;
	}
	cout << "Wrote \"" << fileName << "\"\n";
}