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

void makeArrangementTogoUpward(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
{
    if (!root)
        return;

    if (root->left)
        mp[root->left] = root;

    makeArrangementTogoUpward(root->left, mp);

    if (root->right)
        mp[root->right] = root;

    makeArrangementTogoUpward(root->right, mp);
}

/*
we don't have any way to go upward direction from target, for taking k distance nodes
 so we firstly need the arrangement of going in upward direction..

 for each of the node, we store it's parent node in map.

 from target node start BFS traversal,
*/
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> mp; // curr node and it's parent, and bool to check if it is alredy visited.
    unordered_map<TreeNode *, bool> visitedNodes;

    makeArrangementTogoUpward(root, mp);

    queue<TreeNode *> qNodes;
    qNodes.push(target);

    int level = 0;
    while (!qNodes.empty())
    {
        int n = qNodes.size();

        if (level == k)
            break;

        for (int i = 1; i <= n; i++)
        {
            TreeNode *currNode = qNodes.front();
            qNodes.pop();
            visitedNodes[currNode] = true;
    
            if (currNode->left && visitedNodes[currNode->left] == false)
            {
                qNodes.push(currNode->left);
            }
            if (currNode->right && visitedNodes[currNode->right] == false)
            {
                qNodes.push(currNode->right);
            }

            // check if currNodes, parent is alredy visited or not
            TreeNode *parent = mp[currNode];
            if (parent && visitedNodes[parent] == false) // if parent node is not visited yet, then add into queue
            {
                qNodes.push(parent); // going to upward, toward parent
            }
        }
        level++;
    }

    vector<int> ans;
    while (!qNodes.empty())
    {
        ans.push_back(qNodes.front()->val);

        qNodes.pop();
    }
    return ans;
}
int main()
{

    return 0;
}