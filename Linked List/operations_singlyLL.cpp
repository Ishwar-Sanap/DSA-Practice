#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int m_iVal;
    ListNode *m_ptrNext;

    ListNode(int val);
};

class List
{
private:
    ListNode *head;
    int nodeCnts;

public:
    List()
    {
        head = nullptr;
        nodeCnts = 0;
    }

    ~List()
    {
        while (head != nullptr)
        {
            ListNode *temp = head;
            head = head->m_ptrNext;
            delete temp;
        }

        head = nullptr;
    }
    void insertFirst(int val);
    void insertLast(int val);
    int insertAtPos(int pos, int val);
    int size();
    int deleteNode(int val);
    void printLL();
};

ListNode::ListNode(int val)
{
    m_iVal = val,
    m_ptrNext = nullptr;
}

int List::size() { return nodeCnts; }

void List::printLL()
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->m_iVal << " -> ";
        curr = curr->m_ptrNext;
    }
    cout << endl;
}
void List::insertFirst(int val)
{
    ListNode *ptrNewNode = new ListNode(val);
    nodeCnts++;

    ptrNewNode->m_ptrNext = head;
    head = ptrNewNode;
}

void List::insertLast(int val)
{
    ListNode *ptrNewNode = new ListNode(val);
    nodeCnts++;

    if (head == nullptr)
    {
        head = ptrNewNode;
        return;
    }

    ListNode *temp = head;
    while (temp->m_ptrNext != nullptr)
        temp = temp->m_ptrNext;

    temp->m_ptrNext = ptrNewNode;
}

int List::insertAtPos(int indx, int val)
{
    // Validating the index
    if (indx < 0 || indx > nodeCnts)
        return -1; // invalid index position

    ListNode *ptrNewNode = new ListNode(val);
    nodeCnts++;

    if (head == nullptr)
    {
        head = ptrNewNode;
        return 0;
    }

    ListNode *temp = head;
    if (indx == 0)
    {
        ptrNewNode->m_ptrNext = head;
        head = ptrNewNode;

        return 0;
    }
    for (int i = 0; i < indx - 1; i++)
    {
        temp = temp->m_ptrNext;
    }

    ptrNewNode->m_ptrNext = temp->m_ptrNext;
    temp->m_ptrNext = ptrNewNode;

    return 0;
}

int List::deleteNode(int val)
{
    if (head == nullptr)
        return -1;

    if (head->m_iVal == val)
    {
        ListNode *temp = head;
        head = head->m_ptrNext;
        delete temp;

        nodeCnts--;
        return 0;
    }

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr)
    {
        prev = curr;
        curr = curr->m_ptrNext;

        if (curr != nullptr && curr->m_iVal == val)
            break;
    }

    if (curr == nullptr)
        return -1;

    prev->m_ptrNext = curr->m_ptrNext;
    delete curr;
    nodeCnts--;

    return 0;
}
int main()
{
    List *lobj = new List();

    lobj->insertFirst(11);
    lobj->insertLast(21);
    lobj->insertLast(51);
    lobj->insertFirst(3);

    lobj->printLL();

    lobj->insertAtPos(0, 2);
    lobj->printLL();

    lobj->deleteNode(2);

    lobj->printLL();

    cout<<lobj->size()<<endl;
    return 0;
}