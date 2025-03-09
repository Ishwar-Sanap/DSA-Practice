
/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        left = NULL;
        right = NULL;
    }
};

bool isSameTree(TreeNode *p, TreeNode *q)
{

    if (!p && !q)
        return true;
    else if (!p || !q || p->val != q->val)
        return false;

    bool leftSide = isSameTree(p->left, q->left);
    bool rightSide = isSameTree(p->right, q->right);

    return leftSide && rightSide;
}