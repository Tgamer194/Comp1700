#include <iostream>
using namespace std;

// Input "size" numbers into array "a"
void getNumbers(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        cin >> a[i];
    }
}


// Copy "size" numbers from array "a" to array "b" in reverse order
void reverse(int const a[], int size, int b[]) {
    if (a == b) {
        cout << "Error: cannot use same array for both parameters\n";
    }
    else {
        for (int i = 0; i < size; ++i) {
            b[i] = a[size - 1 - i];
        }
    }
}


// Print "size" numbers from array "a"
void print(int const a[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i != 0) cout << ", ";
        cout << a[i];
    }
    cout << "\n";
}


// WRITE YOUR SUBROUTINE HERE

int main() {
    int size;
    int myArray[100];
    int reverseArray[100];
    cin >> size;
    if (size > 100) {
        cout << "Error: array not big enough";
        return 0;
    }
    getNumbers(myArray, size);
    reverse(myArray, size, reverseArray);
    print(reverseArray, size);
}