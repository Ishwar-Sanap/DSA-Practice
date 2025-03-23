#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = NULL, suc = NULL;
    while (root)
    {
        if (key < root->key)
        {
            suc = root;
            root = root->left;
        }
        else if (key > root->key)
        {
            pre = root;
            root = root->right;
        }
        else
        {
            Node *curr = root;
            // getting rightSubTree leftMost node
            curr = root->right;
            while (curr)
            {
                suc = curr;
                curr = curr->left;
            }

            // getting leftSubTree right most node
            curr = root->left;
            while (curr)
            {
                pre = curr;
                curr = curr->right;
            }

            return;
        }
    }
}

int main()
{

    return 0;
}