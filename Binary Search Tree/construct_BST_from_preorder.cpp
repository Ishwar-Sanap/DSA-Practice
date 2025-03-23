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

// Optimized version
// TC --> O(N)
TreeNode *make_BST(int &i, int upperBound, vector<int> &preorder)
{
    if (i == preorder.size() || preorder[i] > upperBound)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[i]);
    i++;
    root->left = make_BST(i, root->val, preorder);   // while going left, update upper bound
    root->right = make_BST(i, upperBound, preorder); // while going right, pass same upper bound

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{

    int i = 0;
    TreeNode *root = make_BST(i, INT_MAX, preorder);

    return root;
}

// TC --> O(Nlong) + O(N)
/// SC --> O(N)
TreeNode *buildTree(int &i, int si, int ei, vector<int> &preorder, unordered_map<int, int> &mp)
{
    if (i == preorder.size() || si > ei)
        return NULL;

    int nodeVal = preorder[i];
    TreeNode *root = new TreeNode(nodeVal);

    int idx = mp[nodeVal];
    i++;

    root->left = buildTree(i, si, idx - 1, preorder, mp);
    root->right = buildTree(i, idx + 1, ei, preorder, mp);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{

    // In BST, if we perform inorder traversal we get sorted elements
    // So using Inorder and preorder traversal we can build unique binary tree i.e BST.

    int n = preorder.size();
    vector<int> inorder(preorder.begin(), preorder.end());
    sort(inorder.begin(), inorder.end());

    // map will store inorder elements and their indices
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    int i = 0;
    TreeNode *root = buildTree(i, 0, n - 1, preorder, mp);

    return root;
}

int main()
{

    return 0;
}