#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;

    TreeNode *delNodeParent = NULL;
    TreeNode *delNode = root;

    // Finding the node to delete
    while (delNode && delNode->val != key)
    {
        delNodeParent = delNode;

        if (key < delNode->val)
            delNode = delNode->left;
        else
            delNode = delNode->right;
    }

    if (!delNode)
        return root; // not found key to delete

    // if ther is only left or right child exist for node that we want to delete
    if (!delNode->left || !delNode->right)
    {
        TreeNode *childNodes = delNode->left ? delNode->left : delNode->right;

        if (!delNodeParent)
            root = childNodes;

        else if (delNodeParent->left == delNode)
            delNodeParent->left = childNodes;

        else if (delNodeParent->right == delNode)
            delNodeParent->right = childNodes;
    }
    else // both left and right child exist for node that we want to delete
    {
        // get the smallest node from right subtree
        TreeNode *curr = delNode->right;
        while (curr->left)
            curr = curr->left;

        curr->left = delNode->left;

        if (!delNodeParent)
            root = delNode->right;

        else if (delNodeParent->left == delNode)
            delNodeParent->left = delNode->right;

        else if (delNodeParent->right == delNode)
            delNodeParent->right = delNode->right;
    }

    delete delNode;
    delNode = NULL;

    return root;
}