#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *LCR = nullptr;
    bool findGivenNodes(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return false;
        if (root == p || root == q)
        {
            LCR = root;
            return true;
        }

        bool leftSubTree = findGivenNodes(root->left, p, q);
        bool rightSubTree = findGivenNodes(root->right, p, q);

        // updating the LCR, since left and right subtree found p q
        if (leftSubTree && rightSubTree)
            LCR = root;

        return leftSubTree || rightSubTree;
    }
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        findGivenNodes(root, p, q);

        return LCR == nullptr ? root : LCR;
    }

    TreeNode *lowestCommonAncesto_V2(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(!root) return NULL;
        else if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncesto_V2(root->left,p,q); 
        TreeNode* right = lowestCommonAncesto_V2(root->right,p,q); 


        if(!left) return right;
        else if(!right) return left;
        else return root; // when left and right both are exists
    }
};