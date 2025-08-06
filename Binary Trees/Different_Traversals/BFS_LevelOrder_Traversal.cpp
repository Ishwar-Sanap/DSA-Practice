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

vector<vector<int>> levelOrder(TreeNode *root)
{

    vector<vector<int>> ans;
    if(!root) return ans;

   
    queue<TreeNode*>qNodes;

    qNodes.push(root);

    while(!qNodes.empty())
    {
        int n = qNodes.size(); // no of nodes in current level.
        vector<int> traversal;

        // traverse through each node of the level
        for(int i = 1; i<= n; i++)
        {
            TreeNode* currNode = qNodes.front(); 
            qNodes.pop();

            traversal.push_back(currNode->val);

            if(currNode->left) qNodes.push(currNode->left);

            if(currNode->right) qNodes.push(currNode->right);
        }

        ans.push_back(traversal);
    }

    return ans;

}
int main()
{

    return 0;
}