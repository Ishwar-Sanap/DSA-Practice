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

// Using the same approach of Preorder Morris Traversal TC O(N) SC O(1)
 void flatten(TreeNode* root) {
        
    if(!root) return;

    TreeNode* currNode= root;

    while(currNode)
    {
        if(currNode ->left)
        {
            TreeNode* temp = currNode;

            // go towards the leftSub tree right most node
            temp = temp->left;
            while(temp->right)
                temp = temp->right;

            temp->right = currNode->right; // for going backwrd toward to root right node..

            currNode->right = currNode->left; // for making the flatten LL

            TreeNode* leftCopy = currNode->left;
            currNode->left = NULL;

            currNode = leftCopy;
        }
        else{
            currNode = currNode->right;
        }
    }
}

// TC O(N) SC O(N)
TreeNode* nextNode =  nullptr;
void flatten_V2(TreeNode* root)
{
    if(!root) return;

    flatten_V2(root->right);
    flatten_V2(root->left);

    root->left = NULL;
    root->right = nextNode;
    nextNode = root;

}
int main()
{

    return 0;
}