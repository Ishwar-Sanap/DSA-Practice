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

// Recursive way
TreeNode *insertIntoBST2(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST2(root->left, val);
    else
        root->right = insertIntoBST2(root->right, val);

    return root;
}

// Iterative way, T.C O(H) S.C--> O(1)
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
    {
        return new TreeNode(val);
    }

    TreeNode *curr = root;
    while (curr)
    {
        if (val < curr->val)
        {
            if (curr->left == NULL)
            {
                curr->left = new TreeNode(val);
                return root;
            }
            else
            {
                curr = curr->left;
                // go left to find  position to insert node
            }
        }

        else
        {
            if (curr->right == NULL)
            {
                curr->right = new TreeNode(val);
                return root;
            }
            else
            {
                curr = curr->right;
                // go right to find the position to insert node
            }
        }
    }

    return root;
}
int main()
{

    return 0;
}