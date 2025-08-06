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

// ALL Morris traversal T.C --> O(N) , S.C --> O(1)

// Left->Root->Right
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    TreeNode *currNode = root;
    while (currNode)
    {
        if (currNode->left)
        {
            TreeNode *temp = currNode;
            temp = temp->left;

            // go towards the right most pointer
            while (temp->right)
            {
                temp = temp->right;
            }

            // assinging temp->right pointer to currNode, for backward traversal
            temp->right = currNode;

            // before moving to left make left pointer of currNode as NULL, to avoid further dead loop situations.
            TreeNode *leftCopy = currNode->left;
            currNode->left = NULL;

            // go left for left subtree traversal
            currNode = leftCopy;
        }
        else
        {

            ans.push_back(currNode->val);
            currNode = currNode->right; // go right
        }
    }

    return ans;
}

// Root->Left->Right
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    TreeNode *currNode = root;

    while (currNode)
    {
        // root;
        ans.push_back(currNode->val);

        if (currNode->left)
        {
            TreeNode *temp = currNode;
            temp = temp->left;

            // go towards left Subtree, rightmost nodes.
            while (temp->right)
                temp = temp->right;

            // for going backward stored the currNode-> right pointer
            // here we have to visit currNode->right element next, since root, is alredy printed
            temp->right = currNode->right;

            // mark current node left as NULL, to avoid dead loop
            TreeNode *leftCopy = currNode->left;
            currNode->left = NULL;

            // go to the left subtree
            currNode = leftCopy;
        }
        else
        {
            currNode = currNode->right;
        }
    }
    return ans;
}

//Left->Right->Root
// for post order, we consider it in reverse fashion like : Root->Right->Left
// and while returning the answer will reverse the ans..
vector<int> postorderTraversal(TreeNode* root)
{
    vector<int>ans;
    if(!root) return ans;
    TreeNode* currNode = root;

    while(currNode)
    {
        ans.push_back(currNode->val);

        if(currNode->right)
        {
            TreeNode* temp = currNode;
            
            // go towards the right subtree left most node
            temp = temp->right;
            while(temp->left)
                temp = temp->left;

            temp->left = currNode->left; 

            TreeNode*copyRight = currNode->right;
            currNode->right = NULL;

            currNode = copyRight;
        }
        else
        {
          currNode = currNode->left;
        }
    }

    // reverse the answer
    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{   

    TreeNode * root = new TreeNode(11);
    root->left =  new TreeNode(21);
    root->right = new TreeNode(51);

    vector<int> preorder = postorderTraversal(root);

    for(int ele : preorder)
        cout<<ele<<" ";

    return 0;
}