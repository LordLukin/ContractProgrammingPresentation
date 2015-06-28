#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>
#include "nvi.hpp"

#define precondition assert

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

int calculate(int a, int b, Operation op)
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

int calculateWithChecks(int a, int b, Operation op)
{
    if(a < 0 || b < 0)
    {
    	throw out_of_range("Number cannot be negative");
    }
    
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
                           throw logic_error("Division by zero");
                       }
        default:       throw logic_error("Undefined operation");
    }
}

int calculateWithAssertions(int a, int b, Operation op)
{
    assert(a >= 0 || b >= 0);
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

int calculateWithContract(int a, int b, Operation op)
{
    precondition(a >= 0 || b >= 0);
    switch(op)
    {
        case Add:      return a + b;
        case Subtract: return a - b;
        case Multiply: return a * b;
        case Divide:   precondition(b != 0.0);
                       return a / b;
        default:       throw logic_error("Undefined operation");
    }
}

int main()
{
    int a = 0;
    int b = 0;
    int op = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "operation: ";
    cin >> op;

    int result = calculateWithContract(a, b, static_cast<Operation>(op));
    cout << result << endl;
    return 0;
}

