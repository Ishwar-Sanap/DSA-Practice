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

// If we do inorder traversal in BST, we get elements in sorted order

void inorder(TreeNode *root, int k, int &cnt, int &ans)
{
    if (!root)
        return;

    inorder(root->left, k, cnt, ans);

    cnt++;
    if (cnt == k)
    {
        ans = root->val;
        return;
    }

    inorder(root->right, k, cnt, ans);
}
int kthSmallest(TreeNode *root, int k)
{

    int ans = 0, cnt = 0;

    inorder(root, k, cnt, ans);
    return ans;
}