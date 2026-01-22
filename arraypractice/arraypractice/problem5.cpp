#include <iostream>
#include <array>
using namespace std;

const int SIZE = 4;

// WRITE YOUR SUBROUTINE HERE

array<int, SIZE> add(array<int, SIZE> x, array<int, SIZE> y) {
    array<int, SIZE> z;
    for (int i = 0; i < SIZE; i++) {
        z[i] = x[i] + y[i];
    }
    return z;
}


int main() {
    array<int, SIZE> x, y, z;

    for (int i = 0; i < SIZE; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < SIZE; ++i) {
        cin >> y[i];
    }

    z = add(x, y);

    for (int i = 0; i < SIZE; ++i) {
        cout << z[i] << "\n";
    }
}