#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    // travese ptr2 n times, so there will be gap of n nodes between ptr1 and ptr2
    while (n--)
        ptr2 = ptr2->next;

    if (ptr2 == NULL) // all nodes travese i.e first node from start needs to remove
    {
        ListNode *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    // maintinng the gap of n nodes from end
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ListNode *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;
    return head;
}
int main()
{

    return 0;
}