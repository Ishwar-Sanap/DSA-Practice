#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &temp)
{
    if (!root) return;

    // Traverse the left subtree
    inorder(root->left, temp);

    temp.push_back(root->data);

    //Traverse the right subtree
    inorder(root->right, temp);
}
void preorder(TreeNode *root, vector<int> &temp)
{
    if (!root) return;
    temp.push_back(root->data);
    preorder(root->left, temp); // Traverse the left subtree
    preorder(root->right, temp); //Traverse the right subtree
}
void postorder(TreeNode *root, vector<int> &temp)
{
    if (!root) return;
    postorder(root->left, temp); //Traverse the left subtree
    postorder(root->right, temp); //Traverse the right subtree
    temp.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans(3);
    inorder(root, ans[0]);
    preorder(root, ans[1]);
    postorder(root, ans[2]);

    return ans;
}
