#include <bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int *m_ptiArr;
    int m_iTop;

public:
    MyStack();
    int pop();
    void push(int);
    ~MyStack();
};
MyStack ::MyStack()
{
    m_iTop = -1;
    m_ptiArr = new int[1000];
}
void MyStack ::push(int x)
{
    m_iTop++;
    m_ptiArr[m_iTop] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{

    if (m_iTop == -1)
        return -1;
    int poped = m_ptiArr[m_iTop];
    m_iTop--;
    return poped;
}
MyStack ::~MyStack()
{
    delete[] m_ptiArr;
}
int main()
{
    MyStack stObj;
    stObj.push(4);
    stObj.push(5);
    stObj.push(8);
    stObj.push(2);

    cout << stObj.pop() << endl; // 2
    cout << stObj.pop() << endl; // 8

    return 0;
}