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

/*-
 We have to maintain the max path sum through out the recursive calls, and also required to return the maximum path sum from either 
the left side or right side, by including the root, 

*/
int getMaxPathSum(TreeNode *root, int &pathSum)
{
    if (!root)
        return 0;

    int leftSum = getMaxPathSum(root->left, pathSum);
    int rightSum = getMaxPathSum(root->right, pathSum);

    int currPathSum_one_side = max(leftSum, rightSum) + root->val;
    pathSum = max({pathSum, currPathSum_one_side, (leftSum + rightSum + root->val), root->val});

    return max(currPathSum_one_side, root->val);
}
int maxPathSum(TreeNode *root)
{

    int pathSum = INT_MIN;
    getMaxPathSum(root, pathSum);

    return pathSum;
}