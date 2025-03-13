#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

int widthOfBinaryTree(TreeNode *root)
{

    if (!root)
        return 0;

    queue<pair<TreeNode *, int>> qNodes;
    qNodes.push({root, 0}); // storing the node, and it's index

    int maxWidth = 0;

    while (!qNodes.empty())
    {
        int n = qNodes.size();

        int leftMostNodeIndx = qNodes.front().second;
        int rightMostNodeIndx = qNodes.back().second;

        maxWidth = max(maxWidth, rightMostNodeIndx - leftMostNodeIndx + 1);

        for (int i = 1; i <= n; i++)
        {
            TreeNode *currNode = qNodes.front().first;
            int Nodeindx = qNodes.front().second - leftMostNodeIndx; // to start Node index every time from 0, to avoid integer overflows
            qNodes.pop();

            if (currNode->left)
            {
                int currNodeIdx = 2 * Nodeindx + 1;
                qNodes.push({currNode->left, currNodeIdx});
            }

            if (currNode->right)
            {
                int currNodeIdx = 2LL * Nodeindx + 2;
                qNodes.push({currNode->right, currNodeIdx});
            }
        }
    }

    return maxWidth;
}
int main()
{

    return 0;
}