#include <bits/stdc++.h>
using namespace std;

class Test
{
public:
    int data;
    Test(int val)
    {
        data = val;
    }
};

class Base
{
public:
    Test *m_ptobjTest{nullptr};

    Base()
    {
        m_ptobjTest = new Test(12);
    }
    /*
    Virtual Destructors in C++
    A virtual destructor ensures that when you delete an object through a base class pointer,
    the derived class's destructor is called first, followed by the base class's destructor.
    This prevents resource leaks and ensures proper cleanup of resources allocated by the derived class.
    */
    virtual ~Base()
    {
        cout << "Base destructor \n";
        delete m_ptobjTest;
        m_ptobjTest = nullptr;
    }
};

class Child : public Base
{
public:
    Test *m_ptobjTest2{nullptr};

    Child()
    {
        m_ptobjTest2 = new Test(55);
    }

    ~Child()
    {
        cout << "child destructor\n";
        delete m_ptobjTest2;
        m_ptobjTest2 = nullptr;
    }
};

class Child2 : public Base{

};
int main()
{

    Base *ptObjBase = new Child();

    cout << ptObjBase->m_ptobjTest->data << endl;

    // How to access the child class member using base class pointer???
    // cout<<ptObjBase->m_ptobjTest2->data<<endl; this is not valid since base class pointer does't no about child class members..

    // To access it you have to peform the dynamic casting or static casting

    // Static casting
    /*
    If you are 100% sure that ptObjBase actually points to a Child object, you can use static_cast. However, this does not perform any runtime checks, so use it cautiously:
    */
    Child *ptObjChild = static_cast<Child *>(ptObjBase);
    cout << ptObjChild->m_ptobjTest2->data << endl; // 55
    cout << ptObjChild->m_ptobjTest->data << endl;  // 12
    
    // Dynamic casting
    /*
    Dynamic Cast:
    dynamic_cast is used to safely cast the base class pointer (Base*) to a derived class pointer (Child*).
    If the cast is valid, it returns a pointer to the derived class. Otherwise, it returns nullptr.

    Virtual Destructor:
    A virtual destructor in the base class ensures proper cleanup of derived class objects when deleted through a base class pointer

    */

    // Child *ptObjChild2 = dynamic_cast<Child *>(ptObjBase);
    // cout << ptObjChild2->m_ptobjTest2->data << endl; // 55
    // cout << ptObjChild2->m_ptobjTest->data << endl;  // 12

    delete ptObjBase;
    ptObjBase = nullptr;

    return 0;
}