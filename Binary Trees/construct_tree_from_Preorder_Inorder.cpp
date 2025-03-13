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

TreeNode *  bulidTreeAndGetRootNode(int& i, int si, int ei, vector<int> &preorder, unordered_map<int, int> &mp)
{
    if (i == preorder.size() || si > ei)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[i]);

    int index = mp[preorder[i]]; // it is the index to travese the preorder elements
    i++; // after incrementing it goes, toward the left side elements 
    root->left = bulidTreeAndGetRootNode(i, si, index - 1, preorder, mp); // first left, since Preorder--> Root Left Right
    root->right = bulidTreeAndGetRootNode(i, index + 1, ei, preorder, mp);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
    int i = 0, si = 0, ei = n-1;
    unordered_map<int, int> mp; // store indices of inorder

    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    TreeNode *root = bulidTreeAndGetRootNode(i,si,ei,preorder,mp);

    return root;
}

int main()
{

    return 0;
}