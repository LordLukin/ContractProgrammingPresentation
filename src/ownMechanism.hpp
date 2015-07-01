#include "contract.hpp"

class AnotherClass
{
public:
    bool hasData() const
    {
        return false;
    }
};

class SomeClass
{
    bool checkInvariant();
public:
    void someMethod(AnotherClass *fillMeWithData);
};