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

int getDiameter(TreeNode *root, int &dimeter)
{
    if (!root)
        return 0;

    int leftHeight = getDiameter(root->left, dimeter);
    int rightHeight = getDiameter(root->right, dimeter);

    // diameter can be maximum at any node in the paths, not necessorily it should passes through the root.
    dimeter = max(dimeter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode *root)
{

    int diameter = 0;
    getDiameter(root, diameter);
    return diameter;
}