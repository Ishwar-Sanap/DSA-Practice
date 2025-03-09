
#include <bits/stdc++.h>
using namespace std;

/*
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftSubTreeD = maxDepth(root->left);
        if (leftSubTreeD == -1)
            return -1;

        int rightSubTreeD = maxDepth(root->right);
        if (rightSubTreeD == -1 || abs(leftSubTreeD - rightSubTreeD) > 1)
            return -1;

        return 1 + max(leftSubTreeD, rightSubTreeD);
    }
    bool isBalanced(TreeNode *root)
    {

        int ret = maxDepth(root);

        return ret == -1 ? false : true;
    }
};