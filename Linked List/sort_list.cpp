#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-list/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge2SortedList(ListNode *leftList, ListNode *rightList)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    while (leftList && rightList)
    {
        if (leftList->val <= rightList->val)
        {
            curr->next = leftList;
            leftList = leftList->next;
        }
        else
        {
            curr->next = rightList;
            rightList = rightList->next;
        }

        curr = curr->next;
    }

    if (leftList)
        curr->next = leftList;
    if (rightList)
        curr->next = rightList;

    return dummyNode->next;
}
ListNode *getMiddleOfList(ListNode *head)
{
    // EX;  1->2->3->4   we have 2 and 3 are  mid in this case but we want first one i.e 2 then only we can go till sinle node from list
    ListNode *slow = head;
    ListNode *fast = head->next; // slight change to ensure that we will get first mid element if we have even no of nodes
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
ListNode *sortList(ListNode *head)
{

    if (!head || !head->next)
        return head;

    ListNode *ptrMid = getMiddleOfList(head);
    ListNode *rightHead = ptrMid->next;
    ptrMid->next = NULL; // breaking list into 2 parts

    ListNode *leftList = sortList(head);       // left part of list
    ListNode *rightList = sortList(rightHead); // right part of list

    return merge2SortedList(leftList, rightList);
}