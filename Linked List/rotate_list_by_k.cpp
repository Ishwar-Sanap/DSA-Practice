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

/*
https://leetcode.com/problems/rotate-list/ 

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/
int getNodesCnt(ListNode *head)
{
    int cnt = 0;
    while (head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}
ListNode *rotateRight(ListNode *head, int k)
{

    if (!head || !head->next || k == 0)
        return head;

    ListNode *newHead = NULL;
    int n = getNodesCnt(head);

    k = k % n;
    if (k == 0)
        return head;

    ListNode *ptr1 = head;
    ListNode *ptr2 = head;

    while (k--)
        ptr2 = ptr2->next;

    while (ptr2->next)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    newHead = ptr1->next;
    ptr1->next = NULL;
    // Rotated the list
    ptr2->next = head;

    return newHead;
}

int main()
{

    return 0;
}