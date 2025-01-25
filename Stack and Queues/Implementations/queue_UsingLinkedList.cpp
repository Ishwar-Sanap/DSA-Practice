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

class MyQueue
{
    Node *m_ptNodeFront;
    Node *m_ptNodeRear;

public:
    MyQueue()
    {
        m_ptNodeFront = m_ptNodeRear = nullptr;
    }

    void push(int x)
    {
        Node *ptNodeObjNew = new Node(x);
        
        if (m_ptNodeRear == nullptr)
        {
            m_ptNodeFront = ptNodeObjNew;
            m_ptNodeRear = ptNodeObjNew;
        }
        else
        {
            m_ptNodeRear->m_ptNodenext = ptNodeObjNew;
            m_ptNodeRear = ptNodeObjNew;
        }
    }
    int pop()
    {
        if (m_ptNodeFront == nullptr)
            return -1;

        int ele = m_ptNodeFront->m_iData;

        Node *ptcurrNode = m_ptNodeFront;

          // If there is single node and perform pop operations then both pointer has to move
        if (m_ptNodeFront == m_ptNodeRear)
        {
            m_ptNodeFront = m_ptNodeFront->m_ptNodenext;
            m_ptNodeRear = m_ptNodeRear->m_ptNodenext;
        }
        else
        {
            m_ptNodeFront = m_ptNodeFront->m_ptNodenext;
        }

        delete ptcurrNode;

        return ele;
    }

    bool empty()
    {
        return m_ptNodeFront == nullptr ? true : false;
    }

    ~MyQueue()
    {
        // deallocating the memory of linked list.
        while (m_ptNodeFront != nullptr)
        {
            Node *ptNodenext = m_ptNodeFront->m_ptNodenext;
            delete m_ptNodeFront;
            m_ptNodeFront = ptNodenext;
        }
    }
};

int main()
{

    MyQueue qobj;
    // qobj.push(11);
    // qobj.push(21);
    // qobj.push(51);

    // cout << qobj.empty() << endl;
    // cout << "poped : " << qobj.pop() << endl;
    // cout << "poped : " << qobj.pop() << endl;
    // cout << "poped : " << qobj.pop() << endl;

    // cout << qobj.empty() << endl;
    qobj.push(11);
    cout << qobj.pop() << endl;
    qobj.push(21);
    cout << qobj.pop() << endl;

    cout << qobj.empty() << endl;

    return 0;
}