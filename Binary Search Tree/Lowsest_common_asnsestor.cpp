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

// T.C -> O(H)
TreeNode *lowestCommonAncestorIterative(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;

        else
            return root;
    }

    return NULL;
}

//T.C -> O(N)
bool traverseKaro(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&LCR)
{
    if (!root)
        return false;

    if (root == p || root == q)
    {
        LCR = root;
        return true;
    }

    bool l = false, r = false;

    if (p->val < root->val || q->val < root->val)
        l = traverseKaro(root->left, p, q, LCR);
    if (p->val > root->val || q->val > root->val)
        r = traverseKaro(root->right, p, q, LCR);

    if (l && r)
        LCR = root;

    return l || r;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{

    TreeNode *LCR = NULL;
    traverseKaro(root, p, q, LCR);

    return LCR;
}

