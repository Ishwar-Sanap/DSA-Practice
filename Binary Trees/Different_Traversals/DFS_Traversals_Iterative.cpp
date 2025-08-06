#include <bits/stdc++.h>
using namespace std;

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

// Root -> Left ->Right
vector<int> preorderTraversal(TreeNode *root)
{

    if (!root)
        return {};

    vector<int> temp;
    stack<TreeNode *> stNodes;
    stNodes.push(root);

    while (!stNodes.empty())
    {
        // preorder traversal ..> Root left right

        TreeNode *stTop = stNodes.top();
        stNodes.pop();
        temp.push_back(stTop->val);

        // Last pushed will be top item, As stack usese LIFO
        if (stTop->right)
            stNodes.push(stTop->right);
        if (stTop->left)
            stNodes.push(stTop->left);
    }
    return temp;
}

// Left -> Root-> Right
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stNodes;
    vector<int> ans;

    TreeNode *currNode = root;
    while (currNode != NULL || !stNodes.empty())
    {

        // go until last left node as possibe from current node
        while (currNode != NULL)
        {
            stNodes.push(currNode);
            currNode = currNode->left;
        }

        TreeNode *topNode = stNodes.top();
        stNodes.pop();

        // Take root
        ans.push_back(topNode->val);

        // go right
        currNode = topNode->right;
    }

    return ans;
}

/*

Posorder Traversal : Left -> Right -> Root
step1 : Process nodes in reverse Preorder (Root → Right → Left).
step2 : reverse the answer order to Left → Right → Root.
*/
vector<int> postorderTraversal_ReverseLogic(TreeNode *root)
{
    if (!root)
        return {};

    stack<TreeNode *> st1;
    vector<int> ans;
    st1.push(root);

    while (!st1.empty())
    {
        TreeNode *currNode = st1.top();
        st1.pop();
        ans.push_back(currNode->val);

        if (currNode->left)
            st1.push(currNode->left);
        if (currNode->right)
            st1.push(currNode->right);
    }

    // reverse the answer
    reverse(ans.begin(), ans.end());

    return ans;
}

// Left-> Right -> Root
vector<int> postorderTraversal(TreeNode *root)
{

    stack<TreeNode *> st1;
    vector<int> ans;

    TreeNode *currNode = root;
    TreeNode *lastVisitedNode = NULL;

    while (currNode != NULL || !st1.empty())
    {
        // go to the left as much as possible from current node
        while (currNode != NULL)
        {
            st1.push(currNode);
            currNode = currNode->left;
        }

        TreeNode *topNode = st1.top();

        // If righ exist go to right, and also make sure to don't revist the alredy visited right nodes.
        if (topNode->right != NULL && lastVisitedNode != topNode->right)
        {
            currNode = topNode->right;
        }
        else
        {

            ans.push_back(topNode->val);
            st1.pop();

            lastVisitedNode = topNode;
        }
    }

    return ans;
}

int main()
{

    return 0;
}