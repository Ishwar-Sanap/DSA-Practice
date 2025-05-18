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

// Only check is cycle exist or not in Linked list
// https://leetcode.com/problems/linked-list-cycle/

bool hasCycle(ListNode *head)
{

    // Using slow and fast pointers
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

// https://leetcode.com/problems/linked-list-cycle-ii/

ListNode *detectCycle(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Loop found
        if (slow == fast)
        {
            ListNode *temp = head;
            // Identifying the starting point of loop
            while (temp != slow)
            {
                slow = slow->next;
                temp = temp->next;
            }

            return temp;
        }
    }

    return NULL;
}
int main()
{

    return 0;
}