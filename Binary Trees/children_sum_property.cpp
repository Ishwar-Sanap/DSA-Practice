#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int checkChildrenSum(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;

    int leftChild = checkChildrenSum(root->left);
    int rightChild = checkChildrenSum(root->right);

    if (leftChild == -1 || rightChild == -1)
        return -1;

    if (leftChild + rightChild == root->data)
        return root->data;

    else
        return -1;
}
int isSumProperty(Node *root)
{
    if (checkChildrenSum(root) > 0)
        return 1;
        
    return 0;
}
int main()
{

    return 0;
}