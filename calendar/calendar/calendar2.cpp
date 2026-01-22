#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int year, month, maxDays;
	cin >> year;
	cin >> month;
	bool leap;

	if (month == 9 || month == 4 || month == 6 || month == 11) {
		maxDays = 30;
		leap = false;
	}
	else if (month == 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			leap = true;
			maxDays = 29;
		}
		else {
			maxDays = 28;
		}
	}
	else {
		maxDays = 31;
		leap = false;
	}


	int date = 1;
	int weekday;
	cout << "Sun  " << "Mon  " << "Tue  " << "Wed  " << "Thu  " << "Fri  " << "Sat" << endl;
	while (date <= maxDays) {
		weekday = 1;
		while (weekday <= 7 && date <= maxDays) {
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