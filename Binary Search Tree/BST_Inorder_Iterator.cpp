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

class BSTIterator
{
public:
    // There are at N nodes pushed into stack, through out the overall iterator
    // and next called N times , so avg, T.C (N/N) = O(1)
    // S.C --> O(H) , max elemetns that stored in stack

    stack<TreeNode *> st;
    void insertLeftSubTreeNodes(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode *root)
    {
        insertLeftSubTreeNodes(root);
    }

    int next()
    {
        TreeNode *top = st.top();
        st.pop();

        if (top->right)
            insertLeftSubTreeNodes(top->right);

        return top->val;
    }

    bool hasNext()
    {
        if (st.empty())
            return false;
        return true;
    }
};
