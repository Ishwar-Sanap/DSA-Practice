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

class Solution
{
public:
    TreeNode *prev = NULL;
    TreeNode *invalid1 = NULL;
    TreeNode *invalid2 = NULL;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        // dealing with sorted nodes, in inorder traversals..
        if (prev == NULL)
        {
            prev = root;
        }
        else
        {

            // there is invalid node , sorted order is not there
            if (root->val < prev->val)
            {
                // update only first time
                if (invalid1 == NULL)
                    invalid1 = prev;

                invalid2 = root;
            }

            prev = root;
        }

        inorder(root->right);
    }
    void recoverTree(TreeNode *root)
    {

        // finding the invalid nodes using inorder
        inorder(root);

        swap(invalid1->val, invalid2->val);
    }
};