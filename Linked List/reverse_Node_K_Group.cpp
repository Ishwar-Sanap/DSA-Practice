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

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// https://leetcode.com/problems/reverse-nodes-in-k-group/

/*
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/
ListNode *reverseKGroup(ListNode *head, int k)
{

    ListNode *curr = head;
    ListNode *groupStart = head;

    ListNode *newHead = new ListNode(-1);
    ListNode *temp = newHead;

    int cnt = 1;
    while (curr)
    {
        if (cnt < k)
        {
            curr = curr->next;
            cnt++;
        }
        else
        {
            ListNode *nextNode = curr->next;
            curr->next = NULL;

            temp->next = reverseList(groupStart);
            while (temp->next)
                temp = temp->next;

            curr = nextNode;
            groupStart = curr;
            cnt = 1;
        }
    }

    // attach remaining nodes
    temp->next = groupStart;
    return newHead->next;
}

int main()
{

    return 0;
}