#include <iostream>
using namespace std;

int main() {
	int grade;

	cin >> grade;

	if (grade >= 90) {
		cout << "A" << endl;
	}
	else if (grade >= 80) {
		cout << "B" << endl;
	}
	else if (grade >= 70) {
		cout << "C" << endl;
	}
	else { cout << "you need to study more" << endl; }
}