#include "ownMechnism.hpp"

void SomeClass::someMethod(AnotherClass *fillMeWithData)
{
    preCondition(fillMeWithData != nullptr);

    // your code goes here...

    postCondition(fillMeWithData->hasData());
    postCondition(checkInvariant());
}