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

bool checkSymmetry(TreeNode *rootLeft, TreeNode *rootRight)
{
    if (!rootLeft && !rootRight)
        return true;
    if (!rootLeft || !rootRight || rootLeft->val != rootRight->val)
        return false;

    bool leftSymmetry = checkSymmetry(rootLeft->left, rootRight->right);
    bool rightSymmetry = checkSymmetry(rootLeft->right, rootRight->left);

    return leftSymmetry && rightSymmetry;
}
bool isSymmetric(TreeNode *root)
{

    if (!root)
        return true;

    return checkSymmetry(root->left, root->right);
}

int main()
{

    return 0;
}