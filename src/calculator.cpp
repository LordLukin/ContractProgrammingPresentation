#include <iostream>

using namespace std;

enum Operation
{
    Add = 0,
    Subtract = 1,
    Multiply = 2,
    Divide = 3
};

double calculate(double a, double b, Operation op)
{
    switch(op)
    {
        case Add:      return a + b;
        case Subtract: return a - b;
        case Multiply: return a * b;
        case Divide:   return a / b;
        default:       return 0; // should never get here
    }
}

int main()
{
    double a = 0;
    double b = 0;
    int op = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "operation: ";
    cin >> op;

    double result = calculate(a, b, static_cast<Operation>(op));
    cout << result << endl;
    return 0;
}

