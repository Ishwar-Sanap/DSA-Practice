#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int m_iData;
    Node *m_ptNodenext;

    Node(int iData)
    {
        this->m_iData = iData;
        this->m_ptNodenext = nullptr;
    }
};

class MyStack
{
    Node *m_ptNodeTop;

public:
    MyStack()
    {
        m_ptNodeTop = nullptr;
    }

    void push(int x)
    {
        Node *ptNodeObjNew = new Node(x);
        ptNodeObjNew->m_ptNodenext = m_ptNodeTop;
        m_ptNodeTop = ptNodeObjNew;
    }
    int pop()
    {
        if (m_ptNodeTop == nullptr)
            return -1;

        int ele = m_ptNodeTop->m_iData;
        
        Node* ptNodenext = m_ptNodeTop->m_ptNodenext;
        delete m_ptNodeTop;
        m_ptNodeTop = ptNodenext;

        return ele;
    }

    bool empty()
    {
        return m_ptNodeTop == nullptr ? true : false;
    }

    int top()
    {
        return m_ptNodeTop->m_iData;
    }
    ~MyStack()
    {
        //deallocating the memory of linked list.
        while(m_ptNodeTop != nullptr)
        {
            Node* ptNodenext = m_ptNodeTop->m_ptNodenext;
            delete m_ptNodeTop;
            m_ptNodeTop = ptNodenext;
        }
    }
};

int main()
{

    MyStack stobj;
    stobj.push(11);
    stobj.push(21);
    stobj.push(51);

    cout << stobj.empty() << endl;
    cout << "stack top : " << stobj.top() << endl;
    cout << "poped : " << stobj.pop() << endl;
    cout << "poped : " << stobj.pop() << endl;
    cout << "poped : " << stobj.pop() << endl;
    cout << stobj.empty() << endl;
    return 0;
}
