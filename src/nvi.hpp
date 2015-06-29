#define preCondition(c)  assert(c)
#define postCondition(c) assert(c)

class AnotherClass
{
public:
    bool hasData()
    {
        return true;
    }
};

class Base
{
public:
    void someMethod(AnotherClass * ptrData) // non-virtual
    {
        preCondition(ptrData != nullptr);
        someMethodImpl(ptrData);
        postCondition(ptrData->hasData());
        postCondition(checkInvariant());
    }
    virtual ~Base() {}
private:
    virtual void someMethodImpl(AnotherClass * ptrData) = 0;
    bool checkInvariant() { /*...*/ return true; }
};

class SomeClass : public Base
{
private:
    virtual void someMethodImpl(AnotherClass * ptrData)
    { /* your code goes here... */ }
};
