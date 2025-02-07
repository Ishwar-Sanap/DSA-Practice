#include <bits/stdc++.h>
using namespace std;

/*
Virtual Constructor (via Factory Method)
---------------------------------------------------------

Technically, virtual constructors do not exist in C++ because constructors cannot be virtual. 
This is because constructors are responsible for creating objects, and at the time of object creation, the virtual table (vtable) for the object is not yet set up. 
Virtual functions rely on the vtable, so it isn't possible to have a truly virtual constructor.

However, you can achieve polymorphic-like behavior during object creation by using factory methods. 
A common pattern is to use a static method or a separate factory function to determine which 
derived class to instantiate based on some input

Dynamic Object Creation: Helps create objects of derived classes dynamically without knowing the exact type at compile time.


Virtual Destructors
---------------------------------------------------------

A virtual destructor ensures that when you delete an object through a base class pointer, 
the derived class's destructor is called first, followed by the base class's destructor. 
This prevents resource leaks and ensures proper cleanup of resources allocated by the derived class.
*/
class Base
{
public:
    Base()
    {
        cout << "Base constructor\n";
    }

// due to virtual derived class destructor is called first then Base class destructror
    virtual ~Base() 
    {
        cout<<"Base destructor\n";
    }
    virtual void displayName() = 0; // pure virtual function..
};

class Derived1 : public Base
{
public:
    int* arr {nullptr};
    Derived1()
    {
        cout<<"Derived1 constructor \n";
        arr = new int[10]; // allocting resources/Memory
    }
    void displayName()
    {
        cout << "Derived1 called\n";
    }

    ~Derived1()
    {
        cout<<"Derived1 destructor \n";
        delete []arr;
        arr = nullptr;
    }
};
class Derived2 : public Base
{
public:
    void displayName()
    {
        cout << "Derived2 called\n";
    }
};
class Derived3 : public Base
{
public:
    void displayName()
    {
        cout << "Derived3 called\n";
    }
};

class TestFactory
{
public:
    static Base *getTestObject(int testID)
    {
        if (testID == 1)
            return new Derived1();

        else if (testID == 2)
            return new Derived2();

        else
            return new Derived3();
    }
};

int main()
{

    //Dynamic Object Creation: Helps create objects of derived classes dynamically without knowing the exact type at compile time.
    Base* ptObjbase = TestFactory::getTestObject(1);
    ptObjbase->displayName();

    delete ptObjbase;  // deleting object through base class pointer
    ptObjbase = nullptr;
    //properly calls the destructors
    // Derived1 destructor
    // Base destructor
  

    return 0;
}