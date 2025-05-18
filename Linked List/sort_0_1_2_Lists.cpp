#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *segregate(Node *head)
{
    // code here

    Node *head0 = new Node(-1);
    Node *temp0 = head0;

    Node *head1 = new Node(-1);
    Node *temp1 = head1;

    Node *head2 = new Node(-2);
    Node *temp2 = head2;

    Node *curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            temp0->next = curr;
            temp0 = temp0->next;
            curr = curr->next;
            temp0->next = NULL;
        }
        else if (curr->data == 1)
        {
            temp1->next = curr;
            temp1 = temp1->next;
            curr = curr->next;
            temp1->next = NULL;
        }
        else
        {

            temp2->next = curr;
            temp2 = temp2->next;
            curr = curr->next;
            temp2->next = NULL;
        }
    }

    temp0->next = head1->next;
    if (temp0->next == NULL) // if there are no  1 exits
    {
        temp0->next = head2->next;
    }
    else
        temp1->next = head2->next;

    return head0->next;
}