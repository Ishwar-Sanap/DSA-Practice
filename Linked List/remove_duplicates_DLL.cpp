#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

/*
https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4

Explanation:
Only the first occurance of nodes with values 2,3 and 4 are
retained, rest repeating nodes are deleted.
*/

Node *removeDuplicates(struct Node *head)
{
    // Your code here

    if (!head)
        return NULL;

    Node *curr = head->next;

    while (curr)
    {
        if (curr->prev->data == curr->data)
        {
            Node *temp = curr;

            curr->prev->next = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;

            temp->prev = NULL;
            temp->next = NULL;
            delete temp;
        }
        else
            curr = curr->next;
    }

    return head;
}