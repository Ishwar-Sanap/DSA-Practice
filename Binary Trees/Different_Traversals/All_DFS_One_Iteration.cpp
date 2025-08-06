
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

/*
Approach
Use a stack, where each entry stores:
A node pointer.
A count (to track the traversal phase of the node):
1: Preorder (Process node, push left)
2: Inorder (Push right)
3: Postorder (Done, pop from stack)
*/
void allTraversals(TreeNode *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    if (!root)
        return;

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        TreeNode *topNode = st.top().first;
        int cnt = st.top().second;

        if (cnt == 1) // preorder
        {
            preorder.push_back(topNode->val);
            st.top().second++; // update the status of top node

            if (topNode->left)
                st.push({topNode->left, 1}); // inserting first time left nodes
        }
        else if (cnt == 2) // Inorder
        {
            inorder.push_back(topNode->val);
            st.top().second++; // update the status of top node

            if (topNode->right)
                st.push({topNode->right, 1}); // inserting first time right nodes
        }
        else // postorder
        {
            postorder.push_back(topNode->val);
            st.pop();
        }
    }
}

int main()
{

    return 0;
}