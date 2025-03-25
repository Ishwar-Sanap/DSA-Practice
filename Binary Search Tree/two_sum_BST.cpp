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

void inorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
bool findTarget(TreeNode *root, int k)
{

    vector<int> arr;
    // IN BST Inorder traversal arr will be sorted in incresign order
    inorder(root, arr);

    int i = 0, j = arr.size() - 1;

    // applying two pointer to find node's
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == k)
            return true;
        else if (sum < k)
            i++;
        else
            j--;
    }

    return false;
}
int main()
{

    return 0;
}