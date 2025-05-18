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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *head = new ListNode(-1);
    ListNode *curr = head;

    int carry = 0;
    while (l1 && l2)
    {
        int add = l1->val + l2->val + carry;

        int digit = add % 10;
        curr->next = new ListNode(digit);
        curr = curr->next;

        carry = add / 10;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1)
    {
        int add = l1->val + carry;

        int digit = add % 10;
        curr->next = new ListNode(digit);
        curr = curr->next;

        carry = add / 10;

        l1 = l1->next;
    }

    while (l2)
    {
        int add = l2->val + carry;

        int digit = add % 10;
        curr->next = new ListNode(digit);
        curr = curr->next;

        carry = add / 10;

        l2 = l2->next;
    }

    if (carry)
        curr->next = new ListNode(carry);

    return head->next;
}