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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    vector<vector<int>> ans;
    if (!root)
        return ans;

    queue<TreeNode *> qNodes;
    qNodes.push(root);

    int level = 0;
    while (!qNodes.empty())
    {
        int n = qNodes.size();

        vector<int> traversal(n, 0);
        for (int i = 0; i < n; i++)
        {
            TreeNode *currNode = qNodes.front();
            qNodes.pop();

            // for odd levels add elemets from ending
            if (level % 2 != 0)
                traversal[n - i - 1] = currNode->val;
            else
                traversal[i] = currNode->val;

            if (currNode->left)
                qNodes.push(currNode->left);
            if (currNode->right)
                qNodes.push(currNode->right);
        }
        ans.push_back(traversal);
        level++;
    }

    return ans;
}