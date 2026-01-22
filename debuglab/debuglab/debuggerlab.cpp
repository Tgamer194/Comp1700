/*==============================================================================
 * Assignment: Debugger Lab
 * Author: Michael Kelley
 *
 * This program repeatedly calculates the roots of a quadratic polynomial.
 */
#include <iostream>
#include <cmath>
using namespace std;

/*------------------------------------------------------------------------------
 * Calculate and print roots of quadratic polynomial with given coefficients
 */
void findRoots(double a, double b, double c) {

    // Compute the discriminant
    double d = b * b - 4 * a * c;

    // Cannot take square root of 0
    if (d < 0) {
        cout << "No real roots are possible." << endl;
    }

    // +0 is the same as -0
    else if (d == 0) {
        double repeated = (-b / (2 * a));

        cout << "Repeated root found: " << repeated << endl;
    }

    // Two distinct real roots
    else {
        double root1 = (-b + sqrt(d)) / (2 * a);
        double root2 = (-b - sqrt(d)) / (2 * a);

        cout << "Distinct roots found:" << endl;
        cout << root1 << endl;
        cout << root2 << endl;
    }
}

/*------------------------------------------------------------------------------
 * Main program: repeatedly calculate roots until user quits
 */
int main() {
    double a, b, c;

    cout << "Enter the coefficients A, B, and C (0 0 0 to quit): ";
    cin >> a >> b >> c;
    while (a != 0 || b != 0 || c != 0) {
        findRoots(a, b, c);
        cout << "Enter the coefficients A, B, and C (0 0 0 to quit): ";
        cin >> a >> b >> c;
    }
}