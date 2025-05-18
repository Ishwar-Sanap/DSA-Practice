#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void deleteAllOccurOfX(struct Node**head_ref, int x)
{
    // Write your code here

    Node *curr = *head_ref;

    while (curr)
    {
        if (curr->data == x)
        {
            Node *temp = curr;

            if (curr->prev == NULL) // remove head
            {

                *head_ref = curr->next;
                (*head_ref)->prev = NULL;
            }
            else
            {

                curr->prev->next = curr->next;

                if (curr->next)
                    curr->next->prev = curr->prev;
            }

            curr = curr->next;

            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
        }
        else
        {

            curr = curr->next;
        }
    }
}