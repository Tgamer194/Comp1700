/*****************************************************************************
  PROGRAM:  PRIME.CPP
  AUTHOR:   Joe Harding
  DATE:     August 25, 2000

  This program repeatedly asks for a number and reports whether or not that
  number is prime.  The program quits when 0 is given as the input value.

*****************************************************************************/

#include <iostream>
using namespace std;

/****************************************************************************/

// This function returns true (1) if n is a prime number, false (0) otherwise.
int IsPrime(int n)
{
	int d = 3;

	if (n < 2)   // Anything less than 2 is not prime
		return 0;
	else if (n == 2)  // 2 is the first prime number
		return 1;
	else if (n % 2 == 0)   // No even number can be prime
		return 0;
	else
	{                 // Divide by odd #'s looking for a factor
		while (n % d != 0)  // While d is not a factor of n
			d += 2;          // Try next odd number
		if (d == n)
			return 1;     // No factors found, number is prime
		else
			return 0;    // Found a factor, number is not prime
	}
}

/****************************************************************************/

int main()
{
	int number;

	cout << "Number (0 to quit)? ";
	cin >> number;

	while (number > 0)
	{
		if (IsPrime(number))
			cout << "This is a prime number." << endl << endl;
		else
			cout << "This number is NOT prime." << endl << endl;
		cout << "Number (0 to quit)? ";
		cin >> number;
	}
}