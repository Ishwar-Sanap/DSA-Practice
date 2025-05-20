#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge2SortedList(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (l1 && l2)
    {
        if (l1->data <= l2->data)
        {
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
        else
        {
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
    }

    if (l1)
        temp->bottom = l1;
    if (l2)
        temp->bottom = l2;

    return dummyNode->bottom;
}
Node *flatten(Node *root)
{
    // Your code here

    if (!root || !root->next)
        return root;

    Node *curr = root;
    Node *newHead = new Node(-1);
    Node *temp = NULL;
    while (curr)
    {
        newHead->bottom = merge2SortedList(temp, curr);
        curr = curr->next;

        temp = newHead->bottom;
    }

    return newHead->bottom;
}