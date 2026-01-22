#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

double evaluate(double left, char op, double right);
double readNumber(double answer);

void printScreen(double number) {
    cout << "[" << setprecision(14) << setw(20) << number << "]" << endl;
}

double memory;

double power(double x, int y) {
    // Calculate answer
    double product = 1;
    if (y >= 0) {
        for (int i = 1; i <= y; ++i) {
            product *= x;
        }
    }
    else {
        for (int i = -1; i >= y; --i) {
            product /= x;
        }
    }

    return product;
}


void calculate(double answer) {
    printScreen(answer);
    cout << endl;
    char operation;
    while (cin >> operation && operation != 'q' && operation != 'Q') {
        double right = readNumber(answer);
        answer = evaluate(answer, operation, right);
        printScreen(answer);
        cout << endl;
    }
}

double evaluate(double left, char op, double right) {
    switch (op) {
    case '+':
       return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    case '=':
        return right;
    case '^':
        return power(left, right);
    case '@':
        memory = left;
        return right;
    default:
        return left;
    }
}

double readNumber(double answer) {
    string input;
    cin >> input;
    if (input == "pi") { return 3.14159265358979323846; }
    if (input == "ans") { return answer; }
    if (input == "sqrt") { return sqrt(answer); }
    if (input == "sin") { return sin(answer); }
    if (input == "cos") { return cos(answer); }
    if (input == "tan") { return tan(answer); }
    if (input == "mem") { return memory; }
    else {
        double d = stod(input);
        return d;
    }
}

int main() {
    
    calculate(0);

}