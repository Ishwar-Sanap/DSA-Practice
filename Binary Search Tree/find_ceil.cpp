#include <iostream>

struct Node
{
    Node *left;
    Node *right;
    int data;
};

/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Ceil --> Smallest element, >= X
*/
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    // Your code here
    int ans = -1;
    Node *curr = root;

    while (curr)
    {
        if (curr->data == input)
            return input;

        if (input < curr->data)
        {   // since curr data is greater, so this can be the answer, but go left to find more closer answer to input..
            ans = curr->data;
            curr = curr->left;
        }

        else
            curr = curr->right;
    }

    return ans;
}