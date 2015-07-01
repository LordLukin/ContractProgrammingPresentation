#include "ownMechanism.hpp"

bool SomeClass::checkInvariant()
{
    return false;
}

void SomeClass::someMethod(AnotherClass *fillMeWithData)
{
    preCondition(fillMeWithData != nullptr);

    // your code goes here...

    postCondition(fillMeWithData->hasData());
    postCondition(checkInvariant());
}

int main()
{
    AnotherClass* ac = new AnotherClass();

    SomeClass sc = {};
    sc.someMethod(ac);
    
    delete ac;
}