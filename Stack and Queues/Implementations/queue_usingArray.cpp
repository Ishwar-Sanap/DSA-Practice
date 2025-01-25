#include <iostream>
using namespace std;

class MyQueue
{
private:
    int *m_ptiArr;
    int m_iFront;
    int m_iRear;

public:
    MyQueue();
    void push(int ele);
    int pop();
    ~MyQueue();
};

MyQueue::MyQueue()
{
    m_ptiArr = new int[1000];
    m_iFront = -1;
    m_iRear = -1;
}

void MyQueue::push(int ele)
{
    m_iRear++;
    m_ptiArr[m_iRear] = ele;
}
int MyQueue::pop()
{
    if (m_iFront == m_iRear)
        return -1;

    m_iFront++;
    int poped = m_ptiArr[m_iFront];
    return poped;
}
MyQueue::~MyQueue()
{
    delete[] m_ptiArr;
}

int main()
{
    MyQueue qObj;
    qObj.push(11);
    qObj.push(21);
    qObj.push(51);

    cout<<qObj.pop()<<endl;
    cout<<qObj.pop()<<endl;
    cout<<qObj.pop()<<endl;
    cout<<qObj.pop()<<endl;
    return 0;
}