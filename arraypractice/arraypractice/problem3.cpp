#include <iostream>
using namespace std;

// WRITE YOUR SUBROUTINE HERE

int inputPositiveNumbers(double numbers[10], int const SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
        if (numbers[i] < 0) {
            numbers[i] = 0;
            return i;
        }
    }
    return SIZE;
}


int main() {
    double numbers[10];

    int size = inputPositiveNumbers(numbers, 10);

    cout << "Numbers:\n";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << "\n";
    }
}