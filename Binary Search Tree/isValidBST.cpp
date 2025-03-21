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

bool checkValid(TreeNode *root, long minVal, long maxVal)
{
    if (!root)
        return true;

    if (!(maxVal < root->val && root->val < minVal))
        return false;

    bool leftSubtree = checkValid(root->left, root->val, maxVal); // since it is BST, left will always have smaller value

    bool rightSubTree = checkValid(root->right, minVal, root->val); // right will alway have larger value

    return leftSubtree && rightSubTree;
}
bool isValidBST(TreeNode *root)
{
    return checkValid(root, LONG_MAX, LONG_MIN);
}

int main()
{

    return 0;
}