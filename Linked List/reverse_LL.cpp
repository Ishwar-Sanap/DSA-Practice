#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList_Iterative(ListNode *head)
    {

        // for empty or single node return as it is list
        if (!head || !head->next)
            return head;

        ListNode *prevNode = nullptr;
        ListNode *currNode = head;
        ListNode *nextNode = nullptr;

        while (currNode)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    ListNode *reverseList_Recursive(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *newHead = reverseList_Recursive(head->next);

        ListNode *nextNode = head->next;
        nextNode->next = head;
        head->next = NULL;

        return newHead;
    }
};

int main()
{

    return 0;
}