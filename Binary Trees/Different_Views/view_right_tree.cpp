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

void traverseKaroBFS(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    queue<TreeNode *> qNodes;
    qNodes.push(root);

    while (!qNodes.empty())
    {
        int n = qNodes.size();
        
        // traverse all nodes in level
        for(int i = 1; i<= n; i++)
        {
            TreeNode *currNode = qNodes.front();
            qNodes.pop();

            if(currNode->left) qNodes.push(currNode->left);
            if(currNode->right) qNodes.push(currNode->right);

            // only last node in level add to res
            if(i == n)
            {
                ans.push_back(currNode->val);
            }
        }

        
    }
}

void traverseKaroDFS(TreeNode* root, int level, vector<int>&ans)
{
    if(!root) return;


    if(ans.size() <= level) ans.push_back(root->val);

    // since we want right side view, go right.... first , then left..
    traverseKaroDFS(root->right,level+1,ans);
    traverseKaroDFS(root->left,level+1,ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    // traverseKaroBFS(root, ans);
    traverseKaroDFS(root,0,ans);

    return ans;
}
int main()
{

    return 0;
}