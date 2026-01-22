#include <iostream>
#include <array>
using namespace std;

const int SIZE = 4;

// WRITE YOUR SUBROUTINE HERE

void add(int x[SIZE], int y[SIZE], int z[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        z[i] = x[i] + y[i];
    }
}


int main() {
    int x[SIZE], y[SIZE], z[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < SIZE; ++i) {
        cin >> y[i];
    }

    add(x, y, z);

    for (int i = 0; i < SIZE; ++i) {
        cout << z[i] << "\n";
    }
}