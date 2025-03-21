#include <iostream>

struct Node
{
    Node *left;
    Node *right;
    int data;
};

// Floor --> Gretest element that is <= x
int floor(Node *root, int x)
{
    // Code here

    int ans = -1;
    Node *curr = root;

    while (curr)
    {
        if (x == curr->data)
            return x;

        if (x < curr->data)
            curr = curr->left;
        else
        {
            // since, x is larger than curr root, root can be answer, but try for greter ans
            ans = curr->data;
            curr = curr->right;
        }
    }
    return ans;
}
