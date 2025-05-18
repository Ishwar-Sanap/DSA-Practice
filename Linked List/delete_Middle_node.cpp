#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head)
{

    if (!head || !head->next)
    {
        // delete head;
        return NULL;
    }
    ListNode *dummyPrev = new ListNode(-1);
    dummyPrev->next = head;

    // slow is assigned one step behind the head since, we want to delete middle and link to next nodes
    ListNode *slow = dummyPrev;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}
int main()
{

    return 0;
}