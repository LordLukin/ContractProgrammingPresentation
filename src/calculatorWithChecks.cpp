#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>

using namespace std;

enum Operation
{
    Add = 0,
    Subtract = 1,
    Multiply = 2,
    Divide = 3
};

class DivisionByZeroException : public logic_error
{
public:
    explicit DivisionByZeroException(const string & what_arg) 
        : logic_error(what_arg)
    {}
};

double calculate(double a, double b, Operation op)
{
    switch(op)
    {
        case Add:      return a + b;
        case Subtract: return a - b;
        case Multiply: return a * b;
        case Divide:   if(b != 0.0)
                       {
                           return a / b;
                       }
                       else
                       {
                           throw DivisionByZeroException("");
                       }
        default:       throw logic_error("Undefined operation");
    }
}

double calculateWithContract(double a, double b, Operation op)
{
    switch(op)
    {
        case Add:      return a + b;
        case Subtract: return a - b;
        case Multiply: return a * b;
        case Divide:   assert(b != 0.0);
                       return a / b;
        default:       throw logic_error("Undefined operation");
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

