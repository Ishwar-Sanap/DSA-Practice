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

TreeNode *  bulidTreeAndGetRootNode(int& i, int si, int ei, vector<int> &postorder, unordered_map<int, int> &mp)
{
    if (i == -1 || si > ei)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(postorder[i]);

    int index = mp[postorder[i]]; // it is the index to travese the postorder elements
    i--; // after decrement it goes towards the right side elemetns

    root->right = bulidTreeAndGetRootNode(i, index + 1, ei, postorder, mp); // go right first since, in posorder traversal --> Left Right Root
    root->left = bulidTreeAndGetRootNode(i, si, index - 1, postorder, mp);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int i = n-1, si = 0, ei = n-1;
    unordered_map<int, int> mp; // store indices of inorder

    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    TreeNode *root = bulidTreeAndGetRootNode(i,si,ei,postorder,mp);

    return root;
}

int main()
{

    return 0;
}