#include <iostream>
#include <iomanip>
using namespace std;

// WRITE YOUR SUBROUTINE HERE

bool contains(int numbers[100], int howmany, int i) {
    for (int j = 0; j < howmany; j++) {
        if (numbers[j] == i) {
            return true;
        }
    }
    return false;
}


int main() {
    int numbers[100];
    int howmany;

    cin >> howmany;

    for (int i = 0; i < howmany; ++i) {
        cin >> numbers[i];
    }

    for (int i = 1; i <= howmany; ++i) {
        cout << i << ": " << boolalpha << contains(numbers, howmany, i) << "\n";
    }
}