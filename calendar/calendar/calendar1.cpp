#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int date = 1;
	int weekday;
	cout << "Sun  " << "Mon  " << "Tue  " << "Wed  " << "Thu  " << "Fri  " << "Sat" << endl;
	while (date <= 28) {
		weekday = 1;
		while (weekday <= 7) {
			if (weekday != 1) {
				cout << "  ";
			}
			cout << setw(3) << date;
			date++;
			weekday++;
		}
		cout << endl;
	}
}